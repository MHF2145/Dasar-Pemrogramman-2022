#include <stdio.h>
#include <string.h>

int main()
{
    int a, b, c;
    char d[] = "YES", e[] = "NO";

    scanf("%d", &b);
    for (a = 0; a < b; a++)
    {
        scanf("%d", &c);
        while (c > 0)
        {
            if(c % 11 == 0)
            {
                c -= 11;
            }
            else if(c % 15 == 0)
            {
                c -= 15;
            }
            else
            {
                c -= 26;
            }
        }
        // if(c == 0)
        // {
        //     printf("YES\n");
        // }
        // else
        // {
        //     printf("NO\n");
        // }
        c == 0 ? printf("%s\n",d) : printf("%s\n",e);
    }
    return 0;
}