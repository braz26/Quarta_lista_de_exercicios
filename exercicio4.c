#include <stdio.h>
#include <ctype.h>

#define N 50

int main(void) {
    int cont[3][3] = {{0}};      /* linhas: elevador A,B,C | colunas: periodo M,V,N */
    char elev, per;
    const char *nomeElev = "ABC", *nomePer = "MVN";
    const char *textoPer[3] = {"matutino", "vespertino", "noturno"};
    int i, j;

    for (i = 1; i <= N; i++) {
        do {
            printf("Morador %d - elevador mais usado (A/B/C): ", i);
            scanf(" %c", &elev);
            elev = toupper((unsigned char)elev);
        } while (elev < 'A' || elev > 'C');
        do {
            printf("Morador %d - periodo (M/V/N): ", i);
            scanf(" %c", &per);
            per = toupper((unsigned char)per);
        } while (per != 'M' && per != 'V' && per != 'N');

        cont[elev - 'A'][per == 'M' ? 0 : per == 'V' ? 1 : 2]++;
    }

    int totElev[3] = {0}, totPer[3] = {0};
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) { totElev[i] += cont[i][j]; totPer[j] += cont[i][j]; }

    /* indices do maior e menor periodo / elevador */
    int pMax = 0, pMin = 0, eMax = 0, eMin = 0;
    for (i = 1; i < 3; i++) {
        if (totPer[i]  > totPer[pMax])  pMax = i;
        if (totPer[i]  < totPer[pMin])  pMin = i;
        if (totElev[i] > totElev[eMax]) eMax = i;
        if (totElev[i] < totElev[eMin]) eMin = i;
    }

    /* (a) periodo mais usado e o elevador onde ele mais ocorre */
    int eDoPeriodo = 0;
    for (i = 1; i < 3; i++) if (cont[i][pMax] > cont[eDoPeriodo][pMax]) eDoPeriodo = i;
    printf("\n1) Periodo mais usado: %s (%d usos). Elevador com mais usos nesse periodo: %c\n",
           textoPer[pMax], totPer[pMax], nomeElev[eDoPeriodo]);

    /* (b) elevador mais frequentado e seu periodo de pico */
    int pPico = 0;
    for (j = 1; j < 3; j++) if (cont[eMax][j] > cont[eMax][pPico]) pPico = j;
    printf("2) Elevador mais frequentado: %c (%d usos). Maior fluxo no periodo %s\n",
           nomeElev[eMax], totElev[eMax], textoPer[pPico]);

    /* (c) diferenca percentual entre periodo mais e menos usado */
    printf("3) Diferenca entre periodo mais usado (%s) e menos usado (%s): %.2f pontos percentuais\n",
           textoPer[pMax], textoPer[pMin], (float)(totPer[pMax] - totPer[pMin]) * 100 / N);

    /* (d) elevador de media utilizacao */
    int eMed = 3 - eMax - eMin;
    printf("4) Elevador de media utilizacao: %c = %.2f%% do total\n",
           nomeElev[eMed], (float)totElev[eMed] * 100 / N);
    (void)nomePer;
    return 0;
}