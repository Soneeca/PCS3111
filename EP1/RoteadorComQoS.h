#ifndef ROTEADORCOMQOS_H_INCLUDED
#define ROTEADORCOMQOS_H_INCLUDED

#include "Roteador.h"
#include "Datagrama.h"
#include "FilaComPrioridade.h"
#include "Fila.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RoteadorComQoS : public Roteador {

public:
    RoteadorComQoS(int endereco);
    virtual ~RoteadorComQoS();
    virtual void priorizar(int destino);
    virtual vector<int>* getDestinosPriorizados();
    virtual void receber(Datagrama* d);

protected:

    int destino;
    vector<int>* destinosPriorizados;

};

#endif // ROTEADORCOMQOS_H_INCLUDED
