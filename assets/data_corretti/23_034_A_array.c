/* SPECIFICA (max 1):......0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.7
*/
/*SPECIFICA:
	INPUT:un array di valori //***** chipo di valori? Manca la lunghezza -0.3
	PRE-CONDIZIONE:l'array deve contenere almeno 3 elementi
	OUTPUT: un valore 'esiste'
	POS-CONDIZIONE: 'esiste' vale 1 se per ogni tripla di elementi,
					è presente almeno un elemento multiplo di uno degli altri due, altrimenti 0
TIPO DI PROBLEMA: verifica universale*/


#include <stdio.h>

//funzione che verifica la post-condizione
int multipli(int array[], int dimensione){

	int i=0;			//contatore
	int esiste=1;		//valore di output

	//variabili di appoggio
	int primoSecondo;
	int primoTerzo;
	int secondoTerzo;

	//controlla tutta la sequenza
	while(i<(dimensione-2) && esiste){

		//variabili di appoggio usate come 3 condizioni
		primoSecondo=(array[i]%array[i+1]==0) || (array[i+1]%array[i]==0);
		primoTerzo=(array[i]%array[i+2]==0) || (array[i+2]%array[i]==0);
		secondoTerzo=(array[i+1]%array[i+2]==0) || (array[i+2]%array[i+1]==0);

		//verifica la post-condizione
		if(!(primoSecondo || primoTerzo || secondoTerzo))
			//non è soddisfatta
			esiste=0;
		else
			//verifica la prossima tripla
			i++;
	}
	return esiste;
}

//funzione principale
int main(){

	int lunghezza;		//lunghezza dell'array

	//stampa la presentazione del programma
	printf("\nCiao utente, sono un programma che, data una sequenza, verifico se\n%c presente almeno un elemento multiplo di uno degli altri due.",138);

												/*INPUT*/

	//chiede all'utente quanti elementi inserire nell'array
	printf("\n\nQuanti elementi vuoi inserire? ");
	scanf("%d",&lunghezza);

	//verifica la pre-condizione
	if(lunghezza<3){
		do{
			printf("\nDevi inserire almeno 3 elementi!");
			printf("\n\nQuanti elementi vuoi inserire? ");
			scanf("%d",&lunghezza);
		}while(lunghezza<3);
	}

	int sequenza[lunghezza];			//array di lunghezza scelto dall'utente

	//inserimento da tastiera degli elementi nell'array
	for(int i=0;i<lunghezza;i++){
		printf("\nInserisci il %d%c elemento: ",i+1,167);
		scanf("%d",&sequenza[i]);
	}

												/*OUTPUT*/

	if(multipli(sequenza,lunghezza))
		printf("\nPer ogni tripla di elementi,%c presente almeno\nun elemento multiplo di uno degli altri due",138);
	else
		printf("\nC'%c almeno una tripla di elementi dove non %c presente\nalmeno un elemento multiplo di uno degli altri due",138,138);
}
