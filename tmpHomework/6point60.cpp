#include <iostream>
typedef struct tree_node{
    int elem;
    tree_node *brother;
    tree_node *child;
}tree_node,*tree;
/*
 创建节点
 */
tree_node* createNode(int elem) {
    tree_node *node = new tree_node;
    node->elem=elem;
    node->brother = nullptr;
    node->child = nullptr;
    return node;
}
/*
 创建树
 */
tree newATree() {
    tree root = createNode(1);
    root->child = createNode(3);
    root->child->brother = createNode(4);
    root->child->child = createNode(5);
    root->child->brother->brother = createNode(6);
    root->child->brother->child = createNode(12);
    root->child->brother->child->brother = createNode(14);

    return root;
}
/*
 得到树的结果
 */
int getNumberOfLeaf(tree root) {
    if (root == nullptr) {
        return 1;
    }
    int count = getNumberOfLeaf(root->child);
    if (root->brother != nullptr) {
        count += getNumberOfLeaf(root->brother);
    }
    return count;
}

int main() {
    std::cout << getNumberOfLeaf(newATree()) << std::endl;
    return 0;
}
