#ifndef REDE_H
#define REDE_H

#include "RoteadorComQoS.h"
#include "No.h"
#include "Roteador.h"
#include "Hospedeiro.h"

#include <string>
#include <list>

using namespace std;

class Rede {

public:

    Rede();
    virtual ~Rede();

    virtual void adicionar(No* n);
    virtual No* getNo(int endereco);

    virtual list<No*>* getNos();
    virtual list<Hospedeiro*>* getHospedeiros();

    virtual void imprimir();

protected:

    list<No*>* nos;
    list<Hospedeiro*>* hospedeiros;

};

#endif // REDE_H
