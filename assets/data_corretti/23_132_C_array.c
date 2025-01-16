/* SPECIFICA (max 1):......0.3
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............7.3
*/

/*SPECIFICA*/
/*INPUT: array di numeri interi *///******** MANCA LA LUNGHEZZA -0.2
/*Precondizioni: array numerico >= 3 *///******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
/*Postcondizioni: nessuna */ //******* MANCA POST CONDIZIONE -0.3
/*OUTPUT: valore booleano*/

/*Problema di verifica universale*/
#include<stdio.h>


//Funzione elaborativa
int dueUnaCifra (int array[],int lunghezza) {

//Dichiarazioni
int i;		//contatore
int tripla;		//variabile verita
tripla=1;	//inizializzazione del valore di verita

	for(i=0; i<lunghezza-2 &&tripla; i++) {

		if (((array[i]>9)&&(array[i+1]>9))&&(array[i+2]>9))||
			(((array[i]>9)&&(array[i+1]>9))&&(array[i+2]<=9))||
			(((array[i]>9)&&(array[i+1]<=9))&&(array[i+2]>9))
							tripla=0;
//****** LE PARENTESI NON CORRISPONDONO -0.5
//****** MANCA UNA CONDIZIONE: (array[i]<=9&&array[i+1]>9&&array[i+2]>9)) -1

//******** NON TENGO CONTO DI QUESTA IF
 		if	(((array[i]>9)&&(array[i-1]>9))&&(array[i-2]>9))||
			(((array[i]>9)&&(array[i-1]>9))&&(array[i-2]<=9))||
			(((array[i]>9)&&(array[i-1]<=9))&&(array[i-2]>9))
 							tripla=0;



				}

return tripla;

}
/*Funzione Principale*/
int main () {

//variabili
int verita;
int i;
int dimensione;


printf("Ciao,  ti diro' se in tutte le triple adiacenti ch si trovano nel tuo array, almeno due elementi sono di una cifra singola\n");
printf("Per iniziare, quanti elementi vuoi inserire nel tuo array?\n");
scanf("%d", &dimensione);

int array[dimensione];

		for(i=0; i<dimensione; i++) {
		printf("Inserisci intero\n");
		scanf("%d", &array[i]);
}



verita=dueUnaCifra(array, dimensione);

if (verita=1) //**** verita==1 -0.5
	printf("La tua sequenza e' valida\n");//************ OUTPUT NON ESPLICATIVO -0.5
else
	printf("La tua sequenza non e' valida\n");




}