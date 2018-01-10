#include <stdio.h>

int main () {
    long int primeiro_termo_PG, primeiro_termo_PA, segundo_termo_PA, valor_desejado, total_desta_nota, nota_atual, cont = 0, flag = 0, mode = 1;
    
    scanf("%ld %ld %ld %ld", &primeiro_termo_PG, &primeiro_termo_PA, &segundo_termo_PA, &valor_desejado);
    
    total_desta_nota = primeiro_termo_PG;

    while (valor_desejado != 0) {
        if (total_desta_nota > valor_desejado || flag) {
            if (mode == 1) {
                if (flag == 0) {
                    total_desta_nota /= primeiro_termo_PG;
                    if (total_desta_nota == 1) {
                        mode = 2;
                    }
                }
                if (((total_desta_nota - primeiro_termo_PA) % (segundo_termo_PA - primeiro_termo_PA) == 0) && total_desta_nota >= primeiro_termo_PA) {
                    total_desta_nota /= primeiro_termo_PG;
                    flag = 1;
                } else {
                    flag = 0;
                    mode = 2;
                    nota_atual = total_desta_nota;
                }
            } else {
                printf ("%ld %ld\n", cont, nota_atual);
                valor_desejado -= (total_desta_nota - nota_atual);
                total_desta_nota = primeiro_termo_PG;
                cont = 0;
                mode = 1;
            }
        } else if (mode == 1) {
            total_desta_nota *= primeiro_termo_PG;
        } else {
            total_desta_nota += nota_atual;
            cont++;
        }
    }
    return 0;
}