#include<stdio.h>
#include<math.h>

int quy_hoach_dong(int x[], int n) {
    int s[n];
    s[0] = x[0];
    int result = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i-1] > 0) {
            s[i] = s[i-1] + x[i];
        }
        else s[i] = x[i];
        if (result < s[i]) {
            result = s[i];
        }
    }
    return result;
}

int main() {
    int A[] = {-2, 11, -4, 13, -5, 2};
    printf("%d\n", quy_hoach_dong(A, 6));
}