#include <stdio.h>

int kiem_tra_so_nguyen_to(int n){
    if(n < 2) return 0;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Nhap N: ");
    scanf("%d", &n);

    printf("%d", kiem_tra_so_nguyen_to(n));
    return 0;
}

