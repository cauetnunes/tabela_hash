#include "TabelaHashDupla.h"
#include <iostream>

int main() {
    
    TabelaHashDupla tabela(100);

    
    tabela.inserir(23, "Objeto_23");
    tabela.inserir(45, "Objeto_45");
    tabela.inserir(67, "Objeto_67");
    tabela.inserir(89, "Objeto_89");
    tabela.inserir(101, "Objeto_101");

    
    tabela.imprimir();

    
    int chaveBusca = 45;
    Objeto* obj = tabela.buscar(chaveBusca);
    if (obj) {
        std::cout << "\nObjeto encontrado: Chave = " << obj->chave << " Valor = " << obj->valor << std::endl;
    } else {
        std::cout << "\nObjeto com chave " << chaveBusca << " não encontrado." << std::endl;
    }

    return 0;
}
 