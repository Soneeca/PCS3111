#ifndef AGENDADOR_H
#define AGENDADOR_H

#include "No.h"
#include "Rede.h"
#include "Roteador.h"
#include "Hospedeiro.h"
#include "Evento.h"
#include "Datagrama.h"

class Agendador {

public:

    Agendador(int instanteInicial, Rede* rede, int tamanho);
    ~Agendador();

    bool agendar(int instante, No* n, Datagrama* d);
    void processar();
    int getInstante();

private:

    Evento** e1;
    No** nos;
    Rede* r1;
    int tamanho;
    int instanteInicial;
    int instante;
    int quantidade;

};

#endif // AGENDADOR_H
