/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................8.5
*/
/*SPECIFICA
 * Input: un array di interi e la sua lunghezza
 * pre condizioni: array interi[], lunghezza è la sua lunghezza e lunghezza>3
 * output: un booleano esiste
 * post condizioni: esiste=1 se esiste una tripla di elementi  che ha due elementi con somma compresa tra 10 e 20 e due elementi uguali, esiste=0 altrimenti
 *
 * TIPO DI PROBLEMA: verifica esistenziale*/

int ugualiCompresi(int interi[], int lunghezza); //****** NON SERVE SE LA DICHIARI PRIMA DEL MAIN -0.1

int ugualiCompresi(int interi[], int lunghezza){

	int esiste=0;		//all'inizio nessuna tripla soddisfa le condizioni
	int somma=0;		//per vedere se due elementi hanno somma compresa tra 10 e 20
	int uguali=0;		//per vedere se due elementi sono uguali

	for(int i=0; i<lunghezza-3; i++)		//vado avanti fino alla fine della sequenza
	//******** NON USI LA VARIABILE BOOLEANA PER TERMINARE IL CICLO -1
	{       //******** i<=lunghezza-3 NON ESAMINI L'ULTIMA TRIPLA -0.5
		/*controllo che ci siano due elementi con somma compresa tra 10 e 20*/
		if( (interi[i]+interi[i+1]>=10 && interi[i]+interi[i+1]<=20)
		|| (interi[i+1]+interi[i+2]>=10 && interi[i+1]+interi[i+2]<=20)
		|| (interi[i]+interi[i+2]>=10 && interi[i]+interi[i+2]<=20))
		{
			somma=1;		//due elementi hanno somma compresa tra 10 e 20

			/*controllo che ci siano esattamente due elementi uguali*/
			if( (interi[i]==interi[i+1] && interi[i]!=interi[i+2])
			|| (interi[i+1]==interi[i+2] && interi[i+1]!=interi[i])
			|| (interi[i]==interi[i+2] && interi[i]!=interi[i+1]))
			{
				uguali=1;	//ci sono due elementi uguali

				if(uguali && somma){
					esiste=1;
				}

			}
			else
				i++;  //******** NO! ALL'INCREMENTO CI PENSA IL FOR! -1

		}
		else
			i++;


	}
	return esiste;

}

#include <stdio.h>
/*funzione principale*/
int main(int argc, char **argv)
{
	printf("Caro utente sono un programma che ti informa se esiste una tripla di elementi\n che ha due elementi con somma compresa tra 10 e 20 e due elementi uguali\n");

	int lunghezza;

	printf("\nInserisci la lunghezza della sequenza\n");
	scanf("%d", &lunghezza);

	int interi[lunghezza];

	printf("\nInserisci %d elementi\n", lunghezza);
	for(int i=0; i<lunghezza; i++)
		scanf("%d", &interi[i]);

	if(ugualiCompresi(interi,lunghezza))
		printf("\nesiste una tripla di elementi che ha due elementi con somma compresa tra 10 e 20 e due elementi uguali\n");
	else
		printf("\nNON esiste una tripla di elementi che ha due elementi con somma compresa tra 10 e 20 e due elementi uguali\n");

}
