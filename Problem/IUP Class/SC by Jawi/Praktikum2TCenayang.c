#include<stdio.h>

int main(){
    int d, row[10], col[10], sn, sc;
    char m[1000000];

    scanf("%d",&d);

    for(int i=0; i<d;i++){
        scanf("%d %d", &row[i],&col[i]);
    }

    for(int i=0; i<d;i++){
        scanf("%d %[^\n]s", &sn, m);
        int j=0;
        while(m[j]!='\0'){
            sc= m[j];
            if(sn>=26){
                    sn-=26;
                }

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
    }
    for(int i=0; i<d;i++){

    }
    printf("\n");
    for(int i=0; i<d;i++){
        for(int j=0; j<row[i];j++){
            for(int k=0; k<col[i];k++){
                if (k==j+1){
                    printf(" ");
                }
                else{
                    printf("*");
                }
            }
            printf("\n");
        }
        if(d-i>1){
            printf("\n");
        }
    }
    printf("\n");

}
