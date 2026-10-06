#include <stdio.h>
#include <ctype.h>

#define N 100

int main(void) {
    int i, idade;
    char nota;
    int qA = 0, qB = 0, qC = 0, qD = 0, qE = 0;
    int somaIdadeD = 0, maiorA = -1, maiorD = -1, maiorE = -1;

    for (i = 1; i <= N; i++) {
        printf("Espectador %d - idade: ", i);
        scanf("%d", &idade);
        do {
            printf("Nota (A/B/C/D/E): ");
            scanf(" %c", &nota);
            nota = toupper((unsigned char)nota);
        } while (nota < 'A' || nota > 'E');

        switch (nota) {
            case 'A': qA++; if (idade > maiorA) maiorA = idade; break;
            case 'B': qB++; break;
            case 'C': qC++; break;
            case 'D': qD++; somaIdadeD += idade; if (idade > maiorD) maiorD = idade; break;
            case 'E': qE++; if (idade > maiorE) maiorE = idade; break;
        }
    }

    printf("\nRespostas otimo: %d\n", qA);

    float difBC = (float)(qB > qC ? qB - qC : qC - qB) * 100 / N;
    printf("Diferenca percentual entre bom e regular: %.2f pontos percentuais\n", difBC);

    if (qD > 0) printf("Media de idade de quem respondeu ruim: %.2f\n", (float)somaIdadeD / qD);
    else        printf("Ninguem respondeu ruim.\n");

    printf("Percentual de pessimo: %.2f%%\n", (float)qE * 100 / N);
    if (qE > 0) printf("Maior idade que respondeu pessimo: %d\n", maiorE);
    else        printf("Ninguem respondeu pessimo.\n");

    if (maiorA >= 0 && maiorD >= 0)
        printf("Diferenca entre maior idade de otimo e de ruim: %d\n",
               maiorA > maiorD ? maiorA - maiorD : maiorD - maiorA);
    else
        printf("Nao ha respostas otimo e ruim suficientes para calcular a diferenca.\n");
    return 0;
}