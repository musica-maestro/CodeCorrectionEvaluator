/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.2
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................8.7
*/
/* INPUT: sequenza di interi x1,x2,...,xn e la sua lunghezza
 * PRECON: la lunghezza deve essere maggiore o uguale a 3
 * OUTPUT: un intero che vale true se ogni tripla consecutiva nella sequenza ha esattamente due interi maggiori o uguali di 5 e almeno due numeri pari, vale false altrimenti
 * POSTCON:              //******** METTI INSIEME OUTPUT E POST-CONDIZIONE -0.5
 * TIPO:  verifica universale    */
#include <stdio.h>

int maggiori5Pari(int seq[],int lungh){
	int tutti=1;
	int i=0;
	while(seq[i]<lungh-2 && tutti){
		if(((seq[i]>=5)==1 && (seq[i+1]>=5)==1 && (seq[i+2]>=5)==0)
		|| ((seq[i]>=5)==1 && (seq[i+1]>=5)==0 && (seq[i+2]>=5)==1)
		|| ((seq[i]>=5)==0 && (seq[i+1]>=5)==1 && (seq[i+2]>=5)==1) &&
		//****  LA CONDIZIONE E' CORRETTA, MA NON SERVE SCRIVERE ==1 O ==0, BASTAVA SCRIVERE
		//**** AD ESEMPIO (seq[i]>=5) && (seq[i+1]>=5)&& !(seq[i+2]>=5)) -0.3
		      (((seq[i]%0)==0 && (seq[i+1]%0)==0 && (seq[i+2]%0)==1)
		      || ((seq[i]%0)==0 && (seq[i+1]%0)==1 && (seq[i+2]%0)==0)
		      || ((seq[i]%0)==1 && (seq[i+1]%0)==0 && (seq[i+2]%0)==0) ||
               ((seq[i]%0)==0 && (seq[i+1]%0)==0 && (seq[i+2]%0)==0)))
               //****  COSA CALCOLI %0? DOVEVA ESSERE %2  1.5
			i++;
			else
				tutti=0;
	}
	return tutti;
}

int main(){
	int lunghezza;
	printf("Quanti interi vuoi introdurre?\n");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];
	for(int i=0;i<lunghezza;i++){
		printf("\nInserisci il %d intero: ", i+1);
		scanf("%d", &sequenza[i]);
	}
	if(maggiori5Pari(sequenza,lunghezza))
		printf("Tutte le triple della tua sequenza hanno esattamente due interi maggiori o uguali a 5 e almeno due interi pari");
		else
		printf("Non tutte le triple della tua sequenza hanno esattamente due interi maggiori o uguali a 5 e almeno due interi pari");


}
