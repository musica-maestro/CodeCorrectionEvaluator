/* SPECIFICA (max 1):......0.4
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.4
*/
#include <stdio.h>
/*SPECIFICA
*Input: la lunghezza dell'array e i numeri al suo interno
*Pre-condizione:I numeri dell'array devono essere interi e pari alla lunghezza dell'array //******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
*output: un messaggio che comunica all'utente l'esito del controllo 'r' //******* l'OUTPUT E' UN BOOLEANO -0.2
*post-condizione: r deve essere un numero intero uguale a 1 o 0 //******* QUESTO E' L'OUTPUT  -0.2
*TIPO DI PROBLEMA:verifica universale
*/

int dueUnaCifra(int a[],int lunghezza){
	int r=1;
	for(int i=0; i<lunghezza-2 && r==1;i++){
		if((a[i]/10==0 && a[i+1]/10==0) || (a[i]/10==0 && a[i+2]/10==0) ||
			(a[i+1]/10==0 && a[i+2]/10==0))
			i++;
		else
			r=0;
	}
	return r;
}

int main(int argc, char const *argv[])
{
	int lunghezza;
	printf("Quanto e' grande l'array?\n");
	scanf("%d",&lunghezza);
	int a[lunghezza];
	printf("Inserisci i numeri dell'array:\n");
	for(int i=0;i<lunghezza;i++)
		scanf("%d",&a[i]);
	int r;
	r=dueUnaCifra(a,lunghezza);
	if(r==1)
		printf("Ci sono sempre 2 numeri composti da una sola cifra\n");
	else
		printf("Non in tutte le triple sono presenti 2 numeri composti da una sola cifra");
}