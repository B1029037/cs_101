#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void rec_strlen (char* s) {
    if (!*s) {
        return;
    }
    printf("%c,", *s);
    rec_strlen (++s);
}

void hanoi_tower(int i) {
    FILE* fp;
    fp = fopen("hanoi.txt", "w+");
    fclose(fp);
    hanoi_tower_main(i, 'A', 'B', 'C', i);
    return 0;
}

void hanoi_tower_main(int n, char A, char B, char C, int m) {
    if(n == 1) {
        FILE* fp;
        fp = fopen("hanoi.txt", "a");
        fprintf(fp, "Move disk %d from %c to %c\n", m, A, C);
        fclose(fp);
    }
    else {
        hanoi_tower_main(n-1, A, C, B, --m);
        hanoi_tower_main(1, A, B, C, ++m);
        hanoi_tower_main(n-1, B, A, C, --m);
    }
}

void multiplication(int i, int j) {
    if (i == 10) {
        return 0;
    } else if (j == 9) {
        printf("%d*%d=%d \n", i, j, i*j);
        multiplication(i+1, 1);
    } else {
        printf("%d*%d=%d ", i, j, i*j);
        multiplication(i, j+1);
    }
}

int main() {
    char s[]="1234567890";
    rec_strlen (s);
    printf("\nfunc#1---------------\n");
    hanoi_tower(16);
    printf("\nfunc#2---------------\n");
    multiplication(1,1);
    printf("\nfunc#3---------------\n");

    return 0;
}