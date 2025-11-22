#include <stdio.h>

int main() {
    int N;
    long long factorial = 1;
    int isPrime = 1;
    
    do {
        printf("Nhap so nguyen duong N: ");
        scanf("%d", &N);

        if (N <= 0) {
            printf("N phai la so nguyen duong! Moi nhap lai.\n");
        }
    } while (N <= 0);

    for (int i = 1; i <= N; i++) {
        factorial *= i;
    }

    if (N < 2) {
        isPrime = 0;
    } else {
        for (int i = 2; i * i <= N; i++) {
            if (N % i == 0) {
                isPrime = 0;
                break;
            }
        }
    }

    printf("Giai thua %d! = %lld\n", N, factorial);

    if (isPrime == 1) {
        printf("%d la so nguyen to.\n", N);
    } else {
        printf("%d khong phai la so nguyen to.\n", N);
    }

    return 0;
}

