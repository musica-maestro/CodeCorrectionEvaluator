/* SPECIFICA (max 1.5):....1.1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......0
   MAIN PROGRAM (max 2.5):.0.8
   TOTALE..................2.9
*/
#include <stdio.h>

/*specifica*/
/*input: due interi s e l */  //******* s E' UNA SEQUENZA DI INTERI, NON UN INTERO -0.4
/*pre-condizione: l intero lsarà la lunghezza di s */
/*output: un intero "esiste"  */
/*post-condizione: "esiste" avrà valore 1 se esiste una tripla di elementi consecutivi
che contiene almeno due elementi il cui valore è compreso tra -10 e 10 e che
contiene esattamente due elementi multili di 3 altrimenti "esiste sarà 0 */

/* si tratta di un problema di verifica esistenziale*/

int compresiMultipli3 (int arr[], int lenght){
	/*variabile di esistenza della tripla " esiste" e variabile per scorrere l array "i"*/
	int esiste,i;
	/*faccio scorrere l array*/
	while(arr[i]<lenght){//***** i<lenght-2, arr[i]! -2

		/*controllo se esiste una tripla con almeno 2 interi compresi tra -10 e 10*/
			if(((-10<arr[i]<10) && (-10<arr[i+1]<10)) |
						    //******** QUESTA ESPRESSIONE NON ESPRIME "ESSERE COMPRESO TRA" -1.5
						    //******** ESTREMI COMPRESI -0.5
			| ((-10<arr[i+1]<10) && (-10<arr[i+2]<10)) |
			| ((-10<arr[i]<10) && (-10<arr[i+2]<10))){

				/*controllo se in quella tripla esistono 2 elementi multipli di 3*/
				if((arr[i]=3*(arr[i])/2) && (arr[i+1]=3*(arr[i+1])/2) || (arr[i+2]=3*(arr[i+2])/2) && (arr[i]=3*(arr[i])/2) || (arr[i+1]=3*(arr[i+1])/2) && (arr[i+2]=3*(arr[i+2])/2)){
				// FORSE VOLEVI SCRIVERE (arr[i]=3*(arr[i])/3  -1.5
					/*se li trovo allora esiste sarà 1*/
					esiste=1;

				}
				/*altrimenti esiste sarà 0*/ //***** NON HAI SCRITTO ELSE -1
				esiste=0;                    //******** RESTITUISCI IL VALORE CALCOLATO SULL'ULTIMA TRIPLA -1.5

		}
		/*incremento la i*/
		i++;

		}
		/*ritorna al main il valore 1 oppure 0*/
		return esiste;

	}












int main(int argc, char **argv)
{
	int i,lunghezza;
	/*array di interi*/
	int array[lunghezza]; //******** DEVI LEGGERE LA LUNGHEZZA DA INPUT PRIMA DI DICHARARE L'ARRAY -1
	int esiste, //****** ; -0.2
	/*input lunghezza*/
	printf("inserisci la lunghezza: ");
	scanf("%d", &lunghezza);
	/*input interi*/
	printf("inserisci gli interi: ");
	for(i=0;i<lunghezza;i++){
		scanf("%d", &array);
	}
	/*richiamo la funzione*/
	esiste=compresiMultipli3(array,lunghezza);
	if(esiste==1){
		printf("esiste una tripla ");
	}
	else{
			printf("non esiste una tripla ");
		}        //******** OUTPUT MOLTO POVERO -0.5
	return 0;
}
