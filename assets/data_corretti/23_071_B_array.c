/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.8
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.8
*/

/* SPECIFICA DEL PROBLEMA
* Input: una sequenza s di interi con una data lunghezza lung
*Pre-condizioni: la lunghezza deve essere almeno 3
*Output: un booleano verificato
*Post-condizioni: verificato vale 1 se in tutte le triple nella sequenza
					ci sono esattamente due positivi interi, 0 altrimenti
*TIPO DI PROBLEMA: verifica universale */


#include <stdio.h>
#include <math.h>

/* funzione che trova i positivi */
int isPos(int ver){
	return ver>0;
}


/* funzione che controlla ogni tripla */
int duePositivi(int a[], int l) {
	int verificato = 1;
	/* ciclo che va avanti fino all'ultimo carattere -2*/
	for (int i = 0; i < l-2; i++) //****** SENZA LA VAR. BOOLEANA NELLA CONDIZIONE, ANCHE SE TROVI
	{							  //****** UNA TERNA CHE NON SODDISFA LA PROPRIETA' VAI AVANTI A CONTROLLARE -0.2
		/* condizioni dove non ci sono esattamente due triple nella sequenza */
		if(((!isPos(a[i])) && (!isPos(a[i+1])) && (!isPos(a[i+2]))) ||
			(isPos(a[i]) && isPos(a[i+1]) && isPos(a[i+2])) ||
			((!isPos(a[i])) && !isPos(a[i+1]) && isPos(a[i+2])) ||
			((!isPos(a[i])) && isPos(a[i+1]) && (!isPos(a[i+2]))) ||
			(isPos(a[i]) && (!isPos(a[i+1])) && (!isPos(a[i+2])))) //****** UN PO' COMPLICATA MA CORRETTA
			verificato = 0;
	}
	return verificato;


}


/* funzione principale */
int main(int argc, char const *argv[])
{
	int lung;
	printf("Caro utente, quanto %c lunga la sequenza? ", 138);
	scanf("%d", &lung);

	/* creazione dell'array */
	int s[lung];
	/* inserimento da tastiera degli interi */
	for (int i = 0; i < lung; i++)
		{
			printf("Inserisci %d interi: ", lung-i);
			scanf("%d", &s[i]);
		}

		/* stampa della sequenza inserita dall'utente */
		printf("Ecco la tua sequenza: ");
		for (int i = 0; i < lung; i++)
		{
			printf("%d ", s[i]);
		}
		printf("\n");

		/* OUTPUT */
		if (duePositivi(s,lung))
			printf("La sequenza contiene esattamente 2 interi positivi per ogni tripla\n");
		else
			printf("La sequenza NON contiene esattamente 2 interi per ogni tripla\n");

	return 0;
}