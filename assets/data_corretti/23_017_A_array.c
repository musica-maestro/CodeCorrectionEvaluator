/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/

/* SPECIFICA
 * Input: Una sequenza d'interi s e la sua lunghezza l
 * Pre-condizione: l è la lunghezza di s
 * Output: Un intero cond
 * Post-condizione: cond=1 se per ciascuna terna terna di elementi adiacenti della sequenzaci ci sia
 *                  almeno un elemento della terna multiplo di uno degli altri due, altrimenti cond=0
 * TIPO DI PROBLEMA: Verifica universale */

#include <stdio.h>

/* funzione con parametri un array di interi e la sua lunghezza che verifica
 * se per ciascuna terna terna di elementi adiacenti della sequenzaci ci sia almeno un elemento della terna multiplo di uno degli altri due*/
int multipli(int s[], int l){
	//pre: l è la lunghezza di s
	int cond=1; //variabile di universalità inizializzata a 1 dato che ancora non abbiamo trovato eccezioni alla proprietà
	for(int i=0; (i<l-2) && cond ; i++) //scorriamo l'array fino alla fine o fino a che non è verificata la proprietà
		if( !( (s[i]%s[i+1]==0 || s[i]%s[i+2]==0) ||     //verifichiamo se s[i] NON è multiplo di s[i+1] o s[i+2]
			   (s[i+1]%s[i]==0 || s[i+1]%s[i+2]==0) || 	 //verifichiamo se s[i+1] NON è multiplo di s[i] o s[i+2]
			   (s[i+2]%s[i]==0 || s[i+2]%s[i+1]==0) ) )  //verifichiamo se s[i+2] NON è multiplo di s[i] o s[i+1]
			cond=0; //se verificata cambiamo la variabile di universalità in 0
	return cond;
}

/* funzione principale*/
int main(int argc, char const *argv[])
{
	int lunghezza; //lunghezza array
	printf("Ciao, sono un programma che, data una sequenza di interi, ");
	printf("verifica se per ciascuna terna di elementi adiacenti della sequenza, ");
	printf("ci sia almeno un elemento della terna multiplo degli atri due.\n");
	printf("Quanti interi vuoi inserire? ");
	scanf("%d", &lunghezza); // utente inserisce la lunghezza

	int array[lunghezza];
	printf("Inserisci gli interi:\n");
	for(int i=0; i<lunghezza; i++) // utente inserisce gli interi
		scanf("%d", &array[i]);

	/* Output */
	if( multipli(array, lunghezza) ) //se verificata la proprietà
		printf("La sequenza rispetta la proprieta'\n");
	else
		printf("La sequenza NON rispetta la proprieta'\n");
	return 0;
}