#include <stdio.h>
#include <math.h>
#include <string.h>

long long int higher=0;
char output[100];

long long int powe(long long int x, long long int y){
    long long int origin = x;
    if(y==0)return 1;
    for(long long int i=0; i<y-1; i++){
        x*=origin;
    }
    return x;
}


void Netral(long long int n){
    if(n-(powe(2,higher))>=0){
        strcat(output, "1");
        higher--;
        if(n-(powe(2,higher+1))>=1){
            Netral(n-(powe(2,higher+1)));
        }
        else if(higher>=0){
            Netral(0);
        }
    }
    else {
        strcat(output, "0");
        higher--;
        if(higher>=0){
            Netral(n);
        }
    }
}

void GreatestDivisor(long long int n){
    if(n>=2){
        higher++;
        GreatestDivisor(n/2);
    }
}

int main(){
    long long int n;
    scanf("%lli", &n);
    GreatestDivisor(n);
    Netral(n);
    printf("%s", output);
}
