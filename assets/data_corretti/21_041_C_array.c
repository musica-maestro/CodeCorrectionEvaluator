/* SPECIFICA (max 1.5):....0     //******** MANCANTE
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......1.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................4
*/
#include <stdio.h>

/*Pogramma che verifica se per ogni tripla di elementi esistono 2 elementi cui valore è*/
/*compreso tra -10 e 10 (esremi inclusi) e che contiene due elementi multipli di 3*/

// Tipo di Verifica: Universale// //********* NO, VERIFICA ESISTENZIALE -1
int compresiMultilpi3(int array[], int dimensione)
{
	int risultato=1; //******* QUESTA E' UNA VERIFICA ESISTENZIALE -2
	//Leggi la sequenza//
	for(int i=0; i<dimensione; i++){  //******** INDICE DELL'ARRAY FUORI DAI LIMITI, DEVE ESSERE i<dimensione-2 -1
		//primo numero della sequenza//
		if(i==0){  //******** A COSA SERVE DISTINGUERE I DIVERSI VALORI DI i?
			//se la tripla non rispetta le condizioni allora risultato=0//
			if(!((array[i]>=-10 && array[i]<=10) && (array[i+1]>=-10 && array[i+1]<=10) && (!(array[i+2]>=-10 && array[i+2]<=10)))
			|| (((!(array[i]>=-10 && array[i]<=10))) && (array[i+1]>=-10 && array[i+1]<=10) && (array[i+2]>=-10 && array[i+2]<=10))
			|| ((array[i]>=-10 && array[i]<=10) && (!(array[i+1]>=-10 && array[i+1]<=10)) && (array[i+2]>=-10 && array[i+2]<=10)))
			{
			//******** CONDIZIONE TROPPO RESTRITTIVA: NON DEVONO ESSERE NECESSARIAMENTE DUE I NUMERI
			//******** COMPRESI TRA -10 E 10. -0.5
			risultato=0;}
				else{
				if(!((array[i]%3==0 && array[i]%3==0) && (array[i+1]%3==0 && array[i+1]%3==0) && (!(array[i+2]%3==0 && array[i+2]%3==0)))
			|| ((!(array[i]%3==0 && array[i]%3==0)) && (array[i+1]%3==0 && array[i+1]%3==0) && (array[i+2]%3==0 && array[i+2]%3==0))
			|| ((array[i]%3==0 && array[i]%3==0) && (!(array[i+1]%3==0 && array[i+1]%3==0)) && (array[i+2]%3==0 && array[i+2]%3==0)))
			{
			risultato=0;}
		}
		}
		//Numero intermedio//
		if(i>0 && i<dimensione){ //***** COMUNQUE L'INDICE VA FUORI DEI IMITI DELL'ARRAY
			//se nella tripla rispetta le condizioni allora risultato=0//
			if(!((array[i]>=-10 && array[i]<=10) && (array[i+1]>=-10 && array[i+1]<=10) && (!(array[i-1]>=-10 && array[i-1]<=10)))
			|| (((!(array[i]>=-10 && array[i]<=10))) && (array[i+1]>=-10 && array[i+1]<=10) && (array[i-1]>=-10 && array[i-1]<=10))
			|| ((array[i]>=-10 && array[i]<=10) && (!(array[i+1]>=-10 && array[i+1]<=10)) && (array[i-1]>=-10 && array[i-1]<=10)))
			{
			risultato=0;}
			else{
				if(!((array[i]%3==0 && array[i]%3==0) && (array[i+1]%3==0 && array[i+1]%3==0) && (!(array[i-1]%3==0 && array[i-1]%3==0)))
			|| ((!(array[i]%3==0 && array[i]%3==0)) && (array[i+1]%3==0 && array[i+1]%3==0) && (array[i-1]%3==0 && array[i-1]%3==0))
			|| ((array[i]%3==0 && array[i]%3==0) && (!(array[i+1]%3==0 && array[i+1]%3==0)) && (array[i-1]%3==0 && array[i-1]%3==0)))
			{
			risultato=0;}
				}
			}
		//Ultimo della sequenza//
		if(i==(dimensione-1)){    //******** QUESTO RIENTRA NEL CASO PRECEDENTE -1
			//se nella tripla rispetta le condizioni allora risultato=0//
			if(!((array[i]>=-10 && array[i]<=10) && (array[i-1]>=-10 && array[i-1]<=10) && (!(array[i-2]>=-10 && array[i-2]<=10)))
			|| (((!(array[i]>=-10 && array[i]<=10))) && (array[i-1]>=-10 && array[i-1]<=10) && (array[i-2]>=-10 && array[i-2]<=10))
			|| ((array[i]>=-10 && array[i]<=10) && (!(array[i-1]>=-10 && array[i-1]<=10)) && (array[i-2]>=-10 && array[i-2]<=10)))
			{
			risultato=0;}
			else{
				if(!((array[i]%3==0 && array[i]%3==0) && (array[i+1]%3==0 && array[i+1]%3==0) && (!(array[i+2]%3==0 && array[i+2]%3==0)))
			|| ((!(array[i]%3==0 && array[i]%3==0)) && (array[i+1]%3==0 && array[i+1]%3==0) && (array[i+2]%3==0 && array[i+2]%3==0))
			|| ((array[i]%3==0 && array[i]%3==0) && (!(array[i+1]%3==0 && array[i+1]%3==0)) && (array[i+2]%3==0 && array[i+2]%3==0)))
			{
			risultato=0;}
			}
			}
			}
//OUTPUT//
return risultato;
}


int main()
{
	//IMPUT//  //****** INPUT!
	int lunghezza;
	printf("Ciao, sono un programma che verifica che in ogni tripla della sequenza");
	printf("ci siano 2 numeri tra -10 e 10 (estremi inclusi) e che esistano almeno 2 numeri divisibili per 3.\n");
	printf("Inserisci la lunghezza della sequenza!\n");
	scanf("%d",&lunghezza);
	int sequenza[lunghezza];
	printf("Inserisci i numeri della sequenza!\n");
	for(int i=0; i<lunghezza; i++){
		scanf("%d",&sequenza[i]);
	}
	int verifica;
	verifica=compresiMultilpi3(sequenza, lunghezza);
	//OUTPUT della interfacia utente//
	if(verifica!=0)
		printf("La sequenza rispetta i criteri iniziali!\n");
		else
			printf("La sequenza non rispetta i criteri iniziali!\n");


}