#include <stdio.h>

int main() {
    int choice;

    do {
        printf("\n================ MENU =================\n");
        printf("1. Kiem tra Chan/Le\n");
        printf("2. Tinh tong S = 1 + 2 + ... + N\n");
        printf("3. Hien thi bang cuu chuong\n");
        printf("0. Thoat chuong trinh\n");
        printf("=======================================\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int n;
                printf("Nhap so nguyen: ");
                scanf("%d", &n);

                if (n % 2 == 0)
                    printf("%d la so CHAN.\n", n);
                else
                    printf("%d la so LE.\n", n);

                break;
            }

            case 2: {
                int N, S = 0;
                printf("Nhap N (nguyen duong): ");
                scanf("%d", &N);

                if (N <= 0) {
                    printf("N phai lon hon 0!\n");
                    break;
                }

                for (int i = 1; i <= N; i++) {
                    S += i;
                }

                printf("Tong S = %d\n", S);
                break;
            }

            case 3: {
                int K;
                printf("Nhap so K: ");
                scanf("%d", &K);

                printf("Bang cuu chuong cua %d:\n", K);
                for (int i = 1; i <= 10; i++) {
                    printf("%d x %d = %d\n", K, i, K * i);
                }

                break;
            }

            case 0:
                printf("Thoat chuong trinh...\n");
                break;

            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
        }

    } while (choice != 0);

    return 0;
}

