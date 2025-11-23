#include <stdio.h>

struct SinhVien {
    char MaSV[20];
    char Ten[50];
    float DTB;
};

char* phan_loai(struct SinhVien sv){
    if(sv.DTB >= 8.0) return "Gioi";
    if(sv.DTB >= 6.5) return "Kha";
    if(sv.DTB >= 5.0) return "Trung Binh";
    return "Yeu";
}

int main(){
    int N;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &N);

    struct SinhVien ds[N];

    for(int i = 0; i < N; i++){
        printf("Nhap MaSV, Ten, DTB: ");
        scanf("%s %s %f", ds[i].MaSV, ds[i].Ten, &ds[i].DTB);
    }

    printf("\nDanh sach sinh vien Gioi:\n");
    for(int i = 0; i < N; i++){
        if(ds[i].DTB >= 8.0)
            printf("%s - %s - %.2f - Gioi\n", ds[i].MaSV, ds[i].Ten, ds[i].DTB);
    }

    printf("\nDanh sach sinh vien Kha:\n");
    for(int i = 0; i < N; i++){
        if(ds[i].DTB >= 6.5 && ds[i].DTB < 8.0)
            printf("%s - %s - %.2f - Kha\n", ds[i].MaSV, ds[i].Ten, ds[i].DTB);
    }

    printf("\nDanh sach sinh vien Trung Binh:\n");
    for(int i = 0; i < N; i++){
        if(ds[i].DTB >= 5.0 && ds[i].DTB < 6.5)
            printf("%s - %s - %.2f - Trung Binh\n", ds[i].MaSV, ds[i].Ten, ds[i].DTB);
    }

    printf("\nDanh sach sinh vien Yeu:\n");
    for(int i = 0; i < N; i++){
        if(ds[i].DTB < 5.0)
            printf("%s - %s - %.2f - Yeu\n", ds[i].MaSV, ds[i].Ten, ds[i].DTB);
    }

    return 0;
}

