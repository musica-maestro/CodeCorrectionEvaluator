/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9
*/
#include <stdio.h>

/* funzione che verifica se esiste almeno una tripla di interi nella sequenza che contiene almeno
 * due elementi il cui valore è compreso tra -10 e 10 (estremi inclusi) e che contiene esattamente due multipli di 3*/


 /* problema di verifica esistenziale*/
 /* SPECIFICA:
  * INPUT: una sequenza di valori x1,...,xn e un intero n
  * PRE-COND: n rappresenta la lunghezza della sequenza e n>=3
  * OUTPUT: un intero "esiste"
  * POST-COND: "esiste" è una variabile booleana che vale true se esiste almeno una tripla di interi nella sequenza che contiene almeno
  * due elementi il cui valore è compreso tra -10 e 10 (estremi inclusi) e che contiene esattamente due multipli di 3, vale false altrimenti*/


int MultiploDi3(int n)
{
	return (n%3 == 0);
}


int compresiMultipli3(int seq[], int l)
{
	int i = 0;				 // variabile contatore
	int esiste = 0;			// variabile di ricerca esistenziale


	while(i<l-2 && !esiste) {
		//******* ESTREMI INCLUSI! -0.5
		if((((seq[i] > -10 && seq[i] < 10) && (seq[i+1] > -10 && seq[i+1] < 10))
		|| ((seq[i+2] > -10 && seq[i+2] < 10) && (seq[i+1] > -10 && seq[i+1] < 10))
			|| ((seq[i] > -10 && seq[i] < 10)  && (seq[i+2] > -10 && seq[i+2] < 10)))
			&& ((MultiploDi3(seq[i]) && MultiploDi3(seq[i+1]))
			|| (MultiploDi3(seq[i+1]) && MultiploDi3(seq[i+2]))
			|| (MultiploDi3(seq[i]) && MultiploDi3(seq[i+2])))) {
		//******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO DIVISIBILI PER 3 ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
		//******** ES. se la tripla e' 3 12 6 LA TUA CONDIZIONE E' SODDISFATTA  -1.5

				esiste = 1;
			} else {
				i++;
			}
	}
	return esiste;
}
int main()
{
	/*INPUT*/

	int lunghezza;		// variabile che rappresenta la lunghezza della sequenza


	printf("Quanti valori vuoi inserire?\n");
	scanf("%d", &lunghezza);


	int sequenza[lunghezza];
	for(int i = 0; i < lunghezza; i++) {
		printf("Inserisci un valore:\n");
		scanf("%d", &sequenza[i]);
	}
	/*OUTPUT*/
	if(compresiMultipli3(sequenza, lunghezza)) {
		printf("Esiste almeno una tripla di interi nella sequenza che contiene almeno due elementi il cui valore è compreso tra -10 e 10 (estremi inclusi) e che contiene esattamente due multipli di 3!\n");
	} else {
		printf("Non esiste una tripla di interi nella sequenza che contiene almeno due elementi il cui valore è compreso tra -10 e 10 (estremi inclusi) e che contiene esattamente due multipli di 3!\n");
	}
}
