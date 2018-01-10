#include <stdio.h>

int main () {
    char a, b;
    int altura, largura, foto [301][301], num_reg = 2, flag, atual;
    int i, j, k, m;
    
    scanf("%c%c %d %d", &a, &b, &largura, &altura);
    for (i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            scanf("%d", &foto[i][j]);
        }
    }
    
    for (i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            if (foto[i][j] == 1) {
                if (i > 0 && foto[i - 1][j] != 1 && foto[i - 1][j] != 0) {
                    foto[i][j] = foto[i - 1][j];
                } else if (i > 0 && j < largura - 1 && foto[i - 1][j + 1] != 1 && foto[i - 1][j + 1] != 0) {
                    foto[i][j] = foto[i - 1][j + 1];
                } else if (j < largura - 1 && foto[i][j + 1] != 1 && foto[i][j + 1] != 0) {
                    foto[i][j] = foto[i][j + 1];
                } else if (i < altura - 1 && j < largura - 1 && foto[i + 1][j + 1] != 1 && foto[i + 1][j + 1] != 0) {
                    foto[i][j] = foto[i + 1][j + 1];
                } else if (i < altura - 1 && foto[i + 1][j] != 1 && foto[i + 1][j] != 0) {
                    foto[i][j] = foto[i + 1][j];
                } else if (i < altura - 1 && j > 0 && foto[i + 1][j - 1] != 1 && foto[i + 1][j - 1] != 0) {
                    foto[i][j] = foto[i + 1][j - 1];
                }  else if (j > 0 && foto[i][j - 1] != 1 && foto[i][j - 1] != 0) {
                    foto[i][j] = foto[i][j - 1];
                } else if (i > 0 && j > 0 && foto[i - 1][j - 1] != 1 && foto[i - 1][j - 1] != 0) {
                    foto[i][j] = foto[i - 1][j - 1];
                } else {
                    foto[i][j] = num_reg;
                    num_reg++;
                }
            }
        }
    }
    
    for (i = 0; i < altura; i++) {
        for (j = 0; j < largura; j++) {
            if (foto[i][j] != 0) {
                flag = 0;
                if (i > 0 && foto[i - 1][j] != foto[i][j] && foto[i - 1][j] != 0) {
                    atual = foto[i - 1][j];
                    flag = 1;
                } else if (i > 0 && j < largura - 1 && foto[i - 1][j + 1] != foto[i][j] && foto[i - 1][j + 1] != 0) {
                    atual = foto[i - 1][j + 1];
                    flag = 1;
                } else if (j < largura - 1 && foto[i][j + 1] != foto[i][j] && foto[i][j + 1] != 0) {
                    atual = foto[i][j + 1];
                    flag = 1;
                } else if (i < altura - 1 && j < largura - 1 && foto[i + 1][j + 1] != foto[i][j] && foto[i + 1][j + 1] != 0) {
                    atual = foto[i + 1][j + 1];
                    flag = 1;
                } else if (i < altura - 1 && foto[i + 1][j] != foto[i][j] && foto[i + 1][j] != 0) {
                    atual = foto[i + 1][j];
                    flag = 1;
                } else if (i < altura - 1 && j > 0 && foto[i + 1][j - 1] != foto[i][j] && foto[i + 1][j - 1] != 0) {
                    atual = foto[i + 1][j - 1];
                    flag = 1;
                }  else if (j > 0 && foto[i][j - 1] != foto[i][j] && foto[i][j - 1] != 0) {
                    atual = foto[i][j - 1];
                    flag = 1;
                } else if (i > 0 && j > 0 && foto[i - 1][j - 1] != foto[i][j] && foto[i - 1][j - 1] != 0) {
                    atual = foto[i - 1][j - 1];
                    flag = 1;
                } 
                
                if (flag) {
                    num_reg--;
                    for (k = 0; k < altura; k++) {
                        for(m = 0; m < largura; m++) {
                            if (foto[k][m] == atual)
                                foto[k][m] = foto[i][j];
                        }
                    }
                }
            }
        }
    }
    
    printf("%d\n", num_reg - 2);
    
    return 0;
    
}