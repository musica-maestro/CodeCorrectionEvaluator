/* SPECIFICA (max 1.5):....1,5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9,4
*/
#include <stdio.h>

/* SPECIFICA
 * Input: una sequenza di n interi
 * Pre-condizione: n è il numero di elementi della sequenza
 * Output: un valore booleano
 * Post condizione: il valore booleano vale 1 se ogni tripla di elementi contiene esattamente due elementi
 * 					maggiori o uguali di 5 ed almeno due elementi pari, altrimenti 0.
 */

 /* Problema di verifica universale */

/* PROTOTIPI DELLE FUNZIONI */
int maggiori5Pari (int seq[], int d);
int verificaPari (int numero);
int verificaMaggiore5 (int num);

/* FUNZIONE PRINCIPALE */
int main(int argc, char **argv)
{
	int dim; // dimensione della sequenza

	/* INPUT DELLA DIMENSIONE DELLA SEQUENZA */
	printf("Inserire la dimensione della sequenza desiderata: ");
	scanf("%d", &dim);

	/* DICHIARAZIONE DELLA SEQUENZA */
	int sequenza[dim];

	/* INPUT DEGLI INTERI DELLA SEQUENZA */
	printf("Sequenza:\n");
	for (int i = 0; i < dim; i++)
	{
		printf("%d) ", i+1);
		scanf("%d", &sequenza[i]);
	}

	/* INVOCAZIONE DELLA FUNZIONE ED OUTPUT */
	if ( maggiori5Pari(sequenza, dim) )
		printf("Ogni tripla di elementi contiene esattemente due elementi maggiori od uguali a 5 ed almeno due elementi pari\n"); // esito positivo
	else
		printf("Alcune triple di elementi non contengono esattemente due elementi maggiori od uguali a 5 ed almeno due elementi pari\n"); // esito negativo


}

/* Funzione che data una sequenza di n interi, verifica se ogni tripla consecutiva di interi, possiede
 * esattamente due elementi maggiori o uguali a 5 ed almeno due pari. Restituisce 1 se soddisfa la condizione,
 * 0 altrimenti. */
int maggiori5Pari (int seq[], int d)
{
	int esito = 1; // variabile booleana che vale 1 all'inizio e se soddisfa la condizione, 0 altrimenti
	int contaPari; // variabile contatore che conta quanti numeri sono pari in una tripla
	int contaNumMaggiori5; // variabile contatore che conta quanti numeri sono maggiori o uguali a 5 in una tripla
	int ind; // indice della sequenza

	//******** ind NON E' INIZIALIZZATO A ZERO -1
	while (esito && ind < d-2)
	{
		/* I contatori vengono azzerati */
		contaPari = 0;
		contaNumMaggiori5 = 0;

		/* ciclo che conta quanti elementi della tripla sono pari e quanti maggiori od uguali a 5 */
		for (int j = 0; j <= 2; j++)
		{
			if ( verificaPari(seq[ind+j]) ) // se il numero è pari
				contaPari++; // numero pari
			if ( verificaMaggiore5(seq[ind+j]) )
				contaNumMaggiori5++; // numero maggiore o uguale a 5
		}

		/* Verifica della condizione */               //******** CONDIZIONE COMPLICATA, MA CORRETTA -0.5
		if (contaNumMaggiori5 == 2 && contaPari >=2)
			ind++; // passa alla prossima tripla
		else
			esito = 0; // tripla negativa
	}

	return esito; // restituisce 1 se la funzione soddisfa la condizione, 0 altrimenti
}

/* funzione che preso un numero in input, restituisce 1 se il numero è pari, 0 altrimenti */
int verificaPari (int numero)
{
	return (numero % 2 == 0); // vale 1 se è pari, 0 altrimenti
}

/* funzione che preso un numero in input, restituisce 1 se il numero è maggiore o uguale a 5, 0 altrimenti */
int verificaMaggiore5 (int num)
{
	return (num >= 5); // vale 1 se è maggiore od uguale a 5, 0 altrimenti
}