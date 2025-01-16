/* SPECIFICA (max 1):......0.6
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............8.4
*/
/* INPUT: una sequenza di interi (x1,...,xn)
* PRE-CONDIZIZIONE : interi  //******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
* OUTPUT: valore booleano che è uguale a 1 se l'istanza è positiva, uguale a zero altrimenti
* POST-CONDIZIONE: ogni tripla di interi deve contenere almeno due elementi //******* OUTPUT E POSTCONDIZIONE INSIEME -0.2
composti da una sola cifra
* TIPO DI PROBLEMA: verifica universale */
#include <stdio.h>
int dueUnaCifra(int* seq, int lunghezza) {
	int i = 0; 	//variabile contatore
	int verifica = 1; //variabile di universalità
	while(i<lunghezza-2 && verifica) { //fintanto che non ci sono due interi a una cifra
		if (!((seq[i]<10 && seq[i+1]<10 && (seq[i+2]<10 || seq[i+2]>10)) || //primo e secondo minori di 10
//****** CHE SENSO HA (seq[i+2]<10 || seq[i+2]>10))? NON SERVE -1
		(seq[i]<10 && seq[i+2]<10 && (seq[i+1]<10 || seq[i+1]>10)) ||	//primo e terzo minori di 10
		(seq[i+1]<10 && seq[i+2]<10 && (seq[i]<10 || seq[i]>10)))) //secondo e terzo minori di 10
			verifica = 0;	//non è verificata
		else
			i++; //vai al successivo
	}
	return verifica;
}

int main() {
	//input
	int lunghezza;
	printf("quanti elementi vuoi inserire?\n");
	scanf("%d", &lunghezza);
	int seq[lunghezza];
	//assegno a ogni slot dell' array un elemento
	for (int i = 0; i<lunghezza; i++) {
		printf("dammi l'elemento numero %d\n", i+1);
		scanf("%d", &seq[i]);
	}
	//output
	if (dueUnaCifra(seq, lunghezza))
		printf("istanza POSITIVA!\n");
	else
		printf("istanza NON positiva\n");//************ OUTPUT NON ESPLICATIVO -0.5
}

