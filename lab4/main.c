#include <stdio.h>

int* func(int(* p)[10]) {
    int num = 9;
    for (int k = 0; k <= 10; k++) {
        if (*(p[0]+k) == num) {
            printf("&n[%i]->%p, n[%i]=%i;", k, p[0]+k, k, *(p[0]+k));
            return (p[0]+k);
        }
    }
}

int main () {
    int n[]={6,4,7,2,0,9,8,1,5,3};
    int* p;
    printf("NO.1 -------------------\n");
    p = func(&n);
    printf("p->%p, *p=%i\n", p, *p);
    printf("NO.2 -------------------\n");
    int* ap[10];
    for (int i = 0;; i++) {
        for (int j = 0; j < 10; j++){
            if(n[j] == i) {
                ap[i] = &n[j];
                printf("&n[%d]->%p, n[%d]=%d; ap[%d]->%p, *ap=%d\n", j, &n[j], j, n[j], i, ap[i], *ap[i]);
            }
        }
        if (n[i] == n[9]){
            break;
        }
    }
    return 0;
}