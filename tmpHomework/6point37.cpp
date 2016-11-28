#include <iostream>
#include <stack>

using namespace std;

/*
 节点结构
 */
typedef struct tree_node{
    int elem;
    tree_node *leftNode;
    tree_node *rightNode;
}tree_node,*tree;
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

void preOrder(tree root)     //非递归前序遍历
{
    stack<tree> s;
    tree p=root;
    while(p!=NULL||!s.empty()) {
        while(p!=NULL) {
            cout<<p->elem<<" ";
            s.push(p);
            p=p->leftNode;
        }
        if(!s.empty()) {
            p=s.top();
            s.pop();
            p=p->rightNode;
        }
    }
}

int main() {
    tree rootA = create_Tree(1);
    rootA->leftNode=create_Tree(2);
    rootA->rightNode=create_Tree(3);
    rootA->leftNode->leftNode=create_Tree(4);
    rootA->rightNode->leftNode=create_Tree(5);
    preOrder(rootA);
    return 0;
}
