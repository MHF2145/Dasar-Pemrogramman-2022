//Bismillah AC
#include<stdio.h>
#include<stdbool.h>

bool prime(int inp); // deklarasi boolean prima

int main()
{
    int b, c;

    scanf("%d", &b);

    while(b--)
    {
        scanf("%d", &c);
        int f = 0;
        int num[c];
        for(int d = 0; d < c; d++)
        {
            scanf("%d", &num[c]);
            if (prime(num[c]))
            {
                f++;
                printf("%d ", num[c]);
            }
        }
        if (f == 0)
        {
            printf("Unable to send Fever Slot Buckle.\n");
        }
        else
        {
            printf("\n");
        }
    }
}

// fungsi ngecek bilangan prima pake boolehan
bool prime(int inp)
{
    
    if (inp == 2 || inp == 3)
    {
        return true;
    }
    if (inp <= 1 || inp % 2 == 0 || inp % 3 == 0)
    {
        return false;
    }
    for (int a = 5; a * a <= inp; a += 6)
    {
        if (inp % a == 0 || inp % (a + 2) == 0)
        return false;
    }
    return true;
}
