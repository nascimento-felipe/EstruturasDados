#include <iostream>
#include "ArvBinaria.h"

    ArvBinaria::ArvBinaria() {
        raiz = nullptr;
    }

    ArvBinaria::~ArvBinaria() {
        deletarArvore(raiz);
    }
    
    void ArvBinaria::deletarArvore(No* noAtual) {
        if (noAtual != nullptr) {
            deletarArvore(noAtual->filhoEsquerda);
            deletarArvore(noAtual->filhoDireita);

            delete noAtual;
        }
    }
    
    No* ArvBinaria::obterRaiz() {
        return raiz;
    }
    
    bool ArvBinaria::estaVazio() {
        return (raiz == nullptr);
    }
    
    bool ArvBinaria::estaCheia() {
        try {
            No* temp = new No;
            delete temp;
            return false;
        } catch (std::bad_alloc exception) {
            return true;
        }
    }
    
    void ArvBinaria::inserir(Aluno aluno) {
        if (estaCheia()) {
            std::cout << "A arvore esta cheia!\n"
            << "Nao foi possivel inserir esse elemento\n";
        } else {
            No* noNovo = new No;
            noNovo->aluno = aluno;
            noNovo->filhoDireita = nullptr;
            noNovo->filhoEsquerda= nullptr;
            if (raiz == nullptr) {
                raiz = noNovo;
            } else {
                No* temp = raiz;
                while (temp != nullptr) {
                    if (aluno.obterRa() < temp->aluno.obterRa()) {
                        if (temp->filhoEsquerda == nullptr) {
                            temp->filhoEsquerda = noNovo;
                            break;
                        } else {
                            temp = temp->filhoEsquerda;
                        }
                    } else {
                        if (temp->filhoDireita == nullptr) {
                            temp->filhoDireita = noNovo;
                            break;
                        } else {
                            temp = temp->filhoDireita;
                        }
                    }
                }
            }
        }
    }
    
    void ArvBinaria::remover(Aluno aluno) {
        bool busca = false;
        buscar(aluno, busca);
        if (busca) {
            removerBusca(aluno, raiz);
        } else {
            std::cout << "Nao foi encontrado nenhum aluno com esse RA.\n";
        }
        
    }

    void ArvBinaria::removerBusca(Aluno aluno, No *&noAtual) {
        if (aluno.obterRa() < noAtual->aluno.obterRa()) {
            removerBusca(aluno, noAtual->filhoEsquerda);
        } else if (aluno.obterRa() > noAtual->aluno.obterRa()) {
            removerBusca(aluno, noAtual->filhoDireita);
        } else {
            deletarNo(noAtual);
        }
    }

    void ArvBinaria::deletarNo(No *&noAtual) {
        No *temp = noAtual;
        if (noAtual->filhoEsquerda == nullptr) {
            noAtual = noAtual->filhoDireita;
            delete temp;
        } else if (noAtual->filhoDireita == nullptr) {
            noAtual = noAtual->filhoEsquerda;
            delete temp;
        } else {
            Aluno aluno;
            obterSucessor(aluno, noAtual);
            noAtual->aluno = aluno;
            removerBusca(aluno, noAtual->filhoDireita);
        }
    }

    void ArvBinaria::obterSucessor(Aluno &alunoSucessor, No *temp) {
        temp = temp->filhoDireita;
        while (temp->filhoEsquerda != nullptr) {
            temp = temp->filhoEsquerda;
        }
        alunoSucessor = temp->aluno;
    }
    
    void ArvBinaria::buscar(Aluno &aluno, bool &busca) {
        busca = false;
        No* noAtual = raiz;
        while (noAtual != nullptr) {
            if (aluno.obterRa() < noAtual->aluno.obterRa()) {
                noAtual = noAtual->filhoEsquerda;
            } else if (aluno.obterRa() > noAtual->aluno.obterRa()) {
                noAtual = noAtual->filhoDireita;
            } else {
                busca = true;
                aluno = noAtual->aluno;
                break;
            }
        }
    }
    
    void ArvBinaria::imprimirPreOrdem(No* noAtual) {
        if (noAtual != nullptr) {
            std::cout << noAtual->aluno.obterNome() << ": "
            << noAtual->aluno.obterRa() << std::endl;
            imprimirPreOrdem(noAtual->filhoEsquerda);
            imprimirPreOrdem(noAtual->filhoDireita);
        }
    }
    
    void ArvBinaria::imprimirEmOrdem(No* noAtual) {
        if (noAtual != nullptr) {
            imprimirEmOrdem(noAtual->filhoEsquerda);
            std::cout << noAtual->aluno.obterNome() << ": "
            << noAtual->aluno.obterRa() << std::endl;
            imprimirEmOrdem(noAtual->filhoDireita);
        }
    }
    
    void ArvBinaria::imprimirPosOrdem(No* noAtual) {
        if (noAtual != nullptr) {
            imprimirPosOrdem(noAtual->filhoEsquerda);
            imprimirPosOrdem(noAtual->filhoDireita);
            std::cout << noAtual->aluno.obterNome() << ": "
            << noAtual->aluno.obterRa() << std::endl;
        }
    }