/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................11
*/
#include <stdio.h>
/*SPECIFICA DEL PROBLEMA:
 * INPUT:una sequenza di interi x1....xn, e un intero l
 * PRE: l è la lunghezza della sequenza
 * OUTPUT:un valore booleano
 * POST:true se esiste una tripla di elementi consecutivi che contiene almeno due elementi il cui valore è compreso tra -10 e 10( estremi inclusi)
 * e che contiene esattamente due elementi multipli di 3, false altrimenti*/
 /*Problema di VERIFICA ESISTENZIALE */


 /*funzione compresiMultipli3 che verifica se nella sequenza esiste una tripla di elementi consecutivi che contiene almeno due elementi il cui valore è compreso tra -10 e 10( estremi inclusi)
 * e che contiene esattamente due elementi multipli di 3*/
 int compresiMultipli3(int interi[],int lungh){
	 // pre: lungh è la lunghezza di interi
	 int tripla=0;    // variabile di esistenza
	 int i=0;       // variabile contatore

	 /*fintanto che non arrivo alla fine e tripla non è soddisfatta */
	 while(i<lungh-2&&!tripla)
		 // se la proprietà è soddisfatta
		 if((((interi[i]>=-10&&interi[i]<=10)&&(interi[i+1]>=-10&&interi[i+1]<=10))
		 ||((interi[i]>=-10&&interi[i]<=10)&&(interi[i+2]>=-10&&interi[i+2]<=10))||
		 ((interi[i+1]>=-10&&interi[i+1]<=10)&&(interi[i+2]>=-10&&interi[i+2]<=10)))
		 &&((interi[i]%3==0&&interi[i+1]%3==0&&interi[i+2]%3!=0)||
		 (interi[i]%3==0&&interi[i+2]%3==0&&interi[i+1]%3!=0)
		 ||(interi[i+1]%3==0&&interi[i+2]%3==0&&interi[i]%3!=0)))
			 tripla=1;
			 else  // altrimenti verifico i successivi
				 i++;


		return tripla;
 }
 /*funzionbe principale */
int main(){
	int lunghezza;       // lunghezza dell'array
	printf("Ciao, io sono un programma che legge una sequenza di interi e verifica se esiste una tripla\n");
	printf("di elementi consecutivi che abbia almeno due elementi compresi tra -10 e 10\n");
	printf("e che contiene esattamente due multipli di tre!\n");
	/*INPUT*/
	printf("Quanti elementi vuoi  inserire?");
	scanf("%d",&lunghezza);

	int sequenza[lunghezza];    // array

	/*riepo l'array*/
	for(int i=0; i< lunghezza;i++){
		printf("Introduci un intero:");
		scanf("%d",&sequenza[i]);
	}

	/*OUTPUT*/
	if(compresiMultipli3(sequenza,lunghezza))
		printf("Tutte le triple soddisfano la proprieta'!\n");
		else
			printf("Almeno una tripla non soddisfa la proprieta'!\n");

}