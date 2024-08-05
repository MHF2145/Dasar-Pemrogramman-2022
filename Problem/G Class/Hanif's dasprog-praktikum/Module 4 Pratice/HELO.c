#include <stdio.h>
#include <string.h>

struct data
{
    char id[7], pemain[21];
    int mnng, seri, klh, total;
};

int main()
{
    int m, n, o;
    scanf("%d",&m);
    struct data array[m+1];
    struct data temp;

    for(n = 0; n < m; n++)
    {
    scanf("%s %s %d %d %d",array[n].id, array[n].pemain, &array[n].mnng, &array[n].seri,&array[n].klh);
    array[n].total = array[n].mnng * 30 + array[n].seri * 10 + array[n].klh * (-20);
    }

    for(n = 0; n < m; n++)
    {
     for(o = 0; o < m; o++)
     {
      if(array[n].total > array[o].total)
      {
        temp = array[n];
        array[n] = array[o];
        array[o] = temp;
      }
      else if (array[n].total == array[o].total)
      {
        if(strcmp(array[n].pemain,array[o].pemain)<0)
        {
          temp = array[n];
          array[n] = array[o];
          array[o] = temp;
        }
      }
     }
    }

    for( n = 0; n < m; n++)
    {
      printf("%s %s %d %d %d %d\n", array[n].id, array[n].pemain, array[n].mnng, array[n].seri, array[n].klh, array[n].total);
    }
    return 0;
}
