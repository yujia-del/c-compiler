#include "StmtASTNode.h"

StmtASTNode::StmtASTNode(StmtType type) : AbstractASTNode(ASTNodeType::stmt) {
    this->type = type;
}

void StmtASTNode::printInfo(int depth) {
    if (this->type == StmtType::compStmt) {
        fprintf(ast_output_file, "CompoundK statement\n");
    }
    else if (this->type == StmtType::defStmt) {
        fprintf(ast_output_file, "Var Declaration\n");
    }
    else if (this->type == StmtType::expStmt) {
        fprintf(ast_output_file, "Exp Stmt\n");
    }
    else if (this->type == StmtType::returnStmt) {
        fprintf(ast_output_file, "Return Stmt\n");
    }
}
