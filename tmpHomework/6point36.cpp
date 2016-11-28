#include <iostream>

using namespace std;
/*
 树的结构
 */
typedef struct tree_node{
    int elem;
    tree_node *leftNode;
    tree_node *rightNode;
}tree_node,*tree;
/*
 判断是否相似
 输入两棵树的头节点
 输出0/1
 */
bool isLike(tree rootA,tree rootB) {
    if (rootA==NULL&&rootB==NULL) {
        return true;
    }
    if (rootA==NULL||rootB==NULL) {
        return false;
    }
    return isLike(rootA->leftNode, rootB->leftNode)&&isLike(rootA->rightNode, rootB->rightNode);
}
/*
 创建节点
 输入节点值
 返回节点
 */
tree_node* create_Tree(int x) {
    tree_node* node=new tree_node;
    node->elem = x;
    node->rightNode=node->leftNode=NULL;
    return node;
}
int main() {
    tree rootA = new tree_node;
    rootA->leftNode=create_Tree(12);
    rootA->rightNode=create_Tree(12);
    rootA->leftNode->leftNode=create_Tree(23);

    tree rootB = new tree_node;
    rootB->leftNode=create_Tree(12);
    rootB->rightNode=create_Tree(12);
    rootB->leftNode->leftNode=create_Tree(23);

    rootA->rightNode->leftNode=create_Tree(23);
    cout << isLike(rootA,rootB);
    return 0;
}
