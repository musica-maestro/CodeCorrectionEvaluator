/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.8
   MAIN PROGRAM (max 2):...1.8
   TOTALE (10).............9.6
*/
/* SPECIFICA
Input: Una sequenza di interi a e la sua lunghezza d
Pre-condizione: d e' la lunghezza della sequenza a
Output: Un valore booleano 'duepos'
Post-condizione: 'duepos' vale 1 se in ogni tripla di interi adiacenti ci sono esattamente due numeri positivi, 0 altrimenti
TIPO DI PROBLEMA: Verifica universale */
#include <stdio.h>
int duePositivi(int a[], int d) {
	int duepos=1;		//  se in ogni tripla di interi adiacenti ci sono esattamente due numeri positivi, 0 altrimenti
	int i;		// contatore
	for(i=0; i<=d-3; i++) {  //****** SENZA LA VAR. BOOLEANA NELLA CONDIZIONE, ANCHE SE TROVI UNA TERNA CHE NON SODDISFA LA PROPRIETA' VAI AVANTI A CONTROLLARE -0.2
		if(!((a[i]>0&&a[i+1]>0&&a[i+2]<0)||(a[i]>0&&a[i+2]>0&&a[i+1]<0)||(a[i]<0&&a[i+1]>0&&a[i+2]>0)))
			duepos=0;
	}
	return duepos;
}
int main() {
	int d;		// dimensione
	int i;		// contatore
	printf("Quanti interi ha la sequenza?\n");
	scanf("%d", &d);
	int a[d];
	for(i=0; i<d; i++) {
		printf("Inserisci un intero:\n");
		scanf("%d", &a[i]);
	}
	duePositivi(a, d);  //****** CHE LA CHIAMI A FARE? NON SERVE -0.2
	if(duePositivi(a, d))
		printf("In tutte le triple di elementi adiacenti della sequenza ci sono esattamente due numeri positivi.\n");
	else
		printf("Non in tutte le triple di elementi adiacenti della sequenza ci sono esattamente due numeri positivi.\n");
}