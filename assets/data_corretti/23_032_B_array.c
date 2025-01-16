/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............9.5
*/

/* SPECIFICA
*Input: Una sequenza di interi e la sua lunghezza
*Pre-condizione: lunghezza >=0
*Output: una variabile booleana
*Post-condizione: variabile booleana = 1 se per ogni tripla di elementi esattamente due sono positivi, 0, altrimenti
*TIPO DI PROBLEMA: verifica universale*/

#include<stdio.h>
int duePositivi(int array[], int lunghezza){
	int i=0;
	int booleana=1; //variabile dove ancora non ho trovato un caso falso
	while(i<lunghezza-2 && booleana){//fino a che o finisce la sequenza o si trova una tripla dove è verificata la proprietà
		if(((array[i]<0 && array[i+1]<0 && array[i+2]<0)||(array[i]<0 && array[i+1]<0 && array[i+2]>=0))||
		   ((array[i]<0 && array[i+1]>=0 && array[i+2]<0)||(array[i]>=0 && array[i+1]<0 && array[i+2]<0))||
		   (array[i]>=0 && array[i+1]>=0 && array[i+2]>=0))
		booleana=0; //se verificata la proprietà
		else i++;
	}             //***** COMPLICATA MA CORRETTA
	return booleana;
}





int main(){
	int i;
	int n; // variabile lunghezza sequenza
	int booleana;
	printf("Caro utente, inserisci la lunghezza della tua sequenza di numeri interi \n");
	scanf("%d", &n);
	if(n<=2)   //******* MANCANO LE PARENTESI {} NELLA PARTE IF!  -0.5
		printf("Se la lunghezza della sequenza %c minore o uguale a 2, non \n", 138);
		printf("esisteranno mai triple di numeri. Inserisci una lunghezza maggiore di 2: ");
		//faccio reinserire n se ne è stata messa una minore di 2
		scanf("%d", &n);
	//memorizzo la nuova lunghezza
	int sequenza[n];
	for(i=0; i<n; i++){
	//ciclo per memorizzare ogni numero inserito nella cella [i] dell'array
		printf("Inserisci un numero: ");
		scanf("%d", &sequenza[i]);}
	booleana=duePositivi(sequenza, n);
	if(booleana)
	//se la funzione mi ritorna 1
		printf("Nella tua sequenza ogni tripla di numeri consecutivi contiene esattamente due numeri positivi");
	else
	//se la funzione mi ritorna 0
		printf("Nella tua sequenza almeno una tripla di numeri consecutivi non contiene esattamente due positivi");

}