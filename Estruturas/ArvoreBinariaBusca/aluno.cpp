#include "Aluno.h"


    Aluno::Aluno() {
        ra = -1;
        nome = " ";
    }

    Aluno::Aluno(int ra, std::string nome) {
        this->ra = ra;
        this->nome = nome;
    }

    int Aluno::obterRa() {
        return ra;
    }

    std::string Aluno::obterNome() {
        return nome;
    }