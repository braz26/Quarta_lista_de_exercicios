#include <stdio.h>

int main(void) {
    int n, i, total = 0, impressos = 0;

    do {
        printf("Digite um numero positivo: ");
        scanf("%d", &n);
    } while (n <= 0);

    for (i = 1; i <= n; i++)
        if (n % i == 0) total++;

    printf("Os divisores do numero %d sao: ", n);
    for (i = 1; i <= n; i++) {
        if (n % i == 0) {
            impressos++;
            printf("%d", i);
            if (impressos < total - 1)       printf(", ");
            else if (impressos == total - 1) printf(" e ");
        }
    }
    printf(".\n");
    return 0;
}