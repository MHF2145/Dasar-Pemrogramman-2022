#include <stdio.h>

struct kereta{
    int nomor;
    int seri;
    int kapasitas;
};

int main(){
    int n, test, i, j, penumpang, jumlah = 0, setor = 0;
    struct kereta gerbong[50000];

    scanf("%d", &n);                                                                            

    if (n > 0 && n <= 20)
    {
        for(i=0; i<n; i++)
        {
        scanf("%d %d %d", &gerbong[i].nomor, &gerbong[i].seri, &gerbong[i].kapasitas);
        }
    }

    scanf("%d", &test);                                                                         
    for(i = 1; i<=test; i++){ 
        scanf("%d", &penumpang);                                                                
        jumlah += penumpang;
    }

    for(i=0; i<n; i++){
         jumlah = jumlah - gerbong[i].kapasitas;        

        if(jumlah >= 0 ){
            setor = gerbong[0].nomor;

            for(j=0; j<n-1; j++){                       
                gerbong[j].nomor = gerbong[j+1].nomor;  
            }
            
            gerbong[n-1].nomor = setor;                 
        }
         else if(jumlah < 0){ 
            break;
        }
    }

    for(i=0; i<n; i++){
        printf("%d ", gerbong[i].nomor);
    }

    return 0;
}