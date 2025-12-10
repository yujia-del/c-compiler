#include "OperatorASTNode.h"

OperatorASTNode::OperatorASTNode(char *content, opType type)
    : AbstractASTNode(content, ASTNodeType::op)
{
    this->type = type;
}

void OperatorASTNode::printInfo(int depth)
{
    fprintf(ast_output_file, "Expr\t\t\t\t\top:%s", this->content.c_str());
}
