#include "TabelaDeRepasse.h"
#include "No.h"

#include <iostream>
#include <string>

using namespace std;

TabelaDeRepasse::TabelaDeRepasse(int tamanho){
    if(tamanho <= 0) throw new invalid_argument("pequeno dms");
    this->tamanho = tamanho;
    adjacentes = new No*[tamanho];
    atraso = new int[tamanho];
    endereco = new int[tamanho];
    quantidade = 0;
    padrao = NULL;
    atrasoPadrao = 0;
}
TabelaDeRepasse::~TabelaDeRepasse(){
    delete[] adjacentes;
    delete[] atraso;
    delete[] endereco;
}
void TabelaDeRepasse::mapear(int endereco, No* adjacente, int atraso){
    if (quantidade >= tamanho) throw new overflow_error("to cheio");
    if (quantidade < tamanho){
        for (int i = 0; i < quantidade; i++){
            if (this->endereco[i] == endereco) throw new invalid_argument("ja tem");
        }
        this->adjacentes[quantidade] = adjacente;
        this->endereco[quantidade] = endereco;
        this->atraso[quantidade] = atraso;
        quantidade++;
    }

}
No** TabelaDeRepasse::getAdjacentes(){
    return adjacentes;
}
int TabelaDeRepasse::getQuantidadeDeAdjacentes(){
    return quantidade;
}
void TabelaDeRepasse::setPadrao(No* padrao, int atraso){
    this->padrao = padrao;
    atrasoPadrao = atraso;
}
No* TabelaDeRepasse::getProximoSalto(int endereco, int& atraso){
    for (int i = 0; i < quantidade; i++){
        if (this->endereco[i] == endereco){
            atraso = this->atraso[i];
            return adjacentes[i];
        }
    }
    atraso = this->atrasoPadrao;
    return padrao;
}
void TabelaDeRepasse::imprimir(){

}
