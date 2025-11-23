#include <stdio.h>

int main() {
    int a[100], n;
    int tong = 0, tongChan = 0;

    printf("Nhap so luong phan tu N: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < n; i++){
        tong += a[i];
        if(a[i] % 2 == 0){
            tongChan += a[i];
        }
    }

    printf("Tong tat ca phan tu = %d\n", tong);
    printf("Tong cac phan tu chan = %d\n", tongChan);

    return 0;
}

