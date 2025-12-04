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
            std::cout << "Var Declaration, ";
        } else {
            // 否则，这可能是一个类型说明符
            if (type == symbolType::integer)
                std::cout << "Type Specifier, int, ";
            else if (type == symbolType::pointer)
                std::cout << "Type Specifier, pointer, ";
            else if (type == symbolType::Array)
                std::cout << "Type Specifier, array, ";
            else if (type == symbolType::Struct)
                std::cout << "Type Specifier, struct " << this->structType << ", ";
        }
    } else {
        // 否则，这是一个简单的变量声明
        std::cout << "ID Declaration, symbol:" << this->content << ", ";
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
