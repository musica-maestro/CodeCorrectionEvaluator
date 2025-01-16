/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................11
*/


/* SPECIFICA
 * Input: Una sequenza s e la sua lunghezza l
 * Pre-condizione: l>=0
 * Output: Un intero 'verificata' (come valore booleano)
 * Post-condizione: L'intero 'verificata' è pari a 1 se esiste una tripla di elementi consecutivi tale che
 * almeno due elementi della tripla hanno somma compresa fra 10 e 20 (estremi inclusi) ed esattamente due
 * elementi della tripla sono fra loro uguali, è pari a 0 altrimenti.
 *
 * TIPO DI PROBLEMA: Verifica esistenziale  */

#include <stdio.h>

/* funzione che riceve come parfametro un array di interi (e la sua lunghezza) e restituisce 1 se esiste una
 * tripla di elementi consecutivi tale che almeno due elementi della tripla hanno somma compresa fra 10 e 20
 * (estremi inclusi) ed esattamente due elementi della tripla sono fra loro uguali, restituisce 0 altrimenti */
int ugualiCompresi(int seq[], int l) {
	//pre: l è la lunghezza di seq, l>=0
	int i;				//contatore
	int verificata;		//variabile di esistenza

	/* inizializzazioni */
	verificata = 0;			//non abbiamo ancora trovato una tripla che soddisfi le proprietà
	i = 0;

	/* vai avanti finchè non finisce la sequenza o finchè non trovi la tripla che soddisfa la proprietà */
	while(i<l-2 && !verificata) {
		/* l'elemento corrente soddisfa le proprietà? */
		if((((seq[i]==seq[i+1]) && (seq[i]!=seq[i+2])) || ((seq[i]==seq[i+2]) && (seq[i]!=seq[i+1])) ||
			((seq[i+1]==seq[i+2]) && (seq[i+1]!=seq[i]))) && ((seq[i]+seq[i+1]>=10 && seq[i]+seq[i+1]<=20)
			|| (seq[i]+seq[i+2]>=10 && seq[i]+seq[i+1]<=20)
			|| (seq[i+1]+seq[i+2]>=10 && seq[i]+seq[i+1]<=20)))

			verificata = 1;			//aggiorna la variabile di esistenza

		/* l'elemento corrente NON soddisfa la proprietà */
		else
			i++;		//passa al prossimo elemento
	}
	return verificata;
}

/* funzione principale */
int main() {
	int l;			//lunghezza array

	/* INPUT */
	printf("Ciao! Sono un programma che, data una sequenza di interi, verifica se esiste una tripla di elementi ");
	printf("consecutivi tale che almeno due elementi della tripla hanno somma compresa fra 10 e 20 ed esattamente ");
	printf("due elementi della tripla sono fra loro uguali\n");

	printf("Quanti interi vuoi inserire?\n");
	scanf("%d", &l);
	int seq[l];

	/* memorizza in un array i valori introdotti dall'utente */
	for(int i=0; i<l; i++) {
		printf("Introduci un intero: ");
		scanf("%d", &seq[i]);
	}
	printf("\n");

	/* OUTPUT */
	if(ugualiCompresi(seq,l)) {
		printf("\nEsiste nella sequenza una tripla di elementi consecutivi tale che almeno due elementi della tripla ");
		printf("hanno somma compresa fra 10 e 20 (estremi inclusi) ed esattamente due elementi della tripla ");
		printf("sono fra loro uguali.\n\n");
	}
	else {
		printf("\nNON esiste nella sequenza una tripla di elementi consecutivi tale che almeno due elementi della ");
		printf("tripla hanno somma compresa fra 10 e 20 (estremi inclusi) ed esattamente due elementi della tripla ");
		printf("sono fra loro uguali.\n\n");
	}
}