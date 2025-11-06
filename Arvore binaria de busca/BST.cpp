#include "BST.h"
#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;

BinarySearchTree::BinarySearchTree(){
    root = NULL;
}

BinarySearchTree::~BinarySearchTree(){
    clear(root);
}

bool BinarySearchTree::empty(){
    return root == NULL;
}

bool BinarySearchTree::full(){
    return false;
}

void BinarySearchTree::clear(){
    return clear(root);
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
    return print(root, 0); //inicia o print pela raiz 
}

void BinarySearchTree::print(TreePointer &t, int s){
    int i;
    if(t != NULL){ //evita acessar ponteiros nulos
        print(t->rightNode, s+3); //imprime a sub arv direita e faz ela ficar "em cima"
                            //s+3 espaçamento adicional a cada chamada recursiva cada nível da árvore afasta o nó 3 espaços para a direita
                            // s seria a profundida(distancia do nó ate a raiz), controla quantos espaços antes de imprimir 
        for(i = 1; i <= s; i++){ //add espaços para alinhar, controla a profundidade
            cout << " ";
        }
        cout << setw(6) << t->entry << endl; //imprime o valor do nó, mostra o valor já formatado
                //setw largura mínima do número impresso, mantém a formatação alinhada e legível

        print(t->leftNode, s+3); //imprime a sub arv esquerda e faz aparecer "em baixo" 
    }
}

int BinarySearchTree::nodes(){
    return nodes(root);
}

int BinarySearchTree::nodes(TreePointer &t){
    if(t == NULL) return 0;
    return 1 + nodes(t->leftNode) + nodes(t->rightNode);
}

int BinarySearchTree::leaves(){
    return leaves(root);
}

int BinarySearchTree::leaves(TreePointer &t){
    if(t == NULL) return 0;
    if(t->leftNode == NULL && t->rightNode == NULL) //condição para nó ser folha
        return 1;
    return leaves(t->leftNode) + leaves(t->rightNode); //função para somar as folhas da sub arv esquerda+ sub arv direita e retornar ao usuario a qtd
}

int BinarySearchTree::height(){
    return height(root);
}

int BinarySearchTree::height(TreePointer &t){
    if(t == NULL) return -1; //-1 pq: padrão em várias implementações porque uma folha (sem filhos) vai então ter altura 0:max(-1, -1) + 1 = 0

    int L,R;
    L = height(t->leftNode);
    R = height(t->rightNode);
    if(L > R){
        return L + 1; // O +1 serve para contar o nível do nó atual na recursão.
    }else{ //R > L
        return R + 1;
    }
}

void BinarySearchTree::preOrdem(){
    return preOrdem(root);
}

void BinarySearchTree::preOrdem(TreePointer &t){
    if(t == NULL) return;
    cout << t->entry << " "; //1°visita raiz
    preOrdem(t->leftNode); //2°visita sub arv esquerda
    preOrdem(t->rightNode); //3°visita sub arv direita
}

void BinarySearchTree::emOrdem(){
    return emOrdem(root);
}

void BinarySearchTree::emOrdem(TreePointer &t){
    if(t == NULL) return;
    preOrdem(t->leftNode); //1° Visita sub arv esquerda
    cout << t->entry << " ";//2° visita raiz
    preOrdem(t->rightNode); //3° visita sub arv direita
}

void BinarySearchTree::posOrdem(){
    return posOrdem(root);
}

void BinarySearchTree::posOrdem(TreePointer &t){
    if(t == NULL) return;
    preOrdem(t->leftNode); //1° Visita sub arv esquerda
    preOrdem(t->rightNode); //2° visita sub arv direita
    cout << t->entry << " ";//3° visita raiz
}

void BinarySearchTree::insert(TreeEntry x){
    TreePointer p,q,r;
    // q percorre a árvore durante a busca.
    // p guarda o nó anterior a q (ou seja, o pai de q).
    // r será o novo nó que vai ser inserido.

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
    // alocação e inicialização de um novo bó
    r = new TreeNode;
    if(r == NULL){
        cout << "sem memoria" << endl;
        abort();
    }
    r->entry = x; // r recebe o valor que ira ser inserido
    r->leftNode = r->rightNode = NULL; //começa como NULL pois o novo nó é uma folha 
    //inserção do nó há arvore 
    if(p == NULL){
        root = r;
    }else{
        if(x < p->entry){
            p->leftNode = r;
        }else{ //x >p->entry
            p->rightNode = r;
        }
    }
}

TreeEntry BinarySearchTree::minimum(){
    if(root == NULL){
        cout << "arvore vazia" << endl;
        return INT_MIN; // outra forma para não usar o abort e fechar abruptamente o programa
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
        cout << "arvore vazia" << endl;
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
    t = root; // pointeiro auxiliar para começar na raiz
    while(t != NULL && t->entry != x){ //enquanto o nó não for nulo e o valor de x não for encontrado
        if(x < t->entry){
            t = t->leftNode;
        }else{
            t = t->rightNode;
        }
    }//sai do laço while quando encontra o valor (t->entry == x) ou chega em NULL

    return t != NULL; //retorna true = achou ou false = não achou
}

bool BinarySearchTree::remove(TreeEntry x){
    return remove(x, root);
}

bool BinarySearchTree::remove(TreeEntry x, TreePointer &p){
    if(p == NULL) {
        return false;
    }
    //x < do que p->entry -> tentar a remoção na subarvore esquerda
    if(x < p->entry){
        remove(x, p->leftNode);
    }
    //x > do que p->entry -> tentar a remoção na subarvore direita
    if(x > p->entry){
        remove(x, p->rightNode);
    }else{
        //achei! prosseguir com a remoção!
        TreePointer q; // valor a ser removido é guardado em q
        q = p;
        // P Ponteiro que representa a ligação do pai com o nó atual. Ele permite modificar diretamente os ponteiros 
        //da árvore original. É uma referência para o ponteiro que aponta para a raiz da subárvore atual.
        if(q->leftNode == NULL){//caso A
            p = q->rightNode;
        }else{
            if(q->rightNode == NULL){//caso B
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
    if(r->leftNode != NULL) // Detecta o nó mínimo
        removeMin(q, r->leftNode);// Faz a chamada recursiva para a esquerda.Serve para retornar o controle após atingir o nó mínimo
    else{
        q->entry = r->entry;// copia o valor do menor nó para q
        q = r; // q agora aponta para o nó mínimo
        r = r->rightNode; // substitui r pelo filho direito (se existir)
    }
}