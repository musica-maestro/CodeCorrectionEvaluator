/* SPECIFICA (max 1):......0.9
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.9
*/
/* SPECIFICA
 * Input: una sequenza di interi e un intero lunghezza;
 * Pre-condizioni: l'intero lunghezza è la lunghezza della sequenza;
 * Output: Un intero booleano "tutti";
 * Post-condizioni: tutti è positivo se ogni tripla della sequenza contiene esattamente due interi positivi. //********** FALSO, ALTRIMENTI -0.1
 * TIPO DI PROBLEMA: Verifca Universale.
 */

#include <stdio.h>
 /* funzione che verifica se in ogni tripla di una sequenza ci sono esattamente due interi positivi */
int duePositivi(int *a, int l)
{
	int i;		//variabile contatore
	int tutti = 1;		//all'inizio tutte le triple soddisfano la proprietà

	for(i = 0; i < l - 2 && tutti; i++)		//scorro tutta la sequenza una per volta
		if(!((a[i] > 0 && a[i + 1] > 0 && a[i + 2] <= 0) ||		//verifico che in quella tripla ci sono esattamente due interi positivi
			(a[i] <= 0 && a[i + 1] > 0 && a[i + 2] > 0) ||
			(a[i] > 0 && a[i + 1] <= 0 && a[i + 2] > 0)))
			tutti = 0;

	return tutti;
}

/* funzione principale */
int main()
{
	int lunghezza;		//lunghezza della sequenza

	/* input */
	printf("Caro utente, di che lunghezza vuoi la sequenza? ");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];

	for(int i = 0; i < lunghezza; i++)
	{
		printf("Inserisci un elemento della sequenza: ");
		scanf("%d", &sequenza[i]);
	}

	/* output */
	if(duePositivi(sequenza, lunghezza))
		printf("\nIn tutte le triple ci sono esattamente due interi positivi!\n");
	else
		printf("\nNon ci sono esattamente due interi positivi in ogni tripla.\n");
}