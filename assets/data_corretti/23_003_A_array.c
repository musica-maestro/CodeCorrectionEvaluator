/* SPECIFICA (max 1):......0.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3.5
   MAIN PROGRAM (max 2):...1.9
   TOTALE (10).............6.9
*/
/* Il problema è di tipo VERIFICA UNIVERSALE.
INPUT: Un array di valori e la sua lunghezza
PRECONDIZIONE: i valori devono essere di tipo intero
OUTPUT: una istanza
POST CONDIZIONE: L'istanza deve essere booleana //***** QUESTO VA SOPRA -0.2
//******** POST CONDIZIONE NON CORRETTA -0.3

*/

#include <stdio.h>

int multipli(int array[], int arrayCaselle){ //****** MANCA LA VARIABILE DI UNIVERSALITA' -0.5

	for(int i=1;i<arrayCaselle;i++){
		if(array[i]%array[i-1]==0||array[i]%array[i+1]==0)//******** CONDIZIONE INCOMPLETA mancano altre tre combinazioni -1.5

			return 1;
	}//******** 2 RETURN NON E' PROGRAMMAZIONE STRUTTURATA -0.5
	return 0;
}

int main(){
	int arrayCaselle;

	printf("Quanti valori ha l'array che vuole inserire?");  //***** LEGGE APPICCICATO -0.1
	scanf("%d", &arrayCaselle);

	int array[arrayCaselle];

	for(int i=0;i<arrayCaselle;i++){
		printf("Inserire il valore nella casella %d: ", i);
		scanf("%d", &array[i]);
	}

	if(multipli(array, arrayCaselle))
	{
		//istanza positiva
		printf("Il vettore da te iserito contiene almeno una terna che comprende un multiplo di un numero.");
	}
	else
	{
		//istanza negativa
		printf("Il vettore da te iserito non contiene almeno una terna che comprende un multiplo di un numero.");
	}
}