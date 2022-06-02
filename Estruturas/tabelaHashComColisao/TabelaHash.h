#include "Aluno.h"

class TabelaHash {

    private:
    int funcaoHash(Aluno aluno);
    int max_itens;
    int max_posicoes;
    int quantidade_itens;
    Aluno* estrutura;

    public:
    TabelaHash(int tam_vetor, int max);
    ~TabelaHash();
    bool estaCheia();
    int obterTamanho();
    void inserir(Aluno aluno);
    void deletar(Aluno aluno);
    void buscar(Aluno& aluno, bool& busca);
    void imprimir();

};