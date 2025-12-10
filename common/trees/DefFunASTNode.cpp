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
    fprintf(ast_output_file, "Function define\t\t\t\tName:%s", this->content.c_str());
}

void DefFunASTNode::setRevType(char* type)
{
    if (strcmp(type, "int") == 0) {
        this->revType = symbolType::integer;
    } else if (strcmp(type, "void") == 0) {
        this->revType = symbolType::Void;
    }
}
