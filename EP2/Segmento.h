#ifndef SEGMENTO_H
#define SEGMENTO_H

#include <string>

using namespace std;

class Segmento{
public:
    Segmento(int portaDeOrigem, int portaDeDestino, string dado);
    virtual ~Segmento();

    virtual int getPortaDeOrigem();
    virtual int getPortaDeDestino();
    virtual string getDado();

    virtual void imprimir();

protected:
    int portaDeOrigem;
    int portaDeDestino;
    string dado;

private:
};

#endif // SEGMENTO_H
