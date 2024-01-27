// Sudoku
/**
 * Mảng 2 chiều x[0..8, 0..8]
 * Thuộc tính P
 * x[i, j1] != x[i, j2], với mọi i = 0..8 và 0 <= j1 < j2 <= 8
 * x[i1, j] != x[i2, j], với mọi j = 0..8 và 0 <= i1 < i2 <= 8
 * x[3I + i1, 3J + j1] != x[3I + i2, 3J + j2] với
 * mọi I, J = 0, 1, 2 và i1, j1, i2, j2 thuộc {0, 1, 2} sao cho i1 != i2 hoặc j1 != j2
 */

#include<stdio.h>
#include<math.h>
#define MAX 100

int x[MAX][MAX];

int solution() {
    for (int i = 0; i <= 8; i++) {
        for (int j = 0; j <= 8; j++) {
            printf("%d", x[i][j]);
        }
    }

    printf("\n");
}

int check(int v, int r, int c) {
    for (int i = 0; i < r; i++) {
        if (x[i][c] == v) return 0;
    }
    for (int j = 0; j < c; j++) {
        if (x[r][j] == v) return 0;
    }

    int I = r/3;
    int J = c/3;
    int i = r - 3 * I;
    int j = c - 3 * J;
    
    for (int i1 = 0; i1 < i; i1++) {
        for (int j1 = 0; j1 <= 2; j1++) {
            if (x[3*I + i1][3*J + j1] == v) return 0;
        }
    }

    for (int j1 = 0; j1 < j; j1++) {
        if (x[3*I + i][3*J + j1] == v) {
            return 0;
        }
    }

    return 1;
}

void try(int r, int c) {
    for (int v = 1; v <= 9; v++) {
        if (check(v, r, c)) {
            x[r][c] = v;
            if(r == 8 && c == 8) solution();
            else {
                if (c == 8) try(r+1, 0);
                else try(r, c+1);
            }
        }
    }
}

int main() {
    try(0, 0);
}