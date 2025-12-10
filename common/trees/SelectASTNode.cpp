#include "SelectASTNode.h"

SelectASTNode::SelectASTNode(char *content, SelectType type, AbstractASTNode *body,
                             AbstractASTNode *cond, AbstractASTNode *elseStmt)
    : AbstractASTNode(content, ASTNodeType::select)
{
    this->selectType = type;
    this->body = body;
    this->body->setParent(this);
    this->condition = cond;
    this->condition->setParent(this);
    this->elseStmt = elseStmt;
    if (elseStmt) {
        this->elseStmt->setParent(this);
    }
}

void SelectASTNode::printInfo(int depth)
{
    if (this->selectType == SelectType::_if)
    {
        fprintf(ast_output_file, "IF statement\t\t\t");
    }
}
