/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..2
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................10
*/

/*SPECiFICA
 * input: un array S di interi e la sua lunghezza L
 * Pre-condizione: L è la lunghezza dell'array
 * output: un intero
 * post-condizione: l'intero vale 1 se lìesito è positivo, vale 0 se l'esito è negativo //******** LA POST-CONDIZIONE NON DICE NULLA -0.5
 * TIPO DI PROBLEMA: Problema di verifica universale
 */

#include<stdio.h>

int maggiori5Pari(int array[], int dimensione){
	int esito = 1;
	int i = 2;
	while(i<dimensione && esito){
		if((!(array[i-2]>=5 && array[i-1]>=5 && array[i]<5)
		|| !(array[i-2]>=5 && array[i]>=5 && array[i-1]<5)
		|| !(array[i-1]>=5 && array[i]>=5 && array[i-5]<5))
		&& (!(array[i-2]%2==0 && array[i-1]%2==0 && array[i]%2!=0)
		||!(array[i-2]%2==0 && array[i]%2==0 && array[i-1]%2!=0)
		|| !(array[i-1]%2==0 && array[i]%2==0 && array[i-2]%2!=0)))
		//******** DEVI CONTROLLARE CHE ALMENO 2 SIANO PARI, NON ESATTAMENTE 2 -1
			esito=0;
		else
			i++;
	}
	return esito;
}


int main(){
	int result;
	int lunghezza;
	printf("Caro utente digita la lunghezza del tuo vettore: \n");
	scanf("%d", &lunghezza);
	int vettore[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Scegli un intero da posizionare in vettore[%d] :\n", i);
		scanf("%d", &vettore[i]);
	}
	result = maggiori5Pari(vettore, lunghezza);
	if(result==1)
		printf("Esito Positivo.\n");
	else
		printf("Esito negativo.\n");
} //******** OUTPUT MOLTO POVERO -0.5
