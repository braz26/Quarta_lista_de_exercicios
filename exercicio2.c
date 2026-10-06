#include <stdio.h>

int main(void) {
    char sexo, olhos, cabelos;
    int idade, total = 0, qtd = 0;
    float salario;

    while (1) {
        printf("Idade (-1 para encerrar): ");
        scanf("%d", &idade);
        if (idade == -1) break;              /* habitante ficticio: fim */
        while (idade < 10 || idade > 100) {
            printf("Idade invalida! Digite entre 10 e 100: ");
            scanf("%d", &idade);
        }

        do {
            printf("Sexo (m/f): ");
            scanf(" %c", &sexo);
        } while (sexo != 'm' && sexo != 'f');

        do {
            printf("Cor dos olhos (a/v/c/p): ");
            scanf(" %c", &olhos);
        } while (olhos != 'a' && olhos != 'v' && olhos != 'c' && olhos != 'p');

        do {
            printf("Cor dos cabelos (l/c/p/r): ");
            scanf(" %c", &cabelos);
        } while (cabelos != 'l' && cabelos != 'c' && cabelos != 'p' && cabelos != 'r');

        do {
            printf("Salario: ");
            scanf("%f", &salario);
        } while (salario < 0);

        total++;
        if (sexo == 'f' && idade >= 18 && idade <= 35 && olhos == 'c' && cabelos == 'c')
            qtd++;
    }

    if (total == 0)
        printf("Nenhum habitante cadastrado.\n");
    else
        printf("Porcentagem: %.2f%%\n", (float)qtd * 100 / total);
    return 0;
}