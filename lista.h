#include <iostream>

using std::cout;
using std::cin;

typedef struct tNode{
    int val;
    struct tNode *prox;
}Node;

class Lista{
private:
    Node *inicio;
public:

    Lista(){
        inicio = NULL;
    }
    //Destrutor
    ~Lista(){
        while(!(vazia()))
            removePop();
    }

    int vazia(){
        return inicio==NULL;
    }

    void inserir(int valor){
        Node *nova = new Node;
        nova->val = valor;
        nova->prox = NULL;
        if(inicio == NULL) inicio = nova;
        else{
            Node *aux = inicio;
            while(aux->prox != NULL)
                aux = aux->prox;
            aux->prox = nova;
        }
    }

    //O metodo abaixo serve para o buckteSort
    void inserirOrdenado(int val){
        Node *nova = new Node;
        nova->val = val;
        nova->prox = NULL;
        if(vazia()){
            inicio = nova;
        }else if(inicio->val>=val){
            nova->prox = inicio;
            inicio = nova;
        }else{
            Node *aux = inicio;
            while(aux->prox!=NULL && aux->prox->val<val)
                aux = aux->prox;
            if(!(aux->prox!=NULL))
                aux->prox = nova;
            else{
                nova->prox = aux->prox;
                aux->prox = nova;
            }
        }
    }

    void listar(){
        if(vazia()) cout<<"vazia!\n";
        else{
            Node *aux = inicio;
            while(aux!=NULL){
                cout<<aux->val<<" ";
                aux = aux->prox;
            }
            cout<<"\n";
        }
    }
    //Remove o 1°
    void removePop(){
        Node *aux = inicio;
        inicio = inicio->prox;
        delete aux;
    }

    void removeUltimo(){
        Node *aux = inicio;
        while(aux->prox->prox!=NULL)
            aux=aux->prox;
            aux->prox = NULL;
    }

    void removeN(int n){
        int i;
        Node *aux = inicio;
        Node *temp;
        if(n==0) removePop();
        else{
            for(i=1;aux->prox!=NULL && i<n; i++)
                aux = aux->prox;
            temp = aux->prox;
            aux->prox = aux->prox->prox;
            delete temp;
        }
    }
    
    void inserirInicio(int val){
        Node *nova = new Node;
        nova->val = val;
        nova->prox = inicio;
        inicio = nova;
    }
};












