/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...1.9
   TOTALE (10).............9.9
*/
#include <stdio.h>
/*
SPECIFICA
Dati di ingresso: int dim, int valori (x1,x2...xn)
Pre-Condizione: dim intero maggiore di 3, valori inseriti devono essere interi (tanti quanto la dimensione di Dim)
Dati di uscita: int risposta
Post-Condizione: risposta intero (con funzione booleana), con valori 1 se in ogni terna almeno un elemento è multiplo di uno degli altri 2, 0 altrimenti.

Tipo di problema: verifica universale
*/

int multipli(int vettore[], int dim)
{
	int risposta=1;
	int cont=0;
	while((cont+2<dim) && (risposta==1))
	{
		if((vettore[cont]%vettore[cont+1]!=0)&&
		   (vettore[cont+1]%vettore[cont]!=0)&&
		   (vettore[cont]%vettore[cont+2]!=0)&&
		   (vettore[cont+2]%vettore[cont]!=0)&&
		   (vettore[cont+1]%vettore[cont+2]!=0)&&
		   (vettore[cont+2]%vettore[cont+1]!=0))
				risposta=0;

		cont++;
	}

	return risposta;
}

int main()
{
	int dim;
	int cont=0;
	do{
		printf("Inserisci la dimensione dell'array (minimo 3):\n");
		scanf("%d",&dim);}
	while(dim<3);
	int vettore[dim];

	while(cont<dim)
	{
		printf("Inserisci il valore della posizione n. %d:",cont); //****** MANCA SPAZIO -0.1
		scanf("%d",&vettore[cont]);
		cont++;
	}

	int risposta=multipli(vettore,dim);
	if (risposta==1)
	printf("Si! Nelle terne c'e' almeno un elemento multiplo degli altri due!");

	else
		printf("No! Nelle terne non c'e' almeno un elemento multiplo degli altri due!");

}