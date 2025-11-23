#include <stdio.h>

struct NgayThang {
    int Ngay, Thang, Nam;
};

int kiem_tra_hop_le(struct NgayThang d){
    if(d.Thang < 1 || d.Thang > 12) return 0;

    int maxDay;
    switch(d.Thang){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            maxDay = 31; break;
        case 4: case 6: case 9: case 11:
            maxDay = 30; break;
        case 2:
            if((d.Nam % 400 == 0) || (d.Nam % 4 == 0 && d.Nam % 100 != 0))
                maxDay = 29;
            else
                maxDay = 28;
            break;
    }
    return (d.Ngay >= 1 && d.Ngay <= maxDay);
}

int main(){
    int N;
    printf("Nhap N: ");
    scanf("%d", &N);

    struct NgayThang ds[N];

    for(int i = 0; i < N; i++){
        scanf("%d %d %d", &ds[i].Ngay, &ds[i].Thang, &ds[i].Nam);
    }

    printf("Ngay thang hop le:\n");
    for(int i = 0; i < N; i++){
        if(kiem_tra_hop_le(ds[i])){
            printf("%d/%d/%d\n", ds[i].Ngay, ds[i].Thang, ds[i].Nam);
        }
    }
    return 0;
}

