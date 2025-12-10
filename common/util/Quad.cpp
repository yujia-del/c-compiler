#include "Quad.h"
#include <typeinfo>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace compiler;


// flag的不同值如下:
/* 
enum class symbolType
{
    unset = -1,
    integer = 0,
    function = 1,
    pointer = 2,
    boolean = 3,
    Void = 4,
    Struct = 5,
    Array = 6,
    literal = 7
};
*/

// 四元式：
/*
四元式实际上是一种“三地址语句”的等价表示。它的一般形式为：
(op,arg1,arg2,result)
*/

/*
symbol代表变量，int代表字面量
比如 int a = 1；
这里面，a是变量，1是字面量
char a[100] = "111223";
就是将字符串字面量赋值给变量
*/

/*********************** opCode 的操作有很多，对应函数的第一个参数
 * Operation Code for a Quad:
 * @enum JUMP:  JUMP operation.
 * @enum JUMP_SMALL:    if arg1 <  arg2, JUMP
 * @enum JUMP_EQ_SMALL: if arg1 <= arg2, JUMP
 * @enum JUMP_GRATE:    if arg1 >  arg2, JUMP
 * @enum JUMP_EQ_GREAT: if arg1 >= arg2, JUMP
 * @enum JUMP_EQUAL:    if arg1 == arg2, JUMP
 * @enum JUMP_NOT_EQUAL:if arg1 != arg2, JUMP
 * @enum PLUS:  arg1 + arg2 to result
 * @enum MINUS: arg1 - arg2 to result
 * @enum TIMES: arg1 * arg2 to result
 * @enum DIV:   arg1 / arg2 to result
 * @enum MOD:   arg1 % arg2 to result
 * @enum POWER: arg1 ^ arg2 to result
 * @enum NEGATIVE:   - arg1 to result
 * @enum ASSIGN:       arg1 to result
 * @enum ASSIGN_ARRAY: result[arg2] = arg1
 * @enum ASSIGN_STRUCT: result.arg2 = arg1
 * @enum GET_ADDRESS: &arg1 to reuslt
 * @enum PARAM: Param of the function will be called
 * @enum CALL: CALL function
 * @enum RETURN: Exit from a function
 * @enum GET_VALUE: Get the value of a pointer
 * @enum GET_ARRAY: Get the value of an array
 * @enum GET_STRUCT:GET the value of a struct
 ************************
*/
Quad::Quad(OpCode op, int result)// bool 运算符,代表正负
{
    this->op = op;
    this->arg1.var = NULL;
    this->arg2.var = NULL;
    this->result.target = result;
    this->flag = 3;
}

Quad::Quad(OpCode op, symbol *arg1, symbol *result) 
// assign variable to variable
{
    this->op = op;
    this->arg1.var = arg1;
    this->arg2.var = NULL;
    this->result.var = result;
    this->flag = 7;
}

Quad::Quad(OpCode op, int arg1, symbol *result)
// assign literals to variable
// 字面量到变量
{
    this->op = op;
    this->arg1.target = arg1;
    this->arg2.var = NULL;
    this->result.var = result;
    this->flag = 6;
}

Quad::Quad(OpCode op, symbol *arg1, symbol *arg2, symbol *result) 
// 二元运算符，两个变量运算
{
    this->op = op;
    this->arg1.var = arg1;
    this->arg2.var = arg2;
    this->result.var = result;
    this->flag = 7;
}

Quad::Quad(OpCode op, int arg1, symbol *arg2, symbol *result)
// 变量跟字面量运算：2*a
{
    this->op = op;
    this->arg1.target = arg1;
    this->arg2.var = arg2;
    this->result.var = result;
    this->flag = 6;
}

Quad::Quad(OpCode op, symbol *arg1, int arg2, symbol *result)
// 变量跟字面量运算：a*2
{
    this->op = op;
    this->arg1.var = arg1;
    this->arg2.target = arg2;
    this->result.var = result;
    this->flag = 5;
}
Quad::Quad(OpCode op, int arg1, int arg2, symbol *result)
{
    this->op = op;
    this->arg1.target = arg1;
    this->arg2.target = arg2;
    this->result.var = result;
    this->flag = 5;
}

Quad::Quad(OpCode op, int arg1, symbol *arg2, int result)
{
    this->op = op;
    this->arg1.target = arg1;
    this->arg2.var = arg2;
    this->result.target = result;
    this->flag = 13;
}

