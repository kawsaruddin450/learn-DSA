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
    Node *Search(int key);
    int Height(){Height(root);};
    int Height(Node *p);
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

Node* BST::Search(int key){
    Node *t = root;
    while(t!=nullptr){
        if(key == t->data){
            return t;
        }else if(key < t->data){
            t = t->lchild;
        }else{
            t = t->rchild;
        }
    }
    return nullptr;
}

int BST::Height(Node *p){
    int x, y;
    if(p==nullptr){
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x+1 : y+1;
}

int main(){
    BST b;
    int A[] = {23, 56, 11};
    for(int i=0; i<3; i++){
        b.Insert(A[i]);
    }
    b.Inorder();
    Node* temp = b.Search(10);
    if(temp) cout << temp->data << endl;
    else cout << "Item not found." << endl;
    cout << b.Height() << endl;

    return 0;
}