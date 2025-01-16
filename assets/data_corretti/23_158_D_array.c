/* SPECIFICA (max 1):......0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...0.9
   TOTALE (10).............8.6
*/
/*
SPECIFICA

INPUT: seq e lunghezza
PRE CONDIZIONI: seq e lunghezza sono due interi //**** NON SONO DUE, LA SEUQENZA PUO' AVERE PIU' ELEMENTI -0.3
OUTPUT: un intero 'esiste' (valore booleano)
POST CONDIZIONI: esiste assume valore 1 se all'interno della sequenza esiste una tripla di elementi adiacenti in cui
				uno dei tre è il resto della divisione degli altri due, altrimenti assume valore 0

TIPO DI PROBLEMA: verifica esistenziale

*/


int restoDivisione(int*seq, int lunghezza){

	int i=1;
	int esiste=0;

	while(i<=lunghezza-2 && !esiste){

		if((seq[i]%seq[i-1]==seq[i+1]) || (seq[i]%seq[i+1]==seq[i-1]) || (seq[i-1]%seq[i]==seq[i+1]) ||

			(seq[i-1]%seq[i+1]==seq[i]) || (seq[i+1]%seq[i]==seq[i-1]) || (seq[i+1]%seq[i-1]==seq[i]))
		{

			esiste=1;
		}

		else
			i++;
	}

	return esiste;

}


 #include<stdio.h>

int main()
{
	int lunghezza;

	printf("quanti interi vuoi inserire?\n");
	scanf("%d" ,&lunghezza);

	int seq[lunghezza];

	for(int i=0; i<lunghezza; i++){

		printf("inserisci %d intero", i+1); //**** APPICCICATO -0.1
		scanf("%d", &seq[i]);
	}

	if(restoDivisione(seq, lunghezza))
		printf("esiste");
	else
		printf("non esiste"); //************ OUTPUT PRATICAMENTE MANCANTE -1

}