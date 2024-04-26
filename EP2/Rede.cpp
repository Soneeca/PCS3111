#include "Rede.h"

#include <iostream>

using namespace std;

Rede::Rede(){
    nos = new list<No*>();
    hospedeiros = new list<Hospedeiro*>();
}

Rede::~Rede(){
    if(!nos->empty()){
        list<No*>::iterator i = nos->begin();
        do {
            delete (*i);
            i++;
        } while(i != nos->end());
    }
    delete nos;
}

void Rede::adicionar(No* n){
    if(!nos->empty()){
        list<No*>::iterator i = nos->begin();
        while(i != nos->end()) {
            if((*i)->getEndereco() == n->getEndereco()) throw new logic_error("ja tem");
            i++;
        }
    }
    nos->push_back(n);
    Hospedeiro *ht = dynamic_cast<Hospedeiro*>(n);
    if(ht != NULL) hospedeiros->push_back(ht);
}

No* Rede::getNo(int endereco){
    if(!nos->empty()){
        list<No*>::iterator i = nos->begin();
        do {
            if((*i)->getEndereco() == endereco) return (*i);
            i++;
        } while(i != nos->end());
    }
    return NULL;
}

list<No*>* Rede::getNos(){
    return nos;
}

list<Hospedeiro*>* Rede::getHospedeiros(){
    return hospedeiros;
}

void Rede::imprimir(){

}
