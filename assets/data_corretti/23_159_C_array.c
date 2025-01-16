/* SPECIFICA (max 1):......0.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9
*/
#include<stdio.h>
#include<stdlib.h>

/* SPECIFICA
> INPUT: array di numeri, lunghezza dell'array;
> PRECONDIZIONE: entrambi di dati devono essere int;//******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
> OUTPUT: variabile di verifica;
> POSTCONDIZIONE: quest'ultima deve essere compresa tra 0 e 1; //********** LA VARIABILE E' VERA SE... FALSA ALTRIMENTI -0.3
> TIPO DI PROBLEMA: verifica universale;
*/

int dueUnaCifra(int a[], int len){
	int count = 0;

	for(int i = 0; i < len - 2; i++){ 	// per ogni ripetizione controlla tre numeri adiacenti
		if(((a[i] < 10 && a[i+1] < 10) && (a[i] > -10 && a[i+1] > -10)) ||
		   ((a[i] < 10 && a[i+2] < 10) && (a[i] > -10 && a[i+2] > -10)) ||
		   ((a[i+1] < 10 && a[i+2] < 10) && (a[i+1] > -10 && a[i+2] > -10))){
			count++; 					// se una tripla soddisfa la condizione, incrementa questa variabile.
		} else {
			count = 0; 					// altrimenti, la posso portare a zero poichè è una verifica universale.
		}
	} 									// per non finire fuori dall'array si ferma due posizioni prima della fine.

	if(count == len - 2) {	//**** USO DEL CONTATORE STRANO
		return 1;
	} else {
		return 0;  //******** 2 RETURN NON E' PROGRAMMAZIONE STRUTTURATA -0.5
	}
}

int main(){
	int len, chk;

	printf("Di quanti interi sara' la sequenza? ");
	scanf("%d", &len);
	int array[len];

	printf("Sequenza di %d interi.\n", len);
	for(int i = 0; i < len; i++){
		printf("%d di %d: ", i+1, len);
		scanf("%d", &array[i]);
	}
	printf("Stampo array per verifica: \n");
	for(int i = 0; i < len; i++){
		printf("%d ", array[i]);
	}

	printf("\nInvoco dueUnaCifra:\n");
	chk = dueUnaCifra(array, len);
	if(chk == 1){
		printf("(chk = %d) - In tutte le triple di elementi adiacenti della sequenza sono presenti almeno due numeri composti da una sola cifra.\n", chk);
	} else {
		printf("(chk = %d) - In nessuna tripla di elementi adiacenti della sequenza sono presenti almeno due numeri composti da una sola cifra.\n", chk);
	}

	system("PAUSE");
}