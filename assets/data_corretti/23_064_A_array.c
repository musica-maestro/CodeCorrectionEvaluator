/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............8.8
*/
// librerie di funzioni da includere
#include <stdio.h>
int multipli(int s[],int lunghezza); // dichiaro funzione tutteHannoMultipli

/* SPECIFICA DEL PROBLEMA
INPUT: una sequenza di interi, e la lunghezza della sequenza chiamata 'lunghezza'
PRE-CONDIZIONI: 'lunghezza': e' un intero>=0
 OUTPUT: un intero 'verificato' che restituisce 1 se in tutte le terne di elementi adiacenti della sequenza c'è almeno un elemento
multiplo di uno degli altri due, altrimenti restituisce 0
//******* OUTPUT E POSTCONDIZIONE INSIEME -0.2
problema del tipo : VERIFICA UNIVERSALE */

/* FUNZIONE DI SUPPORTO: se in tutte le terne di elementi adiacenti della sequenza c'è almeno un elemento
multiplo di uno degli altri due restituisce 1, altrimenti 0; riceve come parametri un array di interi e la sua lunghezza*/
int multipli(int s[],int lunghezza){
	int i=0; //variabile contatore
	int verificato=1; // inizializzo ad 1 perchè è un problema di verificaa universale
	do{
		if(!((s[i]%s[i+1]==0) || (s[i]%s[i+2]==0) || (s[i+1]%s[i]==0) || (s[i+1]%s[i+2]==0) || (s[i+2]%s[i]==0) || (s[i+2]%s[i+1]==0))){
			verificato=0; // se la condizione non è verificata per una terna allora verificato=0
		}
		else  //altrimenti vai al prossimo elemento della sequenza
		    i++;
	}while(i<lunghezza-2 && verificato);
//***** LA PRECOND. DICE n>0, MA CON IL DO-WHILE VERIFICHI LA TERNA ANCHE E HAI SOLO DUE ELEMENTI! -1
	return verificato; // la funzione restituisce il valore di verificato
}




// FUNZIONE PRINCIPALE

int main(){

	int lunghezza; // lunghezza sequenza di interi
	int i; // variabile contatore che fa scorrere la sequenza

	printf("Ciao utente sono un programma che ti dice se in tutte le terne di elementi adiacenti\n");
	printf(" di una sequenza c'%c almeno un elemento multiplo di uno degli altri due\n\n",138);

	// INPUT
	// chiedo all'utente quanto vuole che sia lunga la sequenza
	printf("Inserisci la lunghezza della sequenza: ");
	scanf("%d",&lunghezza);
	int sequenza[lunghezza]; // dichiaro sequenza di interi

	// chiedo di inserire i numeri della sequenza
	for(i=0;i<lunghezza;i++){
		printf("Inserisci il numero della sequenza di indice %d: ",i);
		scanf("%d",&sequenza[i]);
	}

    // se la funzione tutteHannoMultipli restituisce 1 stampa questo
	if(multipli(sequenza,lunghezza))
		printf("in tutte le terne di elementi adiacenti della sequenza c'%c almeno un elemento multiplo di uno degli altri due \n",138);
	else // altrimenti stampa questo
		printf("NON in tutte le terne di elementi adiacenti della sequenza c'%c almeno un elemento multiplo di uno degli altri due \n",138);
}