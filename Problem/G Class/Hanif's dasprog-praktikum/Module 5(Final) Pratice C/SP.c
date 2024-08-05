#include <stdio.h>
#include <string.h>

int main () {

    int many, i, a;
    int Gnjl, Gnp;

    scanf("%d", &many);
    for (a = 0; a < many; a++) //terus disini biar bisa input lagi
    {
        scanf("%d", &i);
        if (i % 2 == 1)
        {
            Gnjl = (2 * i) + 1;
            printf("%d\n",Gnjl);
        }
        else if (i % 2 == 0)
        {
            Gnp = (2 * i) - 1;
            printf("%d\n",Gnp);
        }
    }


    return 0;
}