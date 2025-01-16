/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
 /*SPECIFICA
 *input: una sequenza di interi e un intero 'n'
 *pre-condizione: 'n' indica la lunghezza della seqeunza
 *output:variabile booleana 'verificato'
 *post-condizione: 'verificato'=1, se in ciascuna terna di elementi adiacenti della sequenza alemeno un elemento della terna è multiplo di uno degli altri due, 0 altrimenti
 *tipo di problema: verifica universale
 */

#include <stdio.h>


//funzione multipli che verifica se in ciascuna terna di elementi adiacenti della sequenza alemeno un elemento della terna è multiplo di uno degli altri due
int multipli(int s[], int l)
{
	int verificato=1;	//variaile di verifica universale
	for (int i = 0; i < l-2&&verificato; i++)
	{
		if(s[i]%s[i+1]!=0&&s[i]%s[i+2]!=0&&s[i+1]%s[i+2]!=0&&s[i+1]%s[i]!=0&&s[i+2]%s[i]!=0&&s[i+2]%s[i+1]!=0)		//verifica della prorpietà
			verificato=0;
	}
	return verificato;		//ritorno la variabile di verifica universale
}



//Funzione principale
int main()
{
	int n;	//variabile che indica la lunghezza della sequenza di interi
	printf("caro utente inserisci la lunghezza della sequenza\n");
	scanf("%d",&n);

	int sequenza[n];		//dichiarazione dell'array di n elementi

	/*INPUT*/
	printf("inserisci i numeri della sequenza\n");
	for (int i = 0; i < n; i++)
		scanf("%d",&sequenza[i]);

	/*OUTPUT*/
	if(multipli(sequenza,n))
		printf("in ciascuna terna di elementi adiacenti della sequenza c'%c alemeno un elemento della terna  %c multiplo di uno degli altri due\n",138,138);
	else
		printf("c' %c almeno una terna di elementi adiacenti della seuqenza in cui nessun elemento %c multiplo di uno degli altri due\n",138,138);
}
