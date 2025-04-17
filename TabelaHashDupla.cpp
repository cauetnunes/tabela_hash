#include "TabelaHashDupla.h"
#include <iostream>

TabelaHashDupla::TabelaHashDupla(int n) {
    
    tamanhoSegundoNivel = n / TAM_NIVEL1;
    tabela.resize(TAM_NIVEL1, nullptr);
    for (int i = 0; i < TAM_NIVEL1; ++i) {
        tabela[i] = new std::vector<std::list<Objeto>>(tamanhoSegundoNivel);
    }
}


TabelaHashDupla::~TabelaHashDupla() {
    for (int i = 0; i < TAM_NIVEL1; ++i) {
        delete tabela[i];
    }
}

int TabelaHashDupla::hash1(int chave) const {
    return chave % TAM_NIVEL1;
}

int TabelaHashDupla::hash2(int chave) const {
    return (chave / TAM_NIVEL1) % tamanhoSegundoNivel;
}

void TabelaHashDupla::inserir(int chave, const std::string &valor) {
    int idx1 = hash1(chave);
    int idx2 = hash2(chave);
    tabela[idx1]->at(idx2).emplace_back(chave, valor);
}

Objeto* TabelaHashDupla::buscar(int chave) {
    int idx1 = hash1(chave);
    int idx2 = hash2(chave);
    for (auto &obj : tabela[idx1]->at(idx2)) {
        if (obj.chave == chave) {
            return &obj;
        }
    }
    return nullptr;
}

void TabelaHashDupla::imprimir() const {
    for (int i = 0; i < TAM_NIVEL1; ++i) {
        std::cout << "Primeiro Nível [" << i << "]:" << std::endl;
        for (int j = 0; j < tamanhoSegundoNivel; ++j) {
            std::cout << "  Segundo Nível [" << j << "]: ";
            for (const auto &obj : tabela[i]->at(j)) {
                std::cout << "(" << obj.chave << ", " << obj.valor << ") ";
            }
            std::cout << std::endl;
        }
    }
}
