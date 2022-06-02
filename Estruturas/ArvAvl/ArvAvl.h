#include <iostream>
#include "Aluno.h"

struct No {
    Aluno aluno;
    No* filhoEsquerda;
    No* filhoDireita;
    int fatorBalanceamento;
};

class ArvAvl {
    private:
    No* raiz;

    public: 
    ArvAvl();
    ~ArvAvl();
    void deletarArvore(No* noAtual);
    
    No* obterRaiz();
    bool estaVazio();
    bool estaCheia();
    
    void inserir(Aluno aluno);
    void remover(Aluno aluno);
    void buscar(Aluno &aluno, bool &busca);
    void removerBusca(Aluno aluno, No *&noAtual, bool &diminuiu);
    void deletarNo(No *&noAtual, bool &diminuiu);
    void obterSucessor(Aluno &alunoSucessor, No* temp);
    
    void imprimirPreOrdem(No* noAtual);
    void imprimirEmOrdem(No* noAtual);
    void imprimirPosOrdem(No* noAtual);

    void rotacaoDireita(No *&pai);
    void rotacaoEsquerda(No *&pai);
    void rotacaoEsquerdaDireita(No *&pai);
    void rotacaoDireitaEsquerda(No *&pai);

    void realizarRotacao(No *&pai);
    void insereRecursivo(No *&noAtual, Aluno aluno, bool &cresceu);
};