#include <iostream>
#include <limits>
#include "fila.h"

void pressKeyToContinue();

int main(void) {

    Fila fila1;
    int opcao;
    TipoItem item;

    do {
        system("clear");
        std::cout << "Menu Inicial\n\nEscolha uma opção:\n"
        << " 1. Inserir novo item\n"
        << " 2. Remover Item\n"
        << " 3. Imprimir fila\n"
        << "-1. Sair\n\n"
        << "Opção escolhida: ";
        std::cin >> opcao;

        if (opcao != -1) {

            std::cout << "\n\n";
            switch (opcao) {
                case 1:
                    std::cout << "Digite um item para inserir na pilha: ";
                    std::cin >> item;

                    fila1.inserir(item);
                    pressKeyToContinue();
                    break;
                case 2:
                    item = fila1.remover();
                    std::cout << "Item removido: " << item << "\n";
                    pressKeyToContinue();
                    break;
                case 3:
                    fila1.imprimir();
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