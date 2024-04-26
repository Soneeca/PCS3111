#include "RoteadorComQoS.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

RoteadorComQoS::RoteadorComQoS(int endereco) : Roteador(endereco, new FilaComPrioridade(TAMANHO_FILA)){
    destinosPriorizados = new vector<int>();
}

RoteadorComQoS::~RoteadorComQoS(){
    delete destinosPriorizados;
}

void RoteadorComQoS::priorizar(int destino){
    destinosPriorizados->push_back(destino);
}

vector<int>* RoteadorComQoS::getDestinosPriorizados(){
    return destinosPriorizados;
}

void RoteadorComQoS::receber(Datagrama* d){
    bool pri = false;
    for (int i = 0; i < destinosPriorizados->size(); i++){
        if (destinosPriorizados->at(i) == d->getDestino()){
            pri = true;
        }
    }
    try{
        FilaComPrioridade* filap = dynamic_cast<FilaComPrioridade*>(fila);
        filap->enqueue(d, pri);
    }catch(overflow_error *e) {
        cout << "\tFila em " << endereco << " estorou" << endl;
        delete e;
    }
}
