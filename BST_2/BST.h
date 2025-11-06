#include <iostream>
#ifndef BST_H
#define BST_H

typedef char TreeEntry;

class BinarySearchTree{
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        bool empty();
        bool full();
        int leaves();
        int nodes();
        int height();
        void print();
        void preOrdem(); //processa raiz, esquerda e direita
        void emOrdem(); //processa esquerda, raiz e direita
        void posOrdem();// processa esquerda, direita e raiz
        void insert(TreeEntry x);
        void clear();
        TreeEntry minimum();
        TreeEntry maximum();
        bool search(TreeEntry x);
        bool remove(TreeEntry x);
    private:
        struct TreeNode;
        typedef TreeNode* TreePointer;

        struct TreeNode{
            TreeEntry entry;
            TreePointer leftNode, rightNode;
        };

        TreePointer root;

        int leaves(TreePointer &t);
        int nodes(TreePointer &t);
        int height(TreePointer &t);
        void preOrdem(TreePointer &t);
        void emOrdem(TreePointer &t);
        void posOrdem(TreePointer &t);
        void print(TreePointer &t, int s);
        void clear(TreePointer &t);
        TreeEntry minimum(TreePointer &t);
        TreeEntry maximum(TreePointer &t);
        bool Isearch(TreeEntry x);
        bool remove(TreeEntry x, TreePointer &p);
        void removeMin(TreePointer &q, TreePointer &r);


};

#endif