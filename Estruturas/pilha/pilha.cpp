#include <iostream>
#include "pilha.h"

    pilha::pilha() { // construtora
        tamanho = 0;
        estrutura = new TipoItem[tamanho];
    } 

    pilha::~pilha() { // destrutora
        delete [] estrutura;
    }

    bool pilha::estaCheia() {
        return (tamanho == MAX_ITENS);
    }
    
    bool pilha::estaVazia() {
        return (tamanho == 0);
    }

    void pilha::inserir(TipoItem item) {
        if (!estaCheia()) {
            estrutura[tamanho] = item;
            tamanho++;
            std::cout << "Inserção concluida!\n";
        } else {
            std::cout << "A pilha está cheia! Não é possível inserir um novo elemento.\n";
        }
    }
    
    TipoItem pilha::remover() {
        if (!estaVazia()){
            tamanho--;
            std::cout << "Remocao concluida!\n";
            return estrutura[tamanho];
        } else {
            std::cout << "A pilha está vazia! Não é possível remover o elemento.\n";
            return -1;
        }
    }
    
    void pilha::imprimir() {
        std::cout << "Pilha: ";

        for (int i = 0; i < tamanho; i++) {
            std::cout << estrutura[i] << " ";
        }
        std::cout << "\n";
    }
    
    int pilha::getTamanho() {
        return tamanho;
    }
