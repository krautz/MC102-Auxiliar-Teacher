#include <stdio.h>

typedef struct Muralha {
    int passagem[361];
    int barreira[361];
} muralha;

typedef struct res {
    int posicao;
    char E_S;
} resposta;

int labirinto (muralha muralhas[], int pos, int indice_muralha, int numero_muralhas, char modo, resposta solucao[], int *count);

int main () {
 
    muralha muralhas[11];
    resposta solucao[1000];
    int numero_muralhas, posicao_muralha, numero_digitos, posicao, passagem_barreira, caso = 0, i, conta_linhas = 0, contador = 0;
    char buffer[10000];
    
    scanf("%d", &numero_muralhas);
    scanf(" ");
    posicao_muralha = 0;
    for (conta_linhas = 0; conta_linhas != 2*numero_muralhas - 1; conta_linhas++) {
        fgets(buffer, sizeof(buffer), stdin);
        if (caso == 0) {
            caso = 1;
            for(i = 0, posicao = 0; sscanf(buffer+i, "%d%n", &passagem_barreira, &numero_digitos)!=EOF; i += numero_digitos, posicao++){
                muralhas[posicao_muralha].passagem[posicao] = passagem_barreira;
            }
            muralhas[posicao_muralha].passagem[posicao] = -1;
        } else {
            caso = 0;
            for(i = 0, posicao = 0; sscanf(buffer+i, "%d%n", &passagem_barreira, &numero_digitos)!=EOF; i += numero_digitos, posicao++){
                muralhas[posicao_muralha].barreira[posicao] = passagem_barreira;
            }
            muralhas[posicao_muralha].barreira[posicao] = -1;
            posicao_muralha++;
        }
    }

    
    i = muralhas[0].passagem[0];
    
    caso = labirinto (muralhas, muralhas[0].passagem[0], 0, numero_muralhas, 'd', solucao, &contador);
    if (!caso)
        caso = labirinto (muralhas, muralhas[0].passagem[0], 0, numero_muralhas, 'e', solucao, &contador);
    
    if (caso) {
        printf("E %d\n", i);
        for (i = contador - 1; i >= 0; i--)
            printf("%c %d\n", solucao[i].E_S, solucao[i].posicao);
    }
    
    return 0;
}

int labirinto (muralha muralhas[], int pos, int indice_muralha, int numero_muralhas, char modo, resposta solucao[], int *contador) {
    
    int i, flag;  
 
    if (pos == -1)
        pos = 359;
    if (pos == 360)
        pos = 0;
    
    if (indice_muralha == (numero_muralhas - 1))
        return 1;
    
    for (i = 0; muralhas[indice_muralha].barreira[i] != -1; i++)
        if (muralhas[indice_muralha].barreira[i] == pos)
            return 0;
    
    for (i = 0, flag = 0; muralhas[indice_muralha + 1].passagem[i] != -1 && flag == 0; i++)
        if (muralhas[indice_muralha + 1].passagem[i] == pos) {
            muralhas[indice_muralha + 1].passagem[i] = -5;
            flag = labirinto (muralhas, pos, indice_muralha + 1, numero_muralhas, 'd', solucao, contador);
            if (flag == 1) {
                solucao[*contador].posicao = pos;
                solucao[*contador].E_S = 'E';
                (*contador)++;
                return flag;
            }
            flag = labirinto (muralhas, pos, indice_muralha + 1, numero_muralhas, 'e', solucao, contador);
            if (flag == 1) {
                solucao[*contador].posicao = pos;
                solucao[*contador].E_S = 'E';
                (*contador)++;
                return flag;
            }
        }
    
    if (indice_muralha > 0) {
        for (i = 0; muralhas[indice_muralha].passagem[i] != -1 && flag == 0; i++)
             if (muralhas[indice_muralha].passagem[i] == pos) {
                muralhas[indice_muralha].passagem[i] = -5;
                flag = labirinto (muralhas, pos, indice_muralha - 1, numero_muralhas, 'd', solucao, contador);
                if (flag == 1) {
                    solucao[*contador].posicao = pos;
                    solucao[*contador].E_S = 'S';
                    (*contador)++;
                    return flag;
                }
                flag = labirinto (muralhas, pos, indice_muralha - 1, numero_muralhas, 'e', solucao, contador);
                if (flag == 1) {
                    solucao[*contador].posicao = pos;
                    solucao[*contador].E_S = 'S';
                    (*contador)++;
                    return flag;
                }
            }             
    }
    
    if (flag == 0 && modo == 'd')
        flag = labirinto (muralhas, pos + 1, indice_muralha, numero_muralhas, 'd', solucao, contador);
    
    if (flag == 0 && modo == 'e')
        flag = labirinto (muralhas, pos - 1, indice_muralha, numero_muralhas, 'e', solucao, contador);
    
    return flag;
    
}