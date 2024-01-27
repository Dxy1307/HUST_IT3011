#include<stdio.h>
#include<math.h>
#define MAX 32
int m[MAX][MAX];
int Cnew(int k, int n) {
    if (k == 0 || k ==n) {
        m[k][n] = 1;
    }
    else {
        if (m[k][n] == 0) {
            m[k][n] = Cnew(k-1, n-1) + Cnew(k, n-1);
        }
    }
    return m[k][n];
}

int main() {
    printf("%d", Cnew(4, 7));
}