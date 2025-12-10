#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_TOKEN_LENGTH 100
#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 1000

// 词法单元结构体
typedef struct {
    char token_type[20];
    char lexeme[100];
    char attribute[100];
} Token;

Token tokens[MAX_TOKENS];
int token_count = 0;

// 关键字列表
const char* keywords[] = {"void", "int", "main", "return", "for", "while", "if", "else", "struct", NULL};
const char* keyword_types[] = {"VOID", "TYPE", "MAIN", "RETURN", "FOR", "WHILE", "IF", "ELSE", "STRUCT", NULL};

// 运算符列表
const char* operators[] = {"=", ">=", "<=", "==", "!=", "<", ">", "+", "-", "*", "/", "%", "^", "&&", "&", "||", "!", "(", ")", "[", "]", "{", "}", ";", ",", ".", NULL};
const char* operator_types[] = {"ASSIGN", "RELOP", "RELOP", "RELOP", "RELOP", "RELOP", "RELOP", "ADD", "MINUS", "STAR", "DIV", "MOD", "POWER", "AND", "SINGALAND", "OR", "NOT", "LP", "RP", "LB", "RB", "LBRACE", "RBRACE", "SEMICOLON", "COMMA", "GETMEMBER", NULL};

/**
 * 计算字符串的哈希值，用于生成标识符的属性
 */
unsigned int hash_string(const char* str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash << 5) + *str++;
    }
    return hash & 0x7FFFFFFF; // 确保是正数
}

/**
 * 检查字符串是否为关键字
 * @return 如果是关键字，返回对应的类型字符串，否则返回NULL
 */
const char* is_keyword(const char* str) {
    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return keyword_types[i];
        }
    }
    return NULL;
}

/**
 * 检查字符串是否为运算符
 * @return 如果是运算符，返回对应的类型字符串，否则返回NULL
 */
const char* is_operator(const char* str, int* length) {
    // 优先检查多字符运算符
    int max_len = 0;
    const char* found_type = NULL;
    
    for (int i = 0; operators[i] != NULL; i++) {
        int op_len = strlen(operators[i]);
        if (strncmp(str, operators[i], op_len) == 0) {
            if (op_len > max_len) {
                max_len = op_len;
                found_type = operator_types[i];
            }
        }
    }
    
    if (length != NULL) {
        *length = max_len;
    }
    
    return found_type;
}

/**
 * 检查字符是否为空白字符
 */
int is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v';
}

/**
 * 过滤注释（移除C风格和C++风格注释）
 */
void filter_comments(char* code) {
    int len = strlen(code);
    int i = 0;      // 当前读取位置
    int j = 0;      // 当前写入位置
    int in_comment = 0;  // 是否在注释中
    int in_string = 0;   // 是否在字符串中
    
    while (i < len) {
        // 不在注释中
        if (!in_comment) {
            // 检查是否为字符串
            if (code[i] == '"' && i > 0 && code[i-1] != '\\') {
                in_string = !in_string;
            }
            
            if (!in_string) {
                // 检查是否开始C风格注释
                if (i < len - 1 && code[i] == '/' && code[i+1] == '*') {
                    in_comment = 1;
                    i += 2;
                    continue;
                }
                // 检查是否开始C++风格注释
                else if (i < len - 1 && code[i] == '/' && code[i+1] == '/') {
                    in_comment = 2;
                    i += 2;
                    continue;
                }
            }
            
            // 正常字符，保留
            code[j++] = code[i++];
        } else {
            // 在C风格注释中
            if (in_comment == 1) {
                if (i < len - 1 && code[i] == '*' && code[i+1] == '/') {
                    in_comment = 0;
                    i += 2;
                } else {
                    i++;
                }
            }
            // 在C++风格注释中
            else if (in_comment == 2) {
                if (code[i] == '\n') {
                    in_comment = 0;
                    code[j++] = '\n';
                }
                i++;
            }
        }
    }
    
    code[j] = '\0';  // 添加字符串结束符
}

/**
 * 执行词法分析
 */
