#include <stdio.h>

int* KnapsackGreedy(int *w, int *v, int n, int wx) {
    static int x[100];
    for (int i = 0; i < n; i++)
        x[i] = 0;

    int capacity = wx;
    for (int i = 0; i < n; i++) {
        if (w[i] <= capacity) {
            x[i] = 1;
            capacity -= w[i];
        }
    }

    return x;
}

int main() {
    int n = 5, wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};
    int *x = KnapsackGreedy(w, v, n, wx);
    
    for (int i = 0; i < n; i++)
        printf("%d ", x[i]);
    
    return 0;
}
