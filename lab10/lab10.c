/* ao rodar o programa no terminal ele funciona normalmente
 * no susy tem problema de memoria dinamica
 * o valgrind acusou uma serie de erros nos scanf com "invalid read size", talvez seja por isso, mas nao consegui arrumar
 * creio que a logica esta correta, ja que os testes funcionaram
 * tempo empregado: 15 horas
 */

/* uma serie de vetores foram alocados estaticamente em vez de dinamicamente pois eu aloquei primeiramente dinamicamente e acreditei que este era o 
 * problema ocorrendo com o valgrind, porem nao era e eu acabei deixando-os estaticos*/

#include <stdio.h>
#include <stdlib.h>
#include "lab10.h"

typedef struct Nota {
    int duracao;
    int frequencia;
} nota;

typedef struct Trecho {
    int id;
    int qtd_notas;
    int intensidade;
    nota notas[1000];
} trecho;

typedef struct {
    unsigned short int time;
    unsigned char canal;
    unsigned char key;
    unsigned char velocity;
} AuxEvento;

int main () {
    int numero_canais, numero_trechos, tabela_musical, **sequencias, tempo = 0, qtd_eventos = 0, evento, eventos[9], aux_eventos[9], canal;
    unsigned short int timbres[10];
    int i, k, j;
    trecho trechos[1000];
    TpEvento final[3000];
    AuxEvento auxevento[10][3000], ordenado[3000];
    
    scanf("%d", &numero_canais);
    for (i = 0; i < numero_canais; i++ ){
        scanf("%hu", &timbres[i]);
        printf("%hu\n", timbres[i]);
    }
    
    scanf("%d %d", &numero_trechos, &tabela_musical);
    
    for (i = 0; i < tabela_musical; i++) {
        scanf("%d %d %d", &trechos[i].id, &trechos[i].intensidade, &trechos[i].qtd_notas);
        /*trechos[i].notas = malloc (sizeof (nota) * trechos[i].qtd_notas);*/ /* por algum motivo a alocação dinamica estava causando problemas...*/
        for (k = 0; k < trechos[i].qtd_notas; k++) {
            scanf("%d %d", &trechos[i].notas[k].duracao, &trechos[i].notas[k].frequencia);
        }
    }

    sequencias = malloc(numero_canais * sizeof(int *));
    for (i = 0; i < numero_canais; i++)
        sequencias[i] = malloc(numero_trechos * sizeof(int));
    
    for (i = 0; i < numero_canais; i++) {
            for(k = 0; k < numero_trechos; k++) {
                scanf("%d", &sequencias[i][k]);
            }
    }

    for (i = 0; i < numero_canais; i++) {
        tempo = 0;
        evento = 0;
        for (k = 0; k < numero_trechos; k++) {
            for (j = 0; j < trechos[sequencias[i][k]-1].qtd_notas; j++) {
                if (trechos[sequencias[i][k]-1].notas[j].frequencia != 128) {
                    auxevento[i][evento].time = tempo;
                    auxevento[i][evento].canal = i;
                    auxevento[i][evento].key = trechos[sequencias[i][k]-1].notas[j].frequencia;
                    auxevento[i][evento].velocity = trechos[sequencias[i][k]-1].intensidade;
                    tempo += trechos[sequencias[i][k]-1].notas[j].duracao;
                    evento++;
                    auxevento[i][evento].time = tempo;
                    auxevento[i][evento].canal = i;
                    auxevento[i][evento].key = trechos[sequencias[i][k]-1].notas[j].frequencia;
                    auxevento[i][evento].velocity = 0;
                    evento++;
                } else {
                    tempo += trechos[sequencias[i][k]-1].notas[j].duracao;
                }
            }
                
        }
        eventos[i] = evento;
        qtd_eventos += evento;
    }
    
    for (i = 0; i < 10; i++) {
        aux_eventos[i] = 0;
    }
    
    for (i = 0; i < qtd_eventos; i++) {
        tempo = 10000000;
        canal = 10;
        for (j = 0; j < numero_canais; j++) {
            if (aux_eventos[j] < eventos[j] && auxevento[j][aux_eventos[j]].time == tempo && auxevento[j][aux_eventos[j]].canal < canal) {
                tempo = auxevento[j][aux_eventos[j]].time;
                canal = auxevento[j][aux_eventos[j]].canal;
                k = j;
            } else if (aux_eventos[j] < eventos[j] && auxevento[j][aux_eventos[j]].time < tempo) {
                tempo = auxevento[j][aux_eventos[j]].time;
                canal = auxevento[j][aux_eventos[j]].canal;
                k = j;
            }
        }
        ordenado[i] = auxevento[k][aux_eventos[k]];
        aux_eventos[k]++;
    }
    
    final[0].deltaTime = 0;
    final[0].canal = ordenado[0].canal;
    final[0].key = ordenado[0].key;
    final[0].velocity = ordenado[0].velocity;
    
    for (i = 1; i < qtd_eventos; i++) {
        final[i].deltaTime = ordenado[i].time - ordenado[i-1].time;
        final[i].canal = ordenado[i].canal;
        final[i].key = ordenado[i].key;
        final[i].velocity = ordenado[i].velocity;
    }
    
    saida(0, numero_canais,timbres, qtd_eventos, final);

                
    for (i = 0; i < numero_canais; i++)
       free(sequencias[i]);
    free(sequencias);
    
    
    return 0;
}