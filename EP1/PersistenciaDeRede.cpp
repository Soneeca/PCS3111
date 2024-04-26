#include "PersistenciaDeRede.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

PersistenciaDeRede::PersistenciaDeRede(string arquivo){
    this->arquivo = arquivo;
    ifstream f1;
    f1.open(arquivo);
    if(f1.fail()) throw new logic_error("tem nada ai");
    f1.close();
}

PersistenciaDeRede::~PersistenciaDeRede(){

}

Rede* PersistenciaDeRede::carregar(){
    Rede* rede = new Rede();
    ifstream f1;
    f1.open(arquivo);
    int qtd;
    f1 >> qtd;
    if(qtd > 0){
        for(int i = 1; i <= qtd; i++){
            string tipo;
            f1 >> tipo;
            int endereco;
            if(tipo == "r"){
                f1 >> endereco;
                Roteador* rot = new Roteador(endereco);
                rede->adicionar(rot);
            }
            else if(tipo == "q"){
                f1 >> endereco;
                RoteadorComQoS* rot = new RoteadorComQoS(endereco);
                int nprio;
                f1 >> nprio;
                for(int n = 1; n <= nprio; n++){
                    int prio;
                    f1 >> prio;
                    rot->priorizar(prio);
                }
                rede->adicionar(rot);
            }
        }
    }
    int qtdh;
    f1 >> qtdh;
    if(qtdh > 0){
        for(int i = 1; i <= qtdh; i++){
            int endereco, gateway, atraso;
            f1 >> endereco >> gateway >> atraso;
            Roteador* rt = dynamic_cast<Roteador*>(rede->getNo(gateway));
            Hospedeiro* h = new Hospedeiro(endereco, rt, atraso);
            int qtdChat;
            f1 >> qtdChat;
            for(int n = 1; n <= qtdChat; n++){
                int porta, enderecoDestino, portaDestino;
                f1 >> porta >> enderecoDestino >> portaDestino;
                h->adicionarChat(porta, enderecoDestino, portaDestino);
            }
            rede->adicionar(h);
        }
    }
    for(int i = 1; i <= qtd; i++){
        int rot, rotp, atrasop;
        f1 >> rot >> rotp >> atrasop;
        Roteador* rt = dynamic_cast<Roteador*>(rede->getNo(rot));
        No* rt2 = rede->getNo(rotp);
        rt->setPadrao(rt2, atrasop);
        int qtdm;
        f1 >> qtdm;
        for(int n = 1; n <= qtdm; n++){
            int endRot, adj, atrasoAdj;
            f1 >> endRot >> adj >> atrasoAdj;
            No* rt3 = rede->getNo(adj);
            rt->mapear(endRot, rt3, atrasoAdj);
        }

    }
    int up;
    f1 >> up;
    if(!f1.eof()) throw new logic_error("parou no meio");
    f1.close();
    return rede;

}
