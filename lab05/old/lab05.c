#include <stdio.h>

int main () {
    int direcao_macho[3000], direcao_femea[3000], tamanho_passos_macho[3000], tamanho_passos_femea[3000], tamanho_macho, tamanho_femea, i, j, flag = 1;
    int dir[8], tamanho_1a_fase, rotacao, checa_rotacao;
    float proporcao;
    int tamanho_2a_fase_f, tamanho_2a_fase_m, angulo_m, angulo_f;
    int flag_1a_fase, flag_2a_fase, flag_3a_fase;
    int direcao_macho_reverso[3000], tamanho_passos_macho_reverso[3000], reverso = 0, reverte, pos;

    scanf("%d %d", &tamanho_femea, &tamanho_macho);
    for (i = 0; i < tamanho_femea; i++) {
        scanf("%d %d", &direcao_femea[i], &tamanho_passos_femea[i]);
    }
    for (i = 0; i < tamanho_macho; i++) {
        scanf("%d %d", &direcao_macho[i], &tamanho_passos_macho[i]);
    }
    for (i = 0; i < 8; i++) {
        dir[i] = 0;
    }
    
    /* determinando os passos da 1a danca */
    for (tamanho_1a_fase = 0; flag; tamanho_1a_fase++) {
        dir[direcao_femea[tamanho_1a_fase]] += tamanho_passos_femea[tamanho_1a_fase];
        if (dir[0] == dir[4] && dir[1] == dir[5] && dir[2] == dir[6] && dir[3] == dir[7]) {
            flag = 0;
        }
    }
    /*checando compatibilidade com o macho*/    
    proporcao = ((float) tamanho_passos_femea[0]) / tamanho_passos_macho[0];
    rotacao = direcao_femea[0] - direcao_macho[0];
    
    for (i = 0, flag_1a_fase = 1; i < tamanho_1a_fase && flag_1a_fase; i++) {
        checa_rotacao = direcao_macho[i] + rotacao;
        if (checa_rotacao < 0) {
            checa_rotacao += 8;
        } else if (checa_rotacao > 7) {
            checa_rotacao -= 8;
        }
        if (!(((float)tamanho_passos_macho[i] * proporcao) == ((float)tamanho_passos_femea[i]) && checa_rotacao == direcao_femea[i] && tamanho_passos_macho[i] > tamanho_passos_femea[i])) {
            flag_1a_fase = 0;
        }
    }
    
    if (flag_1a_fase == 0) {
        reverso = 1;
    } else {
    
        for (tamanho_2a_fase_f = tamanho_1a_fase + 1, flag_2a_fase = 1; flag_2a_fase; tamanho_2a_fase_f++) {
            checa_rotacao = direcao_femea[tamanho_2a_fase_f - 1] + 4;
            if (checa_rotacao > 7)
                checa_rotacao -= 8;
            if (direcao_femea[tamanho_2a_fase_f] == checa_rotacao && tamanho_passos_femea[tamanho_2a_fase_f] > tamanho_passos_femea[tamanho_2a_fase_f - 1]) {
                flag_2a_fase = 0;
            }
        }
        
        
        for (tamanho_2a_fase_m = tamanho_1a_fase + 1, flag_2a_fase = 1; flag_2a_fase; tamanho_2a_fase_m++) {
            checa_rotacao = direcao_macho[tamanho_2a_fase_m - 1] + 4;
            if (checa_rotacao > 7)
                checa_rotacao -= 8;
            if (direcao_macho[tamanho_2a_fase_m] == checa_rotacao && tamanho_passos_macho[tamanho_2a_fase_m] > tamanho_passos_macho[tamanho_2a_fase_m - 1]) {
                flag_2a_fase = 0;
            }
        }
        
        if (!(tamanho_2a_fase_f >= tamanho_2a_fase_m)) {
            reverso = 1;
        } else {
            if (tamanho_macho - tamanho_2a_fase_m == tamanho_femea - tamanho_2a_fase_f) {
                proporcao = ((float) tamanho_passos_femea[tamanho_2a_fase_f]) / tamanho_passos_macho[tamanho_2a_fase_m];
                for (i = tamanho_2a_fase_f + 1, j = tamanho_2a_fase_m + 1, flag_3a_fase = 1; flag_3a_fase && i < tamanho_femea && j < tamanho_macho; i++, j++) {
                    if (((float) tamanho_passos_macho[j] * proporcao) == (float) tamanho_passos_femea[i]) {
                        angulo_f = direcao_femea[i] - direcao_femea[i-1];
                        if (angulo_f < 0)
                            angulo_f += 8;
                        if (angulo_f == 5)
                            angulo_f = 3;
                        if (angulo_f == 6)
                            angulo_f = 2;
                        if (angulo_f == 7)
                            angulo_f = 1;

                        angulo_m = direcao_macho[j] - direcao_macho[j-1];
                        if (angulo_m < 0)
                            angulo_m += 8;
                        if (angulo_m == 5)
                            angulo_m = 3;
                        if (angulo_m == 6)
                            angulo_m = 2;
                        if (angulo_m == 7)
                            angulo_m = 1;
                        if (!(angulo_m == angulo_f || angulo_m + 1 == angulo_f || angulo_m - 1 == angulo_f)) {
                            flag_3a_fase = 0;
                        }
                    } else {
                        flag_3a_fase = 0;
                    }
                }
                if (flag_3a_fase && tamanho_2a_fase_f >= tamanho_2a_fase_m && flag_1a_fase) {
                    printf("Compatibilidade natural.\n");
                } else {
                    reverso = 1;
                }
            } else {
                reverso = 1;
            }
        }
    }
            
    if (reverso) {
        for (i = 0; i < tamanho_macho; i++) {
            reverte = direcao_macho[i] + 4;
            if (reverte > 7)
                reverte -= 8;
            pos = tamanho_macho - i;
            pos -= 1;
            direcao_macho_reverso[pos] = reverte;
            tamanho_passos_macho_reverso[pos] = tamanho_passos_macho[i];
        }
        for (i = 0; i < tamanho_macho; i++) {
            direcao_macho[i] = direcao_macho_reverso[i];
            tamanho_passos_macho[i] = tamanho_passos_macho_reverso[i];
        }
        for (i = 0; i < 8; i++) {
            dir[i] = 0;
        }
    
        /* determinando os passos da 1a danca */
        for (tamanho_1a_fase = 0; flag; tamanho_1a_fase++) {
            dir[direcao_femea[tamanho_1a_fase]] += tamanho_passos_femea[tamanho_1a_fase];
            if (dir[0] == dir[4] && dir[1] == dir[5] && dir[2] == dir[6] && dir[3] == dir[7]) {
                flag = 0;
            }
        }
        /*checando compatibilidade com o macho*/    
        proporcao = ((float) tamanho_passos_femea[0]) / tamanho_passos_macho[0];
        rotacao = direcao_femea[0] - direcao_macho[0];
        
        for (i = 0, flag_1a_fase = 1; i < tamanho_1a_fase && flag_1a_fase; i++) {
            checa_rotacao = direcao_macho[i] + rotacao;
            if (checa_rotacao < 0) {
                checa_rotacao += 8;
            } else if (checa_rotacao > 7) {
                checa_rotacao -= 8;
            }
            if (!(((float)tamanho_passos_macho[i] * proporcao) == ((float)tamanho_passos_femea[i]) && checa_rotacao == direcao_femea[i]) && tamanho_passos_macho[i] > tamanho_passos_femea[i]) {
                flag_1a_fase = 0;
            }
        }
        
        for (tamanho_2a_fase_f = tamanho_1a_fase + 1, flag_2a_fase = 1; flag_2a_fase; tamanho_2a_fase_f++) {
            checa_rotacao = direcao_femea[tamanho_2a_fase_f - 1] + 4;
            if (checa_rotacao > 7)
                checa_rotacao -= 8;
            if (direcao_femea[tamanho_2a_fase_f] == checa_rotacao && tamanho_passos_femea[tamanho_2a_fase_f] > tamanho_passos_femea[tamanho_2a_fase_f - 1]) {
                flag_2a_fase = 0;
            }
        }
        
        
        for (tamanho_2a_fase_m = tamanho_1a_fase + 1, flag_2a_fase = 1; flag_2a_fase; tamanho_2a_fase_m++) {
            checa_rotacao = direcao_macho[tamanho_2a_fase_m - 1] + 4;
            if (checa_rotacao > 7)
                checa_rotacao -= 8;
            if (direcao_macho[tamanho_2a_fase_m] == checa_rotacao && tamanho_passos_macho[tamanho_2a_fase_m] > tamanho_passos_macho[tamanho_2a_fase_m - 1]) {
                flag_2a_fase = 0;
            }
        }
        
        if (tamanho_macho - tamanho_2a_fase_m == tamanho_femea - tamanho_2a_fase_f) {
            proporcao = ((float) tamanho_passos_femea[tamanho_2a_fase_f]) / tamanho_passos_macho[tamanho_2a_fase_m];
            for (i = tamanho_2a_fase_f + 1, j = tamanho_2a_fase_m + 1, flag_3a_fase = 1; flag_3a_fase && i < tamanho_femea && j < tamanho_macho; i++, j++) {
                if (((float) tamanho_passos_macho[j] * proporcao) == (float) tamanho_passos_femea[i]) {
                    angulo_f = direcao_femea[i] - direcao_femea[i-1];
                    if (angulo_f < 0)
                        angulo_f += 8;
                    if (angulo_f == 5)
                        angulo_f = 3;
                    if (angulo_f == 6)
                        angulo_f = 2;
                    if (angulo_f == 7)
                        angulo_f = 1;
                    angulo_m = direcao_macho[j] - direcao_macho[j-1];
                    if (angulo_m < 0)
                        angulo_m += 8;
                    if (angulo_m == 5)
                        angulo_m = 3;
                    if (angulo_m == 6)
                        angulo_m = 2;
                    if (angulo_m == 7)
                        angulo_m = 1;
                    if (!(angulo_m == angulo_f || angulo_m + 1 == angulo_f || angulo_m - 1 == angulo_f)) {
                        flag_3a_fase = 0;
                    }
                } else {
                    flag_3a_fase = 0;
                }
            }
            if (flag_3a_fase && tamanho_2a_fase_f >= tamanho_2a_fase_m && flag_1a_fase) {
                printf("Reverso tem compatibilidade.\n");
            } else {
                printf("Incompatibilidade total.\n");
            }
        } else {
            printf("Incompatibilidade total.\n");
        }
    }
        
    
    return 0;
}