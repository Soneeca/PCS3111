#include "Chat.h"

#include <iostream>

using namespace std;

Chat::Chat(Hospedeiro* h, int porta, int enderecoDestino, int portaDestino){
    if(h == NULL) throw new invalid_argument("hospedeiro nulo");
    else{
        this->porta = porta;
        this->enderecoDestino = enderecoDestino;
        this->portaDestino = portaDestino;
        this->h = h;
        textoCompleto = "";
    }
}

Chat::~Chat(){
}

int Chat::getPorta(){
    return porta;
}

void Chat::enviar(string texto){
    Segmento* s = new Segmento(porta, portaDestino, texto);
    Datagrama* d = new Datagrama(h->getEndereco(), enderecoDestino, s);
    h->receber(d);
    textoCompleto = textoCompleto + "\t\tEnviado: " + texto + "\n";
}

void Chat::receber(Datagrama* d){
    textoCompleto = textoCompleto + "\t\tRecebido: " + d->getSegmento()->getDado() + "\n";
    delete d;
}

string Chat::getTextoCompleto(){
    return textoCompleto;
}

void Chat::imprimir(){
}
