#include <stdio.h>

int main () {
    int B1, B2, B3, B4, B5, B6, B7, B8;
    int C1, C2, C3, C4, C5, C6, C7, C8;
    int prod;
    
    scanf("%d %d %d %d %d %d %d %d", &B1, &B2, &B3, &B4, &B5, &B6, &B7, &B8);
    scanf("%d %d %d %d %d %d %d %d", &C1, &C2, &C3, &C4, &C5, &C6, &C7, &C8);
    
    if (C4 != 2 && C4 != 9) {
        B1 += 3;
        B2 += 3;
        B3 += 3;
        B4 += 3;
        B5 += 3;
        B6 += 3;
        B7 += 3;
        B8 += 3;
    }
    if (C1 >= 11 && C1 <= 42) {
        B8 += 7;
        B7 += 8;
    }
    if (C1 % 2 != 0 && C2 % 2 != 0 && C3 % 2 != 0 && C4 % 2 != 0 && C5 % 2 != 0 && C6 % 2 != 0 && C7 % 2 != 0 && C8 % 2 != 0) {
        B1 += 2*C5;
    }
    if ((C3 < 20 || C6 < 20) && !(C3 < 20 && C6 < 20)) {
        B4 += 6;
        B5 += 6;
    }
    if (C8 != 3 && C8 >= C7) {
        B3 += C2;
    }
    prod = C1*C2*C3*C4*C5*C6*C7*C8;
    if (prod == 30 || (prod % 5 == 0 && prod % 10 != 0)) {
        B6 += 1;
    }
    if (C2 == C8 || C3 == C7) {
        B6 += 1;
    }
    
    
    if (B1 >= 1 && B1 <= 26) {
        printf("%c", B1 + 64);
    } else if (B1 == 27) {
        printf(" ");
    }
    if (B2 >= 1 && B2 <= 26) {
        printf("%c", B2 + 64);
    } else if (B2 == 27) {
        printf(" ");
    }
    if (B3 >= 1 && B3 <= 26) {
        printf("%c", B3 + 64);
    } else if (B3 == 27) {
        printf(" ");
    }
    if (B4 >= 1 && B4 <= 26) {
        printf("%c", B4 + 64);
    } else if (B4 == 27) {
        printf(" ");
    }
    if (B5 >= 1 && B5 <= 26) {
        printf("%c", B5 + 64);
    } else if (B5 == 27) {
        printf(" ");
    }
    if (B6 >= 1 && B6 <= 26) {
        printf("%c", B6 + 64);
    } else if (B6 == 27) {
        printf(" ");
    }
    if (B7 >= 1 && B7 <= 26) {
        printf("%c", B7 + 64);
    } else if (B7 == 27) {
        printf(" ");
    }
    if (B8 >= 1 && B8 <= 26) {
        printf("%c", B8 + 64);
    } else if (B8 == 27) {
        printf(" ");
    }
    printf("\n");
    
    return 0;
}
        
        
        