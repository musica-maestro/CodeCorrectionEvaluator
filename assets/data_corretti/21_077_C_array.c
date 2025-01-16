/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.2
   TOTALE.................10.7
*/
#include <stdio.h>

/*SPECIFICA
 * Input: una sequenza di interi e un intero che ne rappresenta la sua lunghezza
 * Pre-Condizione: lunghezza > 3
 * Output: un valore di verità booleano
 * Post-Condizione: il codice restituisce il valore true all'utente se esiste nella serie numerica una tripla di numeri consecutivi di cui almeno due compresi fra -10 e 10 e due multipli di 3
 * Problema di Verifica Esistenziale */


 /* Funzione che riceve un array e la sua lunghezza e restituisce true se identifica una terna di numeri di cui almeno due compresi fra -10 e 10 e due multipli di 3 */
int compresiMultipli3(int serie[],int dimensione) {
	int esito;   //variabile booleana del risultato
	int i;       //variabile contatore

	esito = 0;   //inizializzazione per un problema di verifica esistenziale

	/*la funzione esamina ogni elemento della serie e i due numeri dopo fino al terzultimo*/
	for (i=0;i<dimensione-2;i++) {
		if (((((serie[i]>=(-10))&&(serie[i]<=10))&&((serie[i+1]>=(-10))&&(serie[i+1]<=10)))
		||(((serie[i+2]>=(-10))&&(serie[i+2]<=10))&&((serie[i+1]>=(-10))&&(serie[i+1]<=10)))
		||(((serie[i]>=(-10))&&(serie[i]<=10))&&((serie[i+2]>=(-10))&&(serie[i+2]<=10))))
		&&(((serie[i]%3==0)&&(serie[i+1]%3==0)&&(serie[i+2]%3!=0))
		||((serie[i+2]%3==0)&&(serie[i+1]%3==0)&&(serie[i]%3!=0))
		||((serie[i]%3==0)&&(serie[i+2]%3==0)&&(serie[i+1]%3!=0)))) {
			esito = 1;
		}
	}
	return esito;
}


int main()
{
	int lunghezza;    //variabile lunghezza della sequenza
	int risultato;    //variabile booleana del risultato
	int i;            //variabile contatore

	printf("Quanti interi vuoi inserire?\n");
	scanf("%d",&lunghezza);

	int sequenza[lunghezza];     //inizializzazione dell'array

	/*il programma richiede all'utente di inserire la serie di interi*/
	for (i=0;i<lunghezza;i++) {
		printf("Inserisci l'intero %d\n",i+1);
		scanf("%d",&sequenza[i]);
	}

	risultato = compresiMultipli3 (sequenza,lunghezza);

	/*il programma comunica all'utente l'esito della funzione compresiMultipli3*/
	if (risultato == 1) {
		printf("La serie di interi contiene almeno una tripla di numeri di cui almeno due compresi fra -10 e 10 e almeno due divisibili per 3\n");
	}
	else {
		printf("La sequenza non presenta alcuna tripla di numeri particolare");
	}//******** SECONDO OUTPUT UN PO' POVERO -0.3
}
