#include "LiteralASTNode.h"

LiteralASTNode::LiteralASTNode(char *content) : AbstractASTNode(content, ASTNodeType::literal)
{
}

void LiteralASTNode::printInfo(int depth)
{
    std::cout << "Const Declaration, " << this->getValue() << ", ";
}

int LiteralASTNode::getValue()
{
    return std::stoi(this->content);
}
