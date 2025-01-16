/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
/*SPECIFICA
*INPUT: seq è una sequenza di lun interi
*PRECONDIZIONE: lun è la lunghezza di seq
*OUTPUT:la variabile di verità resto
*POSTCONDIZIONE:resto vale 1 se esiste una tripla di elementi adiacenti in cui uno è il resto della divisione tra gli altri due, altrimenti resto vale 0
*TIPO DI PROBLEMA: VERIFICA ESISTENZIALE
*/

#include <stdio.h>
/*funzione che verifica se esiste una tripla di elementi adiacenti in cui uno è il resto della divisione tra gli altri due*/
int restoDivisione(int array[], int length){
	int i=0; //contatore
	int resto=0; //variabile di verità

	while((i<length-2) && (resto == 0)) {
		if((array[i]%array[i+1] == array [i+2]) || (array[i]%array[i+2] == array [i+1]) || (array[i+1]%array[i+2] == array [i])
		 ||(array[i+1]%array[i] == array [i+2]) || (array[i+2]%array[i] == array [i+1]) || (array[i+2]%array[i+1] == array [i])){
			resto = 1;
		} else
			i++;
	}
	return resto;
}

int main () {
	int lun;//lunghezza dell'array
	int ris;
	printf("Questo programma verifica se all'interno della sequenza da te inserita esiste una tripla di elementi adiacenti in cui uno dei tre %c il resto della divisione tra gli altri due\n", 138);
	printf("Caro Utente, quanti interi vuoi inserire nella tua sequenza?\n");
	scanf("%d", &lun);
	int seq[lun];//array
	printf("inserisci %d interi:\n");
	/*memorizzazione nell'array dei valori inseriti dall'utente*/
	for(int i=0; i<lun; i++){
		scanf("%d", &seq[i]);
	}
	ris = restoDivisione(seq, lun);
	/*output*/
	if(ris==1){
		printf("Esiste una tripla nella sequenza in cui uno %c il resto degli altri due valori\n", 138);
	} else {
		printf("Non esiste nessuna tripla nella sequenza in cui uno %c il resto degli altri due valori\n", 138);
	}


}