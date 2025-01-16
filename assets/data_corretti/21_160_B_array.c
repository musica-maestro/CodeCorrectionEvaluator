/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................10
*/
#include <stdio.h>
/*SPECIFICA DELLA FUNZIONE
 * dati in ninput: un array di interi e la dimensione dell'array intera
 * pre-condizione: la dimensione deve essere maggiore di 0
 * dati in output: la variabile booleana tutte;
 * post-condizioni: tutte è vera se ogni tripla contiene esattamente due interi  maggiori o uguali a 5 e almeno due elementi pari, falsa altrimenti
 * TIPO DI PROBLEMA: verifica universale*/
 int isPari(char c){  //****** CARATTERE??? -1
	 return(c%2==0);
 }
 int maggiori5Pari(int array[], int l){
	int i=0;
	int tutte=1;
	while (((i<(l-2))&&tutte)){
		if  (!( (  ((array[i]>=5)&&(array[i+1]>=5)&&(array[i+2]<5))
		||   ((array[i]>=5)&&(array[i+2]>=5)&&(array[i+1]<5))
		||  ((array[i+1]>=5)&&(array[i+2]>=5)&&(array[i]<5)))  &&
		(  ((isPari(array[i]))&&(isPari(array[i+1])))  ||((isPari(array[i]))&&(isPari(array[i+2])))  ||((isPari(array[i+1]))&&isPari(array[i+2])) ) ))
            tutte=0;
		else
			i++;
	}
	return tutte;

 }

int main()
{
	int dimensione;
	int i;
	printf("Quanti interi vuoi inserire?\n");
	scanf("%d", &dimensione);
	int array[dimensione];
	printf("inserisci %d interi\n", dimensione);
	for(i=0; i<dimensione; i++)
		scanf("%d", &array[dimensione]);
	if(maggiori5Pari(array, dimensione))
		printf("ogni tripla contiene esattamente due interi  maggiori o uguali a 5 e almeno due elementi pari\n ");
	else
			printf("ogni tripla NON contiene esattamente due interi  maggiori o uguali a 5 e almeno due elementi pari\n ");

	return 0;
}
