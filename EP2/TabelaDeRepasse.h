#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H

#include "No.h"

#include <string>

using namespace std;

class TabelaDeRepasse{
private:
    int tamanho;
    No** adjacentes;
    int* atraso;
    int* endereco;
    int quantidade;
    No* padrao;
    int atrasoPadrao;




public:
    TabelaDeRepasse(int tamanho);
    virtual ~TabelaDeRepasse();

    virtual void mapear(int endereco, No* adjacente, int atraso);
    virtual No** getAdjacentes();
    virtual int getQuantidadeDeAdjacentes();

    virtual void setPadrao(No* padrao, int atraso);

    virtual No* getProximoSalto(int endereco, int& atraso);

    virtual void imprimir();
};



#endif
