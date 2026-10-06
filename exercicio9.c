#include <stdio.h>
#include <ctype.h>

#define N 10

int main(void) {
    char nome[50], sexo;
    float altura, peso;
    int nH = 0, nM = 0, i;
    float somaAltH = 0, somaAltM = 0, somaPesoH = 0, somaPesoM = 0;

    for (i = 1; i <= N; i++) {
        printf("\nPessoa %d - nome: ", i);
        scanf(" %49[^\n]", nome);
        do {
            printf("Sexo (M/F): ");
            scanf(" %c", &sexo);
            sexo = toupper((unsigned char)sexo);
        } while (sexo != 'M' && sexo != 'F');
        do {
            printf("Altura (m): ");
            scanf("%f", &altura);
        } while (altura <= 0);
        do {
            printf("Peso (kg): ");
            scanf("%f", &peso);
        } while (peso <= 0);

        if (sexo == 'M') { nH++; somaAltH += altura; somaPesoH += peso; }
        else             { nM++; somaAltM += altura; somaPesoM += peso; }
    }

    printf("\nHomens: %d\nMulheres: %d\n", nH, nM);
    if (nH > 0) printf("Altura media dos homens: %.2f m\nPeso medio dos homens: %.2f kg\n", somaAltH / nH, somaPesoH / nH);
    else        printf("Sem homens no grupo: medias masculinas indisponiveis.\n");
    if (nM > 0) printf("Altura media das mulheres: %.2f m\nPeso medio das mulheres: %.2f kg\n", somaAltM / nM, somaPesoM / nM);
    else        printf("Sem mulheres no grupo: medias femininas indisponiveis.\n");
    printf("Altura media do grupo: %.2f m\nPeso medio do grupo: %.2f kg\n",
           (somaAltH + somaAltM) / N, (somaPesoH + somaPesoM) / N);
    return 0;
}