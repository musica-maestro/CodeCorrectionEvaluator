/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............8.5
*/
/*SPECIFICA DEL PROBLEMA
*Input: una sequenza di interi "interi" e la sua lunghezza "dimensione".
*Pre-condizione: "lunghezza" è la lunghezza della sequenza "interi" e lunghezza è >=3.
*Output: un intero booleano "esiste".
*Post-condizione: l'intero esiste vale 1 se in tutte le terne adiacenti della sequenza c'è un elemento multiplo di uno degli altri due, altrimenti vale 0.
*Tipo di problema: verifica universale
*/

#include <stdio.h>

/*FUNZIONE MULTIPLI*/

int multipli(int interi[], int dimensione){

	int esiste = 1;		//intero booleano
	int i = 0;			//vaiabile contatore

	while(i<=dimensione-2 && esiste){
		if(!(interi[i]%interi[i+1]==0 && interi[i]%interi[i+2]==0)||
		    (interi[i+1]%interi[i]==0 && interi[i+1]%interi[i+2]==0) ||
		    (interi[i+2]%interi[i]==0 && interi[i+2]%interi[i+1]==0))		//proprietà da verificare
		    //***** NON DEVE ESSERE MULTIPLO DI ENTRAMBI, ALMENO DI UNO DEI DUE, || AL POSTO DI && -1.5
			esiste = 0 ;
		else
			i++;
	}

	return esiste;
}

/*FUNZIONE PRINCIPALE*/

int main(){
	/*input*/
	int lunghezza;
	printf("Ciao utente, sono un programma che verifica se in una terna appartenente ad una sequenza di interi, esiste almeno un elemento multiplo degli altri due\n\n");
	printf("Inserisci la lunghezza della sequenza\n");
	scanf("%d", &lunghezza);

	int sequenza[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Inserisci un intero\n");
		scanf("%d", &sequenza[i]);
	}

	/*output*/
	if(multipli(sequenza, lunghezza))
		printf("In tutte le terne adiacenti esiste almeno un elemento multiplo di uno degli altri due\n");
	else
		printf("NON in tutte le terne adiacenti esiste un elemento multiplo degli altri due\n");

}
