#include "LiteralASTNode.h"

LiteralASTNode::LiteralASTNode(char *content) : AbstractASTNode(content, ASTNodeType::literal)
{
}

void LiteralASTNode::printInfo(int depth)
{
    fprintf(ast_output_file, "Const Declaration\t\t\t	%d", this->getValue());
}

int LiteralASTNode::getValue()
{
    return std::stoi(this->content);
}
