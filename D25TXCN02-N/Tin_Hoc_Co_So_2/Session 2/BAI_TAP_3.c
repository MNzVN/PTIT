#include <stdio.h>

int main() {
    int a[100], n;

    printf("Nhap so luong phan tu N: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    int max = a[0], min = a[0];

    for(int i = 1; i < n; i++){
        if(a[i] > max) max = a[i];
        if(a[i] < min) min = a[i];
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("Max = %d\n", max);
    printf("Min = %d\n", min);
    printf("Mang sau khi sap xep: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

