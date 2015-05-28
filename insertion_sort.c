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
