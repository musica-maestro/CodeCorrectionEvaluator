/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.8
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................10.8
*/
/*SPECIFICA DEL PROBLEMA
 * INPUT: Una sequenza di interi (s), e una variabile (l);
 * PRE-CONDIZIONE: (l) e' la dimensione di (s);
 * OUTPUT: Una variabile booleana (esiste);
 * POST-CONDIZIONE: La variabile (esiste) vale 1 se Ogni tripla di elementi consecutivi contiene esattamente due elementi maggiori o uguali di 5 ed almeno due elementi pari,
 *                  0 altrimenti;
 *
 * PROBLEMA: VERIFICA UNIVERSALE;
 *
 */

#include <stdio.h>

int maggiori5Pari(int array[], int l){

	int esiste=1;
	int i=0;

	while(i<l-2 && esiste){

		if((array[i]<5 && array[i+1]<5 && array[i+2]<5)
		|| (array[i]>=5 && array[i+1]>=5 && array[i+2]>=5)
		|| ((array[i]<5 && array[i+1]<5)
		|| (array[i]<5 && array[i+2]<5)
		|| (array[i+1]<5 && array[i+2]<5)) ||
		  ((array[i]%2!=0 && array[i+1]%2!=0) || (array[i]%2!=0 && array[i+2]%2!=0) || (array[i+1]%2!=0 && array[i+2]%2!=0)))
		//******** CONDIZIONE COMPLICATA, MA CORRETTA POCO LEGGIBILE -0.2//
		  esiste=0;
		else
			i++;
	}

	return esiste;
}

int main(int argc, char **argv){


	int lunghezza;
	printf("Ciao utente, questo e' un  programma che prende una sequenza di interi e verifica se all'interno di essa, ogni tripla di elementi consecutivi contiene\n");
	printf("esattamente due elementi maggiori o uguali di 5 ed almeno due elementi pari.\n");
	printf("\n\nCaro utente, quanti interi vuoi inserire?\n");
	scanf("%d", &lunghezza);

	int sequenza[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Inserire intero, prego..\n");
		scanf("%d", &sequenza[i]);
	}
	if(maggiori5Pari(sequenza, lunghezza))
		printf("Ogni tripla di elementi consecutivi contiene esattamente due elementi maggiori o uguali di 5 ed almeno due elementi pari!\n");
	else
		printf("Esiste almeno una tripla che non contiene esattamente due interi maggiori o uguali a 5 o che non ha almeno due interi pari!\n");

}
