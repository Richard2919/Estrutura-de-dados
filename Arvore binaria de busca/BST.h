#include <string>
#ifndef BST_H
#define BST_H

typedef char TreeEntry;

class BinarySearchTree{
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        bool empty();
        bool full();
        void print();
        int height();
        void insert(TreeEntry x);
        int nodes();
        int leaves();
        void preOrdem();
        void emOrdem();
        void posOrdem();
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

        void clear(TreePointer &t);
        void print(TreePointer &t, int s);
        int height(TreePointer &t);
        int nodes(TreePointer &t);
        int leaves(TreePointer &t);
        void preOrdem(TreePointer &t);
        void emOrdem(TreePointer &t);
        void posOrdem(TreePointer &t);
        TreeEntry minimum(TreePointer &t);
        TreeEntry maximum(TreePointer &t);
        bool Isearch(TreeEntry x);
        bool remove(TreeEntry x, TreePointer &p);
        void removeMin(TreePointer &q, TreePointer &r);
};

#endif