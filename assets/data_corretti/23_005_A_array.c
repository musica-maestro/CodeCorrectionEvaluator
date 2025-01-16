/* SPECIFICA (max 1):......0.5
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......0
   MAIN PROGRAM (max 2):...0
   TOTALE (10).............0.5
*/
/*SPECIFICA: scrivi un programma di numeri interi e verificare se
 per ciascuna terna di elementi adiacenti ci sia almeno un elemento della terna
 multiplo mdi uno degi altri due
*Input: numero di interi //******** MANCA LA LUNGHEZZA -0.2
*Pre-condizione: alemno tre interi nella sequenza
*Output: verificata se ci sono multipli all'interno della terna adiacente
*Post-condizione: reinserisci la sequenza in caso contraio all'output
//******** POST CONDIZIONE NON CORRETTA -0.3
*TIPO DI PROBLEMA: problema di carattere esistenziale   */  //******* VERIFICA UNIVERSALE -1

#include <stdio.h>

int Multipli(int lung, int numero, int i, int bl){
	bl=1;          //esce uno se trovo il multiplo della terna
	if( i/numero && i/i){   // chiedo che i valori inseriti si dividano tra loro
		i++;
	}
	else{
		bl=0;      //deve richiedere la sequenza in quanto non è verificata la richiesta
	}
}//**** LA FUNZIONE DEVE AVERE UN ARRAY COME PARAMETRO, ALTRIMENTI COSA FAI? -6
//******* MANCA ANCHE IL return

int main(){
	int lung;
	int numero;
	int i;
	int bl;

	printf("Caro utente inserisci il numero degli interi presenti nella sequenza desiderata:", numero);
	scanf("%d", &lung);
    //******** MANCA LA DICHIARAZIONE DELL'ARRAY -1
	for(i=0; i<lung; i++){
		printf("Adesso puoi introdurre la tua sequenza\n", i);

		scanf("[%d]", &numero); //**** NON CORRETTA -1
	}
  	printf("La sequenza da te scelta e' la seguente:\n");
  	Multipli( lung,  numero,  i,  bl);      //invoco la funzione multipli
  	//***** CHI E' i? bl NON E' INIZIALIZZATO -1
  		if(bl=1){
  			printf("La terna adiacente contiene un multiplo!");
  		}
 		else{
 			printf("La tua sequenza non ha multipli nella terna, prova a inserirne un'altra!!");
 		}

}
