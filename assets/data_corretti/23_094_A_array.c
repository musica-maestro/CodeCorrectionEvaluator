/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......2
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............5
*/
/*progettare un algoritmo che data una sequenza di interi verifica che per
ciascuna terna di elementi adiacienti della sequenza, ci sia almeno un
elemento della terna multiplo degli altri due
Input: una sequenza di interi s con una lunghezza l
pre-condizioni: l sia la lunghezza della sequenza
output: un intero "funzioneMultipli"
post-condizione: l'intero "funzione multipli" vale 1 se in tutte le terne di
elementi adiacenti della sequenza è presente almeno un multiplo degli altri due
tipo di problema: Verifica Esistenziale*/
//******* E' UNA VERIFICA UNIVERSALE -1
#include <stdio.h>
int funzionemultipli(int seq[],int len) {  /*dichiaro la funzione e inserisco i parametri formali*/
int i=0;
int multipli=0; 	/*verifica esistenziale quindi inzializzo la variabile a 0*/
	while (i<len-2 && !multipli) { 	/*utilizzo il ciclo while per controllare le terne*/
		if (((seq[i]%2==0) && (seq[i+1]%2==0)) &&  /*utilizzo le variabili booleane per verificare se la mia condizione sia verificata o no*/
			((seq[i+1]%2==0) && (seq[i+2]%2==0)) &&
			((seq[i]%2==0) && (seq[i+2]))) {
			//******** CONDIZIONE SBAGLIATA -2
		multipli=1; /*se la variabile da come risultato 1 essendo esistenziale esce dal ciclo e stampa il printf alla riga 39*/
		}
		else	/*se la variabile non da come risultato 1 incremento per analizzare la nuova terna e rientro nel ciclo*/
			i++;
	}
	//******* QUESTA E' UNA VERIFICA ESITENZIALE, NON UNIVERSALE -2
	return multipli;
}



int main () {
	int i;	 /*variabile contatore*/
	int lun; 	/*lunghezza della sequenza */
	printf ("Ciao utente, quanto vuoi che sia lunga la tua sequenza?: ");
	scanf ("%d", &lun);
	int array[lun];	 /*inserisco la lunghezza lun nell'array*/
   		for (i=0;i<lun;i++) { 	/*utilizzo il ciclo for per inserire gli interi nell corrispettive casella dell'array*/
   			printf("Perfavore utente inserisci un numero intero: ");
   			scanf ("%d", &array[i]);
		}
		if (funzionemultipli(array,lun)) 	/*se la funzione ha valore 1 allora stampa: */
			printf ("Esiste una terna per cui almeno un elemento %c multiplo degli altri due", 138);
		else     							 /*se la funzione ha valore 0 stampa: */
			printf("Non esiste un terna per cui almeno un elemento %c multiplo degli altri due", 138);
}
