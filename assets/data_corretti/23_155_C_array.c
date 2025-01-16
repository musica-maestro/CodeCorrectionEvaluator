/* SPECIFICA (max 1):......0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.8
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.5
*/
/* specifica problema:
dati di ingresso: una sequenza di interi e la sua lunghezza
pre-condizioni: sequenza >=3   //******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
dati di uscita: valore booleano esiste
post condizioni: esiste è true se e solo se tutte le terne hanno almeno due numeri <10  //********** FALSO, ALTRIMENTI -0.1
problema di verifica universale*/
#include <stdio.h>
int dueUnaCifra(int numeri[], int quanti)
{
	int trovato=-1;
	int i=0;
	while (i<quanti-2 && trovato!=0)  // fin tanto che tutte le triple hanno almeno due elementi a una crifra (<10), altrimenti ritorna trovato=0
	{
		if((numeri[i]<10 && numeri[i+1]<10 && numeri[i+2]<10) || //***** NON SERVE -0.2
		   (numeri[i]<10 && numeri[i+1]<10) ||
		   (numeri[i]<10 && numeri[i+2]<10) ||
		   (numeri[i+1]<10 && numeri[i+2]<10))
			trovato=1;
		else
			trovato=0;
		i++;
	}
return trovato;
}
int main()
{
	int quanti;
	int esiste=-1;
	printf("Ciao utente, inserisci quanti numeri vuoi inserire nel tuo vettore. Mi raccomando deve essere un numero maggiore uguale a 3\n");
	scanf("%d",&quanti);
	if (quanti>=3)
		{
			int numeri[quanti];
			for (int i=0;i<quanti;i++)
			{
				printf("inserisci il numero\n");
				scanf("%d", &numeri[i]);
			}
			esiste=dueUnaCifra(numeri,quanti);
			if (esiste==1) // se tutte le triple hanno almeno due numeri con una cifra
				printf("tutte le triple hanno almeno due numeri con una sola cifra!");
			else
				printf("non tutte le triple hanno almeno 2 numeri a una cifra");
		}
		else
		printf("numero troppo basso");
}

