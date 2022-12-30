#include <stdio.h>

int main()
{
    char a,b,c;
    // char x[10], y[10], z[10];
    int kunci;

    // x = a;
    // y = b;
    // z = c;

    // printf ("%s%s%s")

    scanf ("%c%c%c", &a, &b, &c);
    scanf ("%d", &kunci);

    int x = a;
    int y = b;
    int z = c;

    
    if ((x + kunci >= 65 && x + kunci <=90) || (x + kunci >= 97 && x + kunci <=122))
    {
        if ((y + kunci >= 65 && y + kunci <=90) || (y + kunci >= 97 && y + kunci <=122))
        {
            if ((z + kunci >= 65 && z + kunci <=90) || (z + kunci >= 97 && z + kunci <=122))
            {
                x += kunci;
                y += kunci;
                z += kunci;

                printf ("Putri Ada Di Ruangan %c%c%c Raja!", x, y, z);
            }
            else {printf ("SALAH KASTIL NIH!");}
        }
        else {printf ("SALAH KASTIL NIH!");}
    }
    else {printf ("SALAH KASTIL NIH!");}
}