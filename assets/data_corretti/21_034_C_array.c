/* SPECIFICA (max 1.5):....1.2
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................10.2
*/
/* SPECIFICA
 * input:x1,x1...xn; un intero n  //******** MANCA IL TIPO DEGLI ELEMENTI DELLA SEQUENZA -0.3
 * pre-condizione: n>=3
 * output: un valore booleano esiste
 * post-condizione: esiste vale 1 se c'è almeno una tripla di elementi consecutivi
 * in cui almeno due elementi hanno valore compreso tra -10 e 10 (inclusi) ed
 * esattamente due elementi sono multipli di 3; esiste vale 0 altrimenti
 *
 * tipo di problema: verifica esistenziale */
 #include <stdio.h>

/* funzione che riceve un array e la relativa lunghezza e restituisce un valore che vale 1
 * se esiste una tripla di elementi consecutivi che contiene almeno due elementi il cui
 * valore è compreso fra -10 e 10 (estremi inclusi) e che contiene esattamente due
 * elementi multipli di 3, restituisce 0 altrimenti */
int compresiMultipli3 (int seq[], int dim) {
	int i;		 //per scandire la sequenza
	int esiste;  //variabile di esistenzialità

	/* inizializzazioni */
	i = 0;
	esiste = 0;	 //inizialmente non hai ancora trovato una terna che soddisfa la proprietà

	/* guarda tutta la sequenza finchè non trovi una terna buona */
	while(i<dim-2 && !esiste)
		/* se la terna non soddisfa la proprietà, guarda quella dopo */
		if(!((((seq[i]>=-10 && seq[i]<=10) && (seq[i+1]>=-10 && seq[i+1]<=10))
		|| ((seq[i+1]>=-10 && seq[i+1]<=10) && (seq[i+1]>=-10 && seq[i+1]<=10)) ||
		//***** SOPRA C'E' DUE VOLTE LA STESSA CONDIZIONE -0.5
			((seq[i+1]>=-10 && seq[i+1]<=10) && (seq[i+2]>=-10 && seq[i+2]<=10)))
			&& ((seq[i]%3==0 && seq[i+1]%3==0 && seq[i+2]%3!=0) ||
			(seq[i]%3==0 && seq[i+1]%3!=0 && seq[i+2]%3==0) || (seq[i]%3!=0 && seq[i+1]%3==0 && seq[i+2]%3==0))))
			i++;
		else	//se ne hai trovata una buona, aggiorna il valore della variabile di esistenzialità
			esiste = 1;

	return esiste;
}


/* funzione principale */
int main(int argc, char **argv) {
	int lunghezza;		//per la lunghezza della sequenza

	printf("Ciao utente!\n");
	printf("Sono un programma che, data una sequenza, verifica\n");
	printf("che ci sia una terna di elementi consecutivi in cui\n");
	printf("almeno due sono sono compresi tra -10 e 10, \n");
	printf("ed esattamente due sono multipli di 3!\n\n ");

	/* input */
	printf("Quanti interi vuoi inserire? ");
	scanf("%d", &lunghezza);

	/* dichiarazione della sequenza */
	int sequenza[lunghezza];

	/* per i valori della sequenza */
	for(int i=0; i<lunghezza; i++) {
		printf("Inserisci un intero: ");
		scanf("%d", &sequenza[i]);
	}

	/* output */
	if (compresiMultipli3(sequenza,lunghezza)) {
		printf("Nella tua sequenza esiste una tripla di elementi consecutivi che contiene\n");
		printf("almeno due elementi il cui valore %c compreso fra -10 e 10 (inclusi) e che\n", 138);
		printf("contiene esattamente due elementi multipli di 3!\n\n");
	}
	else {
		printf("Nella tua sequenza non esiste alcuna tripla di elementi consecutivi che\n");
		printf("contiene almeno due elementi il cui valore %c compreso fra -10 e 10 (inclusi)\n", 138);
		printf("e che contiene esattamente due elementi multipli di 3!\n\n");
	}

	return 0;
}
