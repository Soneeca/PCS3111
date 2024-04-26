#include "No.h"

#include <iostream>

No::No(int endereco): endereco(endereco){
    fila = new Fila(TAMANHO_FILA);
}

No::No(int endereco, Fila* fila): endereco(endereco), fila(fila){}

No::~No(){
    delete fila;
}

int No::getEndereco(){
    return endereco;
}

void No::receber(Datagrama* datagrama){
    try{
        fila->enqueue(datagrama);
    }catch(overflow_error *e) {
        cout << "\tFila em " << endereco << " estorou" << endl;
        delete e;
    }
}

void No::imprimir(){
}



