/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...1.9
   TOTALE (10).............9.7
*/
#include<stdio.h>

/* SPECIFICHE
INPUT: una sequenza di interi x1,x2,x3,...,xn
PRECONDIZIONI: nessuna  //******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
OUTPUT: un valore booleano esiste
POSTCONDIZIONI: esiste vale true se in ogni tripla di elementi adiacenti della
sequenza sono presenti almeno due numeri composti da una sola cifra. Vale false altrimenti.
TIPO DI PROBLEMA: verifica universale
*/

/* funzione che verifica se in ogni tripla di elementi adiacenti della sequenza siano
presenti almeno due numeri composti da una sola cifra. */
int dueUnaCifra(int seq[], int l) {

	/* dichiarazione variabili */
	int i = 0;	// variabile contatore
	int esiste = 1; // variabile di universalità

	/* fintanto che ho degli elementi da controllare o non trovato la mia condizione */
	while(i<l-2 && esiste) {
		if(!((seq[i]>=0 && seq[i]<=9) && (seq[i+1]>=0 && seq[i+1]<=9)) &&
		   !((seq[i]>=0 && seq[i]<=9) && (seq[i+2]>=0 && seq[i+2]<=9)) &&
		   !((seq[i+1]>=0 && seq[i+1]<=9) && (seq[i+2]>=0 && seq[i+2]<=9)))
			esiste = 0;

		/* se la proprietà vale vado al prossimo elemento */
		else
		i++;
	}

	return esiste;
}

/* funzione principale */
int main()
{
	/* dichiarazione variabili */
	int i = 0;	// variabile contatore
	int lunghezza;	// lunghezza array

	/* INPUT */
	printf("Ciao sono un programma che verifica se in ogni tripla di elementi adiacenti della sequenza di numeri che tu introduci sono presenti almeno due numeri composti da una solo cifra! \n");
	printf("Dimmi quanti numeri hai sottomano? \n");
	scanf("%d", &lunghezza);

	int array[lunghezza];

	while(i<lunghezza) {
		printf("Dammi un numero:");  //**** APPICCICATO -0.1
		scanf("%d", &array[i]);
		i++;
	}

	/* OUTPUT */
	if(dueUnaCifra(array, lunghezza))
		printf("Si, in ogni tripla di elementi adiacenti della sequenza sono presenti almeno due numeri composti da una solo cifra");
	else
		printf("No, in ogni tripla di elementi adiacenti della sequenza non sono presenti almeno due numeri composti da una solo cifra\n");

	return 0;
}