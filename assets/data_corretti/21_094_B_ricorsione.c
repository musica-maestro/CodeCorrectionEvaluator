/*
5pt minimo dispari:..4
1pt scrivi numeri:...0
2pt quanti numeri:...0
2pt leggi numeri:....0
TOTALE ..............4
*/
#include <stdio.h>
#include <stdlib.h>

/* SPECIFICA:
 * DATI IN INGRESSO: 'lunghezza' e 'scelta'
 * PRE: 'lunghezza' e' la dimensione dell'array, 'scelta' sono gli interi della sequenza
 * DATI IN USCITA : 'verificato'
 * POST: 'verificato' e' un intero ed ha valore 1 in caso la proprieta' sia verificata, 0 altrimenti
 * TIPO DI PROBLEMA: verifica universale
 */

 /* FUNZIONE CHE VERIFICA SE L'INTERO MINORE E' DISPARI */
 int isDispari(int n1, int n2, int n3){

	 return (((n1<n2 && n1<n3) && n1%2==1) || ((n2<n3 && n2<n1) && n2%2==1) || ((n3<n2 && n3<n1) && n3%2==1));
 }

/* FUNZIONE RICORSIVA CHE VERIFICA CHE IN OGNI TRIPLA L'INTERO MINORE E' DISPARI */
int minimoDispari(int *seq, int lunghezza){

	int verificato = 1; // variabile universale

	/* CASO BASE */
	if(lunghezza == 3){//**** se lunghezza=1 o 2, vai nel passo ricorsivo e accedi a valori che non fanno parte dell'array -1
		verificato = isDispari(seq[0],seq[1],seq[2]) ;
		/* PASSO RICORSIVO */
	}else{
		verificato = isDispari(seq[0],seq[1],seq[2]) && minimoDispari(seq+1, lunghezza-1);
	}

	return verificato;

}

/* FUNZIONE CHE CONTA ... */
int quantiNumeri() {

}

/* FUNZIONE CHE LEGGE UNA SEQUENZA DI INTERI DA UN FILE */
void leggiNumeri(int* sequenza, int lunghezza) {
}

/* FUNZIONE CHE SCRIVE GLI INTERI RICEVUTI SU UN FILE */
void scriviNumeri(int* sequenza, int lunghezza) {

		/*fopen(fp) =  ("interi.txt","w");
		for( int i= 0 ; i<lunghezza; i++){
		fprintf("%d ",sequenza[i]);
		}


		printf("\nScrittura eseguita\n");
	*/
}

/* FUNZIONE PRINCIPALE */
int main() {
    int lunghezza; 		//	lunghezza dell'array
	int scelta;				//	scelta dell'utente

    /* acquisizione dati e lettura dell'array da input */
    printf("Vuoi introdurre una nuova sequenza (premi 1) oppure recuperarla da file (premi 2)? ");
    scanf("%d",&scelta);

	/* introduzione sequenza da input */
	if(scelta==1) {
		/* determina la lunghezza della sequenza */
		printf("Introduci la lunghezza della sequenza: ");
		scanf("%d",&lunghezza);

		/* crea l'array e leggine i valori degli elementi */
		int array[lunghezza];
		printf("Scrivi %d elementi \n",lunghezza);
		for(int i=0;i<lunghezza;i++)
			scanf("%d",&array[i]);

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(minimoDispari(array,lunghezza))
			printf(" Perfetto l'intero minimo di ogni tripla e' negativo \n");
		else
			printf(" Peccato l'intero minimo di ogni tripla NON e' negativo \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
	/* recupero sequenza da file */
	else {
		/* determina la lunghezza della sequenza */
		lunghezza = quantiNumeri();

		/* crea l'array e leggine i valori degli elementi da file */
		int array[lunghezza];
		leggiNumeri(array,lunghezza);
		printf("Ecco la sequenza recuperata\n");
		for(int i=0;i<lunghezza;i++)
			printf("%d ", array[i]);
		printf("\n");

		/* invoca la funzione ricorsiva e stampa il risultato */
		if(minimoDispari(array,lunghezza))
			printf(" Perfetto l'intero minimo di ogni tripla e' negativo \n");
		else
			printf(" Peccato l'intero minimo di ogni tripla NON e' negativo \n");

		/* salva la sequenza su file */
		scriviNumeri(array,lunghezza);
	}
}