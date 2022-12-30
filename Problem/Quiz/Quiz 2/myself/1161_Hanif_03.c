#include <stdio.h>

int jml(int num);

int bnyk, count;
int num, temp;

int main()
{
    count = 0;
    while (scanf("%d", &num) != EOF)
    {
        
        if (num < temp && count != 0)
        {
            break;
        }
        printf("%d\n", jml(num));
        temp = num;

        count++;
    }
    
    return 0;
}

int jml(int num)
{
    bnyk = 0;
    do
    {
        num /= 10;
        ++bnyk;
    } while (num != 0);
    
}