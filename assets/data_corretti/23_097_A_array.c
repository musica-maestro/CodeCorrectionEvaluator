/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............7.5
*/
/* SPECIFICA
 * Input: Una sequenza s di array e la sua lunghezza l
 * Pre-condizione: l è la lunghezza di s
 * Output: Un intero adiacenti
 * Post-condizione: adiacenti è pari a 1 se per ciascuna terna di elementi consecutivi della sequenza,
 * ci sia almeno un elemento della terna multiplo di uno degli altri due; è pari a 0 altrimenti
 * TIPO DI PROBLEMA: Verifica universale
 */
#include <stdio.h>
/* funzione che prende come parametro un array di interi (e la sua lunghezza)
 * e verifica se per ciascuna terna di elementi consecutivi della sequenza,
 * ci sia almeno un elemento della terna multiplo di uno degli altri due */
 int multipli(int interi[], int lunghezza) {
 	//pre: lunghezza è la lunghezza di interi
 	int adiacenti;
 	int i;

 /* inizialmente tutte le terne rispettano la proprietà*/
 	adiacenti = 1;
 /* guarda tutte le terne finchè finisce la sequenza o trovi una terna che non soddisfa la proprietà */
 	i = 0;
 	while(i<lunghezza-2 && adiacenti) {
 		if(interi[i]%interi[i+1]==0 || interi[i]%interi[i+2]==0 || interi[i+1]%interi[i+2]==0)
 		//******** CONDIZIONE INCOMPLETA mancano altre tre combinazioni -1
 		//******** LA CONDIZIONE DEVE ESSERE NEGATA! -1.5
 			adiacenti = 0;
 		else
 			i++;
 	}
 return adiacenti;
 }

 /* funzione principale */
 int main() {
 	int lunghezza;   // numero di elementi dell'array

 	/* INPUT */
 	printf("Ciao utente, sono un programma che legge una sequenza di interi ");
 	printf("e verifica se per ciascuna terna di elementi consecutivi della sequenza, ci sia almeno un elemento della terna ");
 	printf("multiplo di uno degli altri due.\n\n");
 	printf("Quanti interi vuoi introdurre? ");
 	scanf("%d", &lunghezza);

 	int sequenza[lunghezza];
 	printf("\n");
 	for(int i=0; i<lunghezza; i++) {
 		printf("Introduci un intero: ");
 		scanf("%d", &sequenza[i]);
 	}

 	/* OUTPUT */
 	if(multipli(sequenza, lunghezza)) {
 		printf("\nIn ogni terna di elementi consecutivi della sequenza, c'%c almeno un elemento della terna multiplo di uno degli altri due!\n", 138);
 	}
 	else {
 		printf("\nEsiste una terna di elementi consecutivi della sequenza che ha almeno un elemento della terna multiplo di uno degli altri due!\n");
 	}
 }






















