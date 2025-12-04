#include "ASTNode.h"
#include <typeinfo>

AbstractASTNode::AbstractASTNode()
{
  this->child = NULL;
  this->parent = NULL;
  this->peer = NULL;
  this->content = "Initial stat";
}

AbstractASTNode::AbstractASTNode(ASTNodeType nodeType)
{
  this->child = NULL;
  this->parent = NULL;
  this->peer = NULL;
  this->nodeType = nodeType;
}

AbstractASTNode::AbstractASTNode(char *content, ASTNodeType nodeType)
{
  this->child = NULL;
  this->parent = NULL;
  this->peer = NULL;
  this->content = content;
  this->nodeType = nodeType;
}

void AbstractASTNode::addChildNode(AbstractASTNode *node)
{
  if (node != NULL)
  {
    node->parent = this;
    // 儿子的兄弟也是我的儿子
    AbstractASTNode *peerNode = node->peer;
    // 遍历所有儿子的兄弟，他们的父亲都是我
    while (peerNode != NULL)
    {
      peerNode->parent = this;
      peerNode = peerNode->peer;
    }
  }
  this->child = node;
}

void AbstractASTNode::addPeerNode(AbstractASTNode *node)
{
  if (node != NULL)
    node->parent = this->parent;
  this->peer = node;
}

AbstractASTNode *AbstractASTNode::getLastPeerNode()
{
  AbstractASTNode *t = this;
  while (t->peer != NULL)
  {
    t = t->peer;
  }
  return t;
}

// 全局变量，用于生成节点ID
static int nodeId = 0;

void AbstractASTNode::__printTree(AbstractASTNode *node, int depth)
{
  if (node == NULL)
    return;
  
  // 保存当前节点ID
  int currentId = nodeId++;
  
  // 打印节点基本信息（使用%3d确保ID占3位宽度对齐）
  fprintf(ast_output_file, "%3d : ", currentId);
  node->printInfo(depth);
  
  // 打印子节点信息（使用固定宽度确保对齐）
  fprintf(ast_output_file, "%-12s", "Children: ");
  AbstractASTNode *p = node->child;
  bool firstChild = true;
  while (p != NULL)
  {
    if (!firstChild)
      fprintf(ast_output_file, " ");
    fprintf(ast_output_file, "%3d", nodeId);
    firstChild = false;
    p = p->peer;
  }
  fprintf(ast_output_file, "\n");
  
  // 递归打印所有子节点
  p = node->child;
  while (p != NULL)
  {
    AbstractASTNode::__printTree(p, depth + 1);
    p = p->peer;
  }
}

void AbstractASTNode::printTree()
{
  // 重置节点ID为0
  nodeId = 0;
  AbstractASTNode::__printTree(this, 0);
}

RootASTNode::RootASTNode() : AbstractASTNode(ASTNodeType::root)
{
  this->content = "Root";
}

void RootASTNode::printInfo(int depth)
{
  fprintf(ast_output_file, "%s\n", this->content.c_str());
}
