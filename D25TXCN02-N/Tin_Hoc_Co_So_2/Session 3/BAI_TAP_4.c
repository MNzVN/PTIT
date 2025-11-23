#include <stdio.h>

struct DiaChi {
    int SoNha;
    char TenDuong[50];
    char QuanHuyen[50];
};

struct NhanVien {
    char MaNV[50];
    char TenNV[50];
    struct DiaChi DiaChiNha;
};

int main(){
    struct NhanVien nv;

    printf("Nhap Ma NV va Ten NV: ");
    scanf("%s %s", nv.MaNV, nv.TenNV);

    printf("Nhap so nha va ten duong: ");
    scanf("%d %s", &nv.DiaChiNha.SoNha, nv.DiaChiNha.TenDuong);

    getchar();
    printf("Nhap quan/huyen: ");
    fgets(nv.DiaChiNha.QuanHuyen, 50, stdin);
    nv.DiaChiNha.QuanHuyen[strcspn(nv.DiaChiNha.QuanHuyen, "\n")] = '\0';

    printf("Ma NV: %s - Ten: %s\n", nv.MaNV, nv.TenNV);
    printf("Dia chi: %d %s, %s\n", nv.DiaChiNha.SoNha, nv.DiaChiNha.TenDuong, nv.DiaChiNha.QuanHuyen);

    return 0;
}

