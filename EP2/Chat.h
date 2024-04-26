#ifndef CHAT_H
#define CHAT_H

#include "No.h"
#include "Hospedeiro.h"
#include "Datagrama.h"
#include "Segmento.h"

#include <string>

using namespace std;

class Hospedeiro;

class Chat{
public:
    Chat(Hospedeiro* h, int porta, int enderecoDestino, int portaDestino);
    virtual ~Chat();

    virtual int getPorta();
    virtual void enviar(string texto);
    virtual void receber(Datagrama* d);
    virtual string getTextoCompleto();

    virtual void imprimir();

private:
    string textoCompleto;
    int porta;
    int portaDestino;
    int enderecoDestino;
    Hospedeiro* h;

};



#endif // CHAT_H_INCLUDED
