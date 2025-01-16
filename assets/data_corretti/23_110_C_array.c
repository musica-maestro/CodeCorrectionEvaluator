/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.8
*/
/* SPECIFICA DEL PROBLEMA
 * INPUT: una sequenza seq di numeri interi positivi (X1, ..., Xn) //******** MANCA LA LUNGHEZZA -0.2
 * PRE-CONDIZIONE: i numeri nella sequenza sono interi positivi
 * OUTPUT: una variabile intera tutte
 * POST-CONDIZIONE: tutte vale 1 se in tutte le triple di elementi adiacenti della sequenza
 * sono presenti almeno due numeri composti da una sola cifra, vale 0 altrimenti
 * TIPO DI PROBLEMA: verifica universale */

#include <stdio.h>

/* Funzione che riceve come parametri un array seq[] e la relativa lunghezza n e controlla
 * se in ogni tripla di di elementi adiacenti della sequenza sono presenti almeno due numeri
 * composti da una sola cifra, in caso affermativo vale 1, vale 0 altrimenti */
int dueUnaCifra(int seq[], int n) {
	//pre: n è la lunghezza inserita dall'utente dall'array seq[]
	int tutte = 1;		//variabile di ritorno inizzializzata a 1, diventa 0 se non si verifica la proprierà
	int i=0;			//Insice scorrimento vettore

	/* Verifica condizione */
	while(i<n-2 && tutte) {
		if(!((seq[i]<10 && seq[i+1]<10 && seq[i+2]>=10) ||
		     (seq[i]<10 && seq[i+1]>=10 && seq[i+2]<10) ||
		     (seq[i]>=10 && seq[i+1]<10 && seq[i+2]<10) ||
		     (seq[i]<10 && seq[i+1]<10) && seq[i]<10))  //***** POTEVA ESSERE PIU' SINTETICA
			tutte = 0;
		else
			i++;
	}

	/* Valore di ritorno */
	return tutte;
}

/* Funzione principale */
int main() {
	int n;		//Quanti numeri vuole inserire l'utente nella sequenza (lunghezza array);

	/* Presentazione programma */
	printf("\nCiao utente, questo programma chiede di inserire n numeri in una sequenza e ");
	printf("controlla se in ogni tripla della sequenza\nsiano presenti almeno due numeri ");
	printf("composti da una sola cifra\n\n");

	/* INPUT: quanti numeri l'utente vuole inserire nella sequenza */
	printf("Quanti numeri interi positivi vuoi inserire nella sequenza: ");
	scanf("%d", &n);

	int seq[n];		//Creazione array di interi seq[n] di lunghezza n

	/* INPUT: inserimento valori nell'array */
	printf("\n");
	for(int i=0; i<n; i++) {
		printf("Inserire il %d' numero: ", i+1);
		scanf("%d", &seq[i]);
	}

	/* OUTPUT con condizione tramite funzione */
	if(dueUnaCifra(seq, n)) {
		printf("\nIn tutte le triple di elementi adiacenti della sequenza sono presenti\n");
		printf("almeno due numeri composti da una sola cifra\n");
	}
	else {
		printf("\nNON in tutte le triple di elementi adiacenti della sequenza sono presenti\n");
		printf("almeno due numeri composti da una sola cifra\n");
	}
}