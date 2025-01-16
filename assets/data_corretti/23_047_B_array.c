/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.5
*/
/*SPECIFICA

*INPUT: un intero n, sequenza di interi

*Pre-condizione: n>=3

*OUTPUT: variabile booleana tutte

*Post-condizione: variabile di universalità "tutte" vera se e solo se in ogni tripla di interi
adiacenti ci sono esattamente due positivi, altrimenti è falsa

*TIPO DI PROBLEMA: verifica UNIVERSALE*/

#include <stdio.h>

/*Funzione che valuta se in ogni terna di interi consecutivi di un array di interi sono presenti esattamente due positivi*/
int duePositivi(int a[], int l){
	int i;	//conteggio
	int tutte=1;	//variabile di universalità

	/*Verifico la proprietà fintanto che mi trovo al più sul terzultimo elemento e tutte ha valore 1*/
	for(i=0;i<l-2&&tutte;i++)
		if(!((a[i]>0&&a[i+1]>0&&a[i+2]<=0)||(a[i+2]>0&&a[i]>0&&a[i+1]<=0)||(a[i+1]>0&&a[i+2]>0&&a[i]<=0)))
			tutte=0;
		else
			tutte=1; //*******NON SERVE ED E' PERICOLOSO! VA BENE PERCHE' TI FERMI SE tutte E' FALSA -0.5
	return tutte;
}

int main(){
	int i;	//scandisce l'array
	int l;	//dimensione array
	int tutte=1;	//variabile di universalità

	printf("Buongiorno utente, inserisci il numero di interi che vuoi compongano la sequenza!\n");
	scanf("%d", &l);	//prendo in input dimensione array

	int sequenza[l];	//dichiaro array dopo aver ricevuto dimensione in input

	printf("Ottimo, ora inserisci %d interi!\n", l);
	/*prendo in input valori dell'array*/
	for(i=0;i<l;i++)
		scanf("%d", &sequenza[i]);

	tutte=duePositivi(sequenza,l);	//assegno a variabile di universalità il valore di ritorno della funzione duePositivi

	if(tutte)
		printf("Ogni terna di consecutivi ha esattamente due positivi!\n");
	else
		printf("Esiste almeno una terna in cui non ci sono esattamente due positivi!\n");
}