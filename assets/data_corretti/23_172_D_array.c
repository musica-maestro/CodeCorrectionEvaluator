/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...1.9
   TOTALE (10).............9.9
*/
#include <stdio.h>
/*SPECIFICA:
 Input: un array di interi e una lunghezza l
 pre-condizione: l è maggiore di 0 ed e la lunghezza dell'array
 Output: un intero Tripla
 post-condizione: tripla è vero se esiste una tripla di elementi adiacenti in cui uno
 dei tre è il resto della divisione degli altri due, false altrimenti*/

//TIPO DI PROBLEMA:	 verifica esistenziale

/*funzione che verifica se esiste una tripla di elementi adiacenti in cui uno
 dei tre è il resto della divisione degli altri due, false altrimenti*/
int restoDivisione(int seq[], int lunghezza){
	int i=0;  //contatore
	int tripla=0;

	while(i<lunghezza-2 && !tripla){
		if((seq[i]==seq[i+1]%seq[i+2]) || (seq[i+1]==seq[i]%seq[i+2]) || (seq[i+2]==seq[i]%seq[i+1])
		   ||(seq[i]==seq[i+2]%seq[i+1]) || (seq[i+1]==seq[i+2]%seq[i]) || (seq[i+2]==seq[i+1]%seq[i]))
			tripla=1;
		else
			i++;





	}
	return tripla;
}
//funzione main


int main(){
	int l;
	printf("Inserisci la lunghezza del tuo array:"); //**** APPICCICATO -0.1
	scanf("%d", &l);

	int array[l];
	for(int i=0;i<l;i++){
		printf("inserisci un intero:\n");
		scanf("%d", &array[i]);
	}
	if(restoDivisione(array,l))
		printf("esiste una tripla di elementi adiacenti in cui uno dei tre %c il resto della divisione degli altri due",138);
	else
		printf("non esiste una tripla di elementi adiacenti in cui uno dei tre %c il resto della divisione degli altri due",138);



}