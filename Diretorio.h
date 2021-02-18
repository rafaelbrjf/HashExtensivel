#ifndef DIRETORIO_H_INCLUDED
#define DIRETORIO_H_INCLUDED

#include <vector>
#include <string>
#include "Balde.h"

class Diretorio {
    int profGlobal = 0, tamanhoBalde = 0;
    std::vector<Balde*> baldes;
    int hash(std::string strbin);

public:
    Diretorio(int profund, int tamanhoBalde);
    bool busca(std::string elemento);
    void insere(std::string elemento, bool binario=false);
    void duplica(int idBalde, std::string pseudochave);
    void divide(int idBalde, std::string pseudochave);
    void imprime();
    void imprimeCarga();
};

#endif // DIRETORIO_H_INCLUDED
