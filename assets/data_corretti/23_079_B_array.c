/* SPECIFICA (max 1):......0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......2
   MAIN PROGRAM (max 2):...1
   TOTALE (10).............4.7
*/
/*SPECIFICA
*Input: un array di interi (a[]) e la sua lunghezza l
*Pre-condizione: l>=3
*Output: 1 o 0
*Post-condizione: Sarà 1 (vera) se la condizione è verificata, 0 altrimenti. //******* LA POST CONDIZIONE NON DICE NULLA -0.3
*Tipo di Problema: verifica universale
*/


#include <stdio.h>

/*Scrivo una funzione che verifica se in ogni tripla di elementi adiacenti ci sono esattamente due numeri positivi*/
int DuePositivi(int a[], int l){
	/*input*/
	int x=1;	//variabile di verifica universale sempre = 1
	/*Utilizzo un for affinchè il programma vada a controllare se in ogni tripla di elementi ci sono almeno due numeri positivi*/
	for(int i=0; a[i]>=3; i++){ //**** COS'E'! a[i]>=3; -1
		if((a[i]<0 && a[i+1]<0)||(a[i]<0 && a[i+2]<0) || (a[i+1]<0 && a[i+2]<0)){
        //****** COSI' VERIFICHI SE CI SONO ALMENO DUE POSITIVI, NON ESATTAMENTE DUE -1.5
		x=0;
		}else
		x=1; //******** RESTITUISCI IL VALORE CALCOLATO SULL'ULTIMA TRIPLA -1.5


	return x;
	}
}

int main(){
	/*input*/
	int l;		//variabile lunghezza array
	printf("Caro utente, inserisci la lunghezza della stringa: ");
	scanf("%d", &l);

	int a[l];	//dichiaro l'array

	for(int i=0; i<l; i++){
		printf("\nInserisci un intero: ");
		scanf("%d", a); //****** &a[i] -1
	}
	/*Richiamo la funzione e stampo l'output*/
	DuePositivi(a, l);
		if(DuePositivi(a, l)==1){
		printf("\nL'istanza %c positiva!", 138);
		}else
		printf("\nL'istanza %c falsa", 138);
}