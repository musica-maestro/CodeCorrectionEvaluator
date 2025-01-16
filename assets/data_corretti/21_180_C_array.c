/* SPECIFICA (max 1.5):....0  //****** MANCANTE
   TIPO PROBLEMA (max 1):..0  //****** MANCANTE
   FUNZIONE (max 6):.......0  //****** MANCANTE
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................2.5
*/
#include <stdio.h>
//questo programma serve a verificare se esiste una tripla di elementi consecutive
//che contiene almeno due elementi il cui valore è compreso fra -10 e 10
//e che contenga almeno due multipli di 3

int main(int argc, char **argv)
{
	int l;				//variabile lunghezza
	int i;						//variabile contatore
	int risultato;//varaibile contentente output
	printf("Ciao utente quanto %c lunga la tua sequenza?\n",138);
	//stampa la lunghezza
	scanf("%d",&l);
	//inizzializzo l'array chiamato sequenza
	int sequenza[l];
	//assegno ad ogni indice un valore
	for(i=0;i<l;i++){
		printf("Introduci l'intero all'indice %d\n",i);
		scanf("%d",&sequenza[i]);
	}
	ris=compresiMultiplidi3(sequenza,l);
	if(ris){
	printf("Esiste una tripla di elementi consecutivi che contiene almeno due elementi il cui valore è compreso fra -10 e  10");
	printf("e che contiene esattamente due elementi che sono multipli di 3");

	}
	else{
	printf("Mi dispiace, ma non esiste una tripla di elementi consecutivi che contiene almeno due elementi il cui valore è compreso fra -10 e  10", 138);
	printf("e che contiene esattamente due elementi che sono multipli di 3");
	}
}