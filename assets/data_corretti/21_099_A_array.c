/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................8
*/
/* algoritmo che verifica se esiste una tripla di elementi consecutivi tale che almeno due elementi della tripla hanno una somma compresa fra 10 e 20 (estremi inclusi) ed esattamente due elementi della tripla fra loro uguali */

#include <stdio.h>

/* funzione che restituisce uno oppure zero in base alle terne presenti al suo interno */
int ugualiCompresi(int array[], int dimensione){
	int i = 2; //variabile che indica la cella di partenza
	int risultato; //output

	/* verifica se esistono esattamente due elementi ugugali all'interno di una tripla */
	for(i = 2; i < dimensione; i++){ //******** NON USI LA VARIABILE BOOLEANA PER TERMINARE IL CICLO -1
									 //******** ANCHE PERCHE' NON L'HAI INIZIALIZZATA...
		if(((array[i] == array[i-1]) && (array[i-1] != array[i-2]))
		|| ((array[i] == array[i-2]) && (array[i-1] != array[i-2]))
		|| ((array[i-1] == array[i-2]) && (array[i-2] != array[i]))){
			if(((array[i] + array[i-1] >= 10) && (array[i] + array[i-1] <= 20))
			|| ((array[i] + array[i-2] >= 10) && (array[i] + array[i-2] <= 20))
			|| ((array[i-1] + array[i-2] >= 10) && (array[i-1] + array[i-2] <= 20)))
				risultato = 1;
			else
				risultato = 0;  //******** RESTITUISCI IL VALORE CALCOLATO SULL'ULTIMA TRIPLA -1.5
		}
		else
			risultato = 0;
	}
	return risultato;
}

/* funzione main */
int main(int argc, char **argv)
{
	int d; //variabile dimensione array (input)
	int i; //variabile contatore

	//stampa
	printf("Caro utente quanti interi vuoi inserire?:\n");
	scanf("%d", &d);

	//inizializzo l'array
	int array[d];

	//chiede all'utente di inserire dei valori fino a quando non viene riempito l'array
	for(i = 0; i < d; i++){
		printf("Inserisca un valore:\n");
		scanf("%d", &array[i]);
	}

	//stampa gli interi inseriti all'interno dell'array
	printf("I valori inseriti nell'array sono i seguenti:\n");
	for(i = 0; i < d; i++)
	printf("%d ", array[i]);

	//stampa il risultato
	printf("Se all'interno dell'arry ci sono delle triple composte da 2(due) elementi uguali fra loro che sommati formano un numero compreso tra 10(dieci) e 20(venti) viene stampato 1(uno) altrimenti 0(zero):\n");
	printf("| %d |", ugualiCompresi(array, d));
}
/* problema di verifica esistenziale */
/* input: x1, x2, x3, ..., xn.
 * pre-Condizioni: x1, x2, x3, ..., xn sono interi.
 * output: y.
 * post-condizioni: y Ã¨ un valore che indica se la terna soddisfa delle determinate proprietÃ
*/                  //******** LA POST-CONDIZIONE NON DICE NULLA -0.5
