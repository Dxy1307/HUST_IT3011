#include<stdio.h>
#include<math.h>
#define MAX 10
int x[MAX];
int n;

void solution() {
    for (int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

int check(int v, int k) {
    if (v + x[k-1] == 2) {
        return 0;
    }
    else return 1;
}

void Try(int k) {
    for (int v = 0; v <= 1; v++) {
        if (check(v, k)) {
            x[k] = v;
            if (k == n) solution();
            else Try(k+1);
        }
    }
}

int main() {
    n = 4;
    Try(1);
    return 1;
}