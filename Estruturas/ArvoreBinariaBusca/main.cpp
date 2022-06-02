#include <iostream>
#include <limits>

#include "ArvBinaria.h"

void pressKeyToContinue();

int main() {

    ArvBinaria arvoreAlunos;
    int opcao, ra, impressao;
    std::string nome;
    bool busca = false;

    do {
        system("clear");
        std::cout << "Menu Inicial\n\nEscolha uma opção:\n"
        << " 1. Inserir aluno\n"
        << " 2. Remover aluno\n"
        << " 3. Buscar aluno\n"
        << " 4. Imprimir a arvore\n"
        << "-1. Sair\n\n"
        << "Opção escolhida: ";
        std::cin >> opcao;

        if (opcao != -1) {
            switch(opcao) {
                case 1: {
                    std::cout << "Digite o nome do aluno: ";
                    std::cin >> nome;
                    std::cout << "Digite o RA do aluno: ";
                    std::cin >> ra;
                    Aluno aluno(ra, nome);
                    if (arvoreAlunos.estaCheia()) {
                        std::cout << "A arvore esta cheia.\n"
                        << "Nao foi possivel inserir o elemento\n";
                    } else {
                        arvoreAlunos.inserir(aluno);
                    }
                    pressKeyToContinue();
                    break;
                }
                case 2: {
                    std::cout << "Digite o RA do aluno a ser removido: ";
                    std::cin >> ra;
                    Aluno aluno(ra, "");
                    arvoreAlunos.remover(aluno);
                    pressKeyToContinue();
                    break;
                }
                case 3: {
                    std::cout << "Digite o RA do aluno a ser buscado: ";
                    std::cin >> ra;
                    Aluno aluno(ra, "");
                    arvoreAlunos.buscar(aluno, busca);
                    if (busca) {
                        std::cout << "Aluno encontrado!"
                        << "Nome: " << aluno.obterNome()
                        << "\nRA: " << aluno.obterRa() << std::endl;
                    } else {
                        std::cout << "Aluno não encontrado\n";
                    }
                    pressKeyToContinue();
                    break;
                }
                case 4: {
                    system("clear");
                    std::cout << "Submenu de Impressão\n\n"
                    << " 1. Impressao em pré ordem\n"
                    << " 2. Impressao em ordem\n"
                    << " 3. Impressao em pós ordem\n\n"
                    << "Opção escolhida: ";
                    std::cin >> impressao;

                    switch(impressao) {
                        case 1: {
                            arvoreAlunos.imprimirPreOrdem(arvoreAlunos.obterRaiz());
                            pressKeyToContinue();
                            break;
                        }
                        case 2: {
                            arvoreAlunos.imprimirEmOrdem(arvoreAlunos.obterRaiz());
                            pressKeyToContinue();
                            break;
                        }
                        case 3: {
                            arvoreAlunos.imprimirPosOrdem(arvoreAlunos.obterRaiz());
                            pressKeyToContinue();
                            break;
                        }
                        default: {
                            std::cout << "Digite uma opção válida.";
                            pressKeyToContinue;
                        }
                    }
                    break;
                }
                default: {
                    std::cout << "Digite uma opção válida!";
                    pressKeyToContinue();
                }
            }
        }
    } while(opcao != -1);

    return EXIT_SUCCESS;
}

void pressKeyToContinue() {
    // ignora todos - na verdade, todos os N elementos do buffer, onde 
    // N são no máximo o valor do limite numércio do c++ - os inputs do 
    // buffer que não serão usados no programa.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n\nAperte qualquer tecla pra continuar...";
    std::cin.get();
}