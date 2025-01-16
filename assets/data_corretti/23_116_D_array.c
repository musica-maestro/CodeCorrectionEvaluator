/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...1.9
   TOTALE (10).............9.9
*/
/*questo prpgramma vhiede all'utense di inserire prima la lughezza della sequenza e poi riempirla attraverso numeri da tastiera, poi invoca un'altra funzione che ha il compito di
verificare se esiste una tripla di elementi adiacenti della sequenza dove uno dei tre è il resto della divisione degli altri due
infine informa l'utente di cio attraverso un valore booleano di vero o falso*/


/*SPECIFICA
*INPUT:Una sequenza di interi (X1,X2,...,Xn) e una lunghezza della sequenza n
*PRE-CONDIZIONE:almeno tre elementi n>=3
*OUTPUT:un valore booleano
*POST-CONDIZIONE:il valore booleano è 1 se esiste una terna di elementi adiacenti nell'array in cui dove uno dei tre è il resto della divisione degli altri due
0 altrimenti
*/

/*TIPO PROBLEMA:verifica esistenziale */

/*includiamo le libreire necessarie per la funzione*/
#include<stdio.h>

/*funzione che verifica se esiste una tripla di elementi adiacenti della sequenza dove uno dei tre è il resto della divisione degli altri due */
int restoDivisione(int*seq,int l){
	int contatore=0;  //variabile esistenziale
/*verifichiamo tutte le triple dell'array fino a quando non finisce o la variabile universale non diventa vera*/
	for(int i=0;i<l-2 && !contatore;i++){

/*verifichiamo se esiste una tripla di elementi adiacenti della sequenza dove uno dei tre è il resto della divisione intera degli altri due utilizzando la funzione resto*/
		if(seq[i]%seq[i+1]==seq[i+2] || seq[i+2]%seq[i+1]==seq[i] || seq[i+1]%seq[i+2]==seq[i] || seq[i]%seq[i+2]==seq[i+1]
			|| seq[i+1]%seq[i]==seq[i+2] || seq[i+2]%seq[i]==seq[i+1])
			contatore=1;
	}
return contatore;
}


/*funzione principale*/
int main(){

	int lunghezza; //variabile lunghezza della sequenza
/*INPUT*/
	printf("Inserisci la lunghezza della sequenza perfavore\n");//**** per favore...
	scanf("%d",&lunghezza);

	int array[lunghezza]; //variabile della sequenza

/*chiediamo all'utente di riempira la nostra seqeunza dichiarando anche una variabile per il conteggio*/
	for(int i=0;i<lunghezza;i++) {
		printf("Inserisci un intero perfavore\n");//**** per favore...
		scanf("%d",&array[i]);
	}
/*OUTPUT*/
	if(restoDivisione(array,lunghezza))
		printf("Esiste una terna di elementi adiacenti nell'array in cui e presente almeno un elemento multiplo di uno degli altri\n");
	else
		printf("Non esiste una terna di elementi adiacenti nell'array in cui uno dei tre è il resto della divisione degli altri due\n");
}                                                                      //**** NO LETTERE ACCENTATE -0.1