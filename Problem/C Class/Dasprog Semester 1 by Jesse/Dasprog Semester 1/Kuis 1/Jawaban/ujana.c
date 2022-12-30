#include <stdio.h>

int main() {
 
   long long angka;
   long long balik = 0;
   int remainder;
 
   scanf("%lld", &angka);
   long long input = angka;
 
    //angka 3 digit
    remainder = angka % 10;
    balik = balik * 10 + remainder;
    angka = angka / 10;
  
    remainder = angka % 10;
    balik = balik * 10 + remainder;
    angka = angka / 10;
 
    remainder = angka % 10;
    balik = balik * 10 + remainder;
    angka = angka / 10;
    
    //angka lebih dari 3 digit
    if(angka !=0 ) {
       remainder = angka % 10;
       balik = balik * 10 + remainder;
       angka = angka / 10;
    }
 
    if(angka !=0 ) {
       remainder = angka % 10;
       balik = balik * 10 + remainder;
       angka = angka / 10;
    }
 
    if(angka !=0 ) {
       remainder = angka % 10;
       balik = balik * 10 + remainder;
       angka = angka / 10;
    }
 
    if(angka !=0 ) {
       remainder = angka % 10;
       balik = balik * 10 + remainder;
       angka = angka / 10;
    }
 
    if(angka !=0 ) {
       remainder = angka % 10;
       balik = balik * 10 + remainder;
       angka = angka / 10;
    }
 
    if(angka !=0 ) {
       remainder = angka % 10;
       balik = balik * 10 + remainder;
       angka = angka / 10;
    }
 
    if(angka !=0 ) {
       remainder = angka % 10;
       balik = balik * 10 + remainder;
       angka = angka / 10;
    }
 
    if(angka !=0 ) {
       remainder = angka % 10;
       balik = balik * 10 + remainder;
       angka = angka / 10;
    }
 
    if(angka !=0 ) {
       remainder = angka % 10;
       balik = balik * 10 + remainder;
       angka = angka / 10;
    }
 
    if(angka !=0 ) {
       remainder = angka % 10;
       balik = balik * 10 + remainder;
       angka = angka / 10;
    }
 
    if(angka !=0 ) {
       remainder = angka % 10;
       balik = balik * 10 + remainder;
       angka = angka / 10;
    }
 
    if(angka !=0 ) {
       remainder = angka % 10;
       balik = balik * 10 + remainder;
       angka = angka / 10;
    }
 
    if(angka !=0 ) {
       remainder = angka % 10;
       balik = balik * 10 + remainder;
       angka = angka / 10;
    }
 
    if(angka !=0 ) {
       remainder = angka % 10;
       balik = balik * 10 + remainder;
       angka = angka / 10;
    }
 
    if(balik == input) {
      printf("Aku mau satenya!");
    }
    else{
      printf("GMW! Aku ga suka satenya!");
    }
 
  return 0;
}