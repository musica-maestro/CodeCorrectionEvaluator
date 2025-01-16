/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......0.5
   MAIN PROGRAM (max 2):...1.8
   TOTALE (10).............3.1
*/
#include <stdio.h>

/*SPECIFICA
*input : un intero n e la sua lunghezza l
Pre-condizione : l è la lunghezza della sequenza //******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
Output : un intero duenumeriunitari
Post-Condizione : se duenumeriunitari è =1 allora nella terna esistono due numeri unitari
				  se duenumeriunitari= 0 viceversa non esistono

TIPO DI PROBLEMA : verifica esistenziale  */  //******* NO, E' UNIVERSALE -1

int unaCifra(int interi[],int lungh)	{
	int duenumeriunitari ;
	duenumeriunitari=0 ;
	int i ;
	i=0 ;
	while(i<=lungh-2 && duenumeriunitari)	{ //***** i<lungh-2 -0.5
		if((( interi[i]>='0' && interi[i]<='9') && (interi[i+1]>='0' && interi[i+1]<='9')
			&& (interi[i+2]>'9' ) ) || ( (interi[i]>='0' && interi[i]<='9')
			&& (interi[i+1]>'9') && (interi[i+2]>='0' && interi[i+2]<='9') )   //******* CONFRONTI UN INTERO CON UN CARATTERE! -1.5
			|| ( (interi[i]>'9') && (interi[i+1]>='0' && interi[i+1]<='9') &&
			(interi[i+2]>='0' && interi[i+2]<='9') ) ) {  //****** COSI' VERIFICHI SE CI SONO ALMENO DUE POSITIVI, NON ESATTAMENTE DUE -1.5

			duenumeriunitari=1 ; //******* QUESTA E' UNA VERIFICA ESISTENZIALE, NON UNIVERSALE -2
		}
		else i++ ;
	}
	 return duenumeriunitari ;
}


int main() {
	int lunghezza ;
	printf("Caro utente introduca la lunghezza della sequenza : ");
	scanf("%d",&lunghezza) ;
	int sequenza[lunghezza] ;
	for(int i=0;i<lunghezza;i++)	{
		printf("Introduci un intero : ") ;
		scanf("%d",&sequenza[i]) ;
	}
	if(unaCifra(sequenza,lunghezza))
		printf("Dentro ogni terna di interi ci sono effettivamente due numeri unitari") ;
	else
		printf("Dentro la terna di numeri interi non ci sono due numeri unitari") ; //***** OUTPUT POCO CHIARO -0.2
}