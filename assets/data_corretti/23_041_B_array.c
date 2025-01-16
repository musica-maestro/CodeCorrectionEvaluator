/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..2
   FUNZIONE (max 6):.......5.9
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.9
*/
/*SPECIFICA
 *Input: un intero l,una sequenza di interi
 *Pre-condizione: l rappresenta la lunghezzadella sequenza, l>=3
 *Output: un intero x
 *Post-condizione:x equivale a 1 se tutte le triple adiacenti hanno esattamente due interi, 0 altrimenti
 *TIPO DI PROBLEMA: Verifica universale */

#include<stdio.h>

/*funzione che riceve la sequenza e la sua lunghezza e ritorna 1
se ci sono esattamente 2 interi in ogni tripla di elementi consecutivi*/
int duePositivi(int v[],int l){
	int duepos=1;											//variabile universale
	/*ripete fino all'ultima tripla o finchè ci non trova una tripla senza esattamente due positivi*/
	for(int i=0;i<l-2 && duepos==1;i++){
		/*se trova triple senza esattamente due interi*/
		if(!(((v[i]<=0 && v[i+1]>0 && v[i+2]>0)||(v[i+1]<=0 && v[i]>0 && v[i+2]>0)||(v[i+2]<=0 && v[i]>0 && v[i+1]>0)))){
			duepos=0;										//imposta la variabile universale a 0
		}
	}
	return duepos;
}

/*funzione principale*/
int main(){
	int l;												//variabile lunghezza sequenza
	/*input*/
	printf("Quanti elementi desideri inserire?");      //******** APPICCICATO -0.1
	scanf("%d",&l);
	int sequenza[l];									//dichiara l'array
	printf("\nInserire la sequenza");
	/*riempimento array*/
	for(int i=0;i<l;i++){
		printf("\nInserisci %d intero: ",i+1);
		scanf("%d",&sequenza[i]);
	}
	/*output*/
	if(duePositivi(sequenza,l)){
		printf("\nTutte le triple di interi consecutivi hanno esattamente due numeri positivi");
	}else{
		printf("\nNon tutte le triple di interi consecutivi hanno esattamente due numeri positivi");
	}
	return 0;
}