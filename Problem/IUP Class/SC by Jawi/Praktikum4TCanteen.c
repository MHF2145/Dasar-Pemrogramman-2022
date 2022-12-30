#include <stdio.h>
#include <string.h>
#include <math.h>

struct DatabaseMenu{
    char Nama[1000];
    long long int Harga;
};

int Afakahterisi[100]={0};
struct DatabaseMenu m[100];

long long int Cuan=0;

void Tambahkan();
void Ingfokan();
void Pesankan();

int main(){
    char input[6];
    scanf("%s", input);

    if(strcmp(input, "ADD")==0){
        Tambahkan();
    }
    else if(strcmp(input, "INFO")==0){
        Ingfokan();
    }
    else if(strcmp(input, "ORDER")==0){
        Pesankan();
    }
    else if(strcmp(input, "CLOSE")==0){
        printf("Earnings: Rp %lld\n", Cuan);
        printf("TCanteen is closing.. thank you for the visit ^-^");
        return 0;
    }
    else{
        printf("Unknown command!\n");
    }
    main();
}


void Tambahkan(){
    int x;
    scanf("%d", &x);

    getchar();
    scanf("%[^\n]s", m[x].Nama);
    if(Afakahterisi[x]=1){
        scanf("%lld", &m[x].Harga);
        printf("Menu #%lli is already exist\n", x);
    }
    else{
        Afakahterisi[x]=1;
        scanf("%lld", &m[x].Harga);
        printf("Added Menu #%d %s\n", x, m[x].Nama);
    }
}

void Ingfokan(){
    int x;
    scanf("%d", &x);

    if(Afakahterisi[x]==1){
        printf("#%d %s Rp %lld\n", x, m[x].Nama, m[x].Harga);
    }
    else{
        printf("Menu #%d doesn't exist\n", x);
    }
}

void Pesankan(){
    int x,y;
    scanf("%d %d", &x,&y);

    Cuan+=y*m[x].Harga;

    printf("Ordered %dx %s for Rp %lld\n", y, m[x].Nama, m[x].Harga*y);
}
