/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.8
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.8
*/
/* SPECIFICA
 * Input: una sequenza s di numeri di lunghezza lun #include;  //******* #include IMMAGINO SIA UN REFUSO
 * Pre-condizione: i numeri sono interi;
 * Output: un valore variabile;
 * Post-condizione: variabile vale 1 se in ogni tripla di elementi adiacenti ci sono esattamente due numeri positivi<stdio; vale 0 altrimenti.
 * TIPO DI PROBLEMA: Verifica universale */
 #include <stdio.h>

int duePositivi (int *array, int lun) {

	int variabile=1;		//inizilizza la variabile booleana come true
	int i=0;				//inizializza la variabile contatore
	/* fintanto che non è finita la stringa e che le precedenti triple di interi rispettano la condizione, verifica condizione if, altrimenti fai output */
	while (i<lun-2 && variabile==1) {
		/* condizione per verificare se nella tripla ci sono esattamente due interi positivi e uno negatovp */
		if ((array[i]>0 && array[i+1]>0 && array[i+2]<0) || //******* LO 0 COME LO CONSIDERI? -0.2
		    (array[i]>0 && array[i+2]>0 && array[i+1]<0) ||
		    (array[i+1]>0 && array[i+2]>0 && array[i]<0))
			/* se la condizione è rispettata passa all'elemento successivo */
			i++;
		else
			/* altrimenti rendi la variabile booleana uguale a false */
			variabile=0;
	}
	return variabile;

}
int main () {

	int x;
	/* INPUT */
	printf("\nCiao utente, sono un programma che verifica se in ogni tripla di ");
	printf("elementi adiacenti ci sono esattamente due numeri positivi.\n");
	printf("Quanti interi ha la tua sequenza?\n");
	scanf("%d", &x);
	int seq[x];		//dichiara la sequenza di interi di lunghezza fornita dall'utente
	/*ciclo for per memorizzare ogni intero nell'array */
	for (int i=0; i<x; i++) {
		printf("\nInserisci l'elemento con indice [%d]: ", i+1);
		scanf("%d", &seq[i]);
	}
	/* OUTPUT */
	if (duePositivi(seq, x))
		printf("\nSI', in ogni tripla di elementi adiacenti ci sono esattamente due numeri positivi.");

	else
		printf("\nNO, in ogni tripla di elementi adiacenti NON ci sono esattamente due numeri positivi.");
}