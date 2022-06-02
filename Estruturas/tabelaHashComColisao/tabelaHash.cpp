#include <iostream>
#include "TabelaHash.h"


    int TabelaHash::funcaoHash(Aluno aluno) {
        return (aluno.obterRa() % max_posicoes);
    }

// ------------------------  PUBLIC  -----------------------

// ------------------------  PRIVATE -----------------------

    TabelaHash::TabelaHash(int tam_vetor, int max) {

        quantidade_itens = 0;
        max_itens = max;
        max_posicoes = tam_vetor;
        estrutura = new Aluno[tam_vetor];
    
    }

    TabelaHash::~TabelaHash() {
        delete [] estrutura;
    }

    bool TabelaHash::estaCheia() {
        return (quantidade_itens == max_itens);
    }

    int TabelaHash::obterTamanho() {
        return (quantidade_itens);
    }

    void TabelaHash::inserir(Aluno aluno) {
        if (estaCheia()) {
            std::cout << "A tabela Hash está cheia.\n"
            << "O elemento não pode ser inserido.\n";
        } else {
            int local = funcaoHash(aluno);
            while (estrutura[local].obterRa() > 0) {
                local = (local + 1) % max_posicoes;
            }
            estrutura[local] = aluno;
            quantidade_itens++;
        }
    }
    
    void TabelaHash::deletar(Aluno aluno) {
        int local = funcaoHash(aluno);
        bool teste = false;
        while (estrutura[local].obterRa() != -1) {
            if (estrutura[local].obterRa() == aluno.obterRa()) {
                std::cout << "Elemento removido!\n";
                estrutura[local] = Aluno(-2, " ");
                quantidade_itens--;
                teste = true;
                break;
            }
            local = (local+1) % max_posicoes;
        }
        if (!teste) {
            std::cout << "Elemento não encontrado!\n" 
            << "Nenhum elemento foi removido.\n";
        }
    }
    
    void TabelaHash::buscar(Aluno& aluno, bool& busca) {
        int local = funcaoHash(aluno);
        busca = false;
        while (estrutura[local].obterRa() != -1) {
            if (estrutura[local].obterRa() == aluno.obterRa()) {
                busca = true;
                aluno = estrutura[local];
                break;
            }
            local = (local+1) % max_posicoes;
        }
    }
    
    void TabelaHash::imprimir() {
        std::cout << "Tabela Hash: \n";
        for (int i = 0; i < max_posicoes; i++) {
            if (estrutura[i].obterRa() > 0) {
                std::cout << i << " : " << estrutura[i].obterRa();
                std::cout << " " << estrutura[i].obterNome() << "\n";
            }
        }
    }