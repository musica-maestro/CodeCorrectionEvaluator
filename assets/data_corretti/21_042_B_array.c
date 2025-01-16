/* SPECIFICA (max 1.5):....0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......1.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................5.7
*/
#include <stdio.h>

/*Specifica
 * Input: Un'array di numeri e la sua lunghezza
 * Pre-Condizione: L'array deve essere di interi e deve contenere almeno 3 numeri
 * Output: Linea di testo che dice se la proprietà è verificara o meno //******** OUTPUT NON CORRETTO -0.3
 * Post-contizione: Verificata=0 istanza negativa, Verificata=1 istanza positiva //******** QUESTO ERA L'OUTPUT -0.5
 * TIPO DI PROBLEMA; Ricerca universale*/

 /*Funzione che verifica se ci sono esattamente due numeri maggiori di 5 e almeno due numeri pari in una triple di numeri*/

int maggiori5Pari(int array[], int lunghezza){
	int verificata=1; //variabile booleana per la verifca delle proprietà
	int contaPari=0; //conta i numeri pari
	int contamaggiori5=0; //conta i numeri maggiori di 5
	for(int i=0;i<lunghezza-2;i++){

		/*aggiorana contaPari in caso il numero sia pari*/

		if(array[i]%2==0){
			contaPari++;
		}

		/*Se è presente solo un numero pari e gli altri non sono pari verificata=0*/

		if(contaPari==1 && (array[i+1]%2!=0 && array[i+2]!=0)){
			verificata=0;
			break;  //******** BREAK NON PERVENUTO! -0.5
		}//******** E SE IL PRIMO FOSSE DISPARI E GLI ALTRI DUE PARI? -1.5

		/*aggiorana contamaggiori5 in caso il numero sia maggiore o uguale di 5*/

		if(array[i]>=5){
			contamaggiori5++;
		}

		/*Se sono presenti piu' di due numeri maggiori di 5 o solo uno verificata=0*/
		//******* COME FA contamaggiori5 AD ESSERE 3 SE AL MASSIMO LO INCREMENTI DI 1? -2
		if((contamaggiori5==3) || (contamaggiori5==1 && (array[i+1]<5 || array[i+2]<5))){
			verificata=0;
			break;    //******** BREAK NON PERVENUTO! -0.5
		}
	}
	return verificata; //restituise il valore di verificata 1 se la proprietà è verifica, 0 altrimenti
}

/*funzione main che chiede da input all'utente la lunghezza dell'array e i numeri che la compongono
 * e restituisce da output una frase che dice se l'istanza è verificata o meno*/

int main(){
	int lunghezza; //inizializza la lunghezza dell'array
	printf("Ciao utente! Inserisci quanti numeri vuoi mettere!\n");
	scanf("%d", &lunghezza);
	int array[lunghezza]; //inizializza l'array
	printf("Ora inserisci i numeri della sequenza:\n");

	/*ciclo for che permette di inserire i numeri della sequenza*/

	for(int i=0;i<lunghezza;i++){
		scanf("%d", &array[i]);
	}
	int boole=maggiori5Pari(array,lunghezza); //inizializza la variabile booleana
	if(boole==1)
		printf("Ogni tripla di elementi consecutivi contiene esattamente due numeri maggiori o uguali a 5 e almeno due numeri pari");
	else
		printf("NON ogni tripla di elementi consecutivi contiene esattamente due numeri maggiori o uguali a 5 e almeno due numeri pari");

}
