#ifndef HOSPEDEIRO_H
#define HOSPEDEIRO_H

#include "No.h"
#include "Chat.h"
#include "Roteador.h"

#include <vector>
#include <string>

using namespace std;

class Chat;

class Hospedeiro : public No{

public:
    Hospedeiro(int endereco, Roteador* gateway, int atraso);
    virtual ~Hospedeiro ();

    virtual Evento* processar(int instante);
    virtual void adicionarChat(int porta, int enderecoDestino, int portaDestino);
    virtual vector<Chat*>* getChats();
    virtual Chat* getChat(int porta);

private:
    vector<Chat*>* chats;
    Roteador* gateway;
    int atraso;

};

#endif // HOSPEDEIRO_H
