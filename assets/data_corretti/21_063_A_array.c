/* SPECIFICA (max 1.5):....0.7
   TIPO PROBLEMA (max 1):..0    //******* MANCA
   FUNZIONE (max 6):.......2.2
   MAIN PROGRAM (max 2.5):.1.5
   TOTALE..................4.4
*/
/*SPECIFICA:
 * input : sequenza di dati, dimensione; //******** MANCANO I TIPI DEGLI ELEMENTI DELL'ARRAY -0.6
 * pre-condiizoni: la dimensione é la lunghezza della sequenza;
 * output: intero verifica;
 * post-condizioni: se la somma é compresa tra 10 e 20 verfifica =1 altrimenti =0;*/
#include <stdio.h>   //******** POST-CONDIZIONE NON ESPRESSA CORRETTAMENTE -0.2

int UgualiCompresi(int array[], int dim)
{
	int i;
	int verifica;
	verifica=0;

	for(i=0; i<dim-2; i++) //******** NON USI LA VARIABILE BOOLEANA PER TERMINARE IL CICLO -1
   {

		if((array[i]+array[i+1]>10 && array[i]+array[i+1]<20)
		|| (array[i+1]+array[i+2]>10 && array[i+1]+array[i+2]<20)
		|| (array[i]+array[i+2]>10 && array[i]+array[i+2]<20))
		{//******** ESTREMI INCLUSI -0.3
			if((array[i]==array[i+1]) && (array[i+1]==array[i+2]))
			{
				verifica=0;
			}
		//******** COSI' VEDI SE SONO TUTTI E TRE UGUALI E PER DUE VOLTE (??) -2.5
		}
		if((array[i]==array[i+1]) && array[i+1]==array[i+2])
		{
			verifica=0;
		}
	}
	return verifica;

}



int main()
{
	printf("array esonero\n");
	int i;
	int n;
	printf("inserisci la sequenza\n"); //******** STAI RICHIEDENDO LA LUNGHEZZA, NON IL N. DI ELEMENTI -0.5
	scanf("%d", &n);
	int array[n];
	printf("inserisci gli elementi all'interno della sequenza\n");
	for(i=0; i<n; i++)
	{
		scanf("%d", &array[i]);
	}
	printf("verfico la condizione\n");
	if(UgualiCompresi(array, n))
	{
		printf("la condizione si verifica\n");
	}
	else   //******** I/O MOLTO POVERO -0.5
	{
		printf("la condizione non si verfifica\n");
	}
	return 0;
}
