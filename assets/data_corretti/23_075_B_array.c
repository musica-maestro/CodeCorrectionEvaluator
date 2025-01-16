/* SPECIFICA (max 1):......0.6
   TIPO PROBLEMA (max 1):..0    //********** CONTROLLARE
   FUNZIONE (max 6):.......1
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............3.6
*/
/****************************************************************
 *Problema: Data una sequenza di interi verica se in ogni tripla*
 *di elementi adiacenti ci sono esattamente due numeri positivi.*
 ****************************************************************/
/****************************************************************
 *specifica del problema:										*
 *input: sequnza e relativa dimensione;							* //******** MANCA IL TIPO -0.2
 *pre condizione: sequenza di minimo 3 valori;					*
 *output: messaggio che informa l'utente 						* //******* l'OUTPUT E' UN BOOLEANO -0.2
 *post condizione: 1 se esistono in ogni tripla di elementi		*
 *adiacenti ci sono esattamente due numeri positivi.			*
 *0 altrimenti													*
 ****************************************************************/

#include<stdio.h>

/*FUNZIONE 2 POSITIVI*/
int funzione_2_positivi(int sequenza[], int size){
	int ris=0;//inizializzo il risultato a zero;

	if(ris==0){
		int j=0;// contatore positivi;
             //****** j=0 E QUINDI != DA 2. NON ENTRI MAI NEL FOR -2
		for(int i = 0; i < size - 2&&j==2; i++ ){//verifico tutte le tripre facenzo assumere a i i valori di partenza di tutte le possibili triple
			for(int z = i;z < i + 2; z++){//scorro sulle triple
				if(sequenza[i] > 0){//verifico che ci siano solo 2 valori positivi;
					j++;
				}
			}
		}
		if ( j == 2 )  //******* QUESTA ANDAVA SUBITO DOPO IL FOR PIU' INTERNO -1
			ris = 1;
	}                  //*******LA TRATTI COME' UNA VERIFICA ESISTENZIALE, MA E' UNIVERSALE -2

	return ris;
}
/*FUNZIONE MAIN*/
int main(){

	int size;
	printf("inserisci il numero di elementi della sequenza: ");//chiedo all'utente di inserire la dimensione dell'array
	scanf("%d",&size);//prendo il valore da tastiera e memorizzo nella variabile size

	int sequenza[size];// inizializzo la sequenza
	for(int i=0; i<size; i++){
		printf ("inserisci numero nella sequenza: ");//chiedo all'utente di inserire i valori della sequenza uno alla volta
		scanf("%d", &sequenza[i]);
	}
	if(funzione_2_positivi(sequenza, size)){//verifico la sequenza e fornisco il risultato
		printf("ogni tripla di elementi contiene esattamente 2 numeri positivi\n");
	}
	else
		printf("ogni tripla di elementi non contiene esattamente 2 numeri positivi\n");

	return 0;
}