#ifndef TABELA_HASH_DUPLA_H
#define TABELA_HASH_DUPLA_H

#include <string>
#include <vector>
#include <list>


struct Objeto {
    int chave;
    std::string valor;
    Objeto(int c, const std::string &v) : chave(c), valor(v) {}
};

class TabelaHashDupla {
private:
    static const int TAM_NIVEL1 = 10;  
    int tamanhoSegundoNivel;           
   
    std::vector<std::vector<std::list<Objeto>>*> tabela;

   
    int hash1(int chave) const;
   
    int hash2(int chave) const;

public:
   
    TabelaHashDupla(int n);
   
    ~TabelaHashDupla();

    void inserir(int chave, const std::string &valor);
    Objeto* buscar(int chave);
    void imprimir() const;
};

#endif 
