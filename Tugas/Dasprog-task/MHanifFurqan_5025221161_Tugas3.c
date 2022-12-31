#include <stdio.h>

int main(){

    int a;
    printf("Masukkan Nilai Anda! \n");
    scanf("%d", &a);
    //a=nilai


        if (a>=86 && a<=100)
        {
            printf("Nilai = A");
        }
        else if (a>=80 && a<=86)
        {
            printf("Nilai = B");
        }
        else if (a>=60 && a<=79)
        {
            printf("Nilai = C");
        }
        else if (a>=40 && a<=69)
        {
            printf("Nilai = D");
        }
        else if (a>=0 && a<=40)
        {
            printf("Nilai = E");
        }
    return 0;
}