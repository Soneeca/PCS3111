/*

   PRA QUE SERVE
   TANTOS CODIGOS?
   SE A VIDA
   NAO E PROGRAMADA
   E AS MELHORES COISAS
   NAO TEM LOGICA

*/

#include "Segmento.h"
#include "Datagrama.h"
#include "Fila.h"
#include "FilaComPrioridade.h"
#include "TabelaDeRepasse.h"
#include "Evento.h"
#include "No.h"
#include "Roteador.h"
#include "RoteadorComQoS.h"
#include "Hospedeiro.h"
#include "Chat.h"
#include "Rede.h"
#include "Agendador.h"
#include "PersistenciaDeRede.h"

#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

/*

   PRA QUE SERVE
   TANTOS CODIGOS?
   SE A VIDA
   NAO E PROGRAMADA
   E AS MELHORES COISAS
   NAO TEM LOGICA

*/

int main(){
    string arquivo;
    cout << "Nome do arquivo: ";
    cin >> arquivo;
    int instanteInicial;
    cout << "Instante inicial: ";
    cin >> instanteInicial;
    cout << "\n";
    PersistenciaDeRede* p = new PersistenciaDeRede(arquivo);
    Rede* r = p->carregar();
    Agendador* a = new Agendador(instanteInicial, r, 10);

    int opc = 100;
    while(opc != 0){
        cout << "Simulador de Rede" << endl
        << "1) Enviar uma mensagem" << endl
        << "2) Passar tempo" << endl
        << "0) Sair" << endl
        << "Escolha uma opcao: ";
        cin >> opc;
        cout << "\n";

        if(opc == 1){

            list<Hospedeiro*>::iterator i = r->getHospedeiros()->begin();
            while(i != r->getHospedeiros()->end()){
                cout << "Hospedeiro: " << (*i)->getEndereco() << endl;
                int c = (*i)->getChats()->size();
                for(int n = 0; n < c; n++){
                    cout << "\tChat: " << (*i)->getChats()->at(n)->getPorta() << endl;
                }
                i++;
            }

            int endereco, porta;
            cout << "Endereco do hospedeiro: ";
            cin >> endereco;
            cout << "Porta do chat: ";
            cin >> porta;
            list<Hospedeiro*>::iterator p = r->getHospedeiros()->begin();
            bool achou = 0;
            Chat* ch;
            Hospedeiro* hr;
            while(p != r->getHospedeiros()->end()){
                if((*p)->getEndereco() == endereco){
                    hr = (*p);
                    for(int m = 0; m < (*p)->getChats()->size(); m++){
                        if((*p)->getChats()->at(m)->getPorta() == porta){
                            ch = (*p)->getChats()->at(m);
                            achou = true;
                        }
                   }
                }
                p++;
            }
            if(achou){
                string mensagem;
                cout << "Conteudo: " << endl
                << ch->getTextoCompleto()
                << "\n"
                << "Mensagem: ";
                cin >> mensagem;
                cout << "\n";
                ch->enviar(mensagem);
            }
            else{
                cout << "Erro: origem desconhecida" << endl;
            }

        }

        else if(opc == 2){
            int t;
            cout << "Quantidade de tempo: ";
            cin >> t;
            cout << "\n";

            for(int k = 1; k <= t; k++){
                cout << "Instante " << a->getInstante() << endl << "---" << endl;
                a->processar();
                cout << "\n";
            }
        }

    }



return 0;
}



