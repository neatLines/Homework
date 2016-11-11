#include <iostream>

using namespace std;
typedef struct tree_node{
    int elem;
    tree_node *leftNode;
    tree_node *rightNode;
}tree_node,*tree;

bool isLike(tree rootA,tree rootB) {
    if (rootA==NULL&&rootB==NULL) {
        return true;
    }
    if (rootA==NULL||rootB==NULL) {
        return false;
    }
    return isLike(rootA->leftNode, rootB->leftNode)&&isLike(rootA->rightNode, rootB->rightNode);
}
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