#include <stdio.h>
void Terus_Tidak_Berhenti(void);     /*prototype fungsi*/

main()
{
	Terus_Tidak_Berhenti();
}
/*----- Fungsi menampilkan hasil terus tidak berhenti -----*/
void Terus_Tidak_Berhenti(void)		/*definisi fungsi*/
{
	printf("Ctrl-Break untuk berhenti \n");
	Terus_Tidak_Berhenti();
}

