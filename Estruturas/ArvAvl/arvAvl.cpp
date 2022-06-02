#include <iostream>
#include "ArvAvl.h"

    ArvAvl::ArvAvl() {
        raiz = nullptr;
    }

    ArvAvl::~ArvAvl() {
        deletarArvore(raiz);
    }
    
    void ArvAvl::deletarArvore(No* noAtual) {
        if (noAtual != nullptr) {
            deletarArvore(noAtual->filhoEsquerda);
            deletarArvore(noAtual->filhoDireita);

            delete noAtual;
        }
    }
    
    No* ArvAvl::obterRaiz() {
        return raiz;
    }
    
    bool ArvAvl::estaVazio() {
        return (raiz == nullptr);
    }
    
    bool ArvAvl::estaCheia() {
        try {
            No* temp = new No;
            delete temp;
            return false;
        } catch (std::bad_alloc exception) {
            return true;
        }
    }
    
    void ArvAvl::inserir(Aluno aluno) {
        if (estaCheia()) {
            std::cout << "A arvore esta cheia!\n"
            << "Nao foi possivel inserir esse elemento\n";
        } else {
            bool cresceu = false;
            insereRecursivo(raiz, aluno, cresceu);
        }
    }

    void ArvAvl::insereRecursivo(No *&noAtual, Aluno aluno, bool &cresceu) {
        if (noAtual == nullptr) {
            noAtual = new No;
            noAtual->filhoDireita = nullptr;
            noAtual->filhoEsquerda = nullptr;
            noAtual->aluno = aluno;
            noAtual->fatorBalanceamento = 0;
            cresceu = true;
            return;
        }

        if (aluno.obterRa() < noAtual->aluno.obterRa()) {
            insereRecursivo(noAtual->filhoEsquerda, aluno, cresceu);
            if (cresceu) {
                noAtual->fatorBalanceamento -= 1;
            }
        } else {
            insereRecursivo(noAtual->filhoDireita, aluno, cresceu);
            if (cresceu) {
                noAtual->fatorBalanceamento += 1;
            }
        }

        realizarRotacao(noAtual);

        if (cresceu && noAtual->fatorBalanceamento == 0) {
            cresceu = false;
        }
    }
    
    void ArvAvl::remover(Aluno aluno) {
        bool busca = false;
        buscar(aluno, busca);
        if (busca) {
            bool diminuiu = false;
            removerBusca(aluno, raiz, diminuiu);
        } else {
            std::cout << "Nao foi encontrado nenhum aluno com esse RA.\n";
        }
        
    }

    void ArvAvl::removerBusca(Aluno aluno, No *&noAtual, bool &diminuiu) {
        if (aluno.obterRa() < noAtual->aluno.obterRa()) {
            removerBusca(aluno, noAtual->filhoEsquerda, diminuiu);
            if (diminuiu) {
                noAtual->fatorBalanceamento += 1;
            }
        } else if (aluno.obterRa() > noAtual->aluno.obterRa()) {
            removerBusca(aluno, noAtual->filhoDireita, diminuiu);
            if (diminuiu) {
                noAtual->fatorBalanceamento -= 1;
            }
        } else {
            deletarNo(noAtual, diminuiu);
        }

        if (noAtual != nullptr) {
            realizarRotacao(noAtual);
            if (diminuiu && noAtual->fatorBalanceamento != 0) {
                diminuiu = false;
            }
        }
    }

    void ArvAvl::deletarNo(No *&noAtual, bool &diminuiu) {
        No *temp = noAtual;
        if (noAtual->filhoEsquerda == nullptr) {
            noAtual = noAtual->filhoDireita;
            diminuiu = true;
            delete temp;
        } else if (noAtual->filhoDireita == nullptr) {
            noAtual = noAtual->filhoEsquerda;
            diminuiu = true;
            delete temp;
        } else {
            Aluno alunoSucessor;
            obterSucessor(alunoSucessor, noAtual);
            noAtual->aluno = alunoSucessor;
            removerBusca(alunoSucessor, noAtual->filhoDireita, diminuiu);
            if (diminuiu) {
                noAtual->fatorBalanceamento -= 1;
            }
        }
    }

    void ArvAvl::obterSucessor(Aluno &alunoSucessor, No *temp) {
        temp = temp->filhoDireita;
        while (temp->filhoEsquerda != nullptr) {
            temp = temp->filhoEsquerda;
        }
        alunoSucessor = temp->aluno;
    }
    
    void ArvAvl::buscar(Aluno &aluno, bool &busca) {
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
    
    void ArvAvl::imprimirPreOrdem(No* noAtual) {
        if (noAtual != nullptr) {
            std::cout << noAtual->aluno.obterNome() << ": "
            << noAtual->aluno.obterRa() << std::endl;
            imprimirPreOrdem(noAtual->filhoEsquerda);
            imprimirPreOrdem(noAtual->filhoDireita);
        }
    }
    
    void ArvAvl::imprimirEmOrdem(No* noAtual) {
        if (noAtual != nullptr) {
            imprimirEmOrdem(noAtual->filhoEsquerda);
            std::cout << noAtual->aluno.obterNome() << ": "
            << noAtual->aluno.obterRa() << std::endl;
            imprimirEmOrdem(noAtual->filhoDireita);
        }
    }
    
    void ArvAvl::imprimirPosOrdem(No* noAtual) {
        if (noAtual != nullptr) {
            imprimirPosOrdem(noAtual->filhoEsquerda);
            imprimirPosOrdem(noAtual->filhoDireita);
            std::cout << noAtual->aluno.obterNome() << ": "
            << noAtual->aluno.obterRa() << std::endl;
        }
    }

    void ArvAvl::rotacaoDireita(No *&pai) {
        No* novoPai = pai->filhoEsquerda;
        pai->filhoEsquerda = novoPai->filhoDireita;
        novoPai->filhoDireita = pai;
        pai = novoPai;
    }

    void ArvAvl::rotacaoEsquerda(No *&pai) {
        No* novoPai = pai->filhoDireita;
        pai->filhoDireita = novoPai->filhoEsquerda;
        novoPai->filhoEsquerda = pai;
        pai = novoPai;
    }

    void ArvAvl::rotacaoEsquerdaDireita(No *&pai) {
        No* filho = pai->filhoEsquerda;
        rotacaoEsquerda(filho);
        pai->filhoEsquerda = filho;
        rotacaoDireita(pai);
    }

    void ArvAvl::rotacaoDireitaEsquerda(No *&pai) {
        No* filho = pai->filhoDireita;
        rotacaoDireita(filho);
        pai->filhoDireita = filho;
        rotacaoEsquerda(pai);
    }

    void ArvAvl::realizarRotacao(No *&pai) {
        No* filho;
        No* neto;

        if (pai->fatorBalanceamento == -2) { // rotaciona pra direita
            filho = pai->filhoEsquerda;
            if (filho->fatorBalanceamento == -1) { // simples pra direita (fb = 0)
                pai->fatorBalanceamento = 0;
                filho->fatorBalanceamento = 0;
                rotacaoDireita(pai);
            } else if (filho->fatorBalanceamento == 0) { // simples pra direita (fb = -1 e 1)
                pai->fatorBalanceamento = -1;
                filho->fatorBalanceamento = 1;
                rotacaoDireita(pai);
            } else if (filho->fatorBalanceamento == 1) { // rotacao dupla
                neto = filho->filhoDireita;
                if (neto->fatorBalanceamento == -1) {
                    pai->fatorBalanceamento = 1;
                    filho->fatorBalanceamento = 0;
                } else if (neto->fatorBalanceamento == 0) {
                    pai->fatorBalanceamento = 0;
                    filho->fatorBalanceamento = 0;
                } else if (neto->fatorBalanceamento == 1) {
                    pai->fatorBalanceamento = 0;
                    filho->fatorBalanceamento = -1;
                }

                neto->fatorBalanceamento = 0;
                rotacaoEsquerdaDireita(pai);
            }

        } else if (pai->fatorBalanceamento == 2) { // rotaciona pra esquerda
            filho = pai->filhoDireita;
            if (filho->fatorBalanceamento == 1) { // simples para esquerda (fb = 0)
                pai->fatorBalanceamento = 0;
                filho->fatorBalanceamento = 0;
                rotacaoEsquerda(pai);
            } else if (filho->fatorBalanceamento == 0) { // simples pra esquerda (fb = 1 e -1)
                pai->fatorBalanceamento = 1;
                filho->fatorBalanceamento = -1;
                rotacaoEsquerda(pai);
            } else if (filho->fatorBalanceamento == -1) { // rotacao dupla
                neto = filho->filhoEsquerda;
                if (neto->fatorBalanceamento == -1) {
                    pai->fatorBalanceamento = 0;
                    filho->fatorBalanceamento = 1;
                } else if (neto->fatorBalanceamento == 0) {
                    pai->fatorBalanceamento = 0;
                    filho->fatorBalanceamento = 0;
                } else if (neto->fatorBalanceamento == 1) {
                    pai->fatorBalanceamento = -1;
                    filho->fatorBalanceamento = 0;
                }
                
                neto->fatorBalanceamento = 0;
                rotacaoDireitaEsquerda(pai);
            }
        }
    }