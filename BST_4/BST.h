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
        int leaves();
        int height();
        int nodes();
        void print();
        void clear();
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

        int leaves(TreePointer &t);
        int height(TreePointer &t);
        int nodes(TreePointer &t);
        void print(TreePointer &t, int s);
        void clear(TreePointer &t);
        TreeEntry minimum(TreePointer &t);
        TreeEntry maximum(TreePointer &t);
        void preOrdem(TreePointer &t);
        void emOrdem(TreePointer &t);
        void posOrdem(TreePointer &t);
        bool Isearch(TreeEntry x);
        bool remove(TreeEntry x, TreePointer &p);
        void removeMin(TreePointer &q, TreePointer &r);
        
};
#endif

