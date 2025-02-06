#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class BST
{
private:
    Node *root;

public:
    BST() { root = nullptr; };
    Node *getRoot()
    {
        return root;
    };
    void Insert(int x);
    void Inorder() { Inorder(root); };
    void Inorder(Node *p);
    Node *Search(int key);
    int Height() { Height(root); };
    int Height(Node *p);
    Node *InPre(Node *p);
    Node *InSucc(Node *p);
    Node *Delete(int key) { Delete(root, key); };
    Node *Delete(Node *p, int key);
};

void BST::Insert(int x)
{
    Node *t = root;
    Node *p, *r;

    // if tree is empty
    if (root == nullptr)
    {
        p = new Node;
        p->data = x;
        p->lchild = p->rchild = nullptr;
        root = p;
        return;
    }

    while (t != nullptr)
    {
        r = t;
        if (x < t->data)
        {
            t = t->lchild;
        }
        else if (x > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return;
        }
    }

    p = new Node;
    p->data = x;
    p->lchild = p->rchild = nullptr;

    if (x < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

void BST::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

Node *BST::Search(int key)
{
    Node *t = root;
    while (t != nullptr)
    {
        if (key == t->data)
        {
            return t;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    return nullptr;
}

int BST::Height(Node *p)
{
    int x, y;
    if (p == nullptr)
    {
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

Node *BST::InPre(Node *p)
{
    while (p && p->rchild != nullptr)
    {
        p = p->rchild;
    }
    return p;
}
Node *BST::InSucc(Node *p)
{
    while (p && p->lchild != nullptr)
    {
        p = p->lchild;
    }
    return p;
}

Node *BST::Delete(Node *p, int key)
{
    Node *q;
    if(p==nullptr){
        return nullptr;
    }
    if(p->lchild == NULL && p->rchild == NULL){
        if(p==root)
            root = nullptr;
        delete p;
        return nullptr;
    }
    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

int main()
{
    BST b;
    int A[] = {23, 56, 11, 10, 61, 90, 78};
    for (int i = 0; i < 7; i++)
    {
        b.Insert(A[i]);
    }
    b.Delete(61);
    b.Inorder();

    return 0;
}