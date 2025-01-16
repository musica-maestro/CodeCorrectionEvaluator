/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
/*SPECIFICA

*input: una sequenza di interi (x1,x2,...,xn)
*precondizioni: gli interi devono essere maggiori di 0
*output:un valore booleano "triple"
*postcondizioni:"triple" vale true se in ogni tripla
sono presenti almeno 2 interi composti da una singola cifra, "triple" è
falsa altrimenti

*TIPO DI PROBLEMA: verifica universale
*/

#include <stdio.h>
/*funzione che prende in input un array di interi,
 verifica se ci sono almeno due interi composti da
 una cifra in ogni tripla e restituisce un valore booleano*/
int DueUnaCifra(int *seq,int lunghezza){
	int i=0;        //per scandire l'array
	int triple=1;    //variabile booleana triple


/*se ci sono almeno due interi composti da una cifra in ogni tripla incrementa la i di uno*/
	while(i<lunghezza-2 && triple==1){
		if((seq[i]-10 <0 && seq[i+1]-10<0 && seq[i+2]-10<0) ||
		 (seq[i]-10 <0 && seq[i+1]-10<0) || (seq[i]-10 <0 && seq[i+2]-10<0) ||
		  (seq[i+1]-10<0 && seq[i+2]-10<0))
			i++;

		/*altrimenti "triple" diventa false*/
		else triple=0;
	}
	return triple;
}
/*funzione principale*/
int main(){

	int lunghezza;   //per la lunghezza dell'array
/*input*/
	printf("dammi la lunghezza dell'array\n");
	scanf("%d",&lunghezza);

	int seq[lunghezza];   //dichiaro l'array


     /*ciclo for per inserire gli interi nell'array,
      se l'utente inserisce un valore minore di 0 il programma si interrompe*/
	for(int i=0;i<lunghezza;i++){
		printf("dammi un intero: \n");
		scanf("%d",&seq[i]);
		if(seq[i]<0){
			printf("il valore inserito non e' valido");
			break;
          }
		}
		/*invocazione della funzione "DueUnaCifra" e output*/
		if(DueUnaCifra(seq,lunghezza))
			printf("tutte le triple contengono almeno 2 interi composti da una sola cifra");
		else
			printf(" NON tutte le triple contengono almeno 2 interi composti da una sola cifra");


}