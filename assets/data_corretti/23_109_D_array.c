/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............8.5
*/
/*SPECIFICA
*Input: una sequenza di n interi
*Pre-condizione: n>=0
*Output: un vaore booleano 1 o 0
*Post-condizione: 1 se esiste almeno una tripla di elementi adiacenti in cui uno dei tre
è il resto della divisione degli altri due, 0 altrimenti
*TIPO DI PROBLEMA: VERIFICA ESISTENZIALE*/
#include <stdio.h>

/*FUNZIONE INVOCATA*/
int restoDivisione(int seq[],int lung) {
	int i=0; //variabile contatore
	int verificata=0; //variabile booleana
	while(i<lung-2 && !verificata) {
			/*vediamo se uno dei tre è il resto della divisione degli altri due*/
			if((seq[i] % seq[i+1] == seq[i+2]) ||
				(seq[i] % seq[i+2] == seq[i+1]) ||
				(seq[i+1] % seq[i+2] == seq[i]))//******** CONDIZIONE INCOMPLETA mancano altre tre combinazioni -1
				verificata=1;
			else
				i++;
		}
	return verificata;

}

int main() {
	int n; //n è la lunghezza dell'array
	printf("Ciao utente! Quanto vuoi lunga la sequenza da verificare?\n");
	scanf("%d", &n);
	int seq[n];
	int i; //variabile contatore

	/*andiamo a inserire i valori nell'array uno alla volta*/
	for(i=0;i<n;i++) {
		printf("Dammi un intero:\n");
		scanf("%d", &seq[i]);
	}

	if(restoDivisione(seq,n)) {
		printf("Esiste una terna di elementi adiacenti che soddisfa la condizione\n");
	}

	else{
		printf("Non esiste una terna che soddisfa la condizione"); //************ OUTPUT NON ESPLICATIVO -0.5
	}

}