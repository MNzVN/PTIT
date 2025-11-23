#include <stdio.h>

int main() {
    int a[100], n, x;
    int count = 0, firstIdx = -1;

    printf("Nhap so luong phan tu N: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    printf("Nhap gia tri X can tim: ");
    scanf("%d", &x);

    for(int i = 0; i < n; i++){
        if(a[i] == x){
            count++;
            if(firstIdx == -1){
                firstIdx = i;
            }
        }
    }

    printf("So lan X xuat hien = %d\n", count);
    printf("Chi so dau tien = %d\n", firstIdx);

    return 0;
}

