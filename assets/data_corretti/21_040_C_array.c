/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9.5
*/
/*SPECIFICA:
 * Input: Sequenza di interi "interi" e la sua lunghezza
 * Pre-condzione: "lunghezza" è la lunghezza di "interi"
 * Output: un intero "risultato"
 * Post-condizione: "risultato" ha valore pari a 1 nel caso la proprieta' fosse vera, 0 altrimenti
 * //******** LA POST-CONDIZIONE NON DICE NULLA -0.5  QUALE PROPRIETA'?
 * Tipo di Problema: Verifica Esistenziale
 */
#include <stdio.h>

/* Funzione che verifica l'esistenza di una tripla di elementi consecutivi che contiene almeno due elementi il cui
 * valore e' compreso tra -10 e 10 (estremi inclusi) e che contiene esattamente due elementi multipli di 3 */

int compresiMultipli3(int interi[], int lunghezza)
{

    int i = 0;         // variabile contatore inizilizzata a 0
    int risultato = 0; // variabile booleana da restituire, inizialmente poniamo la proprieta' come non rispettata

    /*analizza tutta la sequenza */
    while(i < lunghezza - 2 && !risultato) {
	/*sono tutti divisibili per 3?*/
	if(interi[i] % 3 == 0 && interi[i + 1] % 3 == 0 && interi[i + 2] % 3 == 0)
	    i++; // in tal caso incrementa i di 1 e guarda i prossimi elementi
	else
	    /*vengono rispettate le seguenti proprieta'? se si restituisci valore 1, altrimenti analizza i prossimi
	       elementi fino alla fine della sequenza*/
	    if((interi[i] % 3 == 0 && interi[i + 1] % 3 == 0) || (interi[i + 2] % 3 == 0 && interi[i + 1] % 3 == 0) ||
	        (interi[i] % 3 == 0 && interi[i + 2] % 3 == 0)) {
	    if((interi[i] >= -10 && interi[i] <= 10) && (interi[i + 1] >= -10 && interi[i + 1] <= 10) &&
	        (interi[i + 2] >= -10 && interi[i + 2] <= 10))
	        //******* NON DEVONO ESSERE TUTTI E TRE COMPRESI TRA -10 E 10, MA ALMENO DUE
		risultato = 1;
	    else {
		if((interi[i] >= -10 && interi[i] <= 10) && (interi[i + 1] >= -10 && interi[i + 1] <= 10))
		    risultato = 1;
		else {
		    if((interi[i + 2] >= -10 && interi[i + 2] <= 10) && (interi[i + 1] >= -10 && interi[i + 1] <= 10))
			risultato = 1;
		    else if((interi[i] >= -10 && interi[i] <= 10) && (interi[i + 2] >= -10 && interi[i + 2] <= 10))
			risultato = 1;
		    else  //**********CONDIZIONE TROPPO CONTORTA -0.5
			i++;  //********* INDENTATO MALE! -0.5
		}
	    }
	}
    }
    return risultato; // restituisce valore 1 se la proprieta' si e' confemata, 0 altrimenti
}

/* Funzione Principale */
int main()
{
    int lunghezza; // Quantità di interi dell'array
    /* Input */
    printf("\n\nCiao Utente,\nsono un programma che riceve come parametro una sequenza di interi,\ne verifica "
           "l'esistenza di una un tripla di elementi consecutivi che contiene almeno due elementi,\nil cui valore è "
           "compreso fra -10 e 10 (estremi inclusi)\ne che contiene esattamente due elementi multipli di 3.");
    printf("\nQuanti interi vuoi inserire:? ");
    scanf("%d", &lunghezza);

    int sequenza[lunghezza];
    printf("\n");
    for(int i = 0; i < lunghezza; i++) {
	printf("\nIntroduci un intero: ");
	scanf("%d", &sequenza[i]);
    }

    /* Output */
    if(compresiMultipli3(sequenza, lunghezza))
	printf("\n\nPerfetto! La prorprieta' e' stata verficata =)\n\n ");
    else
	printf("\n\nPeccato! La proprieta' NON e' stata verificata )=\n\n");
}
