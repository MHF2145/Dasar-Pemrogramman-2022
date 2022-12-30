#include<stdio.h>

int main(){
    int digits, temporaryvalue, increment=0, s;
    char numers[101]={0}, winlose[1];
    char tandakutip[1]="!";
    s=tandakutip[0];
    s+=1;
    tandakutip[0]=(char)(s);


    scanf("%d %s %c", &digits, &numers, &winlose);


    if(winlose[0]=='L'){
        printf("Lose! you're no longer a quadrillionaire now :\"(");
        return 0;
    }
    else if(winlose[0]=='W'){
            printf("Win!\nPrize: ");
        for(int i=digits-1; i>=0;i--){
            temporaryvalue =(int)('0'-numers[i]) *(-1);
            temporaryvalue*=2;


            temporaryvalue+=increment;

            increment=(temporaryvalue)/10;
            temporaryvalue%=10;

            numers[i]=temporaryvalue+'0';


        }
    }
    else{
        printf("Jackpot!\nPrize: ");
        for(int i=digits-1; i>=0;i--){
            temporaryvalue =(int)('0'-numers[i]) *(-1);
            temporaryvalue*=5;


            temporaryvalue+=increment;

            increment=(temporaryvalue)/10;
            temporaryvalue%=10;

            numers[i]=temporaryvalue+'0';


        }
    }
    if(increment!=0){
        printf("$%d%s", increment,numers);
    }
    else{
        printf("$%s", numers);
    }

}
