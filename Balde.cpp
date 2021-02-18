#include <iostream>
#include "Balde.h"

Balde::Balde(int profund, int capacidade) {
    this->profund = profund;
    this->capacidade = capacidade;
}



bool Balde::busca(std::string& pseudochave) {
    for(auto & entrada : entradas){
        if(entrada == pseudochave){
            return true;
        }
    }
    return false;
}

bool Balde::verificaCheio() {
    return entradas.size() == capacidade;
}

int Balde::getProfund() const {
    return profund;
}

int Balde::aumentaProfund() {
    profund++;
    return profund;
}

std::vector<std::string> Balde::copia(){
    return entradas;
}

bool Balde::insere(std::string& pseudochave) {
    if(this->verificaCheio()){
        return false;
    }

    if(busca(pseudochave)){
        return true;
    }

    entradas.push_back(pseudochave);
    return true;
}

bool Balde::remocao(std::string pseudochave) {
    auto iterador = entradas.begin();
    for(; iterador != entradas.end(); iterador++){
        if((*iterador) == pseudochave){
            break;
        }
    }
    if(iterador == entradas.end()){
        return false;
    }
    entradas.erase(iterador);

    return true;
}

void Balde::imprime() {
    for(const auto& chave: entradas){
        std::cout << chave << std::endl;
    }
}
