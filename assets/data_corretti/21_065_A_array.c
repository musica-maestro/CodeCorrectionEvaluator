/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................11
*/
#include <stdio.h>
/*Data una sequenza di interi, verificare se esiste una tripla di elementi consecutivi tale che almeno due elementi della tripla abbiano una somma compresa tra 10 e 20 ed esattamente
due elementi della tripla uguali*/
/*SPECIFICA
*Input: una sequenza di interi, un intero che rappresenta la sua lunghezza;
*Pre-condizione: gli elementi della sequenza devono essere interi;
*Output: un booleano "esiste";
*Post-condizione: esiste==1 se esiste una tripla che abbia almeno due elementi la cui somma sia compresa tra 10 e 20 ed esattamente due elementi uguali, esiste==0 altrimewnti.
*TIPO DI PROBLEMA: problema di verifica esistenziale*/
int ugualiCompresi(int array[], int lunghezza){
	int i; //contatore degli elementi della sequenza
	int esiste;//variabile di esistenza
	esiste=0; //inizializzazione della variabile di esistenza
	/*controlliamo tutta la sequenza*/
	for(i=1; i<lunghezza-1 && !(esiste); i++){
		/*se ci sono esattamente due caratteri uguali e almeno due elementi la cui somma è compresa tra 10 e 20...*/
		if(((array[i]==array[i+1] && array[i-1]!=array[i])
		|| (array[i]==array[i-1] && array[i]!=array[i+1])
		|| (array[i-1]==array[i+1] && array[i]!=array[i+1]))
		&& ((array[i]+array[i+1]>=10 && array[i]+array[i+1]<=20)
		|| (array[i]+array[i-1]>=10 && array[i]+array[i-1]<=20)
		|| (array[i-1]+array[i+1]>=10 && array[i-1]+array[i+1]<=20)))
			esiste=1; //cambiamo valore alla variabile di esistenza per uscire dal ciclo
	}
	return esiste;
}

int main(){
	printf("Caro utente, inserisci la lunghezza che la tua sequenza deve avere.\n");
	int lunghezza;
	printf("Lunghezza: ");
	scanf("%d", &lunghezza);
	int array[lunghezza];
	printf("Ora riempi la sequenza.\n");
	for(int i=0; i<lunghezza; i++){
		printf("Elemento con indice %d: ", i);
		scanf("%d", &array[i]);
	}
	if(ugualiCompresi(array, lunghezza))
		printf("La tua sequenza contiene una tripla di elementi consecutivi tale che almeno due elementi della tripla abbiano una somma compresa tra 10 e 20 ed esattamente due elementi della tripla uguali!\n");
		else
			printf("La tua sequenza NON contiene una tripla di elementi consecutivi tale che almeno due elementi della tripla abbiano una somma compresa tra 10 e 20 ed esattamente due elementi della tripla uguali!\n");
}