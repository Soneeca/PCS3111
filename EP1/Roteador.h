#ifndef ROTEADOR_H
#define ROTEADOR_H

#include "No.h"
#include "TabelaDeRepasse.h"
#include "Evento.h"

#include <iostream>
#include <string>

using namespace std;

class Roteador : public No {

public:
Roteador(int endereco);
~Roteador();

virtual void mapear(int endereco, No* adjacente, int atraso);
virtual void setPadrao(No* padrao, int atraso);
virtual Evento* processar(int instante);

static const int TAMANHO_TABELA = 10;

protected:
Roteador(int endereco, Fila* fila);

TabelaDeRepasse* t1;
int instante;
Datagrama* d1;

};



#endif // ROTEADOR_H
