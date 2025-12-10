#include "VarASTNode.h"

VarASTNode::VarASTNode(char *content, AbstractASTNode *value)
    : AbstractASTNode(content, ASTNodeType::assignVar)
{
    this->addChildNode(value);
}

void VarASTNode::printInfo(int depth)
{
    fprintf(ast_output_file, "ID Declaration\t\t\t\tsymbol:%s", this->content.c_str());
}
