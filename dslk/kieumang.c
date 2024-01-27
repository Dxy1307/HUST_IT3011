#include<stdio.h>
#include<math.h>
#define MAX 100
int n = 5;
int a[MAX] = {1, 2, 3, 4, 5};

void insert(int x, int p) {
    for (int j = n - 1; j >= p; j--) {
        a[j+1] = a[j];
    }
    a[p] = x;
    n = n + 1;
}

void delete(int p) {
    for (int j = p+1; j < n; j++) {
        a[j-1] = a[j];
    }
    n--;
}

int retrieve(int p) {
    return a[p];
}

int locate(int x) {
    for (int i = 0; i < n; i++) {
        if(a[i] == x) return i;
    }
    return -1;
}

void makeNull() {
    n = 0;
}

int next(int p) {
    if (0 <= p && p < n-1) return p + 1;
    return -1;
}

int prev(int p) {
    if (p > 0 && p <= n - 1) return p - 1;
    return -1;
}

int main() {
    insert(2, 3);
    delete(4);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n%d", retrieve(2));
    printf("\n%d",locate(2));
    printf("\n%d",next(4));
    printf("\n%d",prev(0));
}