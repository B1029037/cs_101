#include <stdio.h>
#include <stdlib.h>

int* get_int_array(int n) {
    return (int*)calloc(n, sizeof(int));
}

void set_value(int* p, int v) {
    *p = v;
}

void print_array(int* p, int n) {
    printf("[");
    for (int i=0;i<n;i++) {
        if(i<n-1) {
            printf("%d ,", *p+i);
        } else {
            printf("%d", *p+i);
        }
    }
    printf("]\n");
}

int main() {
    int n = 10;
    int* ip = get_int_array(n);
    printf("No.1 ---------------------\n");
    for (int i=0; i<n; i++) {
        set_value(ip+i, i+1);
    }

    print_array(ip, n);
    printf("No.2 ---------------------\n");
    printf("\nNo.3 ---------------------\n");

    return 0;
}