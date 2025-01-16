/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9.5
*/

#include <stdio.h>

/*SPECIFICA DEL PROBLEMA:
 * input: una sequenza di numeri interi e la sua lunghezza,
 * pre-condizioni: lunghezza sarebbe la lunghezza della sequenza,
 * output : un intero esiste,
 * post-condizioni: esiste vale 1 se nella sequenza esiste almeno una tripla di elementi
 * consecutivi che contiene almeno due elementi il cui valore è compreso o uguale tra 10 e -10 ed
 * esattamente te due numeri multipli di 3. vale 0 altrimenti,
 * TIPO DI PROBLEMA: verifica esistenziale.*/

 /*funzione che verifica se nella sequenza esiste almeno una tripla di elementi
 * consecutivi che contiene almeno due elementi il cui valore è compreso o uguale tra 10 e -10 ed
 * esattamente te due numeri multipli di 3*/

 int compresiMultipli3 (int sequenza[], int lunghezza)
 {
	 int i=0;  //variabile di scorrimento della sequenza
	 int esiste=0;  //variabile di ritorno
	 while (i<lunghezza-2 && !esiste)
	 {
		 if (((sequenza[i]%3==0 && sequenza[i+1]%3==0 && sequenza[i+2]%3!=0) ||
			 (sequenza[i]%3==0 && sequenza[i+1]%3!=0 && sequenza[i+2]%3==0) ||
			 (sequenza[i]%3!=0 && sequenza[i+1]%3==0 && sequenza[i+2]%3==0)) &&

			 (((sequenza[i]<=10 && sequenza[i]>=-10) && (sequenza[i+1]<=10 && sequenza[i+1]>=-10) &&
			 (sequenza[i+2]<=10 && sequenza[i+2]>=-10)) ||
			 //**** TUTTI E TRE COMPRESI TRA -10 E 10? QUESTA CONDIZIONE NON E' NECESSARIA

			 ((sequenza[i]<=10 && sequenza[i]>=-10) &&
			 (sequenza[i+1]<=10 && sequenza[i+1]>=-10) &&
			 (!(sequenza[i+2]<=10 && sequenza[i+2]>=-10))) ||

			 ((sequenza[i]<=10 && sequenza[i]>=-10) &&
			 (!(sequenza[i+1]<=10 && sequenza[i+1]>=-10)) &&
			 (sequenza[i+2]<=10 && sequenza[i+2]>=-10)) ||

			 ((!(sequenza[i]<=10 && sequenza[i]>=-10)) &&
			 (sequenza[i+1]<=10 && sequenza[i+1]>=-10) &&
			 (sequenza[i+2]<=10 && sequenza[i+2]>=-10))))   //verifica che la tripla corrente soddisfi la condizione richiesta
		//******** CONDIZIONE TROPPO RESTRITTIVA: NON DEVONO ESSERE ESATTAMENTE DUE ELEENTI,
		//******** MA ALMENO 2 COMPRESI TRA -10 E 10! -1,5

				 esiste=1;

				 else
					 i++;  //altrimenti passa al successivo
	 }
	 return esiste;
 }

 /*funzione principale*/
 int main ()
 {
	 int lunghezza;
	 printf ("sono un programma che verifica se nella sequenza da lei inserita esiste almeno una tripla di elementi consecutivi che\n");
	 printf ("contiene almeno due elementi il cui valore %c compreso o uguale tra 10 e -10\n", 138);
	 printf ("ed esattamente due numeri multipli di 3\n ");
	 printf ("inserisca la lunghezza della sequenza\n");
	 scanf ("%d", &lunghezza);
	 int sequenza[lunghezza];
	 for (int i=0; i<lunghezza; i++)
	 {
		 printf ("inserisca un intero\n");
		 scanf ("%d", &sequenza[i]);
	 }
	 if (compresiMultipli3(sequenza, lunghezza))

		printf ("la sua sequenza soddisfa la condizione richiesta\n");


		 else
			 printf ("la sua sequenza non soddisfa la condizione richiesta\n");



 }