Quad::Quad(OpCode op, symbol *arg1, symbol *arg2, int result)
// 变量跟变量运算，值为int
{
    this->op = op;
    this->arg1.var = arg1;
    this->arg2.var = arg2;
    this->result.target = result;
    this->flag = 3;
}
Quad::Quad(OpCode op, symbol *arg1, int arg2, int result)
// 变量跟字面量运算，值为int
{
    this->op = op;
    this->arg1.var = arg1;
    this->arg2.target = arg2;
    this->result.target = result;
    this->flag = 1;
}
Quad::Quad(OpCode op, int arg1, int arg2, int result)
// 都是字面量： 5 = 1*5 
{
    this->op = op;
    this->arg1.target = arg1;
    this->arg2.target = arg2;
    this->result.target = result;
    this->flag = 0;
}
// 打印生成的运算符
std::string Quad::printOp()
{
    switch (this->op)
    {
    case OpCode::OP_JUMP:
        return "JUMP";
    case OpCode::OP_JUMP_SMALL:
        return "JUMP_SMALL";
    case OpCode::OP_JUMP_EQ_SMALL:
        return "JUMP_EQ_SMALL";
    case OpCode::OP_JUMP_GREAT:
        return "JUMP_GREAT";
    case OpCode::OP_JUMP_EQ_GREAT:
        return "JUMP_EQ_GREAT";
    case OpCode::OP_JUMP_EQUAL:
        return "JUMP_EQUAL";
    case OpCode::OP_JUMP_NOT_EQUAL:
        return "JUMP_NOT_EQUAL";
    case OpCode::OP_PLUS:
        return "PLUS";
    case OpCode::OP_MINUS:
        return "MINUS";
    case OpCode::OP_TIMES:
        return "TIMES";
    case OpCode::OP_DIV:
        return "DIV";
    case OpCode::OP_MOD:
        return "MOD";
    case OpCode::OP_POWER:
        return "POWER";
    case OpCode::OP_NEGATIVE:
        return "NEGATIVE";
    case OpCode::OP_ASSIGN:
        return "ASSIGN";
    case OpCode::OP_ASSIGN_ARRAY:
        return "ASSIGN_ARRAY";
    case OpCode::OP_ASSIGN_STRUCT:
        return "ASSIGN_STRUCT";
    case OpCode::OP_ASSIGN_POINTER:
        return "ASSIGN_POINTER";
    case OpCode::OP_GET_ADDRESS:
        return "GET_ADDRESS";
    case OpCode::OP_PARAM:
        return "PARAM";
    case OpCode::OP_CALL:
        return "CALL";
    case OpCode::OP_RETURN:
        return "RETURN";
    case OpCode::OP_FUNC_DEF:
        return "FUNC_DEF";
    case OpCode::OP_END_FUNCTION:
        return "END_FUNCTION";
    case OpCode::OP_LABEL:
        return "LABEL";
    case OpCode::OP_GET_VALUE:
        return "GET_VALUE";
    case OpCode::OP_GET_ARRAY:
        return "GET_ARRAY";
    case OpCode::OP_GET_STRUCT:
        return "GET_STRUCT";
    default:
        return "unknown";
    }
}
void Quad::printQuad()
// 打印生成的四元式，使用固定宽度格式确保对齐
{
    // 定义各列的宽度
    const int OP_WIDTH = 15;
    const int ARG_WIDTH = 15;
    const int RESULT_WIDTH = 15;
    
    // 辅助函数：格式化字符串为指定宽度
    auto formatStr = [](const std::string &str, int width) {
        std::ostringstream oss;
        oss << std::left << std::setw(width) << str;
        return oss.str();
    };
    
    std::string opStr = this->printOp();
    std::string arg1Str, arg2Str, resultStr;
    
    switch (this->flag)
    {
    case 0:
    {
        // Quad::Quad(OpCode op, int arg1, int arg2, int result)
        // 都是字面量： 5 = 1*5 
        arg1Str = std::to_string(this->arg1.target);
        arg2Str = std::to_string(this->arg2.target);
        resultStr = std::to_string(this->result.target);
        break;
    }
    case 1:
    {
        // Quad::Quad(OpCode op, symbol *arg1, int arg2, int result)
        // 变量跟字面量运算，值为int
        if (arg1.var == NULL)
            arg1Str = "-";
        else
            arg1Str = this->arg1.var->getIdName();
        
        arg2Str = std::to_string(this->arg2.target);
        resultStr = std::to_string(this->result.target);
        break;
    }
    case 2:
    {
        arg1Str = std::to_string(this->arg1.target);
        
        if (arg2.var == NULL)
            arg2Str = "-";
        else
            arg2Str = this->arg2.var->getIdName();
        
        resultStr = std::to_string(this->result.target);
        break;
    }
    case 3:
    {
        if (arg1.var == NULL)
            arg1Str = "-";
        else
            arg1Str = this->arg1.var->getIdName();
        
        if (arg2.var == NULL)
            arg2Str = "-";
        else
            arg2Str = this->arg2.var->getIdName();
        
        resultStr = std::to_string(this->result.target);
        break;
    }
    case 4:
    {
        arg1Str = std::to_string(this->arg1.target);
        arg2Str = std::to_string(this->arg2.target);
        
        if (result.var == NULL)
            resultStr = "-";
        else
            resultStr = this->result.var->getIdName();
        break;
    }
    case 5:
    {
        if (arg1.var == NULL)
            arg1Str = "-";
        else
            arg1Str = this->arg1.var->getIdName();
        
        arg2Str = std::to_string(this->arg2.target);
        
        if (result.var == NULL)
            resultStr = "-";
        else
            resultStr = this->result.var->getIdName();
        break;
    }
    case 6:
    {
        arg1Str = std::to_string(this->arg1.target);
        
        if (arg2.var == NULL)
            arg2Str = "-";
        else
            arg2Str = this->arg2.var->getIdName();
        
        if (result.var == NULL)
            resultStr = "-";
        else
            resultStr = this->result.var->getIdName();
        break;
    }
    case 7:
    {
        if (arg1.var == NULL)
            arg1Str = "-";
        else
            arg1Str = this->arg1.var->getIdName();
        
        if (arg2.var == NULL)
            arg2Str = "-";
        else
            arg2Str = this->arg2.var->getIdName();
        
        if (result.var == NULL)
            resultStr = "-";
        else
            resultStr = this->result.var->getIdName();
        break;
    }
    default:
        arg1Str = arg2Str = resultStr = "-";
        break;
    }
    
    // 输出格式化的四元式
    std::cout << formatStr(opStr, OP_WIDTH) 
              << formatStr(arg1Str, ARG_WIDTH) 
              << formatStr(arg2Str, ARG_WIDTH) 
              << formatStr(resultStr, RESULT_WIDTH) 
              << std::endl;
}