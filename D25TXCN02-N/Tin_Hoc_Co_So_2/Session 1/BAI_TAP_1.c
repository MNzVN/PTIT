#include <stdio.h>
#include <math.h>
#define PI 3.14

int main() {
    float dai,rong;
    float chuVi,dienTich;
    float duongCheo;

    printf("Nhap chieu dai: ");
    scanf("%f", &dai);

    printf("Nhap chieu rong: ");
    scanf("%f", &rong);

    chuVi = (dai + rong) * 2;
    dienTich = dai * rong;
    duongCheo = sqrt(dai * dai + rong * rong);

    printf("\n--- Ket qua ---\n");
    printf("Chu vi hinh chu nhat: %.2f\n", chuVi);
    printf("Dien tich hinh chu nhat: %.2f\n", dienTich);
    printf("Duong cheo hinh chu nhat: %.2f\n", duongCheo);

    return 0;
}

