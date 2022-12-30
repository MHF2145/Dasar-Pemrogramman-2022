#include <stdio.h>

struct counteer {
    int Konsonan, Vowel, Besar, Kecil;

};
char m[101];

int HitungKonsonan();
int HitungVowel();
int HitungBesar();
int HitungKecil();

int main(){
    struct counteer h1;


    scanf("%[^\n]s", m);

    HitungVowel(&h1.Vowel);
    HitungBesar(&h1.Besar);
    HitungKecil(&h1.Kecil);

    printf("Vowel Number: %d\n", HitungVowel());
    printf("Number of Consonants: %d\n", HitungKonsonan());
    printf("Total Uppercase: %d\n", HitungBesar());
    printf("Total Smallcase: %d", HitungKecil());
}

int HitungKonsonan(){
    int j=0, sc, x=0;
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
            if(sc!=65&&sc!=69&&sc!=73&&sc!=79&&sc!=85&&sc!=97&&sc!=101&&sc!=105&&sc!=111&&sc!=117){

                x++;
                j++;
                }
            else{
                j++;
            }
        }
        return x;
}

int HitungVowel(){
    int j=0, sc, x=0;
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
            if(sc==65||sc==69||sc==73||sc==79||sc==85||sc==97||sc==101||sc==105||sc==111||sc==117){

                x++;
                j++;
                }
            else{
                j++;
            }
        }
        return x;
}

int HitungBesar(){
    int j=0, sc, x=0;
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

                x++;
                j++;
                }
            else{
                j++;
            }
        }
        return x;
}

int HitungKecil(){
    int j=0, sc, x=0;
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
            if(sc<=122 && sc>=97){

                x++;
                j++;
                }
            else{
                j++;
            }
        }
        return x;
}
