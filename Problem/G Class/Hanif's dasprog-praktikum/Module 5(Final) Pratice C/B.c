#include <stdio.h>
#include <string.h>

long revpal(char word[], long hitung, int ukuran);

int main()
{
    char word[2000004];
    int ukuran = strlen(word);

    scanf("%s", word);
    printf("%ld", revpal(word, 0, ukuran));
    return 0;
}

long revpal(char word[], long hitung, int ukuran)
{
    for (int a = 0; a < ukuran; a++)
    {
        int b = a - 1;
        int c = a;
        while (c < ukuran - 1 && word[c] == word [c + 1])
        {
            c++;
        }

        hitung += (c - b) * (c - b + 1) / 2;

        a = c++;
        while (b >= 0 && c < ukuran && word[c++] == word[b--])
        {
            ukuran++;
        }

        if (a == ukuran - 1)
        {
            return ukuran;
        }
        
        
        
    }
    
}