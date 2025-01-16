/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
/*SPECIFICA
*Input: sequenza di n interi x1, x2, ... , xn
*Pre-condizione: n >= 3
*Output: Valore booleano true o false
*Post-condizione: La funzione resistuisce true se la sequenza
contiene almeno una tripla di elementi adiacenti in cui uno dei
tre è il resto della divisione intera degli altri due, altrimenti
resistuisce false
*TIPO DI PROBLEMA: VERIFICA ESISTENZIALE*/

#include <stdio.h>

/*funzione che restituisce true se almeno una tripla di adiacenti contiene un intero
che è il resto della divisione intera tra gli altri due, false altrimenti*/
int restoDivisione(int* seq, int l) {
	int esiste = 0; //variabile di controllo della proprietà
	int i = 0; //variabile contatore
	while (i+2<l && !esiste) {
		/*se un intero della tripla attuale è il resto
		della divisione intera degli altri due...*/
		if ((seq[i+1]%seq[i+2]==seq[i] || seq[i+2]%seq[i+1]==seq[i]) ||
			(seq[i]%seq[i+2]==seq[i+1] || seq[i+2]%seq[i]==seq[i+1]) ||
			(seq[i]%seq[i+1]==seq[i+2] || seq[i+1]%seq[i]==seq[i+2]))
			/*... la condizione è soddisfatta e 'esiste' prende il valore
			di verità 'true'*/
			esiste = 1;
		/*altrimenti viene incrementata la variabile contatore di uno*/
		else
			i++;
	}
	/*viene restituito il valore di 'esiste'*/
	return esiste;
}

/*funzione main che chiede all'utente di inserire una sequenza di interi*/
int main() {
	int lunghezza; //lunghezza sequenza
	printf("Ciao utente, dimmi quanti interi vuoi inserire: ");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];
	/*l'utente inserisce gli interi nella sequenza*/
	for (int i=0; i<lunghezza; i++) {
		printf("Inserisci un intero: ");
		scanf("%d", &sequenza[i]);
	}
	/*se la condizione è soddisfatta*/
	if (restoDivisione(sequenza, lunghezza)) {
		printf("Esiste almeno una tripla di elementi adiacenti in cui ");
		printf("un elemento e' il resto della divisione intera degli altri due!");
	}
	/*se la condizione non è soddisfatta*/
	else {
		printf("Non esiste nessuna tripla di elementi adiacenti in cui ");
		printf("un elemento e' il resto della divisione intera degli altri due!");
	}
}