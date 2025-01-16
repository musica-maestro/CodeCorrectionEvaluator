/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3
   MAIN PROGRAM (max 2):...1.8
   TOTALE (10).............6.8
*/
/*SPECIFICA
*input: sequenza di interi e la sua lunghezza
pre condizione: gli interi della sequenza devono essere tutti positivi e la lunghezza >= 3
output: un valore negativo o positivo
post condizione: se in ogni terna ci sono almeno due numeri composti da una sola cifra l'istanza è positiva,
                 mentre se anche in una sola terna della sequenza non ci sono almeno due numeri composti da una sola cifra l'istanza è negativa
TIPO DI PROBLEMA: universale
*/

#include <stdio.h>

int dueUnaCifra(int **seq[], int lunghezza) { //**** O SCRIVI int *seq, OPPURE int seq[] -1

	int verifica = 1;
	int i = 1; //****** i DEVE PARTIRE DA 0 -0.5

	while((i<=lunghezza) && verifica) { //****** i<lunghezza-2 -1
		if((seq[i]>9 && seq[i+1]>9) || (seq[i]>9 && seq[i+2]>9) || (seq[i+2]>9 && seq[i+1]>9)) {
		//***** QUESTA CONDIZIONE E' VERA SE CI SONO ALMENO DUE NUMERI CON PIU' DI UNA CIFRA -1.5
			i++;
		}else{
			verifica = 0;
		}
	}
	return verifica;
}

int main() {

	int lunghezza;
	int seq[lunghezza];

	printf("Ciao, sono un programma che controlla le terne di una sequenza che mi dai e guarda se sono composte da almeno due caratteri da una cifra, dimmi quanto la vuoi fare lunga!!\n");
	scanf("%d", &lunghezza);

	printf("inserisci gli interi della sequenza!!\n");

	for(int i = 0; i < lunghezza; ++i) {
		printf("Dammi un intero!\n");
		scanf("%d", &seq[i]);
	}
                                                //******* I CARATTERI ACCENTATI NON SONO AMMESSI -0.2
	printf("se in ogni terna ci sono almeno due numeri composti da una sola cifra l'istanza è positiva,\n");
	printf("mentre se anche in una sola terna della sequenza non ci sono almeno due numeri composti da una sola cifra l'istanza è negativa\n");
	printf("il valore dell'istanza corrisponde a: %d\n", dueUnaCifra(seq, lunghezza));

}
