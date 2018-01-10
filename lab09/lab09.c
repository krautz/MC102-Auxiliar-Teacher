#include "lab09.h"
#include <stdio.h>
#include <string.h>

int acha_registrador (char *assembly, int linha, int *indice_registrador);
void acha_operacao (char *assembly, char *operacao, int linha);
void acha_2o_registrador (char *assembly, int linha, int *indice_registrador, int flag);
int acha_imeditado (char *assembly, int linha, int flag);
int transforma_int (char *numero, int i);

int main () {
    int n_linhas, valor_registradores[12], indice_registrador, indice_2o_registrador, imediato, j, i, flag, n_operacoes;
    char assembly[151*51], operacao[4], aux;
    
    scanf("%d", &n_linhas);
    for (i = 0, n_operacoes = 0; i < n_linhas; i++) {
        scanf(" ");
        scanf("%c", &aux);
        if (aux != '#') {
            *(assembly + n_operacoes*51) = aux;
            j = 0;
            while (*(assembly + n_operacoes*51 + j) != '\n' && *(assembly + n_operacoes*51 + j) != '\0') {
                j++;
                scanf("%c", (assembly + n_operacoes*51 + j));
            }
            j++;
            *(assembly + n_operacoes*51 + j) = '\0';
            n_operacoes++;
        } else {
            while (aux != '\n' && aux != '\0') {
                scanf("%c", &aux);
            }
        }
    }
   i = 0;
   while (i < n_operacoes) {
           
        acha_operacao (assembly, operacao, i);
        flag = acha_registrador(assembly, i, &indice_registrador);
    
        if (strcmp (operacao, "MOV\0") == 0) {
            acha_2o_registrador (assembly, i, &indice_2o_registrador, flag);
            mov((valor_registradores + indice_registrador), (valor_registradores + indice_2o_registrador), &i);
        } else if (strcmp (operacao, "MOC\0") == 0) {
            imediato = acha_imeditado (assembly, i, flag);
            moc((valor_registradores + indice_registrador), imediato, &i);
        } else if (strcmp (operacao, "ADD\0") == 0) {
            acha_2o_registrador (assembly, i, &indice_2o_registrador, flag);
            add((valor_registradores + indice_registrador), (valor_registradores + indice_2o_registrador), &i);
        } else if (strcmp (operacao, "ADC\0") == 0) {
            imediato = acha_imeditado (assembly, i, flag);
            adc((valor_registradores + indice_registrador), imediato, &i);
        } else if (strcmp (operacao, "SUB\0") == 0) {
            acha_2o_registrador (assembly, i, &indice_2o_registrador, flag);
            sub((valor_registradores + indice_registrador), (valor_registradores + indice_2o_registrador), &i);
        } else if (strcmp (operacao, "SUC\0") == 0) {
            imediato = acha_imeditado (assembly, i, flag);
            suc((valor_registradores + indice_registrador), imediato, &i);
        } else if (strcmp (operacao, "JMP\0") == 0) {
            imediato = acha_imeditado (assembly, i, flag);
            jmp((valor_registradores + indice_registrador), imediato, &i);
        } else if (strcmp (operacao, "PTN\0") == 0) {
            ptn(*(valor_registradores + indice_registrador), &i);
        } else if (strcmp (operacao, "PTC\0") == 0) {
            ptc(*(valor_registradores + indice_registrador), &i);
        } 
   }
   
   printf("\n");

    return 0;
}

int acha_registrador (char *assembly, int linha, int *indice_registrador) {
    char registrador[4];
    int flag;
    
    *(registrador) = *(assembly + 51*linha + 4);
    *(registrador + 1) = *(assembly + 51*linha + 5);
    flag = 0;
    if( *(assembly + 51*linha + 6) != ' ' && *(assembly + 51*linha + 6) != '\n' && *(assembly + 51*linha + 6) != '\0') {
            flag = 1;
            *(registrador + 2) = *(assembly + 51*linha + 6);
            *(registrador + 3) = '\0';
            if (strcmp (registrador, "R10\0") == 0) {
                *indice_registrador = 9;
            } else if (strcmp (registrador, "R11\0") == 0) {
                *indice_registrador = 10;
            } else if (strcmp (registrador, "R12\0") == 0) {
                *indice_registrador = 11;
            }
    } else {
        *(registrador + 2) = '\0';
        if (strcmp (registrador, "R1\0") == 0) {
            *indice_registrador = 0;
        } else if (strcmp (registrador, "R2\0") == 0) {
            *indice_registrador = 1;
        } else if (strcmp (registrador, "R3\0") == 0) {
            *indice_registrador = 2;
        } else if (strcmp (registrador, "R4\0") == 0) {
            *indice_registrador = 3;
        } else if (strcmp (registrador, "R5\0") == 0) {
            *indice_registrador = 4;
        } else if (strcmp (registrador, "R6\0") == 0) {
            *indice_registrador = 5;
        } else if (strcmp (registrador, "R7\0") == 0) {
            *indice_registrador = 6;
        } else if (strcmp (registrador, "R8\0") == 0) {
            *indice_registrador = 7;
        } else if (strcmp (registrador, "R9\0") == 0) {
            *indice_registrador = 8;
        }
    }
    return flag;
}

