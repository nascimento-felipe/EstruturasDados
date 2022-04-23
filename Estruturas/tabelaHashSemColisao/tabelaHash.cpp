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
        int local = funcaoHash(aluno);
        estrutura[local] = aluno;
        quantidade_itens++;
    }
    
    void TabelaHash::deletar(Aluno aluno) {
        int local = funcaoHash(aluno);
        if (estrutura[local].obterRa() != -1) {
            estrutura[local] = Aluno(-1, " ");
            quantidade_itens--;
        }
    }
    
    void TabelaHash::buscar(Aluno& aluno, bool& busca) {
        int local = funcaoHash(aluno);
        Aluno aux = estrutura[local];
        if (aluno.obterRa() != aux.obterRa()) {
            busca = false;
        } else {
            busca = true;
            aluno = aux;
        }
    }
    
    void TabelaHash::imprimir() {
        std::cout << "Tabela Hash: ";
        for (int i = 0; i < max_posicoes; i++) {
            if (estrutura[i].obterRa() != -1) {
                std::cout << i << " : " << estrutura[i].obterRa();
                std::cout << estrutura[i].obterNome() << "\n";
            }
        }
    }