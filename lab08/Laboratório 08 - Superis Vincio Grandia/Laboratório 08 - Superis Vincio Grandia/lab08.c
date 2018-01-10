#include "lab08.h"
#include <math.h>
#include <stdio.h>

#define max_points      500
#define max_operations  60000
#define max_style       256

#define M_PI 3.14159265358979323846

int main () {
    int numero_checagem_operacao[1], numero_checagem_poligono[1], i, j;
    double poligonos[max_operations][2], parametros_operacoes[max_operations][2], original[max_operations][2];
    char operacoes[max_operations], informacoes_visuais[max_operations];
    double transforma_rad = M_PI/180.0, rotacao, x, y;
    double angulo, angulo_atual, modulo;
    
    scan_svg(numero_checagem_operacao,parametros_operacoes,operacoes);
    scan_svg(numero_checagem_poligono, poligonos, informacoes_visuais);
    while (numero_checagem_poligono[0] >= 0) {
        for(j = 0; j < numero_checagem_poligono[0]; j++) {
            original[j][0] = poligonos[j][0];
            original[j][1] = poligonos[j][1];
        }
        for (i = 0; i < numero_checagem_operacao[0]; i++) {
            if (operacoes[i] == 'C' && i != 0) {
                print_svg (numero_checagem_poligono, poligonos, informacoes_visuais);
                for(j = 0; j < numero_checagem_poligono[0]; j++) {
                    poligonos[j][0] = original[j][0];
                    poligonos[j][1] = original[j][1];
                }
            } else if (operacoes[i] == 'S') {
                for(j = 0; j < numero_checagem_poligono[0]; j++) {
                    poligonos[j][0] *= parametros_operacoes[i][0];
                    poligonos[j][1] *= parametros_operacoes[i][1];
                }
            } else if (operacoes[i] == 'T') {
                for(j = 0; j < numero_checagem_poligono[0]; j++) {
                    poligonos[j][0] += parametros_operacoes[i][0];
                    poligonos[j][1] += parametros_operacoes[i][1];
                }
            } else if (operacoes[i] == 'R') {
                if (parametros_operacoes[i][0] != 0.0) {
                    rotacao = parametros_operacoes[i][0] * transforma_rad;
                    for(j = 0; j < numero_checagem_poligono[0]; j++) {
                        x = poligonos[j][0];
                        y = poligonos[j][1];
                        if (x != 0.0 || y != 0.0) {
                            
                            modulo = sqrt(pow(x, 2) + pow(y, 2));
                            angulo_atual = asin (fabs(y)/modulo);
                            
                            if (x < 0 && y > 0) {
                                angulo_atual = M_PI - angulo_atual;
                            } else if (x < 0 && y < 0) {
                                angulo_atual = M_PI + angulo_atual;
                            } else if (x > 0 && y < 0) {
                                angulo_atual = 2*M_PI - angulo_atual;
                            } else if (x > 0 && y == 0) {
                                angulo_atual = 0;
                            } else if (x == 0 && y > 0) {
                                angulo_atual = M_PI/2;
                            } else if (x < 0 && y == 0) {
                                angulo_atual = M_PI;
                            } else if (x == 0 && y < 0) {
                                angulo_atual = 3*(M_PI/2);
                            }
                        
                            angulo = angulo_atual + rotacao;
                            poligonos[j][0] = modulo * cos (angulo);
                            poligonos[j][1] = modulo * sin (angulo);
                        }
                    }
                }
            }
        }
        print_svg (numero_checagem_poligono, poligonos, informacoes_visuais);
        scan_svg (numero_checagem_poligono, poligonos, informacoes_visuais);
    }
    close_svg();
    return 0;
}