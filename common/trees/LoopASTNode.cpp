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
        fprintf(ast_output_file, "RepeatK statement\n");
        // std::cout << "DEC:::::";

        AbstractASTNode::__printTree(this->dec, depth + 1);
        // std::cout << "COND:::::";

        AbstractASTNode::__printTree(this->cond, depth + 1);
        // std::cout << "ACTION:::::";

        AbstractASTNode::__printTree(this->action, depth + 1);
    }
    else
    {
        fprintf(ast_output_file, "RepeatK statement\n");
        // AbstractASTNode::__printTree(this->cond, depth + 1);
    }
}
