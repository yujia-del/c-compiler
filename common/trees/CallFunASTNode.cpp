#include "CallFunASTNode.h"
#include "VarASTNode.h"
CallFunASTNode::CallFunASTNode(char *content, AbstractASTNode *varList)
    : AbstractASTNode(content, ASTNodeType::callFunc)
{
    this->varList = varList;
    if (varList != NULL) {
        varList->setParent(this);
    }
}

void CallFunASTNode::printInfo(int depth) {
    fprintf(ast_output_file, "WriteK statement\n");
    // AbstractASTNode *var = this->varList;
    // while (var != NULL) {
    //     AbstractASTNode::__printTree(var, depth + 1);
    //     var = var->getPeer();
    // }
}
