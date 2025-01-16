/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............9
*/
#include <stdio.h>

/*SPECIFICA

*INPUT: (X1....Xn)

*PRE-CONDIZIONI: interi positivi

*OUTPUT: valore booleano

*POST-CONDIZIONI: positivo se in ogni tripla di interi adiacenti c'è un solo numero con due cifre, negativo altrimenti

*TIPO DI PROBLEMA:verifica universale     */

/*funzione che data una sequenza di interi verifica se in ogni tripla c'è uno e un solo numero a 2 cifre*/
int dueUnaCifra(int* sequenza, int lunghezza){
	int triple=1; //variabile di universalità
	/*vedo la sequenza e controllo se in ogni tripla esiste un solo numero a 2 cifre*/
	for(int j=0;j<lunghezza;j++){ //******** j<lunghezza-2 -0.5
		if(!((sequenza[j]>9 && sequenza[j+1]<=9 && sequenza[j+2]<=9)||
		     (sequenza[j]<=9 && sequenza[j+1]>9 && sequenza[j+2]<=9)||
		     (sequenza[j]<=9 && sequenza[j+1]<=9 && sequenza[j+2]>9))&&(triple==1))
		   triple=0;
	}
	return triple;
}


int main(){
	int lunghezza; //per la lunghezza dell'array
	int risultato; //per il risultato
	printf("ciao utente, sono un programma che data una sequenza di interi individua se esiste o no in un tripla di numeri adiacenti della sequenza un e un solo numero a 2 cifre\n");
	/*INPUT*/
	printf("quanti interi vuoi inserire?: ");
	scanf("%d",&lunghezza);
	int sequenza[lunghezza];
	for(int i=0;i<lunghezza;i++){
		printf("inserisci l'intero %d: ",i+1);
		scanf("%d", &sequenza[i]);
	}


	/*invoco la funzione*/
	risultato=dueUnaCifra(sequenza,lunghezza);

	/*OUTPUT*/
	if(risultato==1)
		printf("la tua istanza e\' positiva");//************ OUTPUT NON ESPLICATIVO -0.5
	else printf("la tua istanza e\' negativa");
}