/* SPECIFICA (max 1.5):....0.4
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......4
   MAIN PROGRAM (max 2.5):.1.5
   TOTALE..................5.9
*/
//Specifica: data una sequenza di numeri analizzo che esista una tripla di elementi che la loro somma sia compresa tra 10 e 20 (estremi compresi) e solo 2 numeri uguali
//Input una sequenza di numeri "array" e la lunghezza dell'array "lunghezza" //******** MANCANO I TIPI DEGLI ELEMENTI DELL'ARRAy -0.6
//Pre condizione Lunghezza è la lunghezza della sequenza di numeri "array"
//Output: il campo int ritorno  //******** CAMPO???
//Post condizione: Ritorno vale 1 se la specifica del problema è rispettata altrimenti vale 0
//******** LA POST-CONDIZIONE NON DICE NULLA -0.5
//Tipo problema: verifica Universale infatti imposto ad 1 ritorno e metto 0 se non la trovo la condizione
//******** E' UNA VERIFICA ESISTENZIALE (TUTTO AL CONTRARIO)! -1



#include <stdio.h>
int sommaArray(int numero1, int numero2)  // ho fatto una funzione che somma due interi e mi restituisce 1 se la loro somma è compresa tra 10 e 20 estremi compresi altrimenti ritorna 0
{ int somma;
if (numero1+numero2 >9  && numero1+numero2<21)
	somma=1;
else
	somma=0;

return somma;
}
int UgualiCompresi(int* array, int lunghezza)
{

	int ritorno=1;
	for (int i=2;i<lunghezza && ritorno==1;i++) {  // parto dal terzo elemento dell'array ed esamino alla sua sinistra

	     if ((sommaArray(array[i],array[i-1])==0)
	     && (sommaArray(array[i],array[i-2])==0)
	     && (sommaArray(array[i-2],array[i-1])==0)) // non ho nessuna somma compresa tra 10 e 20
	         ritorno=0;
 	     if( (array[i]==array[i-1] && array[i]==array[i-2] ) ||
 	     ((array[i]!=array[i-1]) && (array[i]!=array[i-2])
 	     && (array[i-2]!=array[i-1]))) // o tutti uguali o tutti diversi
	            ritorno=0;
	//******* PERFETTAMENTE COERENTE CON LA VERIFICA UNIVERSALE -2

	}
	return ritorno;

}
int main()
{
	int lunghezza; // è la lunghezza dell'array
	int ritorno;
	printf("Caro utente digita quante numeri vuoi inserire\n");
	scanf("%d",&lunghezza);
	int array[lunghezza];
	printf("Digita i numeri da te scelti\n");
	for (int i=0;i<lunghezza;i++)
		 scanf("%d",&array[i]);
	ritorno=UgualiCompresi(array, lunghezza);
	if (ritorno==1)
		printf("Caro utente nella tua sequenza esiste una tripla che soddisfa le condizioni richieste\n");
	else
		printf("Caro utente nella tua sequenza NON esiste una tripla che soddisfa le condizioni richieste\n");
        	//******* OUTPUT NON COERENTE CON LA FUNZIONE (VIENE SCRITTO "ESISTE") E POCO ESPLICATIVO -1
}
