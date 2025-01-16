/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................11
*/
#include <stdio.h>
/*problema di verifica universale
 * INPUT: un intero n e x1, x2...xn interi
 * PRE-COND: n è la lunghezza della sequenza
 * OUTPUT:un valore boleeano
 * POST-COND:tale valore è true se per ogni tripla di elementi consecutivi vi sono
 due elementi maggiori o uguali a 5 e almeno due pari, false altrimenti*/

/*funzione che data una sequenza verifica se per ogni tripla di elementi consecutivi vi sono
 due elementi maggiori o uguali a 5 e almeno due pari*/
int maggioriCinquePari(int seq[], int l) {
	int maggiori=1;
	int i=0;
while(i<=l-3 && maggiori) {
	if(!((seq[i]>=5 && seq[i+1]>=5 && !(seq[i+2]>=5))
	|| (seq[i]>=5 && seq[i+2]>=5 && !(seq[i+1]>=5)) || (seq[i+1]>=5 && seq[i+2]>=5 && !(seq[i]>=5)) &&
	(!(seq[i]%2==0 && seq[i+1]%2==0) || (seq[i+1]%2==0 && seq[i+2]%2==0) || (seq[i]%2==0 && seq[i+2]%2==0))))
		maggiori=0;
	else
		i++;
	}
	return maggiori;
}

/*funzione principale*/
int main(int argc, char **argv)
{
	int lunghezza;
	printf("quanti interi desideri introdurre?");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];
	for(int i=0;i<lunghezza;i++) {
		printf("inserisci un intero: ");
		scanf("%d", &sequenza[i]);
	}
	if(maggioriCinquePari(sequenza,lunghezza)) {
		printf("per ogni tripla di elementi consecutivi vi sono due elementi maggiori o uguali a 5 e almeno due pari\n");
	}
	else {
		printf("per ogni tripla di elementi consecutivi non vi sono due elementi maggiori o uguali a 5 e almeno due pari\n");
	}
}

