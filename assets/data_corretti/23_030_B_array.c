/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.8
*/
#include <stdio.h>
#include <stdlib.h>

/*
input: una sequenza di n numeri   //******** MANCA LA LUNGHEZZA -0.2
precondizioni: i numeri della sequenza sono interi e n>=3
output: una variabile booleana v
postcondizioni: v vale 1 se tutte le triple di interi adiacenti hanno esattamente due numeri postivi, altrimenti vale 0

tipo problema: verifica universale
*/

/*inizio funzione duePositivi*/
int duePositivi(int seq[], int x) {

	int v=1;												//variablie universale

	for(int i=0;i<x-2&&v==1;i++) {
		if((seq[i]>=0&&seq[i+1]>=0&&seq[i+2]>=0)			//tre positivi
			||(seq[i]<0&&seq[i+1]<0&&seq[i+2]<0)			//tre negativi
			||(seq[i]<0&&seq[i+1]<0&&seq[i+2]>=0)			//primo e secondo negativi
			||(seq[i]<0&&seq[i+1]>=0&&seq[i+2]<0)			//primo e terzo negativi
			||(seq[i]>=0&&seq[i+1]<0&&seq[i+2]<0))			//secondo e terzo negativi
			v=0;
	}                //******** UN PO' COMPLICATA, MA CORRETTA
	return v;
}
/*fine funzione*/

/*inizio funzione centrale*/
int main () {

	/*creazione della sequenza*/
	int x;
	printf("inserisci la lunghezza della sequenza\n");
	scanf("%d", &x);
	int seq[x];
	printf("inserisci i valori della sequenza\n");
	for(int i=0;i<x;i++)
		scanf("%d", &seq[i]);

	int v;
	v=duePositivi(seq, x);									//richiama la funzione duePositivi

	if(v==1)
		printf("tutte le triple hanno esattamente due numeri positivi\n");
	else
		printf("non tutte le triple hanno esattamente due numeri positivi\n");
}
/*fine funzione*/