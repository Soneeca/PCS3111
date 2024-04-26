#ifndef PERSISTENCIADEREDE_H
#define PERSISTENCIADEREDE_H

#include "Rede.h"

#include <fstream>

class PersistenciaDeRede{
    public:
        PersistenciaDeRede(string arquivo);
        virtual ~PersistenciaDeRede();

        virtual Rede* carregar();

    protected:
        string arquivo;

    private:
};

#endif // PERSISTENCIADEREDE_H
