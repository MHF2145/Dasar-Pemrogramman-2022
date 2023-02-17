#include <stdio.h>

struct kereta {
    int no_kereta;
    int no_seri;
    int kapasitas;
};

int main()
{
	int N;
	scanf("%d", &N);
	struct kereta arr[N + 1];
	
	int i;
	for (i = 1; i <= N; i++)
	{
		int no_kereta;
		scanf("%d", &no_kereta);
		int no_seri;
		scanf("%d", &no_seri);
		int kapasitas;
		scanf("%d", &kapasitas);
		
		arr[i].no_kereta = no_kereta;
		arr[i].no_seri = no_seri;
		arr[i].kapasitas = kapasitas;
	}
	
	int T;
	scanf("%d", &T);
	int jumlah_penumpang = 0;
	
	for (i = 1; i <= T; i++)
	{
		int K;
		scanf("%d", &K);
		
		jumlah_penumpang = jumlah_penumpang + K;
	}
	
	while(1)
	{
		if(jumlah_penumpang <= 0)
		{
			for (i = 1; i <= N; i++)
			{
				printf("%d ", arr[i].no_kereta);
			}
			printf("\n");
			break;
		}
		
		jumlah_penumpang = jumlah_penumpang - arr[1].kapasitas;
		if(jumlah_penumpang >= 0)
		{
			int j;
			for (j = 1; j <= N; j++)
			{
				arr[j - 1] = arr[j];
			}
			arr[N] = arr[0];
		}
	}
}
