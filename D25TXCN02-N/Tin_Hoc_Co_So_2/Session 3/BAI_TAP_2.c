#include <stdio.h>

struct SanPham {
    char MaSP[50];
    char TenSP[50];
    float DonGia;
    int SoLuong;
};

void nhap_san_pham(struct SanPham *sp){
    getchar();
    printf("Nhap ma san pham: ");
    fgets(sp->MaSP, 50, stdin);
    sp->MaSP[strcspn(sp->MaSP, "\n")] = '\0';

    printf("Nhap ten san pham: ");
    fgets(sp->TenSP, 50, stdin);
    sp->TenSP[strcspn(sp->TenSP, "\n")] = '\0';

    printf("Nhap don gia va so luong: ");
    scanf("%f %d", &sp->DonGia, &sp->SoLuong);
}

float tinh_thanh_tien(struct SanPham sp){
    return sp.DonGia * sp.SoLuong;
}

void hien_thi_san_pham(struct SanPham sp){
    printf("Ma SP: %s - Ten: %s\n", sp.MaSP, sp.TenSP);
    printf("Don gia: %.2f - So luong: %d\n", sp.DonGia, sp.SoLuong);
    printf("Thanh tien: %.2f\n", tinh_thanh_tien(sp));
}

int main(){
    struct SanPham sp;
    nhap_san_pham(&sp);
    hien_thi_san_pham(sp);
    return 0;
}

