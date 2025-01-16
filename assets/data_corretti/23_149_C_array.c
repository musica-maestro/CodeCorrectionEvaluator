/* SPECIFICA (max 1):......0.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............6.5
*/
/* Input: n (X1,X2,....,Xn) di interi   //******** MANCA LA LUNGHEZZA -0.2
* Pre-condizione: n>=0      //******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
* Output: Un valore booleano 'ris' che restituisce 0 oppure 1
* Post-condizione: Verifica se in ogni tripla di elementi adiacenti della sequenza sono presenti
* almeno due numeri composti da una sola cifra. //********** FALSO, ALTRIMENTI -0.1
* TIPO DI PROBLEMA: VERIFICA UNIVERSALE */
#include <stdio.h>
/* Una funzione dueUnaCifra con parametri un array di interi e un intero che rappresenta la lunghezza dell'array,
* La funzione restituisce 1 se in tutte le triple di elementi adiacenti della sequenza sono presenti
* almeno due numeri composti da una sola cifra, 0 altrimenmti */
int dueUnaCifra(int seq[], int lung) {
	int ris=0;
	int cont=0;  //******* LA TRATTI COME UNA VERIFICA ESISTENZALE -1
	for(int i=0; i<lung-2; i++) {
	if(((seq[i]>=0 && seq[i]<=9) || (seq[i+1]>=0 && seq[i+1]<=9) || (seq[i+2]<=0 && seq[i+2]>=9)) && //**** seq[i+2]>9 CASOMAI  -0.5
		((seq[i]>=0 && seq[i]<=9) || (seq[i+1]<=0 && seq[i+1]>=9) || (seq[i+2]>=0 && seq[i+2]<=9)) &&
		((seq[i]<=0 && seq[i]>=9) || (seq[i+1]>=0 && seq[i+1]<=9) || (seq[i+2]>=0 && seq[i+2]<=9)))
		//******** CONDIZIONE SBAGLIATA -2 (ES. 1,2,3,44,55) -> VERO -1.5
		cont=1;
	else
		i++;
	}
	if(cont==1)
		ris=1;
	else
		ris=0;

	return ris;
}

/* Una funzione main che chiede all'utente quanti interi ha la sequenza, legge gli interi e li memorizza in un array
* invoca la funzione dueUnaCifra fornendole come parametro un array di interi e la sua lunghezza;
* infine stampa un messaggio che comunica all'utente se in tutte le triple di elementi adiacenti della sequenza
* sono presenti almeno due numeri composti da una sola cifra, 0 altrimenmti*/
int main() {
	int lung;
	printf("Quanti interi vuoi inserire?\n");
	scanf("%d",&lung);
	int seq[lung];
	for(int i=0; i<lung; i++) {
		printf("Inserisci intero: ");
		scanf("%d",&seq[i]);
	}
	if(dueUnaCifra(seq,lung))
		printf("In tutte le triple di elementi adiacenti della sequenza sono presenti almeno due numeri composti da una sola cifra\n");
	else
		printf("Non in tutte le triple di elementi adiacenti della sequenza sono presenti almeno due numeri composti da una sola cifra\n");
}