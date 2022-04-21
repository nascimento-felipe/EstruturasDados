#include <iostream>
#include "PilhaDinamica.h"
#include <cstddef>

    PilhaDinamica::PilhaDinamica() {
        noTopo = nullptr;
    }

    PilhaDinamica::~PilhaDinamica() {
        No* noTemp;

        while (noTopo != nullptr) {
            noTemp = noTopo;
            noTopo = noTopo->proximo;
            delete noTemp;
        }
    }

    bool PilhaDinamica::estaVazia() {
        return (noTopo == nullptr);
    }

    bool PilhaDinamica::estaCheia() {
        No* noNovo;

        try{
            noNovo = new No;
            delete noNovo;
            return false;
        } catch(std::bad_alloc exception) {
            return true;
        }
    }

    void PilhaDinamica::inserir(TipoItem item) {
        if (!estaCheia()) {
            No* noNovo = new No;
            noNovo->valor = item;
            noNovo->proximo = noTopo;
            noTopo = noNovo;
        } else {
            std::cout << "A pilha está cheia! Nao foi possivel inserir.\n" 
            << "Tente remover um elemento antes.\n";
        }
    }

    TipoItem PilhaDinamica::remover() {
        if (!estaVazia()) {
            No* noTemp;
            noTemp = noTopo;
            TipoItem item = noTopo->valor;
            noTopo = noTopo->proximo;
            delete noTemp;
            
            return item;
        } else {
            std::cout << "A pilha esta vazia! Nao foi possivel remover.\n"
            << "Adicione um elemento e tente novamente.\n";
            
            return -1;
        }
    }

    void PilhaDinamica::imprimir() {
        No* noTemp = noTopo;

        std::cout << "Pilha dinamica: ";

        while (noTemp != nullptr) {
            std::cout << noTemp->valor << " ";
            noTemp = noTemp->proximo;
        }

        std::cout << "\n";
    }