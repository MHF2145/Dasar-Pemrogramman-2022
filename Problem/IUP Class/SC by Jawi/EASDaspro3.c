#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char The_Matrix[100][100];

void Jadikan(int Rows, int Cols);
void Frint(int Rows, int Cols);
int Fibbonaci(int N);
int PrimeNth(int N);



int main() {
    int D; scanf("%d", &D);
    int mode,Rows,Cols;
    for(int i=0;i<D;i++){
        scanf("%d %d",  &Rows, &Cols);
        Jadikan(Rows, Cols);
        Frint(Rows, Cols);
    }
    return 0;
}

void Jadikan(int Rows, int Cols){
    for(int i=0; i<Rows;i++){
        for(int j=0; j<Cols+2; j++){
            if (j==i+1){
                The_Matrix[i][j]=32;
                The_Matrix[i][j+1]=32;
                The_Matrix[i][j+2]=32;
                    j+=2;

            }
            else{
                The_Matrix[i][j]=42;
            }
        }
    }
}

void Frint(int Rows, int Cols){
    for(int i=0; i<Rows;i++){
        for(int j=0; j<Cols+2; j++){
            if (j==i+2){
                printf("%d", Fibbonaci(i+1));
            }
            else{
                printf("%c", The_Matrix[i][j]);
            }

        }
        printf("\n");
    }
    printf("\n");
}

int Fibbonaci(int N){
    if(N<=2)return 1;
    return Fibbonaci(N-1) + Fibbonaci(N-2);
}

int PrimeNth(int N){
    int PrimeCount=0,i,flag,prime=1;
    while(N!=PrimeCount)
    {
        flag=0;
        prime++;
        for(i=2;i<=(prime/2);i++)
        {
            if(prime%i==0)
                flag=1;
        }
        if(flag==0)
        {
            PrimeCount++;
        }
    }
    return prime;
}
