#include "No.h"
#include "Evento.h"

#include <iostream>
#include <string>

using namespace std;

Evento::Evento(int instante, No* destino, Datagrama* d) : instante(instante), destino(destino), d(d){
}

Evento::~Evento(){
}

int Evento::getInstante(){
    return instante;
}

No* Evento::getDestino(){
    return destino;
}

Datagrama* Evento::getDatagrama(){
    return d;
}

void Evento::imprimir(){
}
