/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................11
*/
#include <stdio.h>

/* ESERCIZIO ARRAY
 * INPUT: Sequenze seq di interi di lunghezza lung;
 * PRE-CONDIZIONE: lunghezza lung>=0
 * OUTPUT: un valore esiste di tipo int
 * POST_CONDIZIONE: esiste è pari a 1 se esiste una tripla di elementi consecutivi che
 * contiene almeno due elementi il cui valore è compreso fra -10 e 10(estremi inclusi) e che
 * contiene esattamente due elementi multipli di 3, restituisce 0 altrimenti;
 *
 * TIPO DI PROBLEMA: Verifica esistenziale;
 * */


int compresiMultipli3(int array[], int lung) {
	//pre_condizione: lung >=0 lunghezza della sequenza
	int esiste = 0;
	int i=0;
	while(i<lung-2 && !esiste) {
		if(((array[i]<=10 && array[i]>=-10) && (array[i+1]<=10 && array[i+1]>=-10)
		||(array[i]<=10 && array[i]>=-10) && (array[i+2]<=10 && array[i+2]>=-10)
		|| (array[i+1]<=10 && array[i+1]>=-10) && (array[i+2]<=10 && array[i+2]>=-10))
			&&((array[i]%3==0 && array[i+1]%3==0 && array[i+2]%3!=0)
			|| (array[i]%3==0 && array[i+2]%3==0 && array[i+1]%3!=0)
			||(array[i+2]%3==0 && array[i+1]%3==0 && array[i]%3!=0)))
				esiste = 1;
		else
			i++;
	}
	return esiste;
}


int main(int argc, char **argv)
{
	/* INPUT */
	int lung;
	printf("Programma che verifica se esiste una tripla di elementi consecutivi che contiene almeno due elementi il cui valore %c compreso fra -10 e 10(estremi inclusi) e che contiene esattamente due elementi multipli di 3",138);
	printf("\nQuanti interi ha la sequenza?\n->");
	scanf("%d",&lung);
	int seq[lung];
	printf("Introdurre gli interi della sequenza : \n");
	for(int i=0;i<lung;i++) {
		printf("seq[%d] = ",i+1);
		scanf("%d",&seq[i]);
	}

	/* OUTPUT */
	if(compresiMultipli3(seq,lung))
		printf("Esiste una tripla di elementi consecutivi che contiene almeno due elementi il cui valore %c compreso fra\n -10 e 10(estremi inclusi) e che contiene esattamente due elementi multipli di 3\n",138);
	else
		printf("NON esiste una tripla di elementi consecutivi che contiene almeno due elementi il cui valore %c compreso fra\n -10 e 10(estremi inclusi) e che contiene esattamente due elementi multipli di 3\n",138);
}
