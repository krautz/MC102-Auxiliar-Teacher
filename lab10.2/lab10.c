#include <stdlib.h>
#include "lab10.h"

int main () {
    
    TpEvento *eventos, key;
    int numero_eventos = 0, flag = 1, instrumento, nota, intensidade, inicio, duracao;
    int i, j;
    
    eventos = malloc (sizeof(TpEvento));
    
    while (flag) {
        scanf("%d %d %d %d %d", &instrumento, &nota, &intensidade, &inicio, &duracao);
        if (instrumento != 0 || nota != 0 || intensidade != 0 || inicio !=0 || duracao != 0) {
            eventos = realloc (eventos, (2 + numero_eventos) *sizeof (TpEvento));
            eventos[numero_eventos].instante = inicio;
            eventos[numero_eventos].instrumento = instrumento;
            eventos[numero_eventos].nota = nota;
            eventos[numero_eventos].intensidade = intensidade;
            eventos[numero_eventos + 1].instante = (inicio + duracao);
            eventos[numero_eventos + 1].instrumento = instrumento;
            eventos[numero_eventos + 1].nota = nota;
            eventos[numero_eventos + 1].intensidade = 0;
            numero_eventos += 2;
        } else {
            flag = 0;
        }
    }
    
    /*insertion sort*/
    for (j = 1; j < numero_eventos; j++) {
        key = eventos[j];
        for (i = j - 1, flag = 1; i >= 0 && flag; i--) {
            if (key.instante < eventos[i].instante) {
                eventos[i+1] = eventos[i];
            } else if (key.instante == eventos[i].instante) {
                if (key.instrumento < eventos[i].instrumento) {
                    eventos[i+1] = eventos[i];
                } else if (key.instrumento == eventos[i].instrumento) {
                    if (key.nota < eventos[i].nota) {
                        eventos[i+1] = eventos[i];
                    } else if (key.nota == eventos[i].nota) {
                        if (key.intensidade < eventos[i].intensidade) {
                            eventos[i+1] = eventos[i];
                        } else {
                            flag = 0;
                        }
                    } else {
                        flag = 0;
                    }
                } else {
                    flag = 0;
                }
            } else {
                flag = 0;
            }
        }
        if (flag == 0)
            i++;
        eventos[i+1] = key;
    }
    
    saida(0, numero_eventos, eventos);
    
    free(eventos);

    return 0;
}