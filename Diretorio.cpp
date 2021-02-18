#include <bitset>
#include <cmath>
#include <iostream>
#include <utility>
#include "Diretorio.h"

int registros = 0;
int numBalde = 0;
int id = 0;

Diretorio::Diretorio(int profund, int tamanhoBalde) {
    this->profGlobal = profund;
    this->tamanhoBalde = tamanhoBalde;
    for(int i = 0; i < 1<<profGlobal; i++){
        baldes.push_back(new Balde(profund, tamanhoBalde));
    }
    numBalde++;
}

void Diretorio::divide(int idBalde, std::string pseudochave) {
    int profLocal = baldes[idBalde]->aumentaProfund();
    int par = idBalde^(1<<(this->profGlobal-1));

    baldes[par] = new Balde(profLocal, tamanhoBalde);

    std::vector<std::string> pseudochaves = baldes[idBalde]->copia();

    for(auto& strbin: pseudochaves){
        int id = hash(strbin);
        if(id != idBalde){
            baldes[par]->insere(strbin);
            baldes[idBalde]->remocao(strbin);
        }
    }
    numBalde++;
    insere(pseudochave, true);
}

bool Diretorio::busca(std::string elemento) {
    std::string pseudochave = elemento;
    int idBalde = hash(pseudochave);
    return baldes[idBalde]->busca(pseudochave);
}

void Diretorio::duplica(int idBalde, std::string pseudochave) {
    int tamAntigo = std::pow(2, this->profGlobal);

    for(int i = 0; i < tamAntigo; i++){
        baldes.push_back(baldes[i]);
    }
    this->profGlobal++;

    divide(idBalde, pseudochave);
}

void Diretorio::insere(std::string elemento, bool binario) {
    std::string pseudochave = elemento;
    int idBalde = hash(pseudochave);
    Balde* balde = baldes[idBalde];
    if(!balde->verificaCheio()){
        balde->insere(pseudochave);
        registros++;
    }else if(balde->verificaCheio() && balde->getProfund() < profGlobal){
        divide(idBalde, pseudochave);
    }else{
        duplica(idBalde, pseudochave);
    }
}

int Diretorio::hash(std::string strbin) {
    int chave = 0;
    for(int i = 0; i < profGlobal; i++){
        int val = strbin[i]-48;
        chave = chave + val*(int)std::pow(2,i);
    }
    return chave;
}

void Diretorio::imprime() {

    for(auto balde: baldes){
        std::cout << id << std::endl;
        std::cout << "Profundidade: " << balde->getProfund() << std::endl;
        std::cout << std::endl;
        balde->imprime();
        std::cout << std::endl;
        id++;
    }
}

void Diretorio::imprimeCarga(){
    std::cout << "Fator de Carga: " << registros << "/" << numBalde * this->tamanhoBalde << " = " << (double) registros/ (double)(numBalde *this->tamanhoBalde) << "\n";
    std::cout << "Numero de Baldes: " << numBalde;
}
