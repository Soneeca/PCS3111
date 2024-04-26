#ifndef FILA_H
#define FILA_H

#include "Datagrama.h"

#include <iostream>

class Fila {

protected:
    int tamanhoMax;
    int quantidade = 0;
    Datagrama** filaDatagrama;
    Datagrama* d1;
public:
    Fila(int tamanho);
    virtual ~Fila();

    virtual void enqueue(Datagrama* d);
    virtual Datagrama* dequeue();
    virtual bool isEmpty();
    virtual int getSize();

    virtual void imprimir();
};

#endif
