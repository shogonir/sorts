int pivot_index (int n, int *a) {
    int i;
    for (i=1; i<n; i++) {
        if (a[i] != a[0]) {
            // pivot exists
            return a[i] > a[0] ? i : 0;
        }
    }
    // pivot not exists
    return -1;
}

void quick_sort (int n, int *a) {
    int i=0, j=n-1, swap, piv, piv_index = pivot_index(n, a);
    
    if (piv_index == -1) return; // base case
    
    // recursive case
    piv = a[piv_index];
    while (i <= j) {
        while (a[i] < piv) if (++i>=n) break;
        while (a[j] >= piv) if (--j<0) break;
        if (i <= j) {
            swap = a[i];
            a[i] = a[j];
            a[j] = swap;
        }
    }
    quick_sort(i, a);
    quick_sort(n-i, a+i);
}
