#include <iostream>
#include "FilaDinamica.h"
#include <cstddef>

    FilaDinamica::FilaDinamica() {
        primeiro = nullptr;
        ultimo = nullptr;
    }

    FilaDinamica::~FilaDinamica() {
        No* temp;

        while(primeiro != nullptr) {
            temp = primeiro;
            primeiro = primeiro->proximo;
            delete temp;
        }

        ultimo = nullptr;
    }

    bool FilaDinamica::estaVazia() {
        return (primeiro == nullptr);
    }

    bool FilaDinamica::estaCheia() {
        No* temp;
        try {
            temp = new No;
            delete temp;
            return false;
        } catch (std::bad_alloc exception) {
            return true;
        }
    }

    void FilaDinamica::inserir(TipoItem item) {
        if (estaCheia()) {
            std::cout << "\n\n A fila esta cheia! Nao foi possivel inserir esse elemento.\n"
            << " Remova um elemento e tente de novo.\n";
        } else {
            No* novo = new No;
            novo->valor = item;
            novo->proximo = nullptr;
            
            if (primeiro == nullptr) {
                primeiro = novo;
            } else {
                ultimo->proximo = novo;
            }

            ultimo = novo;
        }
    }

    TipoItem FilaDinamica::remover() {
        if (estaVazia()) {
            std::cout << "\n\n A fila esta vazia!\n"
            << " Insira um novo valor e tente novamente.\n";
            return -1;
        } else {
            No* temp = primeiro;
            TipoItem item = primeiro->valor;
            primeiro = primeiro->proximo;

            if (primeiro == nullptr) {
                ultimo = nullptr;
            }

            delete temp;
            return item;
        }
    }

    void FilaDinamica::imprimir() {
        No* temp = primeiro;

        std::cout << "Fila: ";
        while(temp != nullptr) {
            std::cout << temp->valor << " ";
            temp = temp->proximo;
        }

        std::cout << "\n";
    }