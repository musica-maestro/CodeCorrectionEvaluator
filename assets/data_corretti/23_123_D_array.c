/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.8
*/
/* SPECIFICA
 * Input: una sequenza di interi. //******** MANCA LA LUNGHEZZA -0.2
 * Pre-condizioni: la sequenza di interi deve essere lunga l. //*** NON E' UNA PRECOND, l E' UN INPUT
 * Output: un intero 'esiste'.
 * Post-condizioni: 'esiste' assume valore pari a 1 se, in una tripla, uno dei tre elementi è il resto
 * 			della divisione degli altri due, assume valore pari a 0 altrimenti.
 * TIPO DI PROBLEMA: verifica esistenziale. */


#include <stdio.h>

/*Funzione secondaria che, data una sequenza di interi, verifica se esiste almeno una tripla
 * di elementi che soddisfa le condizioni del problema*/
int restoDivisione(int sequenza[], int l)
{
	int i; 								//Variabile contatore
	int esiste;							//Condizione di esistenza

	/*Inizializzazione*/
	i=1;
	esiste=0;

	/*Analizza ogni tripla finché non è arriva alla fine della sequenza o finché non ha trovato una
	 * tripla che rispetta le condizioni del problema*/
	while(i<l-1&&!esiste)
	{
		/*Se in una tripla un elemento è il resto della divisione degli altri due...*/
		if((sequenza[i-1]%sequenza[i+1]==sequenza[i])||(sequenza[i+1]%sequenza[i-1]==sequenza[i])||
			(sequenza[i-1]%sequenza[i]==sequenza[i+1])||(sequenza[i]%sequenza[i-1]==sequenza[i+1])||
			(sequenza[i]%sequenza[i+1]==sequenza[i-1])||(sequenza[i+1]%sequenza[i]==sequenza[i-1]))
			/*... ho trovato una tripla che rispetta i parametri del problema*/
			esiste=1;

		/*Se ciò non accade, analizza la prossima tripla*/
		else
			i++;
	}

	return esiste;
}

/*Funzione principale*/
int main()
{
	/*Istruzioni del programma*/
	printf("\nCiao utente, questo programma verifica se, data una sequenza di interi,\n");
	printf("esiste una tripla di elementi adiacenti in cui uno dei tre %c il resto della\n", 138);
	printf("divisione degli altri due.\n\n");

	/*INPUT*/
	printf("Inserisci la lunghezza della sequenza di interi: ");
	int l;								//Lughezza della sequenza
	scanf("%d", &l);

	int sequenza[l];					//Sequenza di interi di lunghezza l

	printf("\n");

	/*Inserimento di ogni intero della sequenza*/
	for(int i=0; i<l; i++)
	{
		printf("\nInserisci un intero: ");
		scanf("%d", &sequenza[i]);
	}

	/*OUTPUT*/
	if(restoDivisione(sequenza, l))
		printf("Esiste una tripla nella quale un valore %c il resto della divisione degli altri due.", 138);
	else
		printf("Non esiste alcuna tripla nella quale un valore %c il resto della divisione degli altri due.", 138);
}