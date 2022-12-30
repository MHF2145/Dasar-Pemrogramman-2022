#include <stdio.h>

int main(){
    long long int a,b,c,d,e,f,g;
    long long int A,B,C,D,E,F,G;
    long long int totalbit;

    scanf("%d %d %d %d %d %d %d", &a,&b,&c,&d,&e,&f,&g);

    A = ((a/8)%2) + ((a/4)%2) + ((a/2)%2) + ((a/1)%2);
    B = ((b/8)%2) + ((b/4)%2) + ((b/2)%2) + ((b/1)%2);
    C = ((c/8)%2) + ((c/4)%2) + ((c/2)%2) + ((c/1)%2);
    D = ((d/8)%2) + ((d/4)%2) + ((d/2)%2) + ((d/1)%2);
    E = ((e/8)%2) + ((e/4)%2) + ((e/2)%2) + ((e/1)%2);
    F = ((f/8)%2) + ((f/4)%2) + ((f/2)%2) + ((f/1)%2);
    G = ((g/8)%2) + ((g/4)%2) + ((g/2)%2) + ((g/1)%2);

    totalbit = A + B + C + D + E + F + G;

    if(totalbit > 14){
        printf("Jangan Rakus bang :3");
    } else if(totalbit == 14){
        printf("Nikmati aja bang :\\");
    } else if(totalbit < 14){
            if((totalbit % 2) == 0){
                printf("Semangat Bang :(");
            } else {
                printf("Hallo Bang");
            }       
    }

    return 0;
}