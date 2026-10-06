#include <stdio.h>
#include <ctype.h>

int main(void) {
    int mes, ano, dias;
    char resp;

    do {
        do {
            printf("Mes (1 a 12): ");
            scanf("%d", &mes);
        } while (mes < 1 || mes > 12);
        do {
            printf("Ano (positivo): ");
            scanf("%d", &ano);
        } while (ano <= 0);

        if (mes == 2) {
            int bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
            dias = bissexto ? 29 : 28;
        } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            dias = 30;
        } else {
            dias = 31;
        }
        printf("O mes %02d/%d tem %d dias.\n", mes, ano, dias);

        printf("VOCE DESEJA OUTRAS ENTRADAS (S/?)? ");
        scanf(" %c", &resp);
    } while (toupper((unsigned char)resp) == 'S');
    return 0;
}