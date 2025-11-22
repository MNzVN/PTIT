#include <stdio.h>

int main() {
    int N, K;
    int temp;
    int sum = 0;
    int count = 0;

    do {
        printf("Nhap so nguyen duong N: ");
        scanf("%d", &N);

        if (N <= 0) {
            printf("N phai la so nguyen duong! Moi nhap lai.\n");
        }
    } while (N <= 0);

    temp = N;

    int nCopy = N;
    while (nCopy > 0) {
        sum += nCopy % 10;
        nCopy /= 10;
    }

    do {
        printf("Nhap chu so K (0-9): ");
        scanf("%d", &K);

        if (K < 0 || K > 9) {
            printf("K phai la chu so tu 0 den 9!\n");
        }
    } while (K < 0 || K > 9);

    while (temp > 0) {
        if (temp % 10 == K) {
            count++;
        }
        temp /= 10;
    }

    printf("Tong cac chu so cua %d = %d\n", N, sum);
    printf("Chu so %d xuat hien %d lan trong %d\n", K, count, N);

    return 0;
}

