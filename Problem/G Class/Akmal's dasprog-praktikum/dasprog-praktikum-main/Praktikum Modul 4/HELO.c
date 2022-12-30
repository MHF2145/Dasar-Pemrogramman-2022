#include<stdio.h>

typedef struct list
{
	char id[1001], nama[1001];
	int m, s, k;
	int total;
}list;

void swap(list *a, list *b)
{
    list temp = *a;
    *a = *b;
    *b = temp;
}

int partition(list arr[], int left, int right)
{
    list pivot = arr[right];
    int i = left;
 	int j;
    for(j = left; j < right; j++)
    {
        if(arr[j].total > pivot.total)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
        else if(arr[j].total == pivot.total && strcmp(arr[j].nama, pivot.nama) < 0)
        {   
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[right]);
 
    return i;
}
 
void sort(list arr[], int left, int right)
{
    if(left < right)
    {
        int pivot = partition(arr, left, right);
 
        sort(arr, left, pivot - 1);
        sort(arr, pivot + 1, right);
    }
}

int main()
{
	int n, i;
	
	scanf("%d", &n);
	
	list arr[n + 1];
	
	for(i = 0; i < n; i++)
	{
		scanf("%s %s %d %d %d", arr[i].id, arr[i].nama, &arr[i].m, &arr[i].s, &arr[i].k);
		arr[i].total = (30 * arr[i].m) + (10 * arr[i].s) - (20 * arr[i].k);
	}
	
	sort(arr, 0, n - 1);
	
	for(i = 0; i < n; i++)
	{
		printf("%s %s %d %d %d %d\n", arr[i].id, arr[i].nama, arr[i].m, arr[i].s, arr[i].k, arr[i].total);
	}
}

