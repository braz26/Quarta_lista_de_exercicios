#include <stdio.h>

int main(void) {
    int n, i;
    unsigned long long a = 0, b = 1, prox;

    do {
        printf("Digite n (inteiro >= 0, ate 93): ");
        scanf("%d", &n);
    } while (n < 0 || n > 93);   /* F(93) e o maior que cabe em 64 bits sem sinal */

    if (n == 0) {
        printf("F(0) = 0\n");
        return 0;
    }
    for (i = 2; i <= n; i++) {
        prox = a + b;
        a = b;
        b = prox;
    }
    printf("F(%d) = %llu\n", n, b);
    return 0;
}