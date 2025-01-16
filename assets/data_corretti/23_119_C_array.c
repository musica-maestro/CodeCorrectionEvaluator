/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2):...1.8
   TOTALE (10).............9.3
*/
/*SPECIFICA DEL PROBLEMA
*INPUT:una serie di umeri x1, x2, x3,..., xn, n
*PRE-CONDIZIONI: la serie è composta di numeri interi positivi
*OUTOUT: esiste, un valore booleao
*POST-CONDIZIONI: esiste è vero se in ogn tripla di elemneti adiacenti esistono almeno due valori ad una sola cifra
è falso se invece non ce ne sono almeno due

PROBLEMA DI VERIFICA UNIVERSALE*/

#include <stdio.h>

int positivo(int* arr, int l) {
	int p=1;
	for(int t=0; t<l && p==1; t++) {
		if(arr[t]<0){
			p=0;
		}
	}
	return p;
}


int dueUnaCifra (int* arr, int l) {
	int esiste=1;
	for(int c=0; c<l-2 && esiste==1; c++) {
			if(((arr[c]<10 && arr[c+1]<10)) ||
				((arr[c]<10 && arr[c+2]<10))||
				((arr[c+1]<10 && arr[c+2]<10))) {
				esiste=1;  //******* METTERE LA VARIABILE A 1 E' NON SERVE (PERCHE' GIA' E' A 1), MA TI SALVI
						   //******* PERCHE' HAI MESSO IL BOOLEANO NELLA CONDIZIONE DEL CICLO -0.5
		}
		else
			esiste=0;
	}
	return esiste;
}

int main() {
	int y=0;
	printf("ciao utente\n");
	printf("sono un programma tuo amico\n");
	printf("quanti interi avra' la tua sequenza?\n");
	int lunghezza=0;
	scanf("%d", &lunghezza);
	int arr[lunghezza];
	for(int c=0; c<lunghezza;c++) {
		printf("dammi un elemento positivo in posizione %d\n", c+1);
		scanf("%d", &arr[c]);
	}
	y = dueUnaCifra(arr, lunghezza);
	int x = positivo(arr, lunghezza);
	if (x=0)  //***** E' SEMPRE FALSO! -0.2
		printf("avevo detto solo positivi");
	else if(y==1)
		printf("in ogn tripla di elemneti adiacenti esistono almeno due valori ad una sola cifra");
		else
			printf("non in ogn tripla di elemneti adiacenti esistono almeno due valori ad una sola cifra\n");

}