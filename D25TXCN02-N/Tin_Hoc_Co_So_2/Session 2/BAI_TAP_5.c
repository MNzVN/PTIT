#include <stdio.h>

void nhap_mang(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

void in_mang(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

float tinh_trung_binh_cong(int a[], int n){
    float sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }
    return sum / n;
}

int main(){
    int a[100], n;

    printf("Nhap so luong phan tu N: ");
    scanf("%d", &n);

    nhap_mang(a, n);

    printf("Mang vua nhap: ");
    in_mang(a, n);

    printf("Trung binh cong = %.2f\n", tinh_trung_binh_cong(a, n));

    return 0;
}

