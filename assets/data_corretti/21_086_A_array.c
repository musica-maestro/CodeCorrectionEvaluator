/* SPECIFICA (max 1.5):....0.1
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................7.1
*/
#include <stdio.h>
/*SPECIFICHE:
 *
 * INPUT: array v[] e lunghezza l //******** MANCANO I TIPI DEGLI ELEMENTI DELL'ARRAY  -0.6
 * Pre-condizioni: esiste = 0     //******** NO! -0.3
 * OUTPUT: esiste
 * Post-condizioni: esiste = 1 se le condizioni sono verificate , 0 altrimenti //******** LA POST-CONDIZIONE NON DICE NULLA -0.5
 *
 * TIPO DI PROBLEMA: ricerca   //******** 	NO: E' UNA VERIFICA ESISTENZIALE! 1
*/
/* funzione che individua se presente una tripla di elementi con due valori uguali e con somma compresa tra 10 e 20 */
int ugualiCompresi(int v[],int l){
	int esiste=0;		// variabile esiste=0
	/* istruzione ripetitiva che scorre la sequenza */
	for(int i=0;i<l-2;i++){  //******** NON USI LA VARIABILE BOOLEANA PER TERMINARE IL CICLO -1
		/* con i due if la tripla di elementi viene controllata */
		if((v[i]==v[i+1] && v[i+2]!=v[i])
		|| (v[i]==v[i+2] && v[i+1]!=v[i])
		|| (v[i+1]==v[i+2] && v[i+1]!=v[i])){
			if((v[i]+v[i+1]>=10 && v[i]+v[i+1]<=20)
			|| (v[i]+v[i+2]>=10 && v[i]+v[i+2]<=20)
			|| (v[i+1]+v[i+2]>=10 && v[i+1]+v[i+2]<=20)){
				esiste=1;		// se le condizioni del predicato dell' if sono verificate assegna 1 a esiste
			}
		}
	}
	return esiste;		// restituisci esiste
}
/* funzione principale */
int main()
{
	// INPUT:
	int l;		// lunghezza array
	printf("ciao utente, inserisci la lunghezza.\n");
	scanf("%d",&l);		// inserimento lunghezza
	int v[l];		// dichiarazione array
	printf("Inserisci %d elementi\n",l);
	for(int i=0;i<l;i++){		// riempimento array
		scanf("%d",&v[i]);
	}
	// OUTPUT:
	printf("Risultato : %d\n\n",ugualiCompresi(v,l));		// richiamo funzione e stampa del risutato
	return 0;   //******** I/O MOLTO POVERO -0.5
}
