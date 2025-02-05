#include <bits/stdc++.h>
#include "TQueue.h"
using namespace std;

class Tree
{
private:
    Node *root;
public:
    Tree(){root=NULL;};
    void CreateTree();
    void Preorder(Node *p);
    void Preorder(){Preorder(root);};
    void Inorder(Node *p);
    void Inorder(){Inorder(root);};
    void Postorder(Node *p);
    void Postorder(){Postorder(root);};
    void Levelorder(Node *p);
    void Levelorder(){Levelorder(root);};
};

void Tree::CreateTree()
{
    Node *p, *t;
    int x;
    Queue q(100);

    cout << "Enter root value: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.Enqueue(root);

    while(!q.isEmpty()){
        p = q.Dequeue();
        cout << "Enter left child for " << p->data << " ";
        cin >> x;
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.Enqueue(t);
        }
        cout << "Enter right child for " << p->data << " ";
        cin >> x;
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.Enqueue(t);
        }
    }
}

void Tree::Preorder(Node *p){
    if(p){
        cout << p->data << endl;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Tree::Inorder(Node *p){
    if(p){
        Inorder(p->lchild);
        cout << p->data << endl;
        Inorder(p->rchild);
    }
}
void Tree::Postorder(Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << endl;
    }
}

void Tree::Levelorder(Node *p){
    Queue q(100);
    cout << p->data << " ";
    q.Enqueue(p);
    while(!q.isEmpty()){
        p=q.Dequeue();
        if(p->lchild){
            cout << p->lchild->data << " ";
            q.Enqueue(p->lchild);
        }
        if(p->rchild){
            cout << p->rchild->data << " ";
            q.Enqueue(p->rchild);
        }
    }
}


int main(){
    Tree T;
    T.CreateTree();
    T.Preorder();
    T.Levelorder();

    return 0;
}