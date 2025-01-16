/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.8
*/
/* SPECIFICA
 * Input: una sequenza di interi e la sua lunghezza n;

 * Pre-Condizioni: la sequenza deve contenere aleno 3 elementi;
//******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
 * Output: un valore booleano;

 * Post-Condizioni: l'output sarà 1 se in ogni tripla di elementi adiacenti
   nella sequenza sono presenti almeno due numeri composti da una sola cifra,
   altrimenti l'output sarà 0;

 * Tipo di problema: verifica universale
*/


#include<stdio.h>


/*funzione che prende come input un array di interi ed un intero che
rappresente la lunghezza dell'array e restituisce 1 se in ogni tripla di
elementi adiacenti nella sequenza sono presenti almeno due numeri
composti da una sola cifra, altrimenti restituisce 0 */
int dueUnaCifra(int seq[], int n){

	int i = 0; //contatore per il loop;
	int bl = 1;  //variabile di esistenza universale

	/*loop che scorre su ogni elemento dell'array fino al valore n-2 poiché
	considera triple adiacenti, si ferma arrivando a n-2 o se la condizione
	non è più vera*/
	while(bl && i < n - 2){

		/*se una tripla di elementi adiacenti non rispetta la condizione
		la variabile di esistenza universale diventa 0*/
		if(!((seq[i]/10 == 0 && seq[i + 1]/10 == 0) || (seq[i]/10 == 0 && seq[i + 2]/10 == 0) || (seq[i + 1]/10 == 0 && seq[i + 2]/10 == 0)))
			bl = 0;

		/*aumenta il contatore di uno*/
		i++;
	}

	/*restituisce il valore della variabile di esistenza universale*/
	return bl;
}
/*funzione che:
 *chiede all'utente quanti interi contiene la sequenza, la legge e la memorizza;
 *chiede gli elementi della sequenza, li legge e li memorizza;
 *invoca la funzione dueUnaCifra con parametri un riferimento alla sequenza e la sua lunghezza;
 *stampa un messaggio in che informa l'utente sul fatto che la sequenza di interi soddisfa
 o non soddisfa la proprietà.
*/
int main(){

	/*chiede all'utente di inserire la lunghezza della sequenza*/
	printf("Inserire la lunghezza della sequenza di interi: ");

	int n; //variabile che memorizza la lunghezza della sequenza
	scanf("%d", &n);

	int sequenza[n]; //array che memorizza la sequenza di interi introdotta dall'utente

	/*loop che chiede all'utente di inserire il n-esimo numero della sequenza*/
	int i;
	for(i = 0; i < n; i++){
		printf("Inserire l'elemento numero %d della sequenza: ", i + 1);
		scanf("%d", &sequenza[i]);
	}

	/*stampa un messaggio all'utente se nella sequenza inserita la proprietà è rispettata oppure no*/
	if(dueUnaCifra(sequenza, n))
		printf("Nella sequenza tutte le triple di elementi adiacenti hanno almeno due numeri composti da una sola cifra");
	else
		printf("Esiste almeno una tripla di elementi adiacenti nella sequenza dove almeno due numeri non sono composti da una solo cifra");

	return 0;
}