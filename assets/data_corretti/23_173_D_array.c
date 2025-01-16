/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.8
*/
/*SPECIFICA
 *Input: un array di interi sequenza e la sua lunghezza l
 *Pre-condizione: l è la lunghezza dell'array
 *Output: una variabile verifica
 *Post-condizione: verifica vale 1 se trovo una tripla che soddisfa //*** DEVI SPEIFICARE COSA -0.2
 *la richiesta, altrimenti vale 0
 *TIPO DI PROBLEMA: verifica esistenziale
*/

#include <stdio.h>

int restoDivisione(int seq[], int l)
{
	int i=0;  	//variabile contatore
	int verifica=0;  	//variabile verifica
	while(i<l-2 && !verifica)  /*coltrollo tutte le triple finchè non finisce l'array, oppure finchè non ne trovo una che soddisfa la richiesta*/
	{   			/*se trovo una tripla che soddisfa la richiesta, pongo la variabile verifica=1, sennò controllo la tripla successiva*/
		if((seq[i]%seq[i+1]==seq[i+2]) || (seq[i+1]%seq[i]==seq[i+2]) ||
		(seq[i]%seq[i+2]==seq[i+1]) || (seq[i+2]%seq[i]==seq[i+1]) ||
		(seq[i+1]%seq[i+2]==seq[i]) || (seq[i+2]%seq[i+1]==seq[i]))
			verifica=1;
		else
			i++;
	}
	return verifica;
}

int main()
{
	/*INPUT*/
	int l; 		// lunghezza dell'array
	printf("Ciao, Utente, sono un programma che legge una sequenza di interi e \n");
	printf("verificase esiste una sequenza di tre interi consecutivi tali che \n");
	printf("uno dei tre sia il resto della divisione degli altri due, quanti interi vuoi inserire? \n");
	scanf("%d", &l);
	int array[l]; 	//creo l'array
	for(int i=0; i<l; i++) //faccio lo scan di ogni elemento dell'array
	{
		printf("dammi un intero:\n");
		scanf("%d", &array[i]);
	}
	/*OUTPUT*/
	if(restoDivisione(array, l))
		printf("Esiste una tripla che verifica la richiesta");
	else
		printf("Non esiste una tripla che verifica la richiesta");
}