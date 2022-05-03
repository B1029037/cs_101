#include <stdio.h>

int swap_func(int* i, int* j) {
    int tmp;
    tmp = *i;
    *i = *j;
    *j = tmp;
    printf("after swap, n=%d, m=%d\n", *i, *j);
}

int SWAP(int* i, int* j) {
    int tmp;
    tmp = *i;
    *i = *j;
    *j = tmp;
}

int swapArray(int* source, int* dest, int size) {
    for(int i = 1; i <= size; i++) {
        SWAP(source,dest);
        source++;dest++;
    }
    for(int i = 1; i <= size; i++) {
        source--;dest--;
    }
}

char* copy_string(char* s) {
    int len = 0;
    char* t = s;
    while (*t++) len++;
    char* p = (char*)calloc(len, sizeof(char));
    char* ps = p;
    t = s;
    while (*t) *ps++=*t++;
    *ps = 0;
    return p;
}


int main() {
    int n, m;
    n = 1;
    m = 2;
    printf("No.1------------------\n");
    swap_func(&n, &m);
    int size = 10;
    int source[10] = {0,9,8,7,6,5,4,3,2,1};
    int dest[10] = {10,20,30,40,50,60,70,80,90,100};
    printf("No.2------------------\n");
    swapArray(source, dest, size);
    printf("after swap array, source array = [");
    for (int i=0; i<size; i++) {
        if (i == size-1) {
            printf("%d]", source[i]);
        }else {
            printf("%d, ", source[i]);
        }    
    }
    printf("\nafter swap array, dest array = [");
    for (int i=0; i<size; i++) {
        if (i == size-1) {
            printf("%d]", dest[i]);
        }else {
            printf("%d, ", dest[i]);
        }
    }
    printf("\n");
    printf("No.3------------------\n");
    char str[] = "IU!IU!IU!IU!";
    char* cp_str = copy_string(str);
    printf("copy_string = %s\n", cp_str);
    free(cp_str);
    printf("\n");
    return 0;
}