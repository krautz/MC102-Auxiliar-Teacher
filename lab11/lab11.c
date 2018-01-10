#include <stdio.h>

int expulsa_gremlins (int gremlins);

int main () {
    int numero_inicial;

    scanf("%d", &numero_inicial);

    if (expulsa_gremlins(numero_inicial)) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }
    
    return 0;
}

int expulsa_gremlins (int gremlins) {
    int retorno = 2, aux, decimal, unidade;
    if (gremlins == 42) {
        retorno = 1;
    } else if (gremlins < 42) {
        retorno = 0;
    }
    
    if (retorno != 1 && gremlins > 42 && gremlins % 2 == 0) {
        retorno = expulsa_gremlins(gremlins/2);
    }
    if (retorno != 1 && gremlins > 42 && (gremlins % 3 == 0 || gremlins % 4 == 0)) {
        aux = gremlins;
        while (aux / 100 > 0) {
            aux -= (aux / 100) * 100;
        }
        decimal = aux/10;
        unidade = aux%10;
        if (unidade * decimal != 0) {
            retorno = expulsa_gremlins (gremlins - (decimal * unidade));
        }
    }
    if (retorno != 1 && gremlins > 42 && (gremlins % 5 == 0)) {
        retorno = expulsa_gremlins (gremlins - 42);
    }
    if (retorno == 2) {
        retorno = 0;
    }
    return retorno;
}
        