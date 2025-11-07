#include <iostream>
#include <iomanip>
#include <climits>
#include "BST.h"

using namespace std;

BinarySearchTree::BinarySearchTree(){
    root = NULL;
}

BinarySearchTree::~BinarySearchTree(){
    clear();
}

bool BinarySearchTree::empty(){
    return root == NULL;
}

bool BinarySearchTree::full(){
    return false;
}

void BinarySearchTree::clear(){
    clear(root);
    root = NULL;
}

void BinarySearchTree::clear(TreePointer &t){
    if(t != NULL){
        clear(t->leftNode);
        clear(t->rightNode);
        delete t;
    }
}

void BinarySearchTree::print(){
    print(root, 0);
}

void BinarySearchTree::print(TreePointer &t, int s){
    int i;
    if(t != NULL){
        print(t->rightNode, s+3);
        for(i = 1; i <= s; i++){
            cout << " ";
        }
        cout << setw(6) << t->entry;
        print(t->leftNode, s+3);
    }
}

int BinarySearchTree::nodes(){
    return nodes(root);
}

int BinarySearchTree::nodes(TreePointer &t){
    if(t == NULL){
        return 0;
    }
    return 1 + nodes(t->leftNode) + nodes(t->rightNode);
}

int BinarySearchTree::height(){
    return height(root);
}

int BinarySearchTree::height(TreePointer &t){
    if(t == NULL){
        return -1;
    }
    int L,R;

    L = height(t->leftNode);
    R = height(t->rightNode);

    if(L > R){
        return L + 1;
    }else{
        return R + 1;
    }
}

int BinarySearchTree::leaves(){
    return leaves(root);
}

int BinarySearchTree::leaves(TreePointer &t){
    if(t == NULL){
        return 0;
    }
    if(t->leftNode && t->rightNode == NULL){
        return 1;
    }
    return leaves(t->leftNode) + leaves(t->rightNode);
}

void BinarySearchTree::preOrdem(){
    return preOrdem(root);
}

void BinarySearchTree::preOrdem(TreePointer &t){
    if(t == NULL){
        return;
    }
    cout << t->entry << " ";
    preOrdem(t->leftNode);
    preOrdem(t->rightNode);
}

void BinarySearchTree::emOrdem(){
    return emOrdem(root);
}

void BinarySearchTree::emOrdem(TreePointer &t){
    if(t == NULL){
        return;
    }
    emOrdem(t->leftNode);
    cout << t->entry << " ";
    emOrdem(t->rightNode);
}

void BinarySearchTree::posOrdem(){
    return posOrdem(root);
}

void BinarySearchTree::posOrdem(TreePointer &t){
    if(t == NULL){
        return;
    }
    posOrdem(t->leftNode);
    posOrdem(t->rightNode);
    cout << t->entry << " ";
}

void BinarySearchTree::insert(TreeEntry x){
    TreePointer p,q,r;

    q = root;
    p = NULL;

    while(q != NULL){
        p = q;
        if(x < q->entry){
            q = q->leftNode;
        }else{
            q = q->rightNode;
        }
    }
    r = new TreeNode;
    if(r == NULL){
        cout << "sem memoria" << endl;
        abort();
    }
    r->entry = x;
    r->leftNode = r->rightNode = NULL;

    if(p == NULL){
        root = r;
    }else{
        if(x < p->entry){
             p->leftNode = r;
        }else{
            p->rightNode = r;
        }
    }
}

TreeEntry BinarySearchTree::minimum(){
    if(root == NULL){
        cout << "Arvore vazia" << endl;
        return INT_MIN;
    }
    return minimum(root);
}

TreeEntry BinarySearchTree::minimum(TreePointer &t){
    while(t->leftNode != NULL){
        t = t->leftNode;
    }
    return t->entry;
}

TreeEntry BinarySearchTree::maximum(){
    if(root == NULL){
        cout << "arvore vazia"<< endl;
        return INT_MAX;
    }
    return maximum(root);
}

TreeEntry BinarySearchTree::maximum(TreePointer &t){
    while(t->rightNode != NULL){
        t = t->rightNode;
    }
    return t->entry;
}

bool BinarySearchTree::search(TreeEntry x){
    return Isearch(x);
}

bool BinarySearchTree::Isearch(TreeEntry x){
    TreePointer t;
    t = root;
    while(t != NULL && t->entry != x){
        if(x < t->entry){
            t = t->leftNode;
        }else{
            t = t->rightNode;
        }
    }
    return t != NULL;
}

bool BinarySearchTree::remove(TreeEntry x){
    return remove(x, root);
}

bool BinarySearchTree::remove(TreeEntry x, TreePointer &p){
    if(p == NULL){
        return false;
    }
    if(x < p->entry){
        remove(x, p->leftNode);
    }
    else if(x > p->entry){
        remove(x, p->rightNode);
    }else{
        TreePointer q;
        q = p;
        if(q->leftNode == NULL){
            p = q->rightNode;
        }else{
            if(q->rightNode == NULL){
                p = q->leftNode;
            }else{
                removeMin(q, q->rightNode);
            }
        }
        delete q; 
        return true;
    }
}

void BinarySearchTree::removeMin(TreePointer &q, TreePointer &r){
    if(r->leftNode == NULL){
        removeMin(q, r->leftNode);
    }else{
        q->entry = r->entry;
        q = r;
        r = r->rightNode;
    }
}