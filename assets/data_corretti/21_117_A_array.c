/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9.5
*/
/*SPECIFICA:
 *	input:una sequenza di numeri e quanti sono
 *  pre-condizione: sequenza di interi e intero relativo a quanti interi inserire
 *  output: variabile di verifica
 *  post-condizioni: la variabile di verifica assume solo i valori 1 o 0 rispettivamente se è rispettata la proprietà o no
 *  TIPO DI PROBLEMA: verifica esistenziale*/  //******** LA POST-CONDIZIONE NON DICE NULLA -0.5
#include <stdio.h>
/* funzione che riceve un array e la sua lunghezza e determina se esiste una tripla dove la somma di almeno due elementi della tripla dia
 * un numero compreso tra 10 e 20 e che ci siano solo due elementi uguali fra loro*/
int ugualiCompresi(int array[],int lunghezzaArray)
{
	/*dichiarazioni*/
	int i; //variabile che assumerà gli indici dell'array
	int verifica; //variabile di verifica che potrà assumere solo i valori 1 o 0 se la proprietà è rispettata o no
	/*inizializzazioni*/
	i=0; //la si inizializza al primo elemento dell'array
	verifica=0; //la si inizializza a 0 perchè non è stato ancora trovata una tripla che rispetti la proprietà
	/*finchè non finisce l'array o finchè verifica rimane uguale a 0*/
	while((i<lunghezzaArray-2)&&verifica) //******** NON ENTRA MAI NEL CICLO! -1

	{
		/* se in una tripla la somma di almeno due elementi da un numero compreso tra 10 e 20...*/
		if(((array[i]+array[i+1]>=10)&&(array[i]+array[i+1]<=20))
		||((array[i]+array[i+2]>=10)&&(array[i]+array[i+2]<=20))
		||((array[i+1]+array[i+2]>=10)&&(array[i+1]+array[i+2]<=20)))
		{
			/* e se in questa tripla ci sono solo due elementi uguali tra loro allora la proprietà è rispettata*/
			if(((array[i]==array[i+1])||(array[i]==array[i+2])||(array[i+1]==array[i+2]))&&!((array[i]==array[i+1])&&(array[i]==array[i+2])&&(array[i+1]==array[i+2])))
			{
				verifica=1;
			}
			/* se no vai avanti*/
			else
				i++;
		}
		/* se no vai avanti*/
		else
			i++;
	}
	return verifica;
}
/* funzione principale*/
int main(int argc, char **argv)
{
	int lunghezzaArray; // quanti interi vanno inseriti
	/* acquisizione di quanti interi inserire*/
	printf("quanti interi vuoi inserire? \n");
	scanf("%d",&lunghezzaArray);
	int array[lunghezzaArray]; //sequenza di interi
	/* acquisizione della sequenza interi*/
	printf("inserisci i %d interi\n",lunghezzaArray);
	for (int i=0;i<lunghezzaArray;i++)
	{
		printf("inserisci valore");
		scanf("%d",&array[i]);
	}
	/* se la funzione restituisce 1 allora la proprietà è rispettata se 0 non lo è*/
	if(ugualiCompresi(array,lunghezzaArray)==1)
	{
		printf("esise una tripla dove almeno due elementi danno un risultato compreso tra 10 e 20 e dove solo due elementi di questa somma sono uguali\n");
	}
	else
		printf("non esise una tripla dove almeno due elementi danno un risultato compreso tra 10 e 20\n");
	return 0;
}
