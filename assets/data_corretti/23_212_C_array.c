/* SPECIFICA (max 1):......0.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............7.5
*/
/* SPECIFICA
   INPUT: Interi x1,x2,...,xn
   PRECONDIZIONI: Numeri interi //******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
   OUTPUT: Valore booleano
   POSTCONDIZIONI: Triple di interi in cui siano presenti almeno due numeri composti da una cifra
   Problema di Verifica Universale*/  //******** POST CONDIZIONE NON CORRETTA -0.3

#include <stdio.h>



int dueUnaCifra(int*seq, int lung) {
	int esiste=1;
	int i=0;

	while(i<=lung-2 && esiste) {   //***** i<lung-2  0.5
		if((seq[i]<10 && seq[i+1]<10) ||
		   (seq[i]<10 && seq[i+2]<10) ||
		   (seq[i+1]<10 && seq[i+1]<10))  //**** QUESTA CONDIZIONE VA NEGATA! -1
			esiste=0;

		else
			i++;
	}
	return esiste;
}


/* Funzione principale */

int main() {
	int lunghezza;
	int i;
	printf("Quanti interi vuoi? ");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];

	for(int i=0;i<=lunghezza-2;i++) { //***** i<lunghezza-2 -0.5
	printf("Dammi un intero: ");
	scanf("%d", &sequenza[i]);
    }

    if(dueUnaCifra(sequenza, lunghezza))
		printf("In tutte le triple della sequenza sono presenti due numeri a cifra singola ");
	else
		printf("Non in tutte le triple della sequenza sono presenti due numeri a cifra singola");

}