/* SPECIFICA (max 1.5):....0.9
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3
   MAIN PROGRAM (max 2.5):.1.5
   TOTALE..................6.4
*/
/*SPECIFICA
 * INPUT: una sequenza di numeri
 * PRE-CONDIZIONE: i numeri inseriti devono essere interi
 * OUTPUT: un messaggio che dica all'utente se esistono o no le condizioni  //******** OUTPUT NON CORRETTO (un booleano) -0.3
 * POST-CONDIZIONE: Una tripla di numeri consecutivi deve avere 2 numeri consecutivi uguali e 2 numeri consecutivi con somma compresa tra 10 e 20
 * //******** POST-CONDIZIONE NON CORRETTA (NON DEVONO NECESSARIAMENTE ESSERE CONSECUITIVI NELLA TRIPLA) -0.3
 * TIPO DI PROBLEMA: VERIFICA ESISTENZIALE
 * */
#include <stdio.h>
//******** SE LA FUNZIONE LA SCRIVI SOTTO, DEVI DICHIARARE IL PROTOTIPO -0.5

int main(int argc, char **argv)
{
	int num;
	printf("Quanti valori si vogliono inserire: ");
	scanf("%i",&num); //inizializzazione degli elementi di un array
	//******** IL FORMATO DI ACQUISIZIONE DI UN INTERO E' %d -0.5
	int numeri[num];
	for(int i=0;i<num;i++)
	{
		printf("Numero %i: ",i); //******** IL FORMATO DI STAMPA DI UN INTERO E' %d -0.5
		scanf("%i", &numeri[i]); //******** COME SOPRA
	}

	if(ugualiCompresi(numeri,num))
		printf("Esiste una tripla con 2 numeri consecutivi uguali e 2 numeri consecutivi la cui loro somma e' compresa tra 10 e 20");
	else
		printf("Non esiste una tripla con 2 numeri consecutivi uguali e 2 numeri consecutivi la cui loro somma e' compresa tra 10 e 20");
	return 0;
}

int ugualiCompresi(int numeri[], int num)
{
	int ritorno=0; //serve per avere un unico return attraverso un'operazione booleana
	for(int i=2;i<num;i++) //for ciclare le triple
	{
		if(numeri[i-2]==numeri[i-1] || numeri[i-1]==numeri[i]) //controlla se ci sono 2 numeri consecutivi uguali
		{
			if(numeri[i-2]!=numeri[i]) //controlla se i 2 numeri all'esterno della tripla siano diversi
			{
	//******** CONTROLLI SOLO SE I PRIMI DUE SONO UGUALI, MA POTREBBERO ESSERE UGUALI ANCHE IL SECONDO E IL TERZO
	//******** LA CONDIZIONE E' INCOMPLETA -1.5
				if(10<=(numeri[i-2]+numeri[i-1]) && (numeri[i-2]+numeri[i-1])<=20 || 10<=(numeri[i-2]+numeri[i-1]) && (numeri[i-2]+numeri[i-1])<=20) //controlla se ci sono 2 numeri consecutivi con somma tra 10 e 20
				{//******** RIPETI DUE VOLTE LA STESSA CONDIZIONE  -1.5
					ritorno=1;
				}

			}
		}

	}


	return ritorno;

}
