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
        void clear();
        void print();
        int nodes();
        int height();
        int leaves();
        TreeEntry minimum();
        TreeEntry maximum();
        bool search(TreeEntry x);
        void insert(TreeEntry x);
        bool remove(TreeEntry x);
        void preOrdem();
        void emOrdem();
        void posOrdem();
    private:
        struct TreeNode;
        typedef TreeNode* TreePointer;

        struct TreeNode{
            TreeEntry entry;
            TreePointer leftNode, rightNode;
        };

        TreePointer root;

        void clear(TreePointer &t);
        void print(TreePointer &t, int s);
        int nodes(TreePointer &t);
        int height(TreePointer &t);
        int leaves(TreePointer &t);
        TreeEntry minimum(TreePointer &t);
        TreeEntry maximum(TreePointer &t);
        bool Isearch(TreeEntry x);
        bool remove(TreeEntry x, TreePointer &p);
        void removeMin(TreePointer &q, TreePointer &r);
        void preOrdem(TreePointer &t);
        void emOrdem(TreePointer &t);
        void posOrdem(TreePointer &t);
};
#endif