/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......2
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............6
*/
#include <stdio.h>
#include <stdbool.h>
/*
SPECIFICA
INPUT: una sequenza di interi (A), sia positivi che negativi, e la sua lunghezza (l);
PRE-CONDIZIONI: la lunghezza deve essere maggiore o uguale a 3;
OUTPUT: una stringa con il risultato dell'operazione
POST-CONDIZIONI: verificare tramite variabile booleana se la sequenza contiene tutte
					triple con esattamente 2 valori positivi.
TIPO DI PROBLEMA: Verifica Universale;
*/

/*Funzione che verifica la presenza in tutte le triple di al più 2 elementi positivi*/
bool DuePositivi(int A[], int l){

	bool flg= false; 		/*Variabile booleana per verificare la veridicità della condizione*/
     //******* flg=true; -0.5
	/*Controllo ciclico per tutte le triple della sequenza, rispetto la condizione del problema*/
	for(int i=0; i<l-2; i++){
		if((A[i]>=0)&&(A[i+1]>=0)&&(A[i+2]<0) || (A[i]>=0)&&(A[i+1]<0)&&(A[i+2]>=0) || (A[i]<0)&&(A[i+1]>=0)&&(A[i+2]>=0)){
			flg=true; 		/*Se l'istanza è positiva*/
		}else flg=false;	/*Se l'istanza è negativa*/
	}//******* QUESTA E' UNA VERIFICA ESISTENZIALE -2
     //******* INOLTRE RESTITUISCI IL VALORE CALCOLATO SULL'ULTIMA TRIPLA -1.5
	return flg;
}

int main(){

	int l; 					/*lunghezza della sequenza*/

	/*Richiesta all'utente della lunghezza della sequenza*/
	printf("-> Salve utente di quanti elementi e' composta la sua sequenza di interi? ");
	scanf("%d", &l);
	printf("\n");

	int A[l]; 				/*Array per gestire la sequenza*/

	/*Richiesta di inserimento di tutta la sequenza in base alla sua lunghezza*/
	for(int i=0; i<l; i++){
		printf("-> Inserisci il %d# elemento della sequenza (anche negativo): ", i+1);
		scanf("%d", &A[i]);
	}

	/*
	Controllo del valore riportato dalla Funzione DuePositivi,
	se con esito positivo l'istanza inserita è positiva rispetto il controllo;
	se con esito negativo l'istanza inserita è negativa rispetto il controllo;
	*/
	if(DuePositivi(A, l)) printf("\n-> Utente la sequenza da lei inserita CONTIENE tutte triple con al piu' 2 elementi positivi.");
	else printf("\n-> Utente la sequenza da lei inserita NON CONTIENE tutte triple con al piu' 2 elementi positivi.");

	return 0;
}