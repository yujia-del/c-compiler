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

AbstractASTNode::~AbstractASTNode() {
  // 清理子节点（如果需要）
  // 这里简化处理，实际可能需要递归清理所有子节点和兄弟节点
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
int AbstractASTNode::nodeId = 0;

// 第一次遍历：为所有节点分配ID
void AbstractASTNode::__assignIds(AbstractASTNode *node, std::map<AbstractASTNode*, int> &nodeMap)
{
  if (node == NULL)
    return;
  
  // 分配ID并存储映射关系
  nodeMap[node] = nodeId++;
  
  // 递归处理子节点
  AbstractASTNode *p = node->child;
  while (p != NULL)
  {
    AbstractASTNode::__assignIds(p, nodeMap);
    p = p->peer;
  }
}

// 第二次遍历：打印所有节点信息
void AbstractASTNode::__printNodes(AbstractASTNode *node, const std::map<AbstractASTNode*, int> &nodeMap, int depth)
{
  if (node == NULL)
    return;
  
  // 获取当前节点ID
  int currentId = nodeMap.at(node);
  
  // 打印节点基本信息
  fprintf(ast_output_file, "%d : ", currentId);
  
  // 调用printInfo方法输出节点类型和内容
  node->printInfo(depth);
  
  // 打印子节点信息
  fprintf(ast_output_file, "\t\tChildren: ");
  
  AbstractASTNode *p = node->child;
  bool firstChild = true;
  while (p != NULL)
  {
    if (!firstChild)
      fprintf(ast_output_file, " ");
    fprintf(ast_output_file, "%d", nodeMap.at(p));
    firstChild = false;
    p = p->peer;
  }
  fprintf(ast_output_file, "\n");
  
  // 递归打印所有子节点
  p = node->child;
  while (p != NULL)
  {
    AbstractASTNode::__printNodes(p, nodeMap, depth + 1);
    p = p->peer;
  }
}

// 主打印方法
void AbstractASTNode::__printTree(AbstractASTNode *node, int depth)
{
  if (node == NULL)
    return;
  
  // 重置nodeId
  nodeId = 0;
  
  // 创建节点到ID的映射
  std::map<AbstractASTNode*, int> nodeMap;
  
  // 第一次遍历：分配ID
  AbstractASTNode::__assignIds(node, nodeMap);
  
  // 重置nodeId用于第二次遍历
  nodeId = 0;
  
  // 第二次遍历：打印节点信息
  AbstractASTNode::__printNodes(node, nodeMap, depth);
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
