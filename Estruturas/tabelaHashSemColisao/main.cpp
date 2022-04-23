#include <iostream>
#include <stdlib.h>
#include <limits>
#include "TabelaHash.h"

void pressKeyToContinue();

int main(void) {
    int tamanhoVetor;
    int max;

    std::cout << "Digite o tamanho da Hash Table: ";
    std::cin >> tamanhoVetor;
    std::cout << "Digite o numero maximo de elementos: ";
    std::cin >> max;

    std::cout << "O fator de carga eh : " << ((float) max / (float) tamanhoVetor) 
    << "\n";

    pressKeyToContinue();

    TabelaHash alunoHash(tamanhoVetor, max);
    int opcao;
    int ra;
    std::string nome;
    bool busca;

    do {
        system("clear");
        std::cout << "Menu principal - Hash Table\n"
        << " 1. Inserir um elemento\n"
        << " 2. Remover um elemento\n"
        << " 3. Buscar um elemento\n"
        << " 4. Imprimir a Hash Table\n"
        << "-1. Sair\n\n"
        << "Escolha uma opcao: ";
        std::cin >> opcao;

        if (opcao != -1) {
            switch (opcao) {
                case 1:{
                    std::cout << "\n\n Digite o RA do aluno: ";
                    std::cin >> ra;
                    std::cout << " Digite o nome do aluno: ";
                    std::cin >> nome;

                    Aluno aluno(ra, nome);

                    alunoHash.inserir(aluno);
                    pressKeyToContinue();
                    break;
                }
                case 2: {
                    std::cout << "\n\n Digite o RA do aluno que vai ser removido: ";
                    std::cin >> ra;
                    Aluno aluno(ra, " ");
                    alunoHash.deletar(aluno);
                    pressKeyToContinue();
                    break;
                }
                case 3: {
                    std::cout << "\n\n Digite o RA do aluno a ser buscado: ";
                    std::cin >> ra;

                    Aluno aluno(ra, " ");
                    
                    alunoHash.buscar(aluno, busca);

                    if (busca) {
                        std::cout << " Aluno encontrado: \n"
                        << "  RA: " << aluno.obterRa()
                        << "\n  Nome: " << aluno.obterNome();
                    } else {
                        std::cout << " Aluno nao encontrado!\n";
                    }
                    pressKeyToContinue();
                    break;
                }
                case 4:
                    alunoHash.imprimir();
                    pressKeyToContinue();
                    break;
                default:
                    std::cout << "\n\n Digite uma opcao valida!\n";
                    pressKeyToContinue();
                    break;
            }
        }
    } while (opcao != -1);


    return EXIT_SUCCESS; 
}

void pressKeyToContinue() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n\nAperte qualquer tecla pra continuar...";
    std::cin.get();
}