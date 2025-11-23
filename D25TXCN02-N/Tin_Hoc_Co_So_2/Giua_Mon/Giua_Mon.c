#include <stdio.h>
#include <math.h>

void nhapMang(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void hienMang(int a[], int n){
    printf("Cac phan tu trong mang: ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int laSoNguyenTo(int x){
    if(x < 2) return 0;
    for(int i = 2; i <= sqrt(x); i++){
        if(x % i == 0) return 0;
    }
    return 1;
}

float tinhTBC(int a[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }
    return (float)sum / n;
}

void hienSoNguyenTo(int a[], int n){
    printf("Cac so nguyen to trong mang: ");
    int found = 0;
    for(int i = 0; i < n; i++){
        if(laSoNguyenTo(a[i])){
            printf("%d ", a[i]);
            found = 1;
        }
    }
    if(!found) printf("Khong co so nguyen to nao!");
    printf("\n");
}

void sapXepGiamDan(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] < a[j]){
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int demTanSuat(int a[], int n, int number){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == number) count++;
    }
    return count;
}

int timKiem(int a[], int n, int number){
    for(int i = 0; i < n; i++){
        if(a[i] == number) return i;
    }
    return -1;
}

int main(){
    int n;
    int a[100];
    int choice;

    do{
        printf("Nhap so phan tu (2 <= n <= 100): ");
        scanf("%d", &n);
    } while(n < 2 || n > 100);

    do{
        printf("\n*********************MENU*******************\n");
        printf("1. Nhap gia tri cho cac phan tu\n");
        printf("2. Hien thi gia tri cac phan tu\n");
        printf("3. Trung binh cong cua cac phan tu\n");
        printf("4. Hien thi so nguyen to trong mang\n");
        printf("5. Sap xep mang giam dan\n");
        printf("6. Thong ke tan suat\n");
        printf("7. Tim kiem phan tu theo gia tri\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                nhapMang(a, n);
                break;

            case 2:
                hienMang(a, n);
                break;

            case 3:
                printf("Trung binh cong = %.2f\n", tinhTBC(a, n));
                break;

            case 4:
                hienSoNguyenTo(a, n);
                break;

            case 5:
                sapXepGiamDan(a, n);
                printf("Mang sau khi sap xep giam dan:\n");
                hienMang(a, n);
                break;

            case 6: {
                int number;
                printf("Nhap gia tri can thong ke: ");
                scanf("%d", &number);
                int count = demTanSuat(a, n, number);
                printf("Gia tri %d xuat hien %d lan.\n", number, count);
                break;
            }

            case 7: {
                int number;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &number);
                int pos = timKiem(a, n, number);
                if(pos == -1) printf("Khong tim thay!\n");
                else printf("Tim thay %d tai vi tri a[%d]\n", number, pos);
                break;
            }

            case 8:
                printf("Thoat chuong trinh...\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }

    } while(choice != 8);

    return 0;
}

