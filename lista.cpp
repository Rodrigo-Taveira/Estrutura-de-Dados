#include "lista.h"
#include "iostream"

int main(){
    Lista lista;
    Lista lista2;
    
    lista.inserir(1);
    lista.inserir(2);
    lista.inserir(1);
    lista.inserir(3);
    lista.inserir(1);
    lista.inserir(4);
    lista.inserir(5);
    lista.listar();
    lista.removeIgualN(1);
    lista.listar();

}























