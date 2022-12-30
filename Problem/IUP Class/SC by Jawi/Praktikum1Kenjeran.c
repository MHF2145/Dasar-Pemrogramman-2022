#include <stdio.h>

int main(){
    long long int M, N, T1, T2, sisa, mobilkeluar, totalmobilkeluar;
    scanf("%lli %lli %lli", &M, &N, &T1);

    T2=T1/85;
    sisa=T1%85;
    mobilkeluar=T2*12;

    if (sisa-25>=0){
        totalmobilkeluar= mobilkeluar + ((sisa-25)/5);
    }
    else{
        totalmobilkeluar= mobilkeluar;
    }
    if (totalmobilkeluar<M+1){
        printf("NO! ");
    }
    else{
        printf("YES! ");
    }

    if(totalmobilkeluar>=M+1+N){
        printf("0");
    }
    else if(totalmobilkeluar>=M+1){
        printf("%lli", (M+1+N)-totalmobilkeluar);
    }
    else if(totalmobilkeluar<=M){
        printf("%lli", (M+1+N)-totalmobilkeluar);
    }



}
