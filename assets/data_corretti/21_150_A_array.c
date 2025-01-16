/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......1
   MAIN PROGRAM (max 2.5):.1.5
   TOTALE..................5
*/
/*SPECIFICA DEL PROBLEMA
* Input: sequenza di interi x1, x2,..., xl-1
* PreCondizioni: lunghezza l=>3
* Output: booleano
* PostCondizioni: intero booleaano  1 se nella sequenza esiste una tripla di elementi consecutivi tale che almeno due elementi di questa
* hanno somma fra 10 e 20 (estremi inclusi) ed esattamente due elementi della tripla sono uguali fra loro, 0 altrimenti
*  TIPO DI PROBLEMA: verifica esistenziale
*/

#include <stdio.h>

int ugualiCompresi (int array[], int l)

	int trovato=0;  //variabile di esistenza
	int i=0;
	while(i<l-2 && !trovato)
		if() //******** CONDIZIONE MANCANTE! -3
			trovato=1;
			//******** MANCA L'INCREMENTO DELLA i -1
			//******** MANCA IL RETURN -1
int main(){

	int l; // variabile lunghezza
	int i;

	printf("caro utente, quanti interi vuoi inserire?\n");
	scanf("%d", &l); //lunghezza array da input
	int array [l];
	printf("inserisci l'intero: \n");  //******** PRINTF FUORI DAL CICLO -1
	for(i=0; i<l; i++)
		scanf("%d", &array[i]); //elementi dell'array da input

	//verifica e output

	if(ugualiCompresi(array, l))
		printf("ESISTE una tripla di elementi consecutivi tale che almeno due elementi abbiano una somma compresa tra 10 e 20 ed esattamente due elementi uguali");
	else
		printf("NON ESISTE una tripla di elementi consecutivi tale che almeno due elementi abbiano una somma compresa tra 10 e 20 ed esattamente due elementi uguali");
	return 0;
}