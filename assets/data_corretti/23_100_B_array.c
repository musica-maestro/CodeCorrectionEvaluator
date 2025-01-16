/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.3
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............8.3
*/
# include <stdio.h>

/*    SPECIFICA
INPUT:  un array di interi e la sua lunghezza
PRE-CONDIZIONI: lunghezza è la lunghgezza dell'array
OUTPUT: un valore booleano che vale 1 se l'istanza del problema è vera vale 0 altrimenti
POST-CONDIZIONI: restituisce un valore booleano se ogni tripla di elementi contiene una coppia di interi adiacenti positivi restituisce 0 altrimenti
TIPOLOGIA:VERIFICA UNIVERSALE*/


/* Funzione ausiliaria che verifica se ogni tripla inserita ha almeno una coppia di interi adiacenti positiva*/

int duePositivi(int* array,int lunghezza){

	int i=0; //variabile contatore

	int universale=1; //variabile boleana che vale 1 inzialmente

	/*guardo tutti gli elementi dell'array finchè non ne trovo uno che non soddisfa la proprieta*/

	while(i<lunghezza-2 && universale){
		/*guardo se ogni tripla di elementi e ogni coppia di elemtneti consecutivi non è  maggiore di 0 cioè positiva */
		if(!(array[i]>0 && array[i+1]>0 && array[i+2]>0))               //******** CONDIZIONE SBAGLIATA -1.5
																		//******* ZERO LO CONSIDERI POSITVO O NEGATIVO ? -0.2
			universale=0; //se vale la condizione la variabile vale 0
		else // se non trovi nessun elemento che soddisfa la condizione vai avanti
			i++;

	}
	return universale;
}


/*Funzione main che gestisce l'interazione con l'utente*/


int main(){

	int lunghezza; // lunghezza array

	/* INPUT*/

	printf("Ciao quanti interi vuoi inserire?   \n");

	scanf("%d", &lunghezza);

	int array[lunghezza]; // dichiaro l'array e fornisco la sua lunghezza

	for(int i=0; i<lunghezza;i++){

		printf("Inserisci l'intero sulla quale vuoi verificare la proprieta':   ");

		scanf("%d", & array[i]);
	}

	/*OUTPUT*/

	if(duePositivi(array,lunghezza)) // se la condizione vale 1 stampa
		printf("La sequenza che hai inserito verifica la proprieta' ovvero esistono due interi positivi per ogni tripla ");
	else // se la condizione vale 0 stampa
		printf("La sequenza che hai inserito NON verifica la proprieta' ovvero NON esistono due interi positivi per ogni tripla ");



}