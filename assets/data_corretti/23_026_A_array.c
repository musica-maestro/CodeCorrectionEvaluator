/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............8.3
*/
/*SPECIFICA
 *Input: Una sequenza di interi e una lunghezza l
 *Pre-condizione: La sequenza è data da soli interi
 *Output:  //*******MANCA -0.2
 *Post-condizione: L'istanza del problema vale 1 se per ciascuna terna di elementi adiacenti
 *della sequenza c'è almeno un elemento della terna multiplo degli altri due, altrimenti
 *vale 0
 *TIPO DI PROBLEMA: Verifica universale*/
#include <stdio.h>
/*Funzione che presa una sequenza di interi, verifica se per ciascuna terna
 *di elementi adiacenti della sequenza, ci sia almeno un elemento della terna
 *multiplo di uno degli altri due*/
int Multipli(int array[], int l){
	int i; //variabile contatore
	int multiplo=1;    //inizializzazione multiplo a vero
	/*multiplo vale 1 se vale la condizione scritta nell'if, altrimenti vale 0*/
	for(i=0;i<l;i++){
		if(((array[i]%array[i+1]==0)&&(array[i]%array[i+2]==0))||((array[i+1]%array[i]==0)&&
			(array[i+1]%array[i+2]==0))||((array[i+2]%array[i]==0)&&(array[i+2]%array[i+1]==0))){
			multiplo=1;  //******* CONDIZIONE ERRATA, || AL POSTO DEGLI &&, DEVE ESSERE MULTIPLO DI UNO DEGLI ALTRI DUE,
			i++;         //******* NON DI ENTRAMBI -1.5
	}
		else
			multiplo=0;
	}
	return multiplo;
}

/*Funzione principale*/
int main(){
	int l;    //lunghezza dell'array
	int i;    //variabile contatore

	printf("Caro utente sono un programma che legge una sequenza di interi");
	printf("e verifica se per ogni terna di elementi adiacenti esiste");
	printf("un elemento della terna multiplo di uno degli altri due\n");
	printf("Inserisci la lunghezza del tuo array:");
	scanf("%d", &l);

	int a[l];
	for(i=0; i<l; i++){
	printf("Dammi i numeri: \n");
	scanf("%d", &a[i]);
}
	if(Multipli(a,l))
	printf("Esiste un elemento in ogni terna che %c multiplo degli altri due", 138);
	else
	printf("Non esiste un elemento in ogni terna che %c multiplo degli altri due", 138);
}