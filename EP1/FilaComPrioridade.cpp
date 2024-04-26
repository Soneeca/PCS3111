#include "FilaComPrioridade.h"

#include <iostream>

using namespace std;

FilaComPrioridade::FilaComPrioridade(int tamanho) : Fila(tamanho){
    if(tamanho <= 0) throw new invalid_argument("tamanho nao cabe");
    p = 0;
}

FilaComPrioridade::~FilaComPrioridade(){
}

void FilaComPrioridade::enqueue(Datagrama* d, bool prioritario){
    if(quantidade >= tamanhoMax) throw new overflow_error("overflow");
       if(quantidade < tamanhoMax && d != NULL){
        if(prioritario){
            for(int i = quantidade; i >= p; i--){
                filaDatagrama[i] = filaDatagrama[i - 1];
            }
            filaDatagrama[p] = d;
            p++;
            quantidade++;
        }
        filaDatagrama[quantidade] = d;
        quantidade++;

    }
}

Datagrama* FilaComPrioridade::dequeue(){
    if(quantidade <= 0) throw new underflow_error("nada p tirar");
    if(p >= 1) p--;
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
