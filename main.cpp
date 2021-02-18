#include <iostream>
#include <random>


#include "Diretorio.h"

int main() {

    int teste = 0;
    int tamBalde = 0;
    std::vector<std::string> primeiroTeste = {"0101010101010", "0010010111011", "1000110101101", "1010101010101", "1111010101010", "1100011101110", "1001010101010", "0111011100010", "1101010110101", "1100000100111"};
    std::vector<std::string> segundoTeste = {"111110101010101010", "111110010010111011", "111110000110101101", "111111010101010101", "111110011010101010", "111110101010101111", "111110111011101001", "111110001000101110", "111111100010111110", "111110111000101010"};
    std::cout << "Tamanho do balde?" << std::endl;
    std::cin >> tamBalde;
    Diretorio diretorio(0, tamBalde);
    std::cout << "Digite 1 para pseudo-chaves aleatorias e 2 para pseudo-chaves iniciadas com o mesmo padrao de bits. \n";
    std::cin >> teste;
    if(teste==1)
    {
        for(auto str: primeiroTeste){
            diretorio.insere(str);
        }
    }
    else if(teste==2)
    {
        for(auto str: segundoTeste){
            diretorio.insere(str);
        }
    }
    else
    {
        std::cout << "Digite um numero valido." << std::endl;
        return 0;
    }
    diretorio.imprime();
    diretorio.imprimeCarga();
    return 0;
}
