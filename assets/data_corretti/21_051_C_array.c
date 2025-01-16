/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................11
*/
/* Specifica del problema
 * INPUT: Una sequenza di interi e la sua lunghezza l
 * PRE-CONDIZIONE: l >= 3
 * OUTPUT: una variabile intera esiste
 * POST-CONDIZIONE: esiste vale 1 se esiste una tripla di elementi consecutivi che contiene
 * 					almeno due elementi il cui valore è compreso tra -10 e 10 e che contiene
 * 					due elementi multipli di 3, altrimenti vale 0
 *
 * Si tratta di un problema di VERIFICA ESISTENZIALE
 * */
#include <stdio.h>
int compreso(int n) {return n >= -10 && n <= 10;}
int multiplo(int n) {return n%3 == 0;}

int compresiMultipli3(int seq[], int l)
{
	int esiste = 0;
	short i = 0;

	while(!esiste && i < l - 2)
	{
		if( ((compreso(seq[i]) && compreso(seq[i+1])) ||
			(compreso(seq[i+1]) && compreso(seq[i+2])) ||
			(compreso(seq[i]) && compreso(seq[i+2])))  &&
		    ((multiplo(seq[i]) && multiplo(seq[i+1]) && !multiplo(seq[i+2])) ||
			(multiplo(seq[i]) && multiplo(seq[i+2]) && !multiplo(seq[i+1])) ||
			(multiplo(seq[i+1])&& multiplo(seq[i+2]) && !multiplo(seq[i]))))
				esiste = 1;
		else
			i++;
	}

	return esiste;
}

int main()
{
	int l;
	printf("Quanti interi ha la sequenza?\n");
	scanf("%d", &l);

	int seq[l];
	for(short i = 0; i < l; i++)
	{
		printf("\nInserisci l'elemento numero %d: ",i+1);
		scanf("%d", &seq[i]);
	}

	if(compresiMultipli3(seq, l))
		printf("\nEsiste una tripla di elementi consecutivi che contiene almeno due elementi il cui valore e' compreso tra -10 e 10 e che contienedue elementi multipli di 3\n");
	else
		printf("\nNon esiste una tripla di elementi consecutivi che contiene almeno due elementi il cui valore e' compreso tra -10 e 10 e che contienedue elementi multipli di 3\n");

	return 0;
}

