#include<stdio.h>
#include<math.h>
#define MAX 100

int n;
int x[MAX];
int m[MAX];

void solution() {
    for (int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

void Try(int k) {
    for (int i = 1; i <= n; i++) {
        if (!m[i]) {
            x[k] = i;
            m[i] = 1;
            if (k == n) solution();
            else Try(k + 1);
            m[i] = 0;
        }
    }
}

int main() {
    n = 4;
    for (int i = 1; i <= n; i++) {
        m[i] = 0;
    }
    Try(1);
    return 1;
}