#include <iostream>
#include "fila.h"

    Fila::Fila() {
        primeiro = 0;
        ultimo = 0;
        estrutura = new TipoItem[MAX_ITENS];
    }

    Fila::~Fila() {
        delete [] estrutura;
    }

    bool Fila::estaVazio() {
        return (primeiro == ultimo);
    }

    bool Fila::estaCheio() {
        return ((ultimo - primeiro) == MAX_ITENS);
    }

    void Fila::inserir(TipoItem item) {
        if (!estaCheio()) {
            estrutura[ultimo % MAX_ITENS] = item;
            ultimo++;
            std::cout << "Inserção completa!\n";
        } else {
            std::cout << "A fila está cheia! Tente remover um valor antes.\n";
        }
    }

    TipoItem Fila::remover() {
        if (!estaVazio()) {
            primeiro++;
            return estrutura[(primeiro-1) % MAX_ITENS];
        } else {
            std::cout << "A fila está vazia! Tente adicionar um valor antes.\n";
            return -1;
        }
    }

    void Fila::imprimir() {
        std::cout << "Fila: ";
        for (int i = primeiro; i < ultimo; i++) {
            std::cout << estrutura[i % MAX_ITENS] << " ";
        }
        std::cout << "\n";
    }