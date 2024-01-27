#include<stdio.h>
#include<math.h>
#define MAX 100
int maxL(int x[MAX], int l, int r) {
    int max = -999999999;
    int s = 0;
    for (int i = r; i >= l; i--) {
        s += x[i];
        if (s > max) max = s;
    }
    return max;
}

int maxR(int x[MAX], int l, int r) {
    int max = -999999999;
    int s = 0;
    for (int i = l; i <= r; i++) {
        s += x[i];
        if (s > max) max = s;
    }
    return max;
}

int maxSeq(int x[MAX], int l, int r) {
    if (l == r) return x[l];
    int mid = (l + r) / 2;
    int mL = maxSeq(x, l, mid);
    int mR = maxSeq(x, mid + 1, r);
    int mLR = maxL(x, l, mid) + maxR(x, mid + 1, r);
    int max = mL;
    if (max < mR) max = mR;
    if (max < mLR) max = mLR;
}


void main() {
    int x[MAX] = {-2, 11, -4, 13, 5, 2, 4, -3, 9};
    printf("%d", maxSeq(x, 0, 8));
}
