#include <iostream>


class Aluno {

    private:
    int ra;
    std::string nome;

    public:
    Aluno();
    Aluno(int r, std::string n);
    int obterRa();
    std::string obterNome();
};