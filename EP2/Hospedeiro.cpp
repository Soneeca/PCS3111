#include "Hospedeiro.h"

#include <iostream>

Hospedeiro::Hospedeiro(int endereco, Roteador* gateway, int atraso): No(endereco){
    this->gateway = gateway;
    this->atraso = atraso;
    chats = new vector<Chat*>();
}

Hospedeiro::~Hospedeiro(){
    int t = chats->size();
    for(int i = 0; i < t; i++){
        delete chats->at(i);
    }
    delete chats;
}

void Hospedeiro::adicionarChat(int porta, int enderecoDestino, int portaDestino){
    int t = chats->size();
    for(int i = 0; i < t; i++){
        if(chats->at(i)->getPorta() == porta) throw new logic_error("ja tem");
    }
    chats->push_back(new Chat(this, porta, enderecoDestino, portaDestino));
}

vector<Chat*>* Hospedeiro::getChats(){
    return chats;
}

Chat* Hospedeiro::getChat(int porta){
    int t = chats->size();
    for(int i = 0; i < t; i++){
        if(chats->at(i)->getPorta() == porta) return chats->at(i);
    }
    return NULL;
}

Evento* Hospedeiro::processar(int instante){
    if(fila->isEmpty()) return NULL;
    cout << "Hospedeiro " << endereco << endl;
    Datagrama* d = fila->dequeue();
    if(d->getDestino() == endereco){
        int t = chats->size();
        for(int i = 0; i < t; i++){
            if(chats->at(i)->getPorta() == d->getSegmento()->getPortaDeDestino()){
                chats->at(i)->receber(d);
                cout << "\tMensagem recebida" << endl;
                cout << chats->at(i)->getTextoCompleto() << endl;
            }
            else{
                delete d;
                cout << "\tSem chat: Origem: " << d->getOrigem() << ":" << d->getSegmento()->getPortaDeOrigem() << " Destino: "
                << d->getDestino() << ":" << d->getSegmento()->getPortaDeDestino() << " Dado: " << d->getSegmento()->getDado() << endl;
            }
        }
        return NULL;
    }
    else{
        int tempo = instante + atraso;
        Evento *e = new Evento(tempo, gateway, d);
        cout << "\tMensagem enviada" << endl;
        return e;
    }

}


