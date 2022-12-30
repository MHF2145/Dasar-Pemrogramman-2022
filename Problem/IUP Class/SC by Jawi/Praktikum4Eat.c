#include <stdio.h>
#include <string.h>

struct PersonalData{
    char nama[20];
    int Makan;
};

struct TeamData{
    char Name1[20], Name2[20];
    int Eat1, Eat2, totEat;
};

int main(){
    int n, makanan;
    scanf("%d %d", &n, &makanan);

    struct PersonalData inidata[n];

    for(int i=0; i<n; i++){
        scanf("%s", inidata[i].nama);
        scanf("%d", &inidata[i].Makan);
    }

    struct TeamData h2[n];

    for(int i=0; i<n/2; i++){
        scanf("%s", h2[i].Name1);
        for(int j=0;j<n;j++){
            if(strcmp(h2[i].Name1,inidata[j].nama)==0){
                h2[i].Eat1 = inidata[j].Makan;
            }
        }
        scanf("%s", h2[i].Name2);
        for(int j=0;j<n;j++){
            if(strcmp(h2[i].Name2,inidata[j].nama)==0){
                h2[i].Eat2 = inidata[j].Makan;
            }
        }
    }

    for(int i=0; i<n/2;i++){
        h2[i].totEat= h2[i].Eat1 + h2[i].Eat2;
    }

    int winner=0;
    for(int i=0;i<n/2;i++){
        if(h2[winner].totEat<h2[i].totEat){
            winner=i;
        }
    }

    printf("%s & %s Win!\n", h2[winner].Name1, h2[winner].Name2);
    printf("Total Eaten: %d", h2[winner].totEat*makanan);


}
