/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................8,5
*/
#include <stdio.h>
/*programma che data una sequenza di interi verifica se esiste una tripla di tre elementi
 * consecutivi che contiene almeno due elementi il cui valore è compreso tra -10 e 10
 * e che contiene 2 multipli di 3*/
 /*problema di verifica esistenziale*/
 /*input: sequenza
  * precondizione:sequenza di interi
  * output:variabile booleana
  * post condizione: variabile booleana che indica se la proprietà è soddisfatta*/
  //******** LA POST-CONDIZIONE NON DICE NULLA -0.5
 int CompresiMultipli3 (int array[],int lun){
	 int esistenza;
	 int i;
	 i=0;
	 esistenza=0; //esistenza della tripla inizializzata a 0
	 while(i<lun-2 && esistenza==0) {
		 if (((array[i]+array[i+1]<=10 && array[i]+array[i+1]>=-10) ||
		 //******* QUI STAI VERIFICANDO CHE LA LORO SOMMA SIA COMPRESA TRA -10 E 10! -1.5
		 (array[i]+array[i+2]<=10 && array[i]+array[i+2]>=-10) ||
		 (array[i+2]+array[i+1]<=10 && array[i+2]+array[i+1]>=-10)) &&
		 ((array[i]%3==0 && array[i+1]%3==0 && array[i+2]%3!=0) ||
		 (array[i]%3==0 && array[i+1]%3!=0 && array[i+2]%3==0) ||
		 (array[i]%3!=0 && array[i+1]%3==0 && array[i+2]%3==0)))
		 esistenza=1;
		 else
			 i++;
	 }
	 return esistenza;
 }



int main(int argc, char **argv)
{
	printf("Ciao, sono un programma che risolve il problema richiesto\n");
	printf("Quanti numeri vuoi inserire?");
	int lunghezza;
	scanf("%d",&lunghezza);
	int sequenza[lunghezza];
	for(int i=0;i<lunghezza;i++) {
		printf("Dammi un numero\n");
		scanf("%d",&sequenza[i]);
	}
	if(CompresiMultipli3(sequenza,lunghezza))
		printf("SI, la sequenza soddisfa la richiesta");
		else
			printf("NO, la richiesta non soddisfa la richiesta");
}
//******** OUTPUT MOLTO POVERO -0.5