#include <stdio.h>

void insertation_sort (int n, int *a) {
    int i, j, swap;
    for (i=1; i<n; i++) {
        j = i-1;
        while (j>=0 && a[j]>a[j+1]) {
            swap = a[j];
            a[j] = a[j+1];
            a[j+1] = swap;
            j--;
        }
    }
}

int main(int argc, char *argv[]) {
    int i, n = 5;
    int a[5] = {1, 5, 2, 4, 3};
    
    insertation_sort(n, a);

    printf("[");
    for (i=0; i<n-1; i++) {
        printf("%d, ", a[i]);
    }
    printf("%d]\n", a[i]);
    
    return 0;
}
