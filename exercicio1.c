#include <stdio.h>

int main(void) {
    int opcao, quantidade;
    double total = 0.0;

    do {
        printf("\nFRUTAS DISPONIVEIS\n");
        printf("1 - Abacaxi: R$ 5,00 a unidade\n");
        printf("2 - Maca: R$ 1,00 a unidade\n");
        printf("3 - Pera: R$ 4,00 a unidade\n");
        printf("0 - Finalizar compra\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            return 1;
        }

        if (opcao == 0) {
            break;
        }
        if (opcao < 1 || opcao > 3) {
            printf("Opcao invalida.\n");
            continue;
        }

        printf("Quantidade: ");
        if (scanf("%d", &quantidade) != 1) {
            return 1;
        }
        if (quantidade <= 0) {
            printf("A quantidade deve ser maior que zero.\n");
            continue;
        }

        if (opcao == 1) {
            total += 5.0 * quantidade;
        } else if (opcao == 2) {
            total += 1.0 * quantidade;
        } else {
            total += 4.0 * quantidade;
        }
    } while (1);

    printf("Valor total da compra: R$ %.2f\n", total);
    return 0;
}