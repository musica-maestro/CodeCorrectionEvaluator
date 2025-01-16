/* SPECIFICA (max 1.5):....0  //******** MANCANTE
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......3.2
   MAIN PROGRAM (max 2.5):.2.3
   TOTALE..................5.5
*/
/* programma che dato un array di interi verifica che tutte le triple contengano due interi >= 5 e due interi pari */
/* si tratta di un problema di verifica esistenziale: ossia se esiste una tripla che non soddisfa la condizione */
#include <stdio.h>   //******* NO, E' UNA VERIFICA UNIVERSALE -1

int maggiori5Pari(int interi[], int lunghezza) {
		int i = 0;
		int triple = 1;

	while(i<=lunghezza-3 && triple) {
		if(		// restituisce uno se la tripla soddisfa le proprietà
		((interi[i]>=5 && interi[i+1]>=5 && interi[i+2]<=5)  ///**** interi[i+2]<5 -0.3
		|| (interi[i+1]>=5 && interi[i+2]>=5 && interi[i]<=5)
		|| (interi[i]>=5 && interi[i+2]>=5 && interi[i+1]<=5)) &&		// se l tripla contiene due interi >=5
//**** QUESTA PRIMA CONDIZIONE E' VERA SE CI SONO ESATTAMENTE DUE INTERI >=5
		((interi[i]%2!=0 && interi[i+1]%2!=0 && interi[i+2]%2==0)
		|| (interi[i+1]%2!=0 && interi[i+2]%2!=0 && interi[i]%2==0)
		|| (interi[i]%2!=0 && interi[i+2]%2!=0 && interi[i+1]%2==0))) 	// se la tripla contiene due interi pari
//**** QUESTA SECONDA E' FALSA SE CI SONO ESATTAMENTE DUE PARI
//**** DUE ERRORI: 1) CI POSSONO ESSERE ALMENO 2 PARI (POSSONO ESSERE PARI ANCHE TUTTI E TRE)
//**** 2) ANCHE LA PRIMA CONDIZIONE DEVE ESSERE FALSA, NON VERA -2.5
			triple = 0; 	// se la condizione non è soddisfatta restituisce 0
			else
				i++;		// sennò vai avanti, se è soddisfatta restituisce 1
	}
	return triple;
}
/* funzione principale */
int main(int argc, char **argv)
{
	/* INPUT */
	int lunghezza;	// lunghezza dell'array
	// chiedo la lunghezza dell'array
	printf("Caro utente introduci pure la lunghezza della sequenza di interi: \n");
	scanf("%d", &lunghezza);
	// chiedo di inserire gli interi dell'array
	int sequenza[lunghezza];
	for(int i=0; i<lunghezza; i++) {	// richiesta compilazione array
		printf("Prego introduci l'intero numero %d: \n", i+1);
		scanf("%d", &sequenza[i]);
	}
	/* OUTPUT */
	if(maggiori5Pari(sequenza,lunghezza))
		printf("Tutte le triple contengono esaattamente due interi >=5 e due interi pari\n");
		else  //******** INDENTATO MALE -0.2
			printf("Non tutte le triple contengono esattamente due interi >=5 e due interi pari\n");

	return 0;
}
