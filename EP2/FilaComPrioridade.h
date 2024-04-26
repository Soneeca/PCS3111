#ifndef FILACOMPRIORIDADE_H
#define FILACOMPRIORIDADE_H

#include "Fila.h"

#include <string>

using namespace std;

class FilaComPrioridade : public Fila{
public:
    FilaComPrioridade(int tamanho);
    virtual ~FilaComPrioridade();

    virtual void enqueue(Datagrama* d, bool prioritario);
    virtual Datagrama* dequeue();
    using Fila::enqueue;

protected:
    int p; // conta o numero de prioritarios na fila
};

#endif // FILACOMPRIORIDADE_H
