#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LIST 100

struct Person {
    int contactId;
    char fullName[30];
    char mail[50];
    char phoneNum[11];
    bool gender;
    char homeAddr[50];
};

void showMenu();
void showList(struct Person arr[], int size);
void addNew(struct Person arr[], int *size);
void updateInfo(struct Person arr[], int size);
void removeContact(struct Person arr[], int *size);
void findContact(struct Person arr[], int size);
void sortByName(struct Person arr[], int size);

void printOne(struct Person p);

int main() {
    struct Person directory[MAX_LIST];
    int total = 0;
    int option;

    do {
        showMenu();
        printf("Nhap lua chon: ");
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1:
                showList(directory, total);
                break;
            case 2:
                addNew(directory, &total);
                break;
            case 3:
                updateInfo(directory, total);
                break;
            case 4:
                removeContact(directory, &total);
                break;
            case 5:
                findContact(directory, total);
                break;
            case 6:
                sortByName(directory, total);
                break;
            case 0:
                printf("Thoat chuong trinh...\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (option != 0);

    return 0;
}

void showMenu() {
    printf("\n------------------ Contact Manager ------------------\n");
    printf("1. Xem danh sach lien he\n");
    printf("2. Them lien he moi\n");
    printf("3. Chinh sua thong tin\n");
    printf("4. Xoa lien he\n");
    printf("5. Tim kiem\n");
    printf("6. Sap xep theo ten (A-Z)\n");
    printf("0. Thoat\n");
    printf("-----------------------------------------------------\n");
}

void printOne(struct Person p) {
    printf("%-5d %-20s %-25s %-12s %-5s %-30s\n",
           p.contactId, p.fullName, p.mail, p.phoneNum,
           p.gender ? "Nam" : "Nu", p.homeAddr);
}

void showList(struct Person arr[], int size) {
    if (size == 0) {
        printf("Danh sach rong!\n");
        return;
    }

    printf("\n%-5s %-20s %-25s %-12s %-5s %-30s\n",
           "ID", "Ho ten", "Email", "SDT", "GT", "Dia chi");
    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < size; i++) {
        printOne(arr[i]);
    }
}

void addNew(struct Person arr[], int *size) {
    if (*size >= MAX_LIST) {
        printf("Danh sach day!\n");
        return;
    }

    int num;
    printf("Nhap so luong lien he muon them: ");
    scanf("%d", &num);
    getchar();

    for (int i = 0; i < num; i++) {
        printf("\n--- Lien he thu %d ---\n", *size + 1);
        struct Person p;

        p.contactId = *size + 1;

        printf("Ho ten: ");
        fgets(p.fullName, sizeof(p.fullName), stdin);
        p.fullName[strcspn(p.fullName, "\n")] = '\0';

        printf("Email: ");
        fgets(p.mail, sizeof(p.mail), stdin);
        p.mail[strcspn(p.mail, "\n")] = '\0';

        printf("So dien thoai: ");
        fgets(p.phoneNum, sizeof(p.phoneNum), stdin);
        p.phoneNum[strcspn(p.phoneNum, "\n")] = '\0';

        printf("Gioi tinh (1=Nam, 0=Nu): ");
        scanf("%d", &p.gender);
        getchar();

        printf("Dia chi: ");
        fgets(p.homeAddr, sizeof(p.homeAddr), stdin);
        p.homeAddr[strcspn(p.homeAddr, "\n")] = '\0';

        arr[*size] = p;
        (*size)++;
    }
}

void updateInfo(struct Person arr[], int size) {
    if (size == 0) {
        printf("Danh sach rong!\n");
        return;
    }

    int id;
    printf("Nhap ID lien he can sua: ");
    scanf("%d", &id);
    getchar();

    if (id < 1 || id > size) {
        printf("ID khong ton tai!\n");
        return;
    }

    struct Person *p = &arr[id - 1];

    printf("\n--- Thong tin hien tai ---\n");
    printOne(*p);

    int ch;
    printf("\n1. Sua ho ten\n");
    printf("2. Sua email\n");
    printf("3. Sua so dien thoai\n");
    printf("4. Sua gioi tinh\n");
    printf("5. Sua dia chi\n");
    printf("Chon muc can sua: ");
    scanf("%d", &ch);
    getchar();

    switch (ch) {
        case 1:
            printf("Ho ten moi: ");
            fgets(p->fullName, sizeof(p->fullName), stdin);
            p->fullName[strcspn(p->fullName, "\n")] = '\0';
            break;
        case 2:
            printf("Email moi: ");
            fgets(p->mail, sizeof(p->mail), stdin);
            p->mail[strcspn(p->mail, "\n")] = '\0';
            break;
        case 3:
            printf("SDT moi: ");
            fgets(p->phoneNum, sizeof(p->phoneNum), stdin);
            p->phoneNum[strcspn(p->phoneNum, "\n")] = '\0';
            break;
        case 4:
            printf("Gioi tinh moi (1=Nam, 0=Nu): ");
            scanf("%d", &p->gender);
            break;
        case 5:
            printf("Dia chi moi: ");
            fgets(p->homeAddr, sizeof(p->homeAddr), stdin);
            p->homeAddr[strcspn(p->homeAddr, "\n")] = '\0';
            break;
        default:
            printf("Lua chon khong hop le!\n");
            return;
    }

    printf("Cap nhat thanh cong!\n");
}

void removeContact(struct Person arr[], int *size) {
    if (*size == 0) {
        printf("Danh sach rong!\n");
        return;
    }

    int id;
    printf("Nhap ID can xoa: ");
    scanf("%d", &id);
    getchar();

    if (id < 1 || id > *size) {
        printf("ID khong hop le!\n");
        return;
    }

    printf("\n--- Thong tin lien he muon xoa ---\n");
    printOne(arr[id - 1]);

    char cf;
    printf("Ban co chac muon xoa? (y/n): ");
    scanf("%c", &cf);

    if (cf == 'y' || cf == 'Y') {
        for (int i = id - 1; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
            arr[i].contactId = i + 1;
        }
        (*size)--;
        printf("Xoa thanh cong!\n");
    } else {
        printf("Huy thao tac!\n");
    }
}

void findContact(struct Person arr[], int size) {
    if (size == 0) {
        printf("Danh sach rong!\n");
        return;
    }

    char keyword[50];
    printf("Nhap tu khoa: ");
    getchar();
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    int found = 0;

    printf("\n--- Ket qua tim kiem ---\n");

    for (int i = 0; i < size; i++) {
        if (strstr(arr[i].fullName, keyword) ||
            strstr(arr[i].mail, keyword) ||
            strstr(arr[i].phoneNum, keyword)) {

            printOne(arr[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay!\n");
    }
}

void sortByName(struct Person arr[], int size) {
    if (size < 2) {
        printf("Khong du du lieu de sap xep!\n");
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(arr[i].fullName, arr[j].fullName) > 0) {
                struct Person temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Sap xep thanh cong!\n");
}

