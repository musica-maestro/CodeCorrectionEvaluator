/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3
   MAIN PROGRAM (max 2.5):.2.2
   TOTALE..................7.7
*/
/* Specifica:
 * INPUT: un array di interi e un intero che rappresenta la sua lunghezza
 * PRE-CONDIZIONE: lunghezza>0
 * OUTPUT: trovato è un valore booleano di tipo int
 * POST-CONDIZIONE: trovato 1 (vera) se esiste almeno una tripla di elementi consecutivi
 * 					tale che almeno due elementi della tripla hanno una somma compresa fra 10 e 20 inclusi,
 * 					vale 0 (falsa) altrimenti
 *
 * Tipo di problema: Verifica esistenziale
 */

#include <stdio.h>

int ugualiCompresi(int interi[], int lunghezza){

	int i=0; //variabile contatore
	int trovato=0; //valor booleano restituito alla fine
	while(i<lunghezza-2 && !trovato) {
		/* se non ci stanno due elementi identici e se ci stanno almeno 2 elementi nella tripla
		 * che hanno somma compresa tra 10 e 20 inclusi allora trovato è vera*/
		if(!((interi[i]==interi[i+1])||(interi[i]==interi[i+2])||(interi[i+1]==interi[i+2]))
		//******** CE NE DEVONO ESSERE ESATTAMENTE DUE UGUALI!
		//******** ENTRA NELL'IF SE I TRE ELEMENTI SONO TUTTI DISTINTI -1.5
			&&((10<=interi[i]+interi[i+1]<=20)||(10<=interi[i+1]+interi[i+2]<=20)||(10<=interi[i]+interi[i+2]<=20))) {
			    //******** QUESTA ESPRESSIONE NON ESPRIME "ESSERE COMPRESO TRA"  (caputo/BASSI/FAIELLA)
			    //******** MA IL C CALCOLA ALTRO ((10<=(interi[i]+ interi[i+1])) <=20) -1.5

		trovato=1; }
				else { //i numeri devono essere esattamente 2 senno trovato è falsa
					if(interi[i]==interi[i+1]==interi[i+2])	// ***** QUESTO NON MI DICE ESATTAMENTE DUE
						trovato=0;
						else
							i++; //passo al successivo
				}
				i++;

	}
	return trovato;
}

int main(){

	int i; //variabile contatore
	int l; //lunghezza dell'array

	printf("Caro utente, inserisci la lunghezza della sequenza: ");
	scanf("%d", &l);

	int seq[l];
	for(i=0;i<l;i++) {
		printf("\nInserisci l'elemento in questione: ");
		scanf("%d", &seq[i]);
	}

	if(ugualiCompresi(seq,l)) {
		printf("\nEsiste almeno una tripla di elementi consecutivi tale che\n");
		printf("almeno due elementi della tripla hanno la somma compresa fra 10 e 20 inclusi\n\n");
	}else{
			printf("\nAlmeno una tripla di elementi consecutivi NON ha almeno due dei suoi elementi\n");
			printf("la cui somma %c compresa tra 10 e 20 inclusi\n\n", 138);
	}        //******** OUTPUT UN PO' POVERO -0.3
	return 0;
}
