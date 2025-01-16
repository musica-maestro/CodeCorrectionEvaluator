/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.8
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.6
*/

/*SPECIFICA
* Input: una sequenza di interi  //******** MANCA LA LUNGHEZZA -0.2
* Pre-condizione: gli interi devono essere >=3
* Output: variabile intera
* Post-condizione: La variabile varrà 1  se in ogni tripla di elementi adiacenti ci sono esattamente due numeri positivi, 0 altrimenti
* TIPO DI PROBLEMA: Verifica Universale */

#include <stdio.h>

//Funzione per verificare se in tutte le triple di elementi adiacenti vi sono esattamente due numeri positivi
int duePositivi(int array[], int n){

	int i=0, verifica=1;

    //Ciclo che si ferma quando si trova un istanza negativa del problema o si raggiunge la fine dell array
	while(verifica==1 && i<n-2){

		if((array[i]>0 && array[i+1]>0 && array[i+2]<0) || (array[i]>0 && array[i+1]<0 && array[i+2]>0) || (array[i]<0 && array[i+1]>0 && array[i+2]>0)){
		//******* COME CALCOLI LO 0? -0.2
			i++;

		}else{

			verifica=0;

		}
	}

	return verifica;

}

int main(){

	int n,i;
	//Inserimento del numero di interi da tastiera
	printf("Quanti interi ha la sequenza? ");
	scanf("%d", &n);

	int array[n];

    //Inserimento degli elementi dell'array
	for(i=0;i<n;i++){

		printf("\nInserisci un intero: ");
		scanf("%d", &array[i]);
	}

    //Stampa dell'esito della verifica
	if(duePositivi(array, n)){

		printf("In tutte le triple di elementi adiacenti vi sono esattamente due numeri positivi!");
	}else{

		printf("Non in tutte le triple di elementi adiacenti vi sono esattamente due numeri positivi!");
	}


}