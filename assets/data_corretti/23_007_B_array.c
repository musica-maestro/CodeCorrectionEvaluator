/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.3
*/
#include <stdio.h>

/*	Data una sequenza di interi, verificare se in ogni tripla di elementi adiacenti ci sono esattamente due numeri positivi */

/* SPECIFICA

 * INPUT:				sequenza di n numeri interi; //******** MANCA LA LUNGHEZZA -0.2
 * PRE-CONDIZIONE: 		n>=3, numeri interi;
 * OUTPUT:				variabile booleana: verificato;
 * POST-CONDIZIONE: 	1 : se in ogni tripla di elementi adiacenti ci sono esattamente due numeri positivi;
 						0 : altrimenti;

 * TIPO DI PROBLEMA: 	problema di verifica universale; */

/* funzione che restituisce 1 se in ogni tripla di numeri consecutivi ci sono esattamente due numeri positivi, altrimenti restituisce 0*/
int DuePositivi(int array[], int lunghezza) {
	int verificato=1; //inizializzo la variabile booleana ad 1, poiché si tratta di un problema di verifica universale

	/* analizzo ogni indice del primo elemento di ciascuna tripla */
	for (int i=0; i<lunghezza-2 && verificato==1; i++) {
		/* se rispetta la proprietà */
		if ((array[i]>=0 && array[i+1]>=0 && array[i+2]<0)||(array[i]>=0 && array[i+1]<0 && array[i+2]>=0)||(array[i]<0 && array[i+1]>=0 && array[i+2]>=0))
			verificato=1;  //******* METTERE LA VARIABILE A 1 E' NON SERVE (PERCHE' GIA' E' A 1), MA TI SALVI
                           //******* PERCHE' HAI MESSO IL BOOLEANO NELLA CONDIZIONE DEL CICLO -0.5
		/* altrimenti */
		else
			verificato=0;
	}
	return verificato;
}

/* funzione main */
int main() {
	/* variabili */
	int dimensione;		//dimensione della sequenza
	int verificato=1;	//inizializzo la variabile booleana ad 1, poiché si tratta di un problema di verifica universale

	/* interazione con l'utente */
	printf("\n Salve utente, questo %c un programma in cui si chiede di inserire una sequenza di numeri interi.",138);
	printf("\n Successivamente, il programma stampa un messaggio che comunica all'utente se %c vero che in tutte le triple di elementi adiacenti della sequenza ci sono esattamente due numeri positivi, oppure no.", 138);

	/* 	INPUT */
	printf("\n\n Inserisci un numero che rappresenta la dimensione della tua sequenza: ");
	scanf("%d", &dimensione);

	/* PRE-CONDIZIONE */
	while (dimensione<3) {
		printf("\n Il numero da te inserito non %c valido\n", 138);
		printf(" Riprova: ");
		scanf("%d", &dimensione);
	}

	/* creazione della sequenza */
	int sequenza[dimensione];

	printf("\n Ora devi inserire i numeri della tua sequenza\n");
	for (int i=0; i<dimensione; i++) {
		printf(" N%d: ", i+1);
		scanf("%d", &sequenza[i]);
	}

	/* stampa della sequenza */
	printf("\n Ecco la tua sequenza: (");

	for (int i=0; i<dimensione; i++)
		printf(" %3d", sequenza[i]);

	printf(" )\n");

	/* verifica della proprietà */
	verificato=DuePositivi(sequenza, dimensione);

	/* OUTPUT */
	if (verificato) //se rispetta la proprietà
		printf("\n In ogni tripla di numeri consecutivi della tua sequenza, ci sono esattamente due numeri positivi.");
	else			//altrimenti
		printf("\n Esiste almeno una tripla di numeri consecutivi della tua sequenza, in cui non ci sono esattamente due numeri positivi.");

	printf("\n");
}
