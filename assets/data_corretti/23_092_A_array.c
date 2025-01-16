/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......2.5
   MAIN PROGRAM (max 2):...0
   TOTALE (10).............3.3
*/
/*SPECIFICA:
Input: Una sequenza di interi di lunghezza l.
Pre-condizioni: l è la lunghezza della sequenza e l>=3.
Output: un intero.
Post-condizioni: un intero che e' multiplo degli altri 2 della terna.
//***** POST CONDIZIONE NON COMPLETA -0.2 VERO QUANDO... FALSO QUANDO...
Tipo: Verifica esistenziale. //****** E' UNA VERIFICA UNIVERSALE -1
*/
#include <stdio.h>
int multipli(int interi[],int lunghezza){
	int i=1;
	int multiplo=0;
	while(i<lunghezza-2&&!multiplo){
		if(interi[i]%interi[i+1]==0||interi[i]%interi[i+2]==0)
		//****** MANCANO ALTRE 4 CONDIZIONI! -1.5
			multiplo=1;

		else
			i++;  //******* E' UNA VERIFICA UNIVERSALE -2
	}
	return multiplo;
}

int main(){
	int lunghezza;
	int i;
	int interi;
	for(i=1;i<lunghezza;i++)
		printf("Ciao user, sono un programma che, data una sequenza di interi, verifica se e' presente almeno un intero che sia multiplo di un altro.\n");
		printf("Quanti interi vuoi inserire?\n");
		scanf("%d",&lunghezza);
		printf("Inserisci %d interi.\n",lunghezza);
//******** MANCA LA DICHIARAZIONE DI ARRAY -1
//******** MANCA IL CICLO PER LA LETTURA DELL'ARRAY -1
if(!multipli(interi,lunghezza)){
	printf("Non ci sono elementi che sono multipli di un altro in alcuna terna della sequenza inserita.\n");
	}

	else
		printf("In tutte le terne adiacenti c'e' un elemento multiplo degli altri 2.\n");
}//******* QUI SCRIVI COME SE LA VERIFICA FOSSE UNIVERSALE -0.5