void perform_lexical_analysis(const char* code) {
    token_count = 0;
    int i = 0;
    int len = strlen(code);
    
    while (i < len && token_count < MAX_TOKENS) {
        // 跳过空白字符
        if (is_whitespace(code[i])) {
            i++;
            continue;
        }
        
        // 检查是否为运算符
        int op_length = 0;
        const char* op_type = is_operator(&code[i], &op_length);
        if (op_type != NULL && op_length > 0) {
            strcpy(tokens[token_count].token_type, op_type);
            strncpy(tokens[token_count].lexeme, &code[i], op_length);
            tokens[token_count].lexeme[op_length] = '\0';
            
            // 对于关系运算符，属性为运算符本身
            if (strcmp(op_type, "RELOP") == 0) {
                strcpy(tokens[token_count].attribute, tokens[token_count].lexeme);
            } else {
                tokens[token_count].attribute[0] = '\0';
            }
            
            token_count++;
            i += op_length;
            continue;
        }
        
        // 检查是否为标识符或关键字
        if (isalpha(code[i]) || code[i] == '_') {
            int j = 0;
            char id[MAX_TOKEN_LENGTH];
            
            while (i < len && (isalnum(code[i]) || code[i] == '_')) {
                id[j++] = code[i++];
            }
            id[j] = '\0';
            
            const char* keyword_type = is_keyword(id);
            if (keyword_type != NULL) {
                strcpy(tokens[token_count].token_type, keyword_type);
                strcpy(tokens[token_count].lexeme, id);
                
                // 对于MAIN，生成哈希属性
                if (strcmp(keyword_type, "MAIN") == 0) {
                    sprintf(tokens[token_count].attribute, "%u", hash_string(id));
                } else {
                    tokens[token_count].attribute[0] = '\0';
                }
            } else {
                // 普通标识符
                strcpy(tokens[token_count].token_type, "ID");
                strcpy(tokens[token_count].lexeme, id);
                sprintf(tokens[token_count].attribute, "%u", hash_string(id));
            }
            
            token_count++;
            continue;
        }
        
        // 检查是否为数字
        if (isdigit(code[i])) {
            int j = 0;
            char num[MAX_TOKEN_LENGTH];
            
            while (i < len && isdigit(code[i])) {
                num[j++] = code[i++];
            }
            num[j] = '\0';
            
            strcpy(tokens[token_count].token_type, "INT");
            strcpy(tokens[token_count].lexeme, num);
            strcpy(tokens[token_count].attribute, num);  // 数字的属性就是其值
            
            token_count++;
            continue;
        }
        
        // 其他字符，跳过
        i++;
    }
}

/**
 * 确保目录存在，如果不存在则创建
 */
int ensure_directory_exists(const char* file_path) {
    char* dir = strdup(file_path);
    char* last_slash = strrchr(dir, '/');
    
    if (last_slash != NULL) {
        *last_slash = '\0';  // 截断到目录部分
        
        // 检查目录是否存在
        struct stat st;
        if (stat(dir, &st) != 0) {
            // 目录不存在，创建目录
            char* mkdir_cmd = malloc(strlen(dir) + 20);
            sprintf(mkdir_cmd, "mkdir -p %s", dir);
            int result = system(mkdir_cmd);
            free(mkdir_cmd);
            
            if (result != 0) {
                fprintf(stderr, "Error: Cannot create directory %s\n", dir);
                free(dir);
                return 0;
            }
        }
    }
    
    free(dir);
    return 1;
}

/**
 * 将词法分析结果写入文件
 */
int write_lexical_result(const char* output_file) {
    // 确保输出目录存在
    if (!ensure_directory_exists(output_file)) {
        return 0;
    }
    
    FILE* f = fopen(output_file, "w");
    if (f == NULL) {
        fprintf(stderr, "Error: Cannot open output file %s\n", output_file);
        return 0;
    }
    
    // 写入表头
    fprintf(f, "%-15s%-15s%-15s\n", "单词", "词素", "属性");
    fprintf(f, "%-15s%-15s%-15s\n", "===============", "===============", "===============");
    
    // 写入每个词法单元
    for (int i = 0; i < token_count; i++) {
        fprintf(f, "%-15s%-15s%-15s\n", tokens[i].token_type, tokens[i].lexeme, tokens[i].attribute);
    }
    
    fclose(f);
    printf("词法分析结果已写入: %s\n", output_file);
    return 1;
}

/**
 * 从文件读取内容
 */
char* read_file_content(const char* filename) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr, "Error: Cannot open input file %s\n", filename);
        return NULL;
    }
    
    // 获取文件大小
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    
    // 分配内存
    char* content = (char*)malloc(size + 1);
    if (content == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        fclose(f);
        return NULL;
    }
    
    // 读取文件内容
    size_t bytes_read = fread(content, 1, size, f);
    content[bytes_read] = '\0';
    
    fclose(f);
    return content;
}

/**
 * 处理单个文件
 */
int process_file(const char* input_file, const char* output_file) {
    // 读取文件内容
    char* code = read_file_content(input_file);
    if (code == NULL) {
        return 0;
    }
    
    // 过滤注释
    filter_comments(code);
    
    // 执行词法分析
    perform_lexical_analysis(code);
    
    // 写入结果
    int success = write_lexical_result(output_file);
    
    // 释放内存
    free(code);
    
    return success;
}

/**
 * 主函数
 */
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage:\n");
        printf("  %s input_file.c [output_file.lex]\n", argv[0]);
        return 1;
    }
    
    char* input_file = argv[1];
    char output_file[MAX_LINE_LENGTH];
    
    if (argc == 3) {
        strcpy(output_file, argv[2]);
    } else {
        // 默认输出文件名
        char* dot_pos = strrchr(input_file, '.');
        if (dot_pos != NULL && strcmp(dot_pos, ".c") == 0) {
            strncpy(output_file, input_file, dot_pos - input_file);
            strcpy(output_file + (dot_pos - input_file), ".lex");
        } else {
            sprintf(output_file, "%s.lex", input_file);
        }
    }
    
    return process_file(input_file, output_file) ? 0 : 1;
}