/* SPECIFICA (max 1):......0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...1.8
   TOTALE (10).............9.5
*/
#include <stdio.h>

/*Specifica

Input: una sequernza seq[] di lunghezza l //******* MANCA IL TIPO -0.2

Pre-condizioni: l è la lunghezza dell'array seq[]

Output: una variabile multiplo

Post-condizioni: multiplo verifica se in ciascuna terna di elementi adiacenti
esiste almeno un elemento della terna multiplo di uno degli altri due. //****** FALSO, ALTRIMENTI -0.1

Tipo di Problema: verifica universale

*/

/*Funzione che riceve come parametro un'array e la sua lunghezza e verifica se
in ciascuna terna di elementi adiacenti esiste almeno un elemento della terna
multiplo di uno degli altri due. Se la proprietà è verificata, la funzione
restituisce 1, altrimenti 0. */
int multipli(int seq[], int lunghezza){
	//pre-cond: lunghezza è la lunghezza dell'array seq[]
	int i;			//contatore
	int multipli;	//variabile universale
	/*Inizializzazioni*/
	i=0;
	multipli=1;	//ancora non ho trovato un elemento che verifichi la proprietà
	//controllo tutti gli elementi dell'array dal primo, inizializzando i=0, fino all'ultimo
	while(i<=lunghezza-3 && multipli){
		//verifico se in una terna esiste almeno un elemento che è multiplo di uno trai due rimanenti
		if(!((seq[i]%seq[i+1]==0 || seq[i]%seq[i+2]==0) ||
		   (seq[i+1]%seq[i]==0 || seq[i+1]%seq[i+2]==0) ||
		   (seq[i+2]%seq[i]==0 || seq[i+2]%seq[i+1]==0)))
			multipli=0;
		else 		//se non esisto vado avanti
			i++;
	}
	return multipli;
}


int main()
{
	int dimensione;			// lunghezza array
	int i;					//contatore
	int array[dimensione];	//sequenza di caratteri inserita

	/* INPUT */
	printf("Salve utente! Sono un programma che legge una sequenza di caratteri e verifica ");
	printf("se per ciascuna terna di elementi adiacenti della sequenza esiste almeno un elemento della terna ");
	printf("multiplo di uno degli altri due\n");

	/*Definisco la lunghezza della sequenza*/
	printf("Quanti caratteri vuoi inserire? ");
	scanf("%d", &dimensione);

	/*Definisco i caratteri che costituiscono l'array*/
	for(i=0; i<dimensione; i++){
		printf("Inserici i caratteri: "); //**** DEVI CHIEDERE DI INSERIRE INTERI, NON CARATTERI -0.2
		scanf("%d", &array[i]);
	}

	/*Invocazione della funzione multipli e Output*/
	if(multipli(array,dimensione)){
		printf("Per ciascuna terna di elementi adiacenti, esiste almeno un elemento della terna ");
		printf("che %c multiplo di uno degli altri due!\n", 138);
	}
	else{
		printf("Non in tutte le terne di elementi adiacenti, esiste almeno un elemento della terna ");
		printf("che %c multiplo di uno degli altri due!\n", 138);
	}
}