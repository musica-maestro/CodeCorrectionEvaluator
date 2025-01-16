/* SPECIFICA (max 1):......0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.7
*/
/*SPECIFICA
*input:interi della sequenza e lunghezza
*pre-condizioni:lunghezza è la lunghezza della sequenza, boolena verificato //********* VERIFICATO E' L'OUTPUT -0.3
*output:un messaggio positivo o negativo //***** NO
*post-condizioni:verificato è vera se ogni tripla della sequenza contiene esattamente due interi positivi, è falsa altrimenti
*TIPO: verifica universale  */

#include<stdio.h>
#include<math.h>

/*funzione che verifica se ogni tripla della sequenza contiene esattamente due interi positivi */

int duePositivi(int x[], int lunghezza){

	int verificato=1; //variabile booleana che verifica se viene rispettata la condizione

	/*controlla quando tutte le triple della sequenza non rispettano la condizione*/
	for(int i=0;i<lunghezza-2;i++){
		if ( (x[i]>0 && x[i+1]>0 && x[i+2]>0) ||
			 (x[i]<0 && x[i+1]<0 && x[i+2]<0) ||
			 (x[i]<0 && x[i+1]<0 && x[i+2]>0) ||
			 (x[i]<0 && x[i+1]>0 && x[i+2]<0) ||
			 (x[i]>0 && x[i+1]<0 && x[i+2]<0) )  //********* UN PO' COMPLICATA MA OK

				verificato=0; //se la condizione non viene rispettata la booleana diventa false
	}

	return verificato;
}

int main (){

	/*input*/
	int lunghezza; //lunghezza sequenza
		printf("quanti interi vuoi inserire?\n");
		scanf("%d",&lunghezza);

	int sequenza[lunghezza]; //sequenza
		printf("inserisci gli interi\n");

		/*controlla tutta la sequenza*/
		for(int i=0;i<lunghezza;i++){
			scanf("%d",&sequenza[i]);
		}
		/*output*/
		if(duePositivi(sequenza,lunghezza)){
			printf("ogni tripla della sequenza contiene esattamente due positivi\n");
		} else{
			printf("non ci sono esattamente due positivi in ogni tripla della sequenza\n");
		}


}

