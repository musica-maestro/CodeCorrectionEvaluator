
/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............8.8
*/
/*SPECIFICA

 *Input: 			un intero n per 'lunghezza', una sequenza di interi (x1, x2, ..., xn)

 *Pre-condizioni: 	nessuna             //******* GLI INTERI DEVONO ESSERE POSITIVI -0.2

 *Output: 			un valore booleano per la varibaile universale 'tutte'

 *Post-condizioni: 	la variabile vale 1 (=TRUE) se in tutte le triple della sequenza ci sono almeno due interi composti da una cifra, 0 (=FALSE) altrimenti

 *TIPO DI PROBLEMA: Verifica Universale*/

#include <stdio.h>		//introduco la libreria standard input output per permettere l'utilizzo di funzioni come printf e scanf

/*funzione che mi  verifica se in tutte le triple di elementi adiacenti della sequenza ci sono almeno due interi con una cifra*/
int dueUnaCifra (int* sequenza, int lunghezza) {
	int tutte=1;		//variabile di Universalità inizializzata ad 1 in quanto non abbiamo ancora trovato una tripla di elem. adiacenti che non contiene almeno due interi ad una cifra
	int i;				//variabile contatore

/*guardo ogni elemento della sequenza finchè la variabile i non assume un valore maggiore o uguale a lunghezza-2
e finchè la variabile di universalità non assume un valore falso*/
	for (i=0; i<lunghezza-2 && tutte; i++) {	//variabile i inzializzata a 0 per partire dal primo elemento (con indice 0)
		if (!(((sequenza[i]>=10 || sequenza[i]<10) && sequenza[i+1]<10 && sequenza[i+2]<10) ||
			((sequenza[i+1]>=10 || sequenza[i+1]<10) && sequenza[i+2]<10 && sequenza[i]<10) ||
			((sequenza[i+2]>=10 || sequenza[i+2]<10) && sequenza[i]<10 && sequenza[i+1]<10)))
			//****** CHE SENSO HA (sequenza[i]>=10 || sequenza[i]>10))? NON SERVE -1
			/*se nella tripla di elementi adiacenti non ci sono almeno due elementi con una cifra
			la variabile diventa falsa*/
			tutte=0;
	}
return tutte;
}

/*funzione principale*/
int main () {
	int lunghezza;		//variabile 'lunghezza' per la dimensione dell'array
	int i;				//variabile contatore

	/*avviso l'utente dello scopo del programma e gli chiedo di darmi la lunghezza (ovvero la dimensione) dell'array*/
	printf ("\nCiao Utente! Io sono il programmma che verifica se in ogni tripla di elementi consecutivi della tua sequenza\nci sono almeno due elementi con una cifra\n");
	printf ("\nOra inserisci la lunghezza della tua sequenza: ");
	scanf ("%d", &lunghezza);				//salvo il valore inserito dall'utente nella variabile lunghezza

/*dopo aver ricevuto e memorizzato il valore della dimensione dell'array dichiaro l'array*/
	int sequenza[lunghezza];
	printf ("\nRiempi ora la tua sequenza.\n");
	/*memorizzo tanti valori (ognuno al proprio indice che va da 0 a lunghezza-1) inseriti dall'utente quanti sono gli spazi nell'array (lunghezza)*/
	for (i=0; i<lunghezza; i++) {
		printf ("\nDammi l'elemento %d: ", i+1);
		scanf ("%d", &sequenza[i]);
	}

/*se il valore restituito dalla funzione è un valore true (=1) allora avviso l'utente che tutte le triple di elem. adiacenti della sequenza da lui inserita contengono almeno due interi con una cifra*/
	if (dueUnaCifra(sequenza, lunghezza))
		printf ("\nNella sequenza che hai inserito in tutte le triple di elementi adiacenti\nci sono almeno due elementi con una cifra!");
/*altrimenti lo avviso del contrario*/
	else
		printf ("\nMi dispiace ma non in tutte le triple della tua sequenza ci sono almeno due elementi con una cifra...");

	printf ("\n");
}