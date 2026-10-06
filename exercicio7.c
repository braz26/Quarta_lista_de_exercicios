#include <stdio.h>
#include <ctype.h>

#define MIN 50
#define MAX 300
#define NJOG 5

/* ATENCAO: a tabela do enunciado nao foi enviada. Troque pelos nomes reais. */
const char *jogadoras[NJOG] = {
    "Marta Vieira", "Formiga", "Cristiane", "Debinha", "Megan Rapinoe"
};
#define IDX_MARTA 0   /* posicao de Marta Vieira na tabela acima */

int main(void) {
    char nome[MAX][50], sexo[MAX];
    int idade[MAX], voto[MAX];
    int votos[NJOG] = {0};
    int n = 0, i, j;
    char continuar = 's';

    while (n < MAX && (n < MIN || continuar == 's' || continuar == 'S')) {
        printf("\n--- Entrevistado %d ---\n", n + 1);
        printf("Nome: ");
        scanf(" %49[^\n]", nome[n]);

        do {
            printf("Idade (maior que 12): ");
            scanf("%d", &idade[n]);
        } while (idade[n] <= 12);

        do {
            printf("Sexo (M/F): ");
            scanf(" %c", &sexo[n]);
            sexo[n] = toupper((unsigned char)sexo[n]);
        } while (sexo[n] != 'M' && sexo[n] != 'F');

        for (j = 0; j < NJOG; j++) printf("  %d - %s\n", j + 1, jogadoras[j]);
        do {
            printf("Voto (1 a %d): ", NJOG);
            scanf("%d", &voto[n]);
        } while (voto[n] < 1 || voto[n] > NJOG);
        voto[n]--;
        votos[voto[n]]++;
        n++;

        if (n >= MIN && n < MAX) {
            printf("Deseja continuar? (s/n): ");
            scanf(" %c", &continuar);
        }
    }

    printf("\n===== RELATORIOS =====\n\nVotos por jogadora:\n");
    int maior = 0;
    for (j = 0; j < NJOG; j++) {
        printf("  %s: %d\n", jogadoras[j], votos[j]);
        if (votos[j] > maior) maior = votos[j];
    }

    printf("\nJogadora(s) mais votada(s) (%d votos):\n", maior);
    for (j = 0; j < NJOG; j++)
        if (votos[j] == maior) printf("  %s\n", jogadoras[j]);

    const char *tituloSexo[2] = {"Masculino", "Feminino"};
    const char sexos[2] = {'M', 'F'};
    printf("\nParticipantes:\n");
    for (j = 0; j < 2; j++) {
        printf(" Sexo %s - maiores de idade:\n", tituloSexo[j]);
        for (i = 0; i < n; i++)
            if (sexo[i] == sexos[j] && idade[i] >= 18)
                printf("   %s, %d anos, %c\n", nome[i], idade[i], sexo[i]);
        printf(" Sexo %s - menores de idade:\n", tituloSexo[j]);
        for (i = 0; i < n; i++)
            if (sexo[i] == sexos[j] && idade[i] < 18)
                printf("   %s, %d anos, %c\n", nome[i], idade[i], sexo[i]);
    }

    printf("\nMaiores de idade que votaram em %s:\n", jogadoras[IDX_MARTA]);
    for (i = 0; i < n; i++)
        if (idade[i] >= 18 && voto[i] == IDX_MARTA) printf("  %s\n", nome[i]);

    int mulheres = 0;
    for (i = 0; i < n; i++) if (sexo[i] == 'F') mulheres++;
    printf("\nMulheres na pesquisa: %d\n", mulheres);
    return 0;
}