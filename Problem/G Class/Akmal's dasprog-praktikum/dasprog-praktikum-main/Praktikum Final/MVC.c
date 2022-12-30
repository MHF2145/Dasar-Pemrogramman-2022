#include <stdio.h>
#include <string.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

char num[101], ans[101], gay[101];
int len;

void solve(int st, int en)
{
    int l = 0, i, j;
	for(i = st; i < en; i++)
    {
        gay[l] = num[i];
        l++;
    }
	
    for(i = 0; i < len - 1; i++)
    {
        for(j = 1 + i; j < len; j++)
        {
            if(gay[j] > gay[i])
            {
                char temp = gay[j];
                gay[j] = gay[i];
                gay[i] = temp;
            }
        }
    }

    if(strcmp(gay, ans) > 0) strcpy(ans, gay);
}

int main()
{   
    scanf("%s %d", num, &len);

    memset(ans,'0',len);
    
	int st = 0, i;
    for(i = 0; i < (strlen(num) - len) + 1; i++)
    {
        solve(st + i, len + i);
    }
    
	printf("%s\n", ans);
	
	return 0;
}
