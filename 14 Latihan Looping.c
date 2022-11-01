#include <stdio.h>

int main(){

    for (int i = 1; i <= 5; i++) {
    printf("* \n");
    }

    //membuat kotak dengan nested loop
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            printf("* ");
        }
    printf("\n");
    }

    //membuat segitiga dengan nested loop dengan input
    int jumlah;
    printf("Input tinggi segitiga: ");
    scanf("%i",&jumlah);
    printf("\n");

    for (int i = 1; i <= jumlah; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
    printf("\n");
    }
    return 0;
}