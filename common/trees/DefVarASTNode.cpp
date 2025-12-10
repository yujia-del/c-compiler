#include "DefVarASTNode.h"
#include <cstring>
DefVarASTNode::DefVarASTNode(char *content, AbstractASTNode *value)
    : AbstractASTNode(content, ASTNodeType::defVar)
{
    this->type = symbolType::unset;
    this->addChildNode(value);
}
DefVarASTNode::DefVarASTNode(char* structTypeName, char* structIdName)
    : AbstractASTNode(structIdName, ASTNodeType::defVar)
{
    this->type = symbolType::Struct;
    this->structType = structTypeName;
}

void DefVarASTNode::printInfo(int depth)
{
    // 如果有父节点，且父节点是根节点或语句节点，那么这是一个变量声明
    AbstractASTNode *parent = this->getParent();
    if (parent != NULL && (parent->getNodeType() == ASTNodeType::root || 
                          parent->getNodeType() == ASTNodeType::stmt ||
                          parent->getNodeType() == ASTNodeType::defFunc)) {
        // 检查是否有类型子节点
        AbstractASTNode *child = this->getChild();
        if (child != NULL && child->getNodeType() == ASTNodeType::op) {
            // 如果子节点是运算符节点，那么这是一个变量声明语句
            fprintf(ast_output_file, "Var Declaration\t\t\t");
        } else {
            // 否则，这可能是一个类型说明符
            if (type == symbolType::integer)
                fprintf(ast_output_file, "Type Specifier\t\t\t\tint");
            else if (type == symbolType::pointer)
                fprintf(ast_output_file, "Type Specifier\t\t\t\tpointer");
            else if (type == symbolType::Array)
                fprintf(ast_output_file, "Type Specifier\t\t\t\tarray");
            else if (type == symbolType::Struct)
                fprintf(ast_output_file, "Type Specifier\t\t\t\tstruct %s", this->structType.c_str());
        }
    } else {
        // 否则，这是一个简单的变量声明
        fprintf(ast_output_file, "ID Declaration\t\t\t\tsymbol:%s", this->content.c_str());
    }
}

void DefVarASTNode::setAllType(char *type)
{
    symbolType varType;
    if (strcmp(type, "int") == 0)
    {
        varType = symbolType::integer;
    }
    else if (strcmp(type, "void") == 0)
    {
        varType = symbolType::Void;
    }
    else if (strcmp(type, "integer pointer") == 0)
    {
        varType = symbolType::pointer;
    }
    else if (strcmp(type, "struct") == 0)
    {
        varType = symbolType::Struct;
    }
    else if (strcmp(type, "array") == 0) {
        varType = symbolType::Array;
    }
    if (this->type == symbolType::unset) {
        this->type = varType;
    }
    DefVarASTNode *peer = (DefVarASTNode *)this->getPeer();
    while (peer != NULL)
    {
        if (peer->type == symbolType::unset) {
            peer->type = varType;
        }
        peer = (DefVarASTNode *)peer->getPeer();
    }
}

void DefVarASTNode::setArrayLength(char *length) {
    this->arrayLength = atoi(length);
}
