#ifndef BST_H
#define BST_H
#include <iostream>

typedef char TreeEntry;

class BinarySearchTree{
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        bool empty();
        bool full();
        void print();
        void clear();
        bool remove(TreeEntry x);
        bool search(TreeEntry x);
        void insert(TreeEntry x);
        int leaves();
        int nodes();
        int height();
        void preOrdem();
        void emOrdem();
        void posOrdem();
        TreeEntry minimum();
        TreeEntry maximum();
    private:
        struct TreeNode;
        typedef TreeNode* TreePointer;

        struct TreeNode{
            TreeEntry entry;
            TreePointer leftNode, rightNode;
        };

        TreePointer root;

        void print(TreePointer &t, int s);
        void clear(TreePointer &t);
        bool remove(TreeEntry x, TreePointer &p);
        bool Isearch(TreeEntry x);
        void removeMin(TreePointer &q, TreePointer &r);
        int leaves(TreePointer &t);
        int nodes(TreePointer &t);
        int height(TreePointer &t);
        void preOrdem(TreePointer &t);
        void emOrdem(TreePointer &t);
        void posOrdem(TreePointer &t);
        TreeEntry minimum(TreePointer &t);
        TreeEntry maximum(TreePointer &t);
};
#endif