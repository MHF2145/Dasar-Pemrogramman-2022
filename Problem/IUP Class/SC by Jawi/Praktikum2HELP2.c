/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main(){
    long long int counter;
    long long int number[100]= {0}, olength[100]={0}, mlength[100]={0};
    char type[2][10]={0};

    scanf("%lli", &counter);

    for(long long int c=0; c<counter; c++){
        scanf("%s %lli %lli", &type[1][c], &number[c], &olength[c]);
    }


    for(long long int i=0; i< counter;i++){


        if(type[1][i]=='A'){
                printf("pattern no : %lli", i+1);
            if(olength[i]%2==0){
                mlength[i]=olength[i]/2;
            }
            else{
                mlength[i]= (olength[i]-1)/2;
            }

            for(long long int j=0; j<number[i];j++){
                printf("\n");
                if(j%2==0){
                printf(" ");
                }
                for(long long int k=0; k<mlength[i];k++ ){
                    printf(".-");

                }
                if(olength[i]%2!=0){
                    printf(".");
                }
            }
        }
        else{
            printf("pattern no : %lli", i+1);
            if(olength[i]%2==0){
                mlength[i]=olength[i]/2;
            }
            else{
            mlength[i]= (olength[i]-1)/2;
            }

            for(long long int j=0; j<number[i];j++){
                printf("\n");
            if(j%2!=0){
                printf(" ");
            }
                for(long long int k=0; k<mlength[i];k++ ){
                    printf("-.");
                }
                if(olength[i]%2!=0){
                printf("-");
                }
            }
        }
    if(counter-i>1){
        printf("\n");
    }





}
}
