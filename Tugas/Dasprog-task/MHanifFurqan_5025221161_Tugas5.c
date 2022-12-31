#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main () {
    int a, b, e, f, g, h, i, j, k, l, total, ones, kabisat, dayskabisat;
    char c[9];
    char d[9];
    int bulanc, buland;
    //char Januari, Februari, Maret, April, Mei, Juni, Juli, Agustus, September, Oktober, November, Desember;
    //char bulan[12] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"}; 

    printf("Enter your dad's year, dad's month, dad's day:");
    scanf("%d %s %d", &e, &c, &a);

    printf("Enter your mom's year, mom's month, mom's day:");
    scanf("%d %s %d", &f, &d, &b);
    
    //jujur ini ngapain
    switch (c[0]) {
        case 'J':
            switch (c[3]) {
                case 'u':
                bulanc = 1;
                break;
                case 'i':
                bulanc = 6;
                break;
            }
            switch (c[2]) {
                case 'l':
                bulanc = 7;
                break;
            }
        case 'F':
            bulanc = 2;
            break;
        case 'M':
            switch (c[2]) {
                case 'r':
                bulanc = 3;
                break;
                case 'i':
                bulanc = 5;
                break;
            }
        case 'A':
            switch (c[1]) {
                case 'p':
                bulanc = 4;
                break;
                case 'g':
                bulanc = 8;
                break;
            }
        case 'S':
        bulanc = 9;
        break;
        case 'O':
        bulanc = 10;
        break;
        case 'N':
        bulanc = 11;
        break;
        case 'D':
        bulanc = 12;
        break;
    }

    switch (d[0]) {
        case 'J':
            switch (d[3]) {
                case 'n':
                buland = 1;
                break;
                case 'i':
                buland = 6;
                break;
            }
            switch (d[2]) {
                case 'l':
                buland = 7;
                break;
            }
        case 'F':
            buland = 2;
            break;
        case 'M':
            switch (d[2]) {
                case 'r':
                buland = 3;
                break;
                case 'i':
                buland = 5;
                break;
            }
        case 'A':
            switch (d[1]) {
                case 'p':
                buland = 4;
                break;
                case 'g':
                buland = 8;
                break;
            }
        case 'S':
        buland = 9;
        break;
        case 'O':
        buland = 10;
        break;
        case 'N':
        buland = 11;
        break;
        case 'D':
        buland = 12;
        break;
    }

    // Januari = 1;
    // Februari = 2;
    // Maret = 3;
    // April = 4;
    // Mei = 5;
    // Juni = 6;
    // Juli = 7;
    // Agustus = 8;
    // September = 9;
    // Oktober = 10;
    // November = 11;
    // Desember = 12;

    //selisih tahun
    g = a - b;
    h = abs(g);

    //kabisat  
    /*if (a % 4 == 0 || b % 4 == 0) {
       kabisat += 1; 
    }
    
    for (int h; h % 4 == 0; h--) {
        if (h == 0) {
            kabisat = 0;
        }
    }*/
    
    dayskabisat = (h * 365) + kabisat;
    //dayskabisat = (h * 365);
    
    
    //printf("%d", h);

    //perhitungan hari
    /*if (bulanc < buland) {
        if (bulanc == 2) {
            e = 28 - e;
        }
        else if (bulanc == 1 || bulanc == 3 || bulanc == 5 || bulanc == 7 || bulanc == 8 || bulanc == 10 || bulanc == 12) {
            e = 31 - e;
        }
        else {
            e = 30 - e;
        }
    }
    if (bulanc > buland) {
        if (buland == 2) {
            e = 28 - e;
        }
        else if (buland == 1 || buland == 3 || buland == 5 || buland == 7 || buland == 8 || buland == 10 || buland == 12) {
            e = 31 - e;
        }
        else {
            e = 30 - e;
        }
    }*/

    if (e - f < 30 || e - f > -30) {
        j -= 1;
    }

    k = e + f;
    l = abs(k);

    //selisih bulan
    i = bulanc - buland;
    j = abs(i);
    j *= 30;
    //31 28 31 30 31 30 31 31 30 31 30 31

    total = dayskabisat + j + l;
    ones = total % 10;

    //printf("Perubahan Hari %d\n", total);

    if (ones == 0 || ones == 1) {
        printf("You are a Calon K\n");
    }
    else if (ones >= 2 && ones <= 5) {
        printf("You are a Calon P\n");
    }
    else {
        printf("Manusia Biasa\n");
    }
    system ("pause");
}

// JADI GINI TEST CASE BIASA SIH BISA, TAPI KALO KENA................................................
// 2024 2 29
// 2020 2 21
// DUARRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
// KOK MALAH JADI CALON PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP