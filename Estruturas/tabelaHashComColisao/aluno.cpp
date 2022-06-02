#include "Aluno.h"


    Aluno::Aluno() {
        ra = -1;
        nome = " ";
    }

    Aluno::Aluno(int r, std::string n) {
        ra = r;
        nome = n;
    }

    int Aluno::obterRa() {
        return ra;
    }

    std::string Aluno::obterNome() {
        return nome;
    }