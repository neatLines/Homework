#include <iostream>
#include <stack>

using namespace std;
/*
 树的结构
 增加nextNode
 */
typedef struct tree_node{
    int elem;
    tree_node *leftNode;
    tree_node *rightNode;
    tree_node *nextNode;
}tree_node,*tree;
/*
 创建树
 */
tree_node* create_Tree(int x) {
    tree_node* node=new tree_node;
    node->elem = x;
    node->rightNode=node->leftNode=node->nextNode=NULL;
    return node;
}

void preOrder(tree root) {    //非递归前序遍历
    stack<tree> s;
    tree p=root;
    tree temp = root;
    while(p!=NULL||!s.empty()) {
        while(p!=NULL) {
            temp->nextNode=p;
            temp=temp->nextNode;
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
    cout << endl;
    while (rootA!=NULL) {
        cout << rootA->elem << " ";
        rootA=rootA->nextNode;
    }
    return 0;
}


