#include "Agendador.h"

#include <iostream>
#include <string>
#include <list>

using namespace std;

Agendador::Agendador(int instanteInicial, Rede* rede, int tamanho): tamanho(tamanho), instanteInicial(instanteInicial){
    e1 = new Evento*[tamanho];
    r1 = rede;
    instante = instanteInicial;
    quantidade = 0;
}

Agendador::~Agendador(){
    for (int i = 0; i < quantidade; i++) {
        delete e1[i];
    }
    delete[] e1;
}

bool Agendador::agendar(int instante, No* n, Datagrama* d){
    if (quantidade < tamanho){
        Evento* en = new Evento(instante, n, d);
        e1[quantidade] = en;
        quantidade++;
        return true;
    }
    return false;
}

void Agendador::processar(){

    for (int i = 0; i < quantidade; i++){
        if (e1[i]->getInstante() == instante){
            e1[i]->getDestino()->receber(e1[i]->getDatagrama());
            delete e1[i];
            for (int n = i; n < quantidade; n++){
                e1[n] = e1[n + 1];
            }
            quantidade--;
            i--;
        }
    }
    list<No*>::iterator i = r1->getNos()->begin();
    while(i != r1->getNos()->end()){
        Hospedeiro *h1 = dynamic_cast<Hospedeiro*>(*i);
        if(h1 != NULL){
            e1[quantidade] = h1->processar(instante);
        }
        else{
            Roteador* r2 = dynamic_cast<Roteador*>(*i);
            if(r2 != NULL) e1[quantidade] = r2->processar(instante);
        }
        if (e1[quantidade] != NULL){
            quantidade++;
        }
        i++;
    }

    instante++;
}

int Agendador::getInstante(){
    return instante;
}

