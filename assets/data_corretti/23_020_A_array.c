/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.7
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.5
*/
/*SPECIFICA:
 *Input: Una sequenza di interi. //******** MANCA LA LUNGHEZZA -0.2
 *Pre-condizione: La sequenza contiene almeno 3 interi.
 *Output: Un booleano "multipli".
 *Post-condizione: "multipli" vale 1 se per ogni terna di elementi consecutivi della sequenza un numero è il multiplo di un altro, vale 0 altrimenti.
 *TIPO DI PROBLEMA: verifica universale. */
#include <stdio.h>
/*FUNZIONE CHE VERIFICA SE IN OGNI TERNA DI ELEMENTI ADIACENTI ESISTE ALMENO UN NUMERO MULTIPLO DI UN ALTRO*/
int multipli(int sequenza[],int lunghezza){
	//pre: sequenza ha almeno 3 elementi
	int i,j,k,conteggio; //variabili di scorrimento e di conteggio
	int multipli = 1;
	for(i=0;i<lunghezza-2 && multipli;i++){
		conteggio = 0;
		for(j=i;j<=i+2;j++)
			for(k=i;k<=i+2;k++)
			if(sequenza[j]%sequenza[k]==0 && sequenza[j]!=sequenza[k]) //sequenza[j] è multiplo di sequenza[k] e i due numeri sono diversi
				conteggio++;  //****** un po' complicata, potevi semplificarla -0.3
		if(conteggio==0) //se nessun numero della terna è multiplo di un altro
		    multipli = 0;
	}
	return multipli;
}
/*PROGRAMMA CHE VERIFICA SE IN OGNI TERNA DI ELEMENTI ADIACENTI DI UNA SEQUENZA ESISTE ALMENO UN NUMERO MULTIPLO DI UN ALTRO*/
int main(){
	int lunghezza; //lunghezza della sequenza

	/*INPUT*/
	printf("Programma che verifica se in una sequenza di interi in ogni terna di numeri adiacenti è presente almeno un numero multiplo di un altro.\n");
	printf("Inserire il numero di interi della sequenza: ");
	scanf("%d",&lunghezza);
	int sequenza[lunghezza];

	for(int i=0;i<lunghezza;i++){
		printf("Inserire l'intero numero %d: ",i+1);
		scanf("%d",&sequenza[i]);
	}


	/*OUTPUT*/
	if(multipli(sequenza,lunghezza))
		printf("\nOgni terna di numeri adiacenti della sequenza %c tale che un numero %c il multiplo di un altro.\n\n",138,138);
	else
		printf("Esiste almeno una terna di numeri adiacenti tale che NESSUN numero %c il multiplo di un altro.",138);
}