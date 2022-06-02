#include <iostream>
#include "Aluno.h"

struct No {
    Aluno aluno;
    No* filhoEsquerda;
    No* filhoDireita;
};

class ArvBinaria {
    private:
    No* raiz;

    public: 
    ArvBinaria();
    ~ArvBinaria();
    void deletarArvore(No* noAtual);
    No* obterRaiz();
    bool estaVazio();
    bool estaCheia();
    void inserir(Aluno aluno);
    void remover(Aluno aluno);
    void buscar(Aluno &aluno, bool &busca);
    void imprimirPreOrdem(No* noAtual);
    void imprimirEmOrdem(No* noAtual);
    void imprimirPosOrdem(No* noAtual);
    void removerBusca(Aluno aluno, No *&noAtual);
    void deletarNo(No *&noAtual);
    void obterSucessor(Aluno &alunoSucessor, No* temp);
};