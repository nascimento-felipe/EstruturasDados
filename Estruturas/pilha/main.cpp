#include <iostream>
#include <limits>
#include "pilha.h"

void pressKeyToContinue();

int main(void) {

    pilha pilha1;
    TipoItem novoItem;
    int opcao = 0;

    do {
        system("clear");
        std::cout << "Menu Inicial\n\nEscolha uma opção:\n"
        << " 1. Inserir novo item\n"
        << " 2. Remover Item\n"
        << " 3. Imprimir pilha\n"
        << " 4. Imprimir Tamanho da pilha\n"
        << "-1. Sair\n\n"
        << "Opção escolhida: ";
        std::cin >> opcao;

        if (opcao != -1) {
            switch (opcao) {
                case 1:
                    std::cout << "Digite um item para inserir na pilha: ";
                    std::cin >> novoItem;

                    pilha1.inserir(novoItem);
                    pressKeyToContinue();
                    break;
                case 2:
                    novoItem = pilha1.remover();
                    std::cout << "Item removido: " << novoItem << "\n";
                    pressKeyToContinue();
                    break;
                case 3:
                    pilha1.imprimir();
                    pressKeyToContinue();
                    break;
                case 4:
                    std::cout << "Tamanho da pilha: " << pilha1.getTamanho();
                    pressKeyToContinue();
                    break;
                default:
                    std::cout << "Opcao invalida. Tente novamente com um valor listado.\n";
                    pressKeyToContinue();
                    break;
            }
        }
    } while(opcao != -1);


    return EXIT_SUCCESS;
}

void pressKeyToContinue() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n\nAperte qualquer tecla pra continuar...";
    std::cin.get();
}