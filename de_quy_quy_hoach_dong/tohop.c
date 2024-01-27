#include<stdio.h>
#include<math.h>
int k;
int n;
#define MAX 100
int x[MAX];
void solution() {
    for (int i = 1; i <= k; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

int check(int v, int k) {
    return 1;
}

void Try(int i) {
    for (int v = x[i-1] + 1; v <= n-k+i; v++) {
        if(check(v, i)) {
            x[i] = v;
            if (i == k) solution();
            else Try(i + 1);
        }
    }
}

int main() {
    k = 3;
    n = 5;
    Try(1);
    return 1;
}