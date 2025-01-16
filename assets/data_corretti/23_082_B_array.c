/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......2.3
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............5.6
*/
/*SPECIFICA
*INPUT: intero o una sequenza di interi  //******** MANCA LA LUNGHEZZA -0.2
*PRE-CONDIZONE: n interi>=3
*OUTPUT: valore booleano
*POST-CONDIZIONE: un valore booleano che sara' 1 se ogni tripla conterrà esattamente due numeri positivi
o sarà 0 se ogni tripla non verificherà quest'ultima condizione
*TIPO DI PROBLEMA: VERIFICA UNIVERSALE
*/
#include <stdio.h>
int duepositivi(interi[],lunghezza[]){  //***** MANCA IL TIPO DI PARAMETRI -1 //****** lunghezza NON E' UN ARRAY -1
	int triple=1;
	int i=0;
	while(i<lunghezza-3 && triple){ //****** i<=lunghezza-3 0.5
		if ((interi[i]>=0 && interi[i+1]>=0 && interi[i+2]<=0)||  //****** LO ZERO O VIENE CONSIDERATO POSITIVO, O NEGATIVO -0.2
			(interi[i]>=0 && interi[i+1]<=0 && interi[i+2]>=0)||
			(interi[i]<=0 && interi[i+1]>=0 && interi[i+2]>=0))   //******** PARTE IF MACANTE -1.5
		else
			i++;
	}
	return triple;
}
int main(){
	int lunghezza;
	printf("ciao utente, sono un programma che che verifica se in ogni tripla ci sono almeno due numeri positivi");
	printf("quanti numeri vorresti introdurre\n");
	scanf("%d",&lunghezza);

	int sequenza[lunghezza];
	int i;
	printf("introdurre un intero\n");
	scanf("%d", sequenza[i]);    //******** &sequenza[i] -0.5
	for(int i=0;i<lunghezza;i++){
		if(duepositivi(sequenza,lunghezza))
			printf("in tutte le triple sono presenti esattamente due interi duepositivi\n");
		else
			printf("in tutte le triple non sono presenti due interi positivi\n");
	}

}