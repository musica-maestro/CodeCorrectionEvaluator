/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.8
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............9.3
*/
#include <stdio.h>
//INPUT: una sequenza di interi {x1, x2, ...xn} e la sua lunghezza
//PRE-CONDIZIONE: {x1, x2, ...xn}
//OUTPUT: una variabile booleana "condizione"
//POST CONDIZIONE: "condizione" vale 1 se ogni tripla di interi contiene esattamente 2 numeri positivi, vale 0 altrimenti
//TIPO DI PROBLEMA: Verifica universale


int duePositivi (int sequenza[], int lunghezza){
	int i=0;
	int condizione=1;
	while(i<=lunghezza-2 && condizione==1){
		if ((sequenza[i]<0 && sequenza[i+1]>=0 && sequenza[i+2]>=0) || (sequenza[i]>=0 && sequenza[i+1]>=0 && sequenza[i+2]<0) || (sequenza[i]>=0 && sequenza[i+1]<0 && sequenza[i+2]>=0))
		{
			condizione=1; //**** NON SERVE! -0.2
			i++;
		}
		else{
			condizione=0;
		}
	}
	return condizione;

}



int main()
{

	int lunghezza;
	printf("Di quanto vuoi lunga la sequenza?\n");
	scanf("%d", &lunghezza);

	int sequenza[lunghezza];
	for (int i = 0; i < lunghezza; i++)
	{
		printf("Inserisci un numero\n");
		scanf("%d", &sequenza[i]);
	}
	duePositivi(sequenza, lunghezza);
	if (duePositivi(sequenza, lunghezza)==1)
	{
		printf("La condizione %c verificata!", 138); //************ OUTPUT NON ESPLICATIVO -0.5
	}
	else
		printf("La condizione non %c verificata!", 138);
}