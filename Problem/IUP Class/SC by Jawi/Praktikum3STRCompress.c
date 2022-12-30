#include <stdio.h>

int d;
char m[10000], alphabet[26]={0};

void Frinter();

void Compresser(){
    int j=0, sc;
    while(m[j]!='\0'){
            sc= m[j];

            if(sc>=48 && sc<=57){
                j++;
                continue;
            }
            else if(sc==32){
                j++;
                continue;
            }
            if(sc<=90 && sc>=65){
                sc-=65;

                alphabet[sc]++;
                j++;
                }
            else if(sc<=122 && sc>=97){
                sc-=97;

                alphabet[sc]++;
                j++;
                }
        }
    Frinter();

}

void StartHere(){
    scanf("%s",m);
    Compresser();
}

int main(){
    scanf("%d",&d);
    StartHere();
}

void Frinter(){
    for(int i=0; i<26; i++){
        int sc =i;
        if(alphabet[i]==0){
            continue;
        }
        else if(alphabet[i]==1){
            printf("%c", (char)sc+97);
            alphabet[i]=0;
        }
        else{
            printf("[%d%c]", alphabet[i], (char)sc+97);
            alphabet[i]=0;
        }
    }
    d--;
    if(d>0){
        printf("\n");
        StartHere();
    }
}
