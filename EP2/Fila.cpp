#include <iostream>

#include "Fila.h"

Fila::Fila(int tamanho) {
    if(tamanho <= 0) throw new invalid_argument("Argumento invalido");
    tamanhoMax = tamanho;
    filaDatagrama = new Datagrama*[tamanhoMax];
}

Fila::~Fila() {
}

void Fila::enqueue(Datagrama* d) {
    if(quantidade >= tamanhoMax) throw new overflow_error("overflow");

    if(quantidade < tamanhoMax && d != NULL){
        filaDatagrama[quantidade] = d;
        quantidade++;
    }

}

Datagrama* Fila::dequeue() {
    if(quantidade <= 0) throw new underflow_error("nada p tirar");
    if(quantidade > 1){
       Datagrama* d1 = filaDatagrama[0];
       for (int i = 1; i < quantidade; i++){
            filaDatagrama[i - 1] = filaDatagrama[i];
       }
       quantidade--;
       return d1;
    }
    else if(quantidade == 1){
        quantidade--;
        return filaDatagrama[0];
    }

}

bool Fila::isEmpty() {
    if(quantidade == 0){
        return true;
    }
    else{
        return false;
    }
}

int Fila::getSize() {
    return quantidade;
}

void Fila::imprimir() {
}
