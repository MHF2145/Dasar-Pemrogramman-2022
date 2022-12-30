#include <stdio.h>

struct data
{
    int input;
};

int main(){
    int n, output, i;

    scanf("%d", &n);

    struct data a[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i].input);
    }

    for (i = 0; i < n; i++)
    {
        if (a[i].input % 2 == 0)
        {
            output = (a[i].input * 2) - 1;
            printf("%d\n", output);
        } else if (a[i].input % 2 != 0)
        {
            output = (a[i].input * 2) + 1;
            printf("%d\n", output);
        }
    }
}