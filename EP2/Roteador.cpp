#include "Roteador.h"

#include <iostream>
#include <string>

using namespace std;

Roteador::Roteador(int endereco) : No(endereco) {
    t1 = new TabelaDeRepasse(TAMANHO_TABELA);
    instante = 0;
}

Roteador::Roteador(int endereco, Fila* fila) : No(endereco, fila) {
    t1 = new TabelaDeRepasse(TAMANHO_TABELA);
    instante = 0;
}

Roteador::~Roteador() {
    delete t1;
}

void Roteador::setPadrao(No* padrao, int atraso) {
    t1->setPadrao(padrao, atraso);
}

void Roteador::mapear(int endereco, No* adjacente, int atraso) {
   t1->mapear(endereco, adjacente, atraso);
}


Evento* Roteador::processar(int instante) {
    if (fila->getSize() > 0) {
        cout << "Roteador " << endereco << endl;
        d1 = fila->dequeue();
        if (d1->getDestino() == endereco) {
            cout << "\tRecebido: " << d1->getSegmento()->getDado() << endl;
            delete d1;
            return NULL;
        }
        int atraso;
        if (t1->getProximoSalto(d1->getDestino(), atraso) == NULL) {
            cout << "\tSem proximo: ";
            d1->imprimir();
            delete d1;
            return NULL;
        }
        No* n1 = t1->getProximoSalto(d1->getDestino(), atraso);
        cout << "\tRepassado para " << t1->getProximoSalto(d1->getDestino(), atraso)->getEndereco() << " (instante " << instante + atraso << "): ";
        d1->imprimir();
        Evento* e1 = new Evento(instante + atraso, n1, d1);
        return e1;
    }
    return NULL;
}




