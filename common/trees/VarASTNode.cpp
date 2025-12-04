#include "VarASTNode.h"

VarASTNode::VarASTNode(char *content, AbstractASTNode *value)
    : AbstractASTNode(content, ASTNodeType::assignVar)
{
    this->addChildNode(value);
}

void VarASTNode::printInfo(int depth)
{
    std::cout << "ID Declaration, symbol:" << this->content << ", ";
}
