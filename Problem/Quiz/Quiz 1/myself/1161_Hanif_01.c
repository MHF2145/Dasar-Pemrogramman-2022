#include<stdio.h>

int perima(int a);

int main()
{
    int a;

    while((scanf("%d", &a) == 1))
	 	{
	 		printf("%d\n", perima(a));

	 		if(getchar() == EOF) 
            {
                break;
            }
	 	}
    return 0;
}

int perima(int a)
{
    int b, c, dicek, skrg = 3;

    if(a == 1) 
    {
        return 2;
    }

    for(b = 1; b < a; skrg++)
    {
        dicek = 1;

        for(c = 2; c < skrg; c++) 
        {
            if(skrg % c == 0) 
            {
                dicek = 0;
            }
        }

        if(dicek == 1) 
        {
            b++;
        }
    }

    return skrg - 1;
}
