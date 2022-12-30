#include <stdio.h>

struct kereta{
    int nomor;
    int seri;
    int kapasitas;
};

int main(){
    int n, test, i, j, penumpang, jumlah = 0, tempe = 0;
    struct kereta gerbong[20];

    scanf("%d", &n);                                                                            //input jumlah gerbong

    
        for(i=0; i<n; i++)
        {
        scanf("%d %d %d", &gerbong[i].nomor, &gerbong[i].seri, &gerbong[i].kapasitas);          //input data gerbong
        }
    

    scanf("%d", &test);                                                                         //input jumlah test yang dilakukan

    for(i = 1; i<=test; i++){ 
        scanf("%d", &penumpang);                                                                //input penumpang yang masuk
        jumlah += penumpang;
    }

    for(i=0; i<n; i++){
         jumlah = jumlah - gerbong[i].kapasitas;

        if(jumlah > 0 ){
            tempe = gerbong[0].nomor;

            for(j=0; j<n-1; j++){
                gerbong[j].nomor = gerbong[j+1].nomor;
            }
            
            gerbong[n-1].nomor = tempe;
        }
         else { 
            break;
        }
    }

    for(i=0; i<n; i++){
        printf("%d ", gerbong[i].nomor);
    }

    return 0;
}