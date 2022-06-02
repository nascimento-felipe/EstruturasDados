#include <iostream>


class Aluno {

    private:
    int ra;
    std::string nome;

    public:
    Aluno();
    Aluno(int ra, std::string nome);
    std::string obterNome();
    int obterRa();
};