/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............8.5
*/
#include <stdio.h>
/*problema di verifica universale
  specifica
  input: sequenza interi positivi (x1,..., xn);
  pre-condizione: interi positivi;
  output: valore booleano per il risultato;
  post-condizione: valore booleano che indica se in ogni tripla di elementi adiacenti della sequenza sono presenti almeno due numeri composti da una sola cifra*/


int dueUnaCifra(int* seq, int n){
	int tripla=1;
	int i;
	i=0;
	while(i<n-2 && tripla){
		if(!((seq[i]>='0' && seq[i]<='9') && (seq[i+1]>='0' && seq[i+1]<='9')) || //******* CONFRONTI UN INTERO CON UN CARATTERE! -1.5
			((seq[i+1]>='0' && seq[i+1]<='9') && (seq[i+2]>='0' && seq[i+2]<='9')) ||
			((seq[i]>='0' && seq[i]<='9') && (seq[i+2]>='0' && seq[i+2]<='9')))
			tripla=0;
		else
			i++;
	}
	return tripla;
}

int main() {
	int n;
	/*INPUT*/
	printf("Quanti interi vuoi introdurre? ");
	scanf("%d", &n);
	int seq[n];
	for(int i=0; i<n; i++){
		printf("Inserisci un intero: ");
		scanf("%d", &seq[i]);
	}
	/*OUTPUT*/
	if(dueUnaCifra(seq, n))
		printf("Non sono presenti almeno due numeri composti da una sola cifra");
	else
		printf("sono presenti due numeri composti da una sola cifra");
}