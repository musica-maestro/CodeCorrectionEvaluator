/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4
   MAIN PROGRAM (max 2.5):.1
   TOTALE..................7
*/

#include <stdio.h>

 /*
  * Precondizioni: sequenza s di numeri interi, lunghezza l. l è la lunghezzza della sequenza.
  * Input: sequnza di numeri interi, l>0
  * Output: valore condizione di tipo int
  * Postcondizioni: condizione può valere 1 se si verifica la condizione prefissata, oppure 0 se, invece, non la verifica.
  * Tipo problema: verifica esistenziale. //******** LA POST-CONDIZIONE NON DICE NULLA -0.5
*/

// funzione che controlla la condizione del problema
int compresiMultipli3(int sequenza[], int lunghezza)
{
	int i=0, condizione=0; // inizializzo il contatore e la variabile condizione usata per riportare l'esito della verifica

	while(i+2<lunghezza && condizione==0) //scorro la sequenza finchè non si verifica la condizione oppure vado oltre la lunghezza della sequenza
	{
		if((sequenza[i]<10 && sequenza[i]>-10)&&(sequenza[i+1]<10 && sequenza[i+1]>-10)
		||(sequenza[i]<10 && sequenza[i]>-10)&&(sequenza[i+2]<10 && sequenza[i+2]>-10)
		||(sequenza[i+1]<10 && sequenza[i+1]>-10)&&(sequenza[i+2]<10 && sequenza[i+2]>-10)) // controllo se nei tre numeri presi in considerazione almeno 2 di loro sono compresi tra -10 e 10
		{//*********** MINORE O UGUALE, MAGGIORE O UGUALE -0.5
			if((sequenza[i]%3==0 && sequenza[i+1]%3==0)
			||(sequenza[i]%3==0 && sequenza[i+2]%3==0)
			||(sequenza[i+1]%3==0 && sequenza[i+1]%3==0)) // controllo se nei primi numeri presi in consiederazione 2 sono multipli di 3
//******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO DIVISIBILI PER 3 ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
//******** ES. se la tripla e' 3 12 6 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
			{
				condizione=1; //se si verficano tutte le condizioni, cambio valore alla variabile condizione
			}

			else
			{
				i++; // incremenento il contatore se la condizione non è stata verificata
			}
		}
		else
		{
			i++;// incremenento il contatore se la condizione non è stata verificata
		}
	}
	return condizione;
}

int main(int argc, char **argv)
{
	// dichiaro la lunghezza, la variabile sequenza e il contatore
	int lunghezza;
	int sequenza[lunghezza];//******** DEVI LEGGERE LA LUNGHEZZA DA INPUT PRIMA DI DICHARARE L'ARRAY -1
	int i=0;

	printf("inserisci la lunghezza della sequenza/n"); // chiedo all'utente la lunghezza della sequenza desiderata
	scanf("%d",&lunghezza); //inserimento della lunghezza da parte dell'utente
	for(i=0; i<lunghezza; i++)
	{
		printf("inserisci il valore all'interno della sequenza");// chiedo all'utente di inserire i valori nella sequenza
		scanf("%d", &sequenza[i]);//inserimento dei valori da parte dell'utente
	}
	if(compresiMultipli3(sequenza, lunghezza)) //richiamo la funzione e controllo il risultato dato dalla funzione
	{
		printf("i valori della sequenza verficano la condizione proposta");// stampo questo se condizione è uguale a 1
	}
	else
	{
		printf("i valori della sequenza non verficano la condizione proposta");// stampo questo se condizione è uguale a 0
	}
	return 0; //******** OUTPUT MOLTO POVERO -0.5
}
