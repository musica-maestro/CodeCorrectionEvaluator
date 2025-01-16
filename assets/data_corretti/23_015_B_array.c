/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............7
*/
/*specifiche
 *input: una seqeunza di interi e la sua lunghezza
 *pre-condizioni: 'lunghezza' è la dimensione della sequenza
 *output: un intero trilpla
 *post-condizioni:se in tutte le triple di elemti adiacenti della sequenza ci sono esattamente due positivi si restituisce 1, altrimenti o
 *tipo di problema: verifica universale*/
#include <stdio.h>
/*funzione che restituisce 1 se in tutte le triple  di elemti adiacenti della sequenza ci sono esattamente
*due positivi, 0 altrimenti*/
int duePositivi(int seq[], int lunghezza) {
	//pre: lunghezza è la dimensione della sequenza
	int tripla;
	int i;        //variabile contatore

    tripla=0;   //inizialmente non vi sono triple con due numeri positivi //******** tripla=1  -0.5
    i=0;
    while(i<lunghezza-2 && !tripla) {  //***** && tripla -0.5
    	if((seq[i]>0 && seq[i+1]>0 && seq[i+2]<=0)||(seq[i]>0 && seq[i+2]>0 && seq[i+1]<=0)||(seq[i+1]>0 && seq[i+2]>0 && seq[i]<=0))

    	  tripla=1;  //******* QUESTA E' UNA VERIFICA ESISTENZIALE, NON UNIVERSALE -2
    	else
    	   i++;
    }
   return tripla;
}
/*funzione principale*/
int main() {
	int lunghezza;         //dimensione della sequenza

    /*input*/
	printf("caro utente, sono un programma che riceve una sequenza di interi\n");
	printf("e verifca se per ogni tripla della sequenza ci sono esattamente due numeri posirivi\n");
	printf("quenti interi hai intenzione di introdurre?\n");
	scanf("%d", &lunghezza);

	int sequenza[lunghezza];
	    for(int i=0; i<lunghezza; i++) {
	    	printf("inserisci un numero\n");
	    	scanf("%d", &sequenza[i]);
	    }
   /*output*/
	if(duePositivi(sequenza, lunghezza))
		printf("caro utnte in tutte le triple di elemti ci sono due interi positivi\n");
	else
	   printf("caro utente non in tutte le triple ci sono due interi positivi\n");
}






