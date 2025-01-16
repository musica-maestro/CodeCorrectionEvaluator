/* SPECIFICA (max 1.5):....0.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9.0
*/
/*SPECIFICA:  Questo programma data una sequenza di interi in ingresso, verifica se esiste ALMENO
 * una tripla di interi consecutivi tali che, ALMENO 2 elementi della tripla abbiano una somma
 * con un valore compreso tra 10 e 20, e che in questa tripla contemporaneamente ci siano
 * ESATTAMENTE 2 numeri uguali.
 *
 * Input: un intero "numeriTot" ed esattamente X1,X2;x3,.....,XnumeriTot interi che formano una sequenza
 *
 * Pre-condizione: numeriTot e X1,X2;x3,....XnumeriTot devono essere degli interi e NumeriTot deve MAGGIORE O UGUALE A 3
 *
 * Output: Una stampa che informa l'utente se la sequenza di interi da lui inserita ha una almeno una tripla che possiede le caratteristiche descritte
 * 																//******** OUTPUT DEVE RESTITUIRE UN BOOLEANO -0.5
 * Post-condizione: La stampa deve fornire l'informazione corretta.
 * 																//******** LA POST-CONDIZIONE NON DICE NULLA -0.5
 * TIPO DI PROBLEMA: VERIFICA ESISTENZIALE (possiede anche un sotto problema di conteggio)
 * */
#include <stdio.h>
int ugualiCompresi(int sequenza[],int lunghezza);//dichiarazione della funzione ugualiCompresi

//FUNZIONE MAIN:
int main()
{
	int numeriTot; //dichiarazione della variabile che conterrà il numero di elementi totali della sequenza
	int esiste=0; //variabile di esistenza (che assumerà il valore fornito dalla funzione ugualiCompresi)

	//stampa delle istruzioni per l'utente, ovvero quello che fa il programma
	printf("Questo programma ti dice se la sequenza da te inserita possiede almeno una tripla, \nin cui 2 elementi della tripla abbiano una somma con un valore compreso tra 10 e 20, \ne che in questa tripla contemporaneamente ci siano due numeri uguali.\n");
	printf("Dimmi quanti numeri vuoi inserire: \n");
	scanf("%d",&numeriTot);//lettura dell'input dell'utente
	int sequenza[numeriTot];//dichiaro l'array di interi con dimensione numeriTot

	//ciclo for che permette di acquisire tutti i numeri della sequenza dell'utente
	for(int i=0;i<numeriTot;i++)
	{
		printf("Inserisci il numero: ");//stampa dell'istruzione che dice di inserire il numero corrente all'utente
		scanf("%d",&sequenza[i]);
	}
	esiste=ugualiCompresi(sequenza,numeriTot);
	if(esiste==1)
	{
		printf("EVVAI, esiste almeno una tripla che possiede le caratteristiche del problema\n");
	}
	else
	{
		printf("MI DISPIACE, NON ESISTE alcuna tripla che possiede le caratteristiche del problema");
	}
	return 0;
}

//FUNZIONE UGUALI COMPRESI
int ugualiCompresi(int sequenza[],int lunghezza)
{
	//variabile booleana che diverrà 1 quando nella tripla esaminata troverà almeno 2 elementi
	//la cui somma è compresa tra 10 e 20
	int esisteAlmenoSomma=0;
	//variabile di conteggio che conterà il numero di valori uguali tra loro nella tripla esaminata
	int numUguali=1;
	//variabile di esistenza posta a 0, perchè per il momento non abbiamo ancora trovato nessuna
	//tripla che possiede tali caratteristiche
	int esisteTripla=0;
	//ciclo che analizza ogni tripla
	for(int i=0;(i<(lunghezza-2))&&(esisteTripla==0);i++)
	{
		//sequenza di tre if dove per ogni combinazione della tripla verificano se la somma di 2 elementi
		//è compresa tra 10 e 20
		if((((sequenza[i]+sequenza[i+1])<=20) && ((sequenza[i]+sequenza[i+1])>=10)))
		{
			esisteAlmenoSomma=1;//pongo la variabile booleana uguale a 1 perchè ho trovato una coppia che ha le caratteristiche richieste
		}
		if(((sequenza[i]+sequenza[i+2])<=20) && ((sequenza[i]+sequenza[i+2])>=10))
		{
			esisteAlmenoSomma=1;//pongo la variabile booleana uguale a 1 perchè ho trovato una coppia che ha le caratteristiche richieste
		}
		if(((sequenza[i+2]+sequenza[i+1])<=20) && ((sequenza[i+2]+sequenza[i+1])>=10))
		{
			esisteAlmenoSomma=1;//pongo la variabile booleana uguale a 1 perchè ho trovato una coppia che ha le caratteristiche richieste
		}

		//sequenza di tre if che verifica quanti numeri uguali tra loro ci sono
		if(sequenza[i]==sequenza[i+1])
		{
			numUguali++;//incremento la variabile di conteggio
		}
		if(sequenza[i]==sequenza[i+2])
		{
			numUguali++;//incremento la variabile di conteggio
		}
		if(sequenza[i+2]==sequenza[i+1])
		{
			numUguali++;//incremento la variabile di conteggio
		}
		//verifico se le condizioni per la tripla sono verificate, in caso affermativo pongo
		//esisteTripla uguale a 1 e il ciclo finisce, altrimenti resta zero e passo alla terna successiva
		if((esisteAlmenoSomma==1)&&(numUguali==2))
		{
			esisteTripla=1;  //******* NONOSTANTE SIA MOLTO COMPLICATO E' CORRETTO, MA E' TROPPO MACCHINOSO! -1
		}
		//riinizializzo le due variabili a 0 in modo da poterle riutilizzare per la prossima terna
		numUguali=1;
		esisteAlmenoSomma=0;
	}
	return esisteTripla;//restituisco il valore di esisteTripla al main
}