void acha_2o_registrador (char *assembly, int linha, int *indice_registrador, int flag) {
    char registrador[4];
    
    *(registrador) = *(assembly + 51*linha + 7 + flag);
    *(registrador + 1) = *(assembly + 51*linha + 8 + flag);
    if( *(assembly + 51*linha + 9 + flag) != '\n' && *(assembly + 51*linha + 9 + flag) != '\0' && *(assembly + 51*linha + 9 + flag) != ' ') {
            *(registrador + 2) = *(assembly + 51*linha + 9 + flag);
            *(registrador + 3) = '\0';
            if (strcmp (registrador, "R10\0") == 0) {
                *indice_registrador = 9;
            } else if (strcmp (registrador, "R11\0") == 0) {
                *indice_registrador = 10;
            } else if (strcmp (registrador, "R12\0") == 0) {
                *indice_registrador = 11;
            }
    } else {
        *(registrador + 2) = '\0';
        if (strcmp (registrador, "R1\0") == 0) {
            *indice_registrador = 0;
        } else if (strcmp (registrador, "R2\0") == 0) {
            *indice_registrador = 1;
        } else if (strcmp (registrador, "R3\0") == 0) {
            *indice_registrador = 2;
        } else if (strcmp (registrador, "R4\0") == 0) {
            *indice_registrador = 3;
        } else if (strcmp (registrador, "R5\0") == 0) {
            *indice_registrador = 4;
        } else if (strcmp (registrador, "R6\0") == 0) {
            *indice_registrador = 5;
        } else if (strcmp (registrador, "R7\0") == 0) {
            *indice_registrador = 6;
        } else if (strcmp (registrador, "R8\0") == 0) {
            *indice_registrador = 7;
        } else if (strcmp (registrador, "R9\0") == 0) {
            *indice_registrador = 8;
        }
    }
}

int acha_imeditado (char *assembly, int linha, int flag) {
    char numero[10000];
    int i = 0, j = 7;
    while (*(assembly + linha*51 + j + flag) != '\n' && *(assembly + linha*51 + j + flag) != '\0' && *(assembly + linha*51 + j + flag) != ' ') {
        *(numero + i) = *(assembly + linha*51 + j + flag);
        i++;
        j++;
    }
    *(numero + i) = '\0';
    return transforma_int(numero, i);
}

int transforma_int (char *numero, int i) {
    int num = 0, pot_dez = 1;
    i--;
    while (i > 0) {
        num += pot_dez * (*(numero + i) - 48);
        pot_dez *= 10;
        i--;
    }
    if (*numero == '-') {
        num = num * (-1);
    } else {
        num += pot_dez * (*(numero) - 48);
    }
    return num;
}

void acha_operacao (char *assembly, char *operacao, int linha) {    
    *(operacao) = *(assembly + 51*linha);
    *(operacao + 1) = *(assembly + 51*linha + 1);
    *(operacao + 2) = *(assembly + 51*linha + 2);
    *(operacao + 3) = '\0';
    return;
}

void mov(int *rd, int *ro, int *pc) {
    (*pc)++;
    *rd = *ro;
    return;
}
    
void moc(int *rd, int n, int *pc) {
    (*pc)++;
    *rd = n;
    return;
}

void add(int *rd, int *ro, int *pc) {
    (*pc)++;
    (*rd) += *ro;
    return;
}

void adc(int *rd, int n, int *pc) {
    (*pc)++;
    (*rd) += n;
    return;
}

void sub(int *rd, int *ro, int *pc) {
    (*pc)++;
    (*rd) -= *ro;
    return;
}

void suc(int *rd, int n, int *pc) {
    (*pc)++;
    *(rd) -= n;
    return;
}

void jmp(int *rd, int n, int *pc) {
    if ((*rd) >= 0) {
        (*pc) += n;
    } else {
        (*pc)++;
    }
    return;
}

void ptc(int valor, int *pc) {
    (*pc)++;
    printf("%c", valor);
    return;
}

void ptn(int valor, int *pc) {
    (*pc)++;
    printf("%d ", valor);
    return;
}