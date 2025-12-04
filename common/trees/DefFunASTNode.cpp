#include "DefFunASTNode.h"
#include "DefVarASTNode.h"
#include <cstring>
DefFunASTNode::DefFunASTNode(char* content, AbstractASTNode* argList, AbstractASTNode* funcBody)
    :AbstractASTNode(content, ASTNodeType::defFunc)
{
    this->argList = argList;
    this->addChildNode(funcBody);
}

void DefFunASTNode::printInfo(int depth)
{
    fprintf(ast_output_file, "Function define. Name:%s", this->content.c_str());
    // 打印参数列表，确保格式与其他节点一致
    AbstractASTNode* var = (AbstractASTNode*)this->argList;
    // 只有当存在参数时才进行特殊处理
    if (var != NULL) {
        fprintf(ast_output_file, "\n");
        // 添加适当的缩进以保持对齐
        for (int i = 0; i < 8; i++) fprintf(ast_output_file, " ");
        AbstractASTNode::__printTree(var, depth + 1);
        var = var->getPeer();
        while (var != NULL) {
            // 参数的兄弟节点也需要保持相同的缩进
            for (int i = 0; i < 8; i++) fprintf(ast_output_file, " ");
            AbstractASTNode::__printTree(var, depth + 1);
            var = var->getPeer();
        }
    } else {
        // 没有参数时也需要输出换行符，确保节点类型和Children信息分开
        fprintf(ast_output_file, "\n");
    }
}

void DefFunASTNode::setRevType(char* type)
{
    if (strcmp(type, "int") == 0) {
        this->revType = symbolType::integer;
    } else if (strcmp(type, "void") == 0) {
        this->revType = symbolType::Void;
    }
}
