#include "Datagrama.h"

#include <iostream>

using namespace std;

Datagrama::Datagrama(int origem, int destino, Segmento* dado){
    this->origem = origem;
    this->destino = destino;
    this->segmento = dado;
}

Datagrama::~Datagrama(){
}

int Datagrama::getOrigem(){
    return origem;
}

int Datagrama::getDestino(){
    return destino;
}

Segmento* Datagrama::getSegmento(){
    return segmento;
}

void Datagrama::imprimir(){
    cout << "Origem: " << getOrigem() << ":"
    << getSegmento()->getPortaDeOrigem()
    << ", Destino: " << getDestino() << ":"
    << getSegmento()->getPortaDeDestino() << ", "
    << getSegmento()->getDado() << endl;
}
