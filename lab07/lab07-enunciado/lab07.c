#include <stdio.h>
#include "lab07.h"
#include <string.h>

int main() {
    char texto[51][251], palavras[11][21], marcVetor[N_MARCADORES][TAM_MARCADORES], palavra[21], imprime[5000][21];
    int num_frases, i, j, num_palavras, relacao_temporal[11][12], inicio, ocorrencias[5000];
    int media, maior_media, indice, total, flag, n_imprime = 0, achou;
    
    strcpy (marcVetor[0], "ontem\0");
    strcpy (marcVetor[1], "hoje\0");
    strcpy (marcVetor[2], "amanha\0");
    strcpy (marcVetor[3], "agora\0");
    strcpy (marcVetor[4], "logo\0");
    strcpy (marcVetor[5], "cedo\0");
    strcpy (marcVetor[6], "tarde\0");
    strcpy (marcVetor[7], "breve\0");
    strcpy (marcVetor[8], "nunca\0");
    strcpy (marcVetor[9], "sempre\0");
    strcpy (marcVetor[10], "jamais\0");
    
    for (i = 0; i < 5000; i++) {
        ocorrencias[i] = 0;
    }
    
    for (i=0; i < 5000; i ++) {
        for(j = 0; j < 21; j++) {
            imprime[i][j] = '\0';
        }
    }
    
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 12; j++) {
            relacao_temporal[i][j] = 0;
        }
    }
    
    scanf("%d", &num_frases);
    
    for (i = 0; i < num_frases; i++ ) {
        scanf (" ");
        j = 0;
        do { 
            scanf ("%c", &texto[i][j]);
        } while (texto[i][j++] != '\n');
        texto[i][j] = '\0';
    }
    
    for (i = 0; i < num_frases; i++)
        minusculas(texto[i]);
    
    scanf("%d", &num_palavras);
    for(i = 0; i < num_palavras; i++) {
        scanf(" ");
        j = 0;
        do {
            scanf("%c", &palavras[i][j]);
        } while (palavras[i][j++] != '\n');
        palavras[i][j] = '\0';
    }
    
    for (i = 0; i < num_palavras; i++)
        minusculas(palavras[i]);
    
    
    for (i = 0; i < num_frases; i++) {
        for (j = 0; j < num_palavras; j++ ) {
            inicio = 0;
            flag = 1;
            achou = 0;
            while (inicio != -1) {
                inicio = proxima_palavra(texto[i], palavra, inicio);
                if (palavra[0] != '\0') {
                    flag = strcmp (palavra, palavras[j]);
                    if (flag == 0) {
                        relacao_temporal[j][11]++;
                        achou++;
                    }
                }
            }
            if (achou) {
                inicio = 0;
                while (inicio != -1) {
                    inicio = proxima_palavra (texto[i], palavra, inicio);
                    if (palavra[0] != '\0') {
                        indice = verifica_marcador (marcVetor, palavra);
                        if (indice != -1)
                            relacao_temporal[j][indice] += achou;
                    }
                }
            }
        }
    }
    
    for (i = 0; i < num_palavras; i++) {
        total = 0;
        for(j = 0; j < 11; j++) {
            total += relacao_temporal[i][j];
        }
        if (total == 0)
            printf("<%s> nao se relacionou com nenhum marcador temporal.\n", palavras[i]);
        else {
            maior_media = 0;
            for (j = 0; j < 11; j++) {
                media = (relacao_temporal[i][j] * 100) / relacao_temporal[i][11];
                if (media > maior_media)
                    maior_media = media;
            }
            for (j = 0; j < 11; j++) {
                media = (relacao_temporal[i][j] * 100) / relacao_temporal[i][11];
                if (media == maior_media) {
                    printf("<%s> se relaciona com <%s> em %d %% das ocorrencias.\n", palavras[i], marcVetor[j], media);
                }
                    
            }
        }
    }
    
    for (i = 0; i < num_frases; i++) {
        inicio = 0;
        while (inicio != -1) {
            inicio = proxima_palavra (texto[i], palavra, inicio);
            if (palavra[0] != '\0') {
                flag = 1;
                for (j = 0; j < n_imprime && flag != 0; j++)
                    flag = strcmp (imprime[j], palavra);
                if (flag == 0) {
                    j--;
                    ocorrencias[j]++;
                } else {
                    strcpy (imprime[j], palavra);
                    ocorrencias[j]++;
                    n_imprime++;
                }
            }
        }
    }
    
    for (i = 0; i < n_imprime; i++) {
        printf("%s ", imprime[i]);
    }
    printf("\n");
    for (i = 0; i < n_imprime; i++) {
        printf("%d ", ocorrencias[i]);
    }
    printf("\n");
        
    
    return 0;
}

int proxima_palavra(char frase[], char palavra[], int inicio) {
    char aux = frase[inicio++];
    int i = 0;
    while (aux != '\n' && aux != ' ' && aux != '\0') {
        palavra[i++] = aux;
        aux = frase[inicio++];
    }
    palavra[i] = '\0';
    if (aux == '\n' || aux == '\0')
        inicio = -1;
    return inicio;
}

int verifica_marcador(char marcVetor[][TAM_MARCADORES], char palavra[]) {
    int i = 0, flag = 1;
    for (i = 0; i < N_MARCADORES && flag != 0; i++) 
        flag = strcmp (marcVetor[i], palavra);
    
    if (flag != 0)
        i = -1;
    else
        i--;
    
    return i;
}