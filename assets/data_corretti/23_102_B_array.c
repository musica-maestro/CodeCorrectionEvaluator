/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
/* SPECIFICA:
*Input:una sequenza di n interi e la sua lunghezza

*Pre-condizioni: n>=3 e n intero

*Output: variabile booleana verifica

*Post-condizioni: se in tutte le triple di elementi adiacenti della sequenza ci sono esattamente due numeri positivi allora verifica vale 1, altrimenti vale 0;

*TIPO DI PROBLEMA: VERIFICA UNIVERSALE

*/
#include <stdio.h>
int DuePositivi(int array[],int lunghezza) {
	int verifica=1;
	for(int i=0;i<=lunghezza-3 && verifica;i++) { //comicio il giro dal primo numero e finisco con il primo elemeto dell'ultima tripla
		if(!((array[i]>0&&array[i+1]>0&&array[i+2]<=0)||(array[i]>0&&array[i+1]<=0&&array[i+2]>0)||(array[i]<=0&&array[i+1]>0&&array[i+2]>0))) {	//se non sono esattamente due positivi, allora verifica vale 0
			verifica=0;
		}
	}
	return verifica;
}
int main() {
	int lunghezza;
	int verifica;
	printf("Ciao Utente, a quanti numeri stavi pensando?\n");
	scanf("%d",&lunghezza);
	printf("Inserisci i numeri qui sotto:\n");
	int array[lunghezza];
	for(int i=0;i<=lunghezza-1;i++) {
		scanf("%d",&array[i]);
	}
	verifica=DuePositivi(array,lunghezza);
	if(verifica==0) {
		printf("In ogni tripla di elementi adiacenti NON ci sono esattamente due numeri positivi\n",138);
	}
	else {
		printf("In ogni tripla di elementi adiacenti ci sono esattamente due numeri positivi!\n");
	}
}