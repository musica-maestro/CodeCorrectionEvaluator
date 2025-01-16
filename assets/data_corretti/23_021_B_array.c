/* SPECIFICA (max 1):......0
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9
*/
#include <stdio.h>

/*problema di verifica universale
*che controlla se esiste solo una coppia di
numeri positivi per ogni tripletta */

int DuePositivi(int array[], int lunghezza){
	int j=0; //contatore
	int z=1; //riporto
	while((j!=(lunghezza-2))&&z){ //**** meglio j<lunghezza-2 -0.1
		if((array[j]>=0&&array[j+1]>=0&&array[j+2]<=0)
		||(array[j]>=0&&array[j+1]<=0&&array[j+2]>=0)
		||(array[j]<=0&&array[j+1]>=0&&array[j+2]>=0)){
				j++;
			}
			else{
				z=0;
			}
		}

	return z;
}


int main(){
	int lunghezza;
	printf("quanto la impostiamo lunga l'array?\n");
	scanf("%d",&lunghezza);
	printf("introduci i valori dell'array\n");
	int array[lunghezza];
	for(int i=0; i!=lunghezza; i++){
		scanf("%d",&array[i]);
	}
	if(DuePositivi(array,lunghezza)){
		printf("esistono due interi positivi per ogni tripletta\n");
	}
	else{
		printf("non esistono due interi positivi per ogni tripletta");
	}

}