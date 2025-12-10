#include "LoopASTNode.h"

LoopASTNode::LoopASTNode(char *content,
                         LoopType type,
                         AbstractASTNode *body,
                         AbstractASTNode *condition)
    : AbstractASTNode(content, ASTNodeType::loop)
{
    this->loopType = type;
    this->addChildNode(body);
    if (condition != NULL) condition->setParent(this);
    this->cond = condition;
    this->dec = NULL;
    this->action = NULL;
}

LoopASTNode::LoopASTNode(char *content,
                         LoopType type,
                         AbstractASTNode *body,
                         AbstractASTNode *dec,
                         AbstractASTNode *condition,
                         AbstractASTNode *action)
    : AbstractASTNode(content, ASTNodeType::loop)
{
    this->loopType = type;
    this->addChildNode(body);
    this->cond = condition;
    this->dec = dec;
    this->action = action;
    if (condition != NULL) condition->setParent(this);
    if (dec != NULL) dec->setParent(this);
    if (action != NULL) action->setParent(this);
}

void LoopASTNode::printInfo(int depth)
{
    if (this->loopType == LoopType::_for)
    {
        fprintf(ast_output_file, "RepeatK statement\t\t\twhile");
    }
    else if (this->loopType == LoopType::_while)
    {
        fprintf(ast_output_file, "RepeatK statement\t\t\twhile");
    }
}
