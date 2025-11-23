#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char pass[100];
    printf("Nhap mat khau: ");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = '\0';

    int length = strlen(pass);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    int specialCount = 0;

    char specialChars[] = "!@#$%^&*";

    for(int i = 0; i < length; i++){
        if(isupper(pass[i])) hasUpper = 1;
        else if(islower(pass[i])) hasLower = 1;
        else if(isdigit(pass[i])) hasDigit = 1;
        
        // Kiem tra ky tu dac biet
        for(int j = 0; j < strlen(specialChars); j++){
            if(pass[i] == specialChars[j]){
                hasSpecial = 1;
                specialCount++;
            }
        }
    }

    int isValid = 1;
    if(length < 8) isValid = 0;
    if(!hasUpper || !hasLower || !hasDigit || !hasSpecial) isValid = 0;

    if(isValid){
        printf("Hop le\n");
    } else {
        printf("Khong hop le\n");
        printf("Loi: ");
        if(length < 8) printf("Do dai < 8; ");
        if(!hasUpper) printf("Thieu chu in hoa; ");
        if(!hasLower) printf("Thieu chu thuong; ");
        if(!hasDigit) printf("Thieu chu so; ");
        if(!hasSpecial) printf("Thieu ky tu dac biet; ");
        printf("\n");
    }

    printf("Tong ky tu dac biet: %d\n", specialCount);
    return 0;
}

