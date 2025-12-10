#include "StmtASTNode.h"

StmtASTNode::StmtASTNode(StmtType type) : AbstractASTNode(ASTNodeType::stmt) {
    this->type = type;
}

void StmtASTNode::printInfo(int depth) {
    if (this->type == StmtType::compStmt) {
        fprintf(ast_output_file, "CompoundK statement\t\t\t");
    }
    else if (this->type == StmtType::defStmt) {
        fprintf(ast_output_file, "Var Declaration\t\t\t");
    }
    else if (this->type == StmtType::expStmt) {
        fprintf(ast_output_file, "Exp Stmt\t\t\t\t");
    }
    else if (this->type == StmtType::returnStmt) {
        fprintf(ast_output_file, "Return Stmt\t\t\t\t");
    }
    // 添加Write语句的支持
    else if (this->type == StmtType::writeStmt) {
        fprintf(ast_output_file, "WriteK statement\t\t\t");
    }
    // 添加Repeat语句的支持
    else if (this->type == StmtType::whileStmt) {
        fprintf(ast_output_file, "RepeatK statement\t\t\t");
    }
}
