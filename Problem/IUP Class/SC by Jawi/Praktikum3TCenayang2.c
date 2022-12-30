#include<stdio.h>

int d;
char m[1000000];

int Fibonacci(int n){
    if (n<=2)return 1;
    return Fibonacci(n-1)+Fibonacci(n-2);
}

int Simplify(int big){
    if(big>=26){
        return big%26;
    }
    else{
        return big;
    }
}

void Encrypt();

void Decrypt();

void StartHere(){
    int sn, ind;
    scanf("%d", &ind);
    if (ind==0){
        Encrypt();
    }
    else if(ind==1){
        Decrypt();
    }
    else{
        printf("Mode is not valid!");
    }
}



int main(){
    scanf("%d",&d);
    StartHere();

}

void Decrypt(){
    int sn;
    scanf("%d %[^\n]s", &sn, m);
    sn=Fibonacci(sn);
    sn=Simplify(sn);
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
                sc-=sn;

                if(sc>90 || sc<65){
                    sc+=26;
                }

                m[j]=(char)(sc);
                j++;
                }
            else if(sc<=122 && sc>=97){
                sc-=sn;

                if(sc>122 || sc<97){
                    sc+=26;
                }
                m[j]=(char)(sc);
                j++;
                }
        }
        printf("\n%s", m);
        d--;
        if(d>0)StartHere();
}

void Encrypt(){
    int sn;
    scanf("%d %[^\n]s", &sn, m);
    sn=Fibonacci(sn);
    sn=Simplify(sn);
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
                sc+=sn;

                if(sc>90 || sc<65){
                    sc-=26;
                }

                m[j]=(char)(sc);
                j++;
                }
            else if(sc<=122 && sc>=97){
                sc+=sn;

                if(sc>122 || sc<97){
                    sc-=26;
                }
                m[j]=(char)(sc);
                j++;
                }
        }
        printf("\n%s", m);
        d--;
        if(d>0)StartHere();
}
