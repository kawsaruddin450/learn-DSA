#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class BST{
private:
    Node *root;
public:
    BST(){root=nullptr;};
    Node *getRoot(){
        return root;
    };
    void Insert(int x);
    void Inorder(){Inorder(root);};
    void Inorder(Node *p);
};

void BST::Insert(int x){
    Node *t = root;
    Node *p, *r;

    //if tree is empty
    if(root==nullptr){
        p = new Node;
        p->data = x;
        p->lchild = p->rchild = nullptr;
        root = p;
        return;
    }

    while(t!=nullptr){
        r=t;
        if(x < t->data){
            t=t->lchild;
        }
        else if(x > t->data){
            t=t->rchild;
        }
        else{
            return;
        }
    }

    p = new Node;
    p->data = x;
    p->lchild = p->rchild = nullptr;

    if(x < r->data){
        r->lchild = p;
    }else{
        r->rchild = p;
    }
}

void BST::Inorder(Node *p){
    if(p){
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

int main(){
    BST b;
    int A[] = {23, 56, 11, 98, 34, 10, 7};
    for(int i=0; i<7; i++){
        b.Insert(A[i]);
    }
    b.Inorder();

    return 0;
}