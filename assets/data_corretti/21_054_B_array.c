/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.8
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................10.3
*/
/* SPECIFICA:
 * Input: intero num, array di interi sequenza;
 * Pre-condidizione: num >0, elementi di sequenza devono essere interi;
 * Output: 1 se soddisfa le condizioni, 0 altrimenti;
 * Post-condizioni: restituisce 1 o 0 in base all'istanza inserita. //******** LA POST-CONDIZIONE NON DICE NULLA -0.5
 *
 * TIPO DI PROBLEMA: verifica universale */
#include <stdio.h>

/* Funzione che restituisce 1 se ogni tripla di elementi della sequenza ha esattamente due elementi maggiori di 5 ed almeno due elementi pari */
int maggiore5Pari(int array[], int n){
	int tutte=1;				//variabile di ritorno, booleana, vale 1 fino a quando le condizione sono soffisfatte
	int i=0;					//indice
	/* interrogo tutti gli elementi dell'array fino a che la condizione è soddisfatta */
	while (tutte && i<n-2){
		/* se la condizione è soddisfatta allora proseguo*/
		if (((array[i]>=5 && array[i+1]>=5 && array[i+2]<5)
		|| (array[i]>=5 && array[i+2]>=5 && array[i+1]<5)
		|| (array[i+2]>=5 && array[i+1]>=5 && array[i]<5)) &&
		((array[i]%2==0 && array[i+1]%2==0)
		|| (array[i+2]%2==0 && array[i+1]%2==0)
		|| (array[i]%2==0 && array[i+2]%2==0) || (array[i]%2==0 && array[i+1]%2==0 && array[i+2]%2==0)))
				i++; //******** L'ULTIMA CONDIZIONE NON SERVE -0.2
		else //altrimenti esco dal ciclo while
			tutte=0;
	}
	return tutte;
}

/* Funzione principale */
int main(){
	int num; 					//variabile chew memorizza la lunghezza della sequenza di interi
	/* Input */
	//pre: num>0
	printf("Caro utente,\nInserisci qui di seguito la lunghezza della tua sequenza di interi (maggiore di zero): ");
	scanf("%d", &num);
	int sequenza[num];			//array di interi
	/* inserimento elementi nell'array */
	for (int i=0; i<num; i++){
		printf("Inserisci il %d%c numero intero della sequenza: ", i+1, 169);
		scanf("%d",&sequenza[i]);
	}
	/* output con invocazione della funzione */
	if (maggiore5Pari(sequenza, num)) //se restituisce 1 allora l'istanza è positiva
		printf("Ogni tripla della sequenza da te inserita ha esattamente due elementi maggiori di 5 ed almeno due elementi pari.");
	else // se restituisce 0 l'istanza è negativa
		printf("Non tutte le triple della sequenza da te inserita hanno esattamente due elementi maggiori di 5 ed almeno due elementi pari.");
	return 0;
}
