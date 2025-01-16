/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.1
   TOTALE..................10.6
*/
/*Specifiche del problema
 * Input: array di interi e variabile l, che ne indica la lunghezza
 * Pre-condizioni: l>=3
 * Output: variabile trovato di tipo booleana (int in C)
 * Post-condizioni: trovato=1, se esiste una tripla di elementi in cui due elementi hanno somma compresa fra 10 e 20 (inclusi) e solo due di loro sono uguali, altrimenti vale 0
 * TIPO DI PROBLEMA : Verifica esistenziale
 * */
#include <stdio.h>

int compresoTra(int numero){
	return numero <= 20 && numero >= 10;
}


int ugualiCompresi(int array[],int l){
	int trovato=0;
	int somma1=0,somma2=0,somma3=0;

	for(int i=0;(i<l-2) && (!trovato);i++){
		somma1= array[i]+array[i+1]; // somma elemento i e i+1
		somma2= array[i+1]+array[i+2];// somma elemento i+1 e i+2
		somma3= array[i]+array[i+2];// somma elemento i e i+2
		if( ((( (array[i]==array[i+1]) + (array[i+1]==array[i+2]) + (array[i]==array[i+2])) == 1)) && (compresoTra(somma1) || compresoTra(somma2) || compresoTra(somma3))){
				trovato=1;
		}
	}
	return trovato;
}

int main(int argc, char **argv){
	int l;//lunghezza array
	printf("inserisci lunghezza array: ");
	scanf("%d",&l);
	int arrayInteri[l]; // array di interi
	/*Riempo l'array*/
	for(int i=0;i<l;i++){
		printf("Inserire l'elemento numero %d: ", i+1);
		scanf("%d",&arrayInteri[i]);
	}

	if(ugualiCompresi(arrayInteri,l)){
		printf("\nQuesta e' un istanza positiva del problema");
	}else{
		printf("\nQuesta e' un istanza negativa del problema");
	}
}   //******** I/O MOLTO POVERO -0.4