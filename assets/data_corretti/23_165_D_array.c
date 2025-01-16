/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
/* SPECIFICA DEL PROBLEMA:
* Input: un intero n e una sequenza di interi x1, ..., xn
* Pre-condizioni: sequenza di interi n
* Output: un valore booleano 'verifica'
* Post-condizioni: 'esiste' ha valore TRUE se esiste almeno una tripla di interi adiacenti
 nella sequenza in cui un intero è il resto della divisione fra gli altri due interi,
 vale FALSE altrimenti
* TIPO DI PROBLEMA: verifica esistenziale */

#include <stdio.h>		// includiamo la libreria di funzioni che ci serve
						// per scrivere il programma

/* funzione che riceve come parametri la sequenza di interi e la sua lunghezza e verifica
se la condizione del problema è verificata o no tramite una variabile booleana 'verifica' */
int restoDivisione(int* sequenza, int lunghezza){

	/* dichiariazione con inizializzazione della variabile booleana a FALSE. Rimarrà così fino alla fine
	o finchè non si trova una terna che verifcica la condizione del problema */
	int verifica=0;

	int i=0;		// variabile che indica l'indice dell'elemento della sequenza (partendo dal primo elemento della sequenza)

	/* verifichiamo terne di interi adiacenti finchè ce ne sono o finchè la variabile 'verifica' non diventa TRUE */
	while(i<=lunghezza-3 && verifica==0){

		  /* se è verificata la condizione del problema, la variabile 'verifica' diventa TRUE */
		  if(((sequenza[i]==sequenza[i+1]%sequenza[i+2]) || (sequenza[i]==sequenza[i+2]%sequenza[i+1])) ||
		  	((sequenza[i+1]==sequenza[i]%sequenza[i+2]) || (sequenza[i+1]==sequenza[i+2]%sequenza[i])) ||
		  	((sequenza[i+2]==sequenza[i+1]%sequenza[i]) || (sequenza[i+2]==sequenza[i]%sequenza[i+1])))
		  	verifica=1;

		  /* se la condizione del problema non è verificata passiamo alla terna di interi adiacenti successiva */
		  else
		  	i++;
	}

	return verifica;		// la funzione restituisce il valore della variabile 'verifica'
}

/* funzione principale che chiede all'utente quanto è lunga la sequenza di interi e poi inserisce
tanti interi quanti sono gli spazi nell'array a seconda dell'intero che indica la lunghezza
inizialmente inserito dall'utente. Viene stampato infine un messaggio che informa l'utente
se la condizione del problema è verificata all'interno della sequenza da lui inserita o no*/
int main(){

	int lunghezza;		// variabile che indica la lunghezza dell'array

	/* viene chiesto di inserire un intero che indica la lunghezza dell'array */
	printf("Quanti interi ha la sequenza?\n");
	scanf("%d", &lunghezza);

	int sequenza[lunghezza];		// dichiarato l'array di lunghezza 'lunghezza'

	/* l'utente deve inserire interi finchè gli spazi nell'array non sono finiti */
	for(int i=0; i<=lunghezza-1; i++){
		printf("Inserisci l'intero di indice %d della sequenza: ", i);
		scanf("%d", &sequenza[i]);
	}

	/* la variabile booleana 'verifica' assume il valore restituito dalla funzione restoDivisione */
	int verifica=restoDivisione(sequenza, lunghezza);

	/* viene stampato il messaggio che informa l'utente della verifica o meno della
	condizione del problema */
	if(verifica==1){
		printf("Esiste una terna di interi adiacenti in cui uno dei tre e' ");
		printf("il resto della divisione fra gli altri due.");
	}
	else{
		printf("Non esiste una terna di interi adiacenti in cui uno dei tre e' ");
		printf("il resto della divisione fra gli altri due.");
	}

}