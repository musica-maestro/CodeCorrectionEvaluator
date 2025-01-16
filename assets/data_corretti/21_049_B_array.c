/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................11
*/
/* SPECIFICA
 * Input: una sequenza di interi 'sequenza' e la sua lunghezza 'l'
 * Pre-condizione: l>=0
 * Output: un intero 'contiene'
 * Post-condizione: contiene è pari a 1 se ogni tripla di elementi consecutivi
 *                  contiene esattamente due elementi maggiori o uguali a 5 ed
 *                  almeno due elementi pari; 0 altrimenti
 *
 * TIPO DI PROBLEMA: verifica universale */

#include <stdio.h>
/* Funzione che riceve come parametri un array di interi e la sua lunghezza e restituisce 1
 * se ogni tripla di elementi consecutivi contiene esattamente due elementi maggiori o uguali
 * a 5 ed almeno due elementi pari; 0 altrimenti */
int maggiori5Pari(int a[], int l){
	int contiene;            //variabile di universalità
	int i=0;                 //variabile contatore

	/* inizialmente prendo tutte le triple di elementi consecutivi come valide */
	contiene=1;

	/* leggo la sequenza finchè non arrivo alla fine o finchè non trovo una tripla di elementi
	 * consecutivi non valida */
	while(i<l-2 && contiene)
		if(!(((a[i]>=5 && a[i+1]>=5 && a[i+2]<5)
		|| (a[i]>=5 && a[i+1]<5 && a[i+2]>=5)
		|| (a[i]<5 && a[i+1]>=5 && a[i+2]>=5)) &&
		   ((a[i]%2==0 && a[i+1]%2==0) || (a[i]%2==0 && a[i+2]%2==0) || (a[i+1]%2==0 && a[i+2]%2==0))))
			contiene=0;
		else
			i++;
	return contiene;
}

/* Funzione principale */
int main(){
	int l;               //lunghezza della sequenza
	int i;               //gestisce gli indici della sequenza

	/* input */
	printf("Ciao, sono un programma che legge una sequenza di interi e verifica se ogni tripla di elementi consecutivi contiene esattamente ");
	printf("due elementi maggiori o uguali a 5 ed almeno due elementi pari\n\n");

	printf("Quanti numeri vuoi inserire? ");
	scanf("%d",&l);
	int sequenza[l];

	printf("\nQuali sono i numeri?\n");
	for(i=0; i<l; i++)
		scanf("%d",&sequenza[i]);

	/* output */
	if(maggiori5Pari(sequenza,l))
		printf("\nTutte le triple di elementi consecutivi contengono esattamente due elementi maggiori o uguali a 5 ed almeno due elementi pari\n\n");
	else
		printf("\nNON tutte le triple di elementi consecutivi contengono esattamente due elementi maggiori o uguali a 5 ed almeno due elementi pari\n\n");
}