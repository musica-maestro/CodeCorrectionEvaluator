/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
/*SPECIFICA
*Input: una sequenza di interi (sequenza) e la sua lunghezza (l)
*Pre-condizione: l>=3
*Output: un valore booleano
*Post-condizione: se in ogni tripla di elementi ci sono esattamente due numeri positivi è vero (1),
                  altrimenti è falso (0)
*TIPO DI PROBLEMA: Verifica universale
*/
#include <stdio.h>


/*Funzione che legge un numero e restituisce 1 se è positivo o 0 se è negativo*/
int isPos(int a){
	return (a>0);
}


/*Funzione che calcola se in ogni tripla ci sono esattamente 2 positivi e*/
/*restituisce un valore booleano 1 se è vero o 0 se è falso*/
int duePositivi(int seq[], int d){
    int i=0; //indice della sequenza
    int verifica=1; //variabile booleana

    while(verifica&&i<d-2){
    	if((isPos(seq[i])&&isPos(seq[i+1])&&!isPos(seq[i+2]))||
    	  (isPos(seq[i])&&isPos(seq[i+2])&&!isPos(seq[i+1]))||
    	  (isPos(seq[i+1])&&isPos(seq[i+2])&&!isPos(seq[i])))
    		i++;
    	else
    		verifica=0;

    }

    return verifica;
}


/*Funzione main che legge una sequenza di numeri inserita dall'utente e restituisce un output*/
int main(){
	int l;  //lunghezza della sequenza
	printf("Caro utente,\n");
	printf("Benvenuto nel programma.\n");
	/*INPUT*/
	printf("Inserisci la lunghezza della tua sequenza di numeri:\n");
	scanf("%d", &l);

	int sequenza[l]; //variabile della sequenza

	for(int i=0; i<l; i++){
		printf("Inserisci un intero per la tua sequenza:\n");
		scanf("%d", &sequenza[i]);
	}
    /*OUTPUT*/
	if(duePositivi(sequenza, l))
		printf("In ogni tripla di elementi della sequenza sono presenti esattamente due positivi.\n");
	else
		printf("In ogni tripla di elementi della sequenza non sono presenti esattamente due positivi.\n");
}