#ifndef BALDE_H_INCLUDED
#define BALDE_H_INCLUDED

#include <string>
#include <vector>

class Balde {
    int profund, capacidade;
    std::vector<std::string> entradas;
public:
    int getProfund() const;

public:
    Balde(int profund, int capacidade);
    bool busca(std::string& elemento);
    bool insere(std::string& elemento);
    bool remocao(std::string strbin);
    void imprime();
    std::vector<std::string> copia();
    int aumentaProfund();
    bool verificaCheio();
};


#endif // BALDE_H_INCLUDED
