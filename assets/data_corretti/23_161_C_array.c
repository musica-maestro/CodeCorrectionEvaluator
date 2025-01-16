/* SPECIFICA (max 1):......0.6
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............6.6
*/
/*SPECIFICA
*INPUT: una lunghezza l e una sequenza s  //******** MANCA IL TIPO -0.2
*PRE-CONDIZIONI: l è la lunghezza della sequenza s e deve essere >2//******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
*OUTPUT: risultato
*POST-CONDIZIONI: se risultato = 1 se in tutte le triple di elementi adiacenti della sequenza ci sono almeno 2 numeri composti da una sola cifra
altrimenti risultato=0
*TIPO DI PROBLEMA: verifica universale
*/

#include <stdio.h>

int DueUnaCifra(int interi[], int lunghezza){
	int risultato=0;   //********* risultato =1 -1
	for (int i = 0; i < lunghezza-2; ++i)  //controllo se è rispettata la condizione delle cifre
	{
		if ((interi[i]<10 && (interi[i+1]<10 ||interi[i+2]<10)) ||
		    (interi[i+1]<10 && (interi[i]<10 ||interi[i+2]<10)) ||
		    (interi[i+2]<10 && (interi[i]<10 ||interi[i+1]<10)) )
		{//
			risultato=1; //**** STAI IMPLEMENTANDO UN VERIFICA ESISTENZIALE -2
		}
	}


return risultato;


}

int main () {

	printf("Ciao! sono un programma che verifica se in tutte le triple di elementi\n");
	printf("adiacenti della sequenza ci sono almeno 2 numeri composti da una sola cifra\n");

	int lunghezza; //lunghezza della sequenza
	printf("Da quanti elementi vuoi che sia composta la tua seqeunza?\n");
	scanf("%d", &lunghezza);

	if (lunghezza>2)
		{

		int sequenza[lunghezza]; // un array formato da lunghezza numeri

		for (int i = 0; i < lunghezza; ++i)
		{
			printf("Dimmi un numero!\n");
			scanf("%d", &sequenza[i]);
		}

		int risultato=DueUnaCifra(sequenza, lunghezza);

		if (risultato==1)
		{
			printf("In tutte le triple di elementi adiacenti della sequenza ci sono almeno 2 numeri composti da una sola cifra\n");
		}
		else
			printf("Non in tutte le triple di elementi adiacenti della sequenza ci sono almeno 2 numeri composti da una sola cifra\n");
		}
	else
		printf("La lunghezza della sequenza deve essere almeno di 3 numeri!\n");
}