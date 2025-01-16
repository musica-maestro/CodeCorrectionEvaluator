/* SPECIFICA (max 1):......0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...1.8
   TOTALE (10).............9.5
*/
/*
specifica:
DATI INGRESSO sequenza interi di almeno 1 elemento //******** MANCA LA LUNGHEZZA -0.2
PRECONDIZIONE è una sequenza di interi
DATI USCITA	variabile booleana che vale 1 se la condizione e universalmente verificata, altrimenti vale 0
POSTCONDIZIONE la variabile booleana verifica se ci sia almeno un elemento di ciascuna terna multiplo di uno degli altri due
//********** FALSO, ALTRIMENTI -0.1
tipo problema: verifica universale
*/

#include <stdio.h>
int multipli(int seq[], int l){
	int isMultiplo = 1; //variabile booleana ver. universale inizializzata.
	int i; // variabile contatore
	//ora passo in rassegna ciascuna terna per verificare la condizione
	for(i=0; i<l-2 && isMultiplo; i++ ){
		if(!(seq[i]%seq[i+1]==0 || seq[i]%seq[i+2]==0 || seq[i+1]%seq[i+2]==0 || seq[i+1]%seq[i]==0 || seq[i+2]%seq[i]==0 || seq[i+2]%seq[i+1]==0))
			isMultiplo = 0;
	}
	//restituisco valore booleano calcolato
	return isMultiplo;
}





int main(){
	int lunghezza; // lunghezza array da leggere in input
	int i; //contatore elementi array
	//leggo lunghezza array da input
	printf("Caro utente, quanti elementi vuoi inserire nella tua sequenza?\n");
	scanf("%d", &lunghezza);
	//istruzione ripetitiva entra in funzione se valore inserito non è valido
		while(lunghezza<=0){
				printf("valore non valido, inserisci un intero maggiore di zero\n");
				scanf("%d", &lunghezza);
			}
	//ora dichiaro array e ne leggo i valori
	int sequenza[lunghezza];
	for(i=0; i<lunghezza; i++){
		printf("inserisci valore di indice %d\n", i);
		scanf("%d", &sequenza[i]);
	}
	//ora invoco la funzione
	multipli(sequenza,lunghezza);
	//OUTPUT stampo messaggio che dichiara se la sequenza soddisfa la condizione
	if(multipli(sequenza,lunghezza))
		printf("si, ciasciuna terna ha almeno un elemento multiplo di uno degli altri due!\n");
		else
		printf("no, la sequenza non soddisfa la condizione.\n");
}      //******* MESSAGGIO NON CHIARO -0.2