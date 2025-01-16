/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
#include <stdio.h>

/*funzione duePositivi: SPECIFICA
  input: una sequenza di interi x1,...,xn e un intero n (lunghezza)
  pre-cond: n è la lunghezza della sequenza
  output: un intero verifica
  post-cond: verifica vale 1 se in ogni tripla di interi adiacenti ci sono esattamente 2 numeri positivi. 0,altrimenti.

  TIPO DI PROBLEMA: VERIFICA UNIVERSALE
*/
int duePositivi(int a[], int n){
	int verifica=1;
	int i=0;
	while(i<n-2 && verifica){
		if (!((a[i]>0 && a[i+1]>0 && a[i+2]<=0) || (a[i]<=0 && a[i+1]>0 && a[i+2]>0) || (a[i]>0 && a[i+1]<=0 && a[i+2]>0)))
			verifica=0;
		else
			i++;
	}
	return verifica;
}

/*funzione main*/
int main()
{
	int l;
	//INPUT
	/*leggi la lunghezza*/
	printf("Caro utente, introduci la lunghezza della sequenza: \n");
	scanf("%d", &l);
	/*leggi la sequenza*/
	int seq[l];
	for (int i = 0; i < l; i++)
	{
		printf("Caro utente introduci un intero: \n");
		scanf("%d", &seq[i]);
	}
	//OUTPUT
	if (duePositivi(seq,l))
		printf("Ogni tripla di elementi adiacenti nella sequenza contiene esattamente 2 interi positivi!\n");
	else
		printf("Ogni tripla di elementi adiacenti nella sequenza non contiene esattamente 2 interi positivi!\n");
	return 0;
}