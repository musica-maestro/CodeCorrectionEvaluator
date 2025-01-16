/* SPECIFICA (max 1):......0.1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............7.1
*/
/*
input: una sequenza s e un valore l //******** MANCA IL TIPO -0.2
pre-condizione: che il valore l corrisponda alla lunghezza della sequenza s//******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
lo cifra,
o altrimenti tutte le triple di elementi adiacenti della sequenza sono presenti almeno due numeri composti da una solo cifra
TIPO DI PROBLEMA: verifica universale   //**** MANCANO OUTPUT E POSTCONDIZIONI -0.5
*/

#include <stdio.h>

int dueunacifra(int array[],int lunghezza){
	int output=1;
	for(int i=0;i<lunghezza-2&&output==1;i++){
		if(((array[i]<10&&array[i]>=0)&&(array[i+1]<10&&array[i+1]>=0))||   //**** QUESTA CONDIZIONE VA NEGATA! -1.5
		   ((array[i]<10&&array[i]>=0)&&(array[i+2]<10&&array[i+2]>=0))||
		   ((array[i+1]<10&&array[i+1]>=0)&&(array[i+2]<10&&array[i+2]>=0)))
			output=0;
	}
    return output;
}


int main(){
	int lunghezza;
	printf("buongiorno utente immetti la lunghezza della sequenza:\n");
	scanf("%d",&lunghezza);
	int array[lunghezza];
	for(int i=0;i<lunghezza;i++){
		printf("immetti il valore %d della sequenza:\n", i);
		scanf("%d",&array[i]);

		if(dueunacifra(array,lunghezza)) //**** STA NEL CICLO FOR DI LETTURA ARRAY! -0.5
			printf("tutte le triple di elementi adiacenti della sequenza sono presenti almeno due numeri composti da una solo cifra ");
		else
			printf("non in tutte le triple di elementi adiacenti della sequenza sono presenti almeno due numeri composti da una solo cifra");
	}

}