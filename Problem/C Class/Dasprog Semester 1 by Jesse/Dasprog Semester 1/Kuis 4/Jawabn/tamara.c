#include <stdio.h>

struct gerbong{
    int nomor;
    int seri;
    int kapasitas;
};

int main(){
    int n;
    scanf("%d", &n);

    struct gerbong bonk[100000];
    int i, j, x;

    if (n > 0 && n < 20){
        for(i = 0 ; i < n ; i++){
            scanf("%d %d %d", bonk[i].nomor , bonk[i].seri , bonk[i].kapasitas);
        }
    }
    
    scanf("%d", &x);

    for (i = 0; i < x; i++)
    {
        scanf();
    }
    


    
}