/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................11
*/
/*SPECIFICA
 * Input: una sequenza di interi e la sua lunghezza
 * Pre-condizione: la sequenza è formata da interi ci sono almeno tre numeri nella sequenza
 * Output: un numero(0 o 1)
 * Post-condizione: il numero restituito rappresenta un booleano che dice se
 * in ogni tripla di numeri consecutivi ci sono esattamente due numeri maggiori o uguali a 5 e almeno due elementi pari
 * TIPO DI PROBLEMA: Verifica Universale
 * */


#include <stdio.h>

/*funzione maggiori5Pari*/
int maggiori5Pari(int interi[], int l){
	int i=0; //contatore elementi array
	int tutte=1; //booleano che dice se tutte le triple della stringa contengono almeno esattamente due elementi maggiori di 5 e almeno due pari

	while(i<l-2 && tutte==1){
		/*verifico che nella tripla ci sono esattamente due numeri maggiori di 5 altrimenti esco*/
		if((interi[i]>=5 && interi[i+1]>=5 && interi[i+2]<5)
		|| (interi[i+1]>=5 && interi[i+2]>=5 && interi[i]<5)
		|| (interi[i]>=5 && interi[i+2]>=5 && interi[i+1]<5)){
			/*se è verificata la prima condizione verifico la seconda per la stessa tripla se non è verificata esco*/
			if((interi[i]%2==0 && interi[i+1]%2==0) || (interi[i+1]%2==0 && interi[i+2]%2==0) || (interi[i]%2==0 && interi[i+2]%2==0))
				i++;
			else
				tutte=0;
		}
		else
			tutte=0;
	}
	return tutte;
}


/*funzione principale*/
int main(){
	int n; //lunghezza array
	int i=0; //contatore elementi array

	/*acquisizione lunghezzaa della stringa*/
	printf("caro utente quanti elementi ci sono nella sequenza che vuoi introdurre?   \n\n");
	scanf("%d", &n);

	/*dichiarazione array di lunghezza n*/
	int interi[n];

	/*acquisizione elementi dell'array*/
	for(i=0; i<n; i++){
		printf("inserisci il %d%c elemento della sequenza   ", i+1, 167);
		scanf("%d", &interi[i]);
	}

	/*invocazione funzione maggiori5Pari stampa del risultato*/
	if(maggiori5Pari(interi, n))
		printf("\nsi! tutte le triple della sequenza contengono esattamente due elementi maggiori o uguali a 5 ed almeno due elementi pari\n\n");
	else
		printf("\nno! non tutte le triple della sequenza contengono esattamente due elementi maggiori o uguali a 5 ed almeno due elementi pari\n\n");
}
