/* SPECIFICA (max 1):......0.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2):...1
   TOTALE (10).............7.5
*/
/*SPECIFICA
*Input: sequenza di interi   //******** MANCA LA LUNGHEZZA -0.2
*Pre-condizione: sequenza con almeno tre elementi
*Output:                    //********* MANCA -0.2
*Post-condizione:ogni tripla di numeri diaenti contiene esattamente due numeri positivi //********** FALSO, ALTRIMENTI -0.1
Tipo di problema: Verifica universale*/
#include<stdio.h>
/*funzione due positivi, restituisce 1 se se in tutte le triple di elementi adiacenti della sequenza ci sono esattamente due numeri positivi, se no 0*/
int duePositivi(int lunghezza, int array[lunghezza], int i, int bl){
	bl=1;
	i=0;  //******** INDICE DELL'ARRAY FUORI DAI LIMITI, DEVE ESSERE i<lunghezza-2 -1
	while(i<lunghezza && bl==1){ //finchè il contatore è minore della lunghezza e la vafriabile booleana è 1 entra nel ciclo
		if(array[i]>0 && array[i+1]>0 && array[i+2]<0||array[i]<0 && array[i+1]>0 && array[i+2]>0 || array[i]>0 && array[i+1]<0 && array[i+2]>0 ){
		/*controlla se ci sono esattamente due interi psitivi nella tripla*/
			i++; // se ci sono il contatore passa all'elemento successivo

		}
		else{ //se non ci sono modifica il valore a di bl a 0
			bl=0;
		}
	} return bl;
}
int main(){
	/*input*/
	int lunghezza; //lunghezza array
	int array[lunghezza];  //******** l'array lo devi dichiarare solo dopo aver acquisito la lunghezza -0.5
	int i;
	int bl; //variabile booleana

	printf("caro utente inserisci la lunghezza dell'array\n"); //chiede all'utente quanti numeri inserire
	scanf("%d", &lunghezza);

	/*chiede all'utente per ogni indice il numero da inserire */
	for(i=0; i<lunghezza; i++){
		printf("inserisci l'elemento da inserire nell'indice %d\n",i);
		scanf("%d",&array[i]);

	}
	//****** non era richisto di passare i e bl come parametri, queste sono locali alla funzione duePostivi -0.5
	duePositivi(lunghezza, array, i, bl); //chiamo la funzione per verificare che ci siano esattamente due numeri interi
	if(bl==1){
		printf("ogni tripla di elementi adiacenti contiene esattamente due numeri positivi\n");
	}
	else{
		printf("in tutte le triple di elementi adiacenti NON ci sono esattamente due interi positivi\n");
	}

}
