/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2
   TOTALE.................10.5
*/
#include <stdio.h>

/* SPECIFICA
 * INPUT: una sequenza di interi x1, x2, ..., xn e un intero n
 * PREC: n è la lunghezza della sequenza
 * OUTPUT: un valore booleano esiste
 * POSTC: esiste vale 1 se c'è una tripladi elementi consecutivi che contiene almeno due elementi il cui valore
 * è compreso tra 10 e -10 (estremi inclusi) e che contiene esattamente due elementi multipli di 3, esiste vale 0 altrimenti
 *
 * TIPO PROBLEMA: verifica esistenziale */

/* funzione che restituisce 1 se la tripla di elementi in posizione i, i+1, i+2 della sequenza contiene
 * almeno due elementi il cui valore è compreso tra 10 e -10, 0 altrimenti*/
int almenoDueCompresi(int seq[], int i){
	int ris; // risultato
	if(((seq[i]>=-10 && seq[i]<=10) && (seq[i+1]>=-10 && seq[i+1]<=10))
	|| ((seq[i]>=-10 && seq[i]<=10) && (seq[i+2]>=-10 && seq[i+2]<=10))
	|| ((seq[i+1]>=-10 && seq[i+1]<=10) && (seq[i+2]>=-10 && seq[i+2]<=10)))
		ris=1;
	else
		ris=0;
	return ris;
 }

 /* funzione che restituisce 1 se la tripla di elementi in posizione i, i+1, i+2 della sequenza contiene
 * esattamente due elementi multipli di 3, 0 altrimenti*/
int dueMultipli3(int seq[], int i){
	int ris; // risultato
	if(((seq[i]%3 == 0) && (seq[i+1]%3 == 0) && (seq[i+2]%3 != 0))
	|| ((seq[i]%3 == 0) && (seq[i+1]%3 != 0) && (seq[i+2]%3 == 0))
	|| ((seq[i]%3 != 0) && (seq[i+1]%3 == 0) && (seq[i+2]%3 == 0)))
		ris=1;
	else
		ris=0;
	return ris;
}

int compresiMultipli3(int seq[], int lung){
	int i=0; // indice
	int esiste=0; // variabile esistenziale
	while(i<lung-2 && !esiste){
		if(almenoDueCompresi(seq, i) && dueMultipli3(seq, i))
			esiste=1;
		else
			i++;
	}
	return esiste;
}

int main(){
	int lung, ris;
	printf("Inserisci la lunghezza della sequenza: ");
	scanf("%d", &lung);
	int seq[lung];
	for(int i=0; i<lung; i++){
		printf("Inserisci l'intero x%d: ", i+1);
		scanf("%d", &seq[i]);
	}
	ris= compresiMultipli3(seq, lung);
	if(ris)
		printf("La tripla cercata esiste!\n"); //******* OUTPUT MOLTO POVERO! -0.5
	else
		printf("La tripla cercata NON esiste!\n");
}
