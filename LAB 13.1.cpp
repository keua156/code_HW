#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int *KnapsackDP(int w[], int v[], int n, int wx) {
    static int K[101][101];
    static int x[101];
    
    for (int i = 0; i <= n; i++) {
        for (int w_ = 0; w_ <= wx; w_++) {
            if (i == 0 || w_ == 0)
                K[i][w_] = 0;
            else if (w[i - 1] <= w_)
                K[i][w_] = max(v[i - 1] + K[i - 1][w_ - w[i - 1]], K[i - 1][w_]);
            else
                K[i][w_] = K[i - 1][w_];
        }
    }

    int i = n, j = wx;
    while (i > 0 && j > 0) {
        if (K[i][j] != K[i - 1][j]) {
            x[i - 1] = 1;
            j -= w[i - 1];
        } else {
            x[i - 1] = 0;
        }
        i--;
    }

    return x;
}

int main() {
    int n = 5, wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};
    int *x;
    x = KnapsackDP(w, v, n, wx);
    for (int i = 0; i < n; i++)
        printf("%d ", x[i]);
    return 0;
}
