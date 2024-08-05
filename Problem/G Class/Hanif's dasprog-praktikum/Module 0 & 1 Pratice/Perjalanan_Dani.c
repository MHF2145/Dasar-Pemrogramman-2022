#include <stdio.h>

int main () {
    
    long long N;

    scanf("Jumlah Test Data : %lld", &N);
    
    if (N%5==1)
    {
        printf("Alpha");
    }
    if (N%5==2)
    {
        printf("Beta");
    }
    if (N%5==3)
    {
        printf("Gamma");
    }
    if (N%5==4)
    {
        printf("Theta");
    }
    if (N%5==0)
    {
        printf("Epsilon");
    }
    

    return 0;

}
