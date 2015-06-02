void reverse (int n, int *a) {
    int i, swap;
    for (i=0; i<(float)n/2; i++) {
        swap = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = swap;
    }
}

void insert_heap (int x, int n, int* s) {
    int swap;
    s[n] = x;
    while (n>0 && s[n] < s[(n-1)/2]) {
        swap = s[n];
        s[n] = s[(n-1)/2];
        s[(n-1)/2] = swap;
        n = (n-1)/2;
    }
}
 
int delmin_heap (int n, int* a) {
    int i=0, j, min=a[0], swap;
    a[0] = a[n-1];
    while (i*2+2 <= n) {
        if (i*2+2 == n) {
            j = i*2+1;
            if (a[j] < a[i]) {
                swap = a[i];
                a[i] = a[j];
                a[j] = swap;
            }
            i = j;
        }
        else {
            j = (a[i*2+1]>a[i*2+2]) ? i*2+2 : i*2+1;
            if (a[j] < a[i]) {
                swap = a[i];
                a[i] = a[j];
                a[j] = swap;
            }
            i = j;
        }
    }
    return min;
}
 
void heap_sort (int n, int* a) {
    int i, x;
    for (i=0; i < n; i++){
        insert_heap(a[i], i, a);
    }
    for (i=0; i < n; i++) {
        x = delmin_heap(n-i, a);
        a[n-1-i] = x;
    }
    reverse(n, a);
}
