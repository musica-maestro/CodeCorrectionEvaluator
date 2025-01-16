/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.8
*/
/* SPECIFICA DEL PROBLEMA
	input: un array V e un intero N  //******** MANCA IL TIPO DEGLI ELEMENTI DELL'ARRAY -0.2
	pre-condizioni: l'intero N deve essere la lunghezza dell'array V, n>=3
	output: intero VER
	post-condizioni: l'istanza è verificata se ogni tripla dell'array contiene esattamente due numeri positivi, falso viceversa
	TIPO DI PROBLEMA: Verifica Universale
*/

#include <stdio.h>


int duePositivi(int arr[], int n){

	int i=0; // contatore
	int ver=1; // variabile di verifica

	// ciclo per controllare l'intero array
	while(i<n-2 && ver){

		// verifico se all'interno della tripla siano presenti solamente 2 positivi
		if((arr[i]>=0 && arr[i+1]>=0 && arr[i+2]<0) || (arr[i]>=0 && arr[i+1]<0 && arr[i+2]>=0) || (arr[i]<0 && arr[i+1]>=0 && arr[i+2]>=0))

			i++;

		else

			ver=0; // in caso non siamo presenti esattamente 2 positivi imposto la condizione di verità a 0


	}

	return ver;
}

int main(){
	int ver; // variabile di verifica
	int n; // lunghezza array

	// prendo in input la lunghezza dell'array
	printf("Inserisci lunghezza array: ");
	scanf("%d", &n);
	int v[n]; // array

	// compilo l'intero array
	for(int i=0; i<n; i++){
		printf("Inserisci un numero: ");
		scanf("%d", &v[i]);
	}

	ver=duePositivi(v, n);

	if(ver)
		printf("\nIl tuo array contiene ogni stringa con al suo interno esattamente due numeri positivi.\n");
	else
		printf("\nIl tuo array NON contiene ogni stringa con al suo interno esattamente due numeri positivi.\n");


}