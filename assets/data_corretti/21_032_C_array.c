/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9.5
*/
/* SPECIFICA
 * Input: una sequenza di interi 's' e un intero 'l'
 * Pre-condizione: 'l' è la lunghezza (dimensione) di 's'
 * Output: un intero 'risultato'
 * Post-condizione: 'risultato' restituisce 1 (true)  se
 * esiste una tripla di elementi consecutivi che contiene
 * almeno due elementi il cui valore è compreso tra -10 e
 * 10 (estremi inclusi) e che contiene esattamente due elementi
 * multipli di 3, restituisce 0 (false) altrimenti.
 *
 * TIPO DI PROBLEMA: verifica esistenziale */


#include <stdio.h>

/* funzione che riceve come parametro un array di interi e verifica
 * se esiste una tripla di elementi consecutivi che contiene
 * almeno due elementi il cui valore è compreso tra -10 e
 * 10 (estremi inclusi) e che contiene esattamente due elementi
 * multipli di 3, restituisce 0 (false) altrimenti. */

int compresiMultipli3(int seq[], int lunghezza){
	int risultato=0;		// variabile di esistenza inizializzata a zero
	int i=0;				// variabile contatore

	/* scorri la sequenza fino alla fine o interrompi prima se individui
	 * la tripla che soddisfa la verifica richiesta */
	 while(i<lunghezza-2 && !risultato)
		 if((seq[i]>=-10 && seq[i]<=10 && seq[i+1]>=-10 && seq[i+1]<=10) ||
			(seq[i]>=-10 && seq[i]<=10 && seq[i+2]>=-10 && seq[i+2]<=10) ||
			(seq[i+1]>=-10 && seq[i+1]<=10 && seq[i+2]>=-10 && seq[i+2]<=10) &&
			((seq[i]%3==0 && seq[i+1]%3==0) || (seq[i]%3==0 && seq[i+2]%3==0) ||
			(seq[i+1]%3==0 && seq[i+2]%3==0)))
			//******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO DIVISIBILI PER 3 ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
			//******** ES. se la tripla e' 3 12 6 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
			 risultato=1;
			 else
				 i++;
				 return risultato;
}

/* funzione principale */
int main(){
	/* dichiarazione variabili */
	int lunghezza;

	/* input */
	printf("Caro utente, sono un programma che legge una sequenza di interi ");
	printf("e comunica se esiste almeno una tripla di elementi consecutivi ");
	printf("che contiene almeno due elementi ");
	printf("il cui valore e' compreso tra -10 e 10 (estremi inclusi) e che ");
	printf("contiene esattamente due elementi multipli di 3.\n");

	printf("Quanti interi contiene la tua sequenza? ");
	scanf("%d", &lunghezza);

	int sequenza[lunghezza];

	/* leggi l'array da tastiera */
	for(int i=0; i<lunghezza; i++){
		printf("Introduci un intero: ");
		scanf("%d%", &sequenza[i]);
	}

	if(compresiMultipli3(sequenza, lunghezza)){
		printf("Esiste almeno una tripla di elementi consecutivi ");
		printf("che contiene almeno due elementi ");
		printf("il cui valore e' compreso tra -10 e 10 (estremi inclusi) e che ");
		printf("contiene esattamente due elementi multipli di 3\n");

	}
		else{
			printf("Non esiste una tripla di elementi consecutivi ");
			printf("che contiene almeno due elementi ");
			printf("il cui valore e' compreso tra -10 e 10 (estremi inclusi) e che ");
			printf("contiene esattamente due elementi multipli di 3\n");

		}
}
