
/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......2.5
   MAIN PROGRAM (max 2.5):.1
   TOTALE..................4.5
*/
/*PROBLEMA DI VERIFICA ESISTENZIALE                         //********* NO, VERIFICA UNIVERSALE -1
 * INPUT: lunghezza, sequenza
 * PRECOND: un vettore di interi e la sua lunghezza
 * OUTPUT: una variabile intera
 * POSTCOND: la variabile =1 se vero e =0 se falso /******** LA POST-CONDIZIONE NON DICE NULLA -0.5
 * */

 #include <stdio.h>

 int maggiori5Pari(int v[],int x){
	 int a,b,r1=1,r2=1;

	 for(int i=0; i<x-2; i++){ //******** NON USI LA VARIABILE BOOLEANA PER TERMINARE IL CICLO -1
		 a=0;
		 b=0;
		 for(int j=i; j<3;j++){  //******* j<i+3 -1
			 if(v[j]>=5)//conta qunati numeri sono >=5
			 a++;
			 if(v[i]%2==0)//conta quanti numeri sono pari
		     b++;
		 }
		 if(a!=2)
			 r1=0;
		 if(b<2)
			 r2=0;
	 }                   //******* SE LULTIMA TRIPLA E' L'UNICA A SODDISFARE LA CONDIZIONE
	 return (r1 && r2);  //******* LA FUNZIONE RESTITUISCE VERO
 }                       //******* RESTITUISCI IL VALORE CALCOLATO SULL'ULTIMA TRIPLA -1.5

int main(){

int i, lunghezza, sequenza[lunghezza]; //******** DEVI LEGGERE LA LUNGHEZZA DA INPUT PRIMA DI DICHARARE L'ARRAY -1

	printf("PROGRAMMA CHE aANALIZZA UNA SERIE DI INTERI E DICE SE IN OGNI TRIPLA CI SONO DUE ELEMENTI >=5 E ALMENO DUE PARI ");
	printf("\nQuanti numeri vuoi controllare?");
	scanf("%d", &lunghezza);

	for(int i=0; i<lunghezza; i++){
		printf("\nInserisci un numero: ");
		scanf("%d", &sequenza[i]);
	}


if(maggiori5Pari(sequenza, lunghezza))
	printf("La sequenza rispetta le condizioni"); //******** OUTPUT MOLTO POVERO -0.5
	else
		printf("La sequenza NON rispetta le condizioni");

}
