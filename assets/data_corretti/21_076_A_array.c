/* SPECIFICA (max 1.5):....0.4
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......2.7
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................6.6
*/
/*SPECIFICA
 * Programma che legge una sequenza di interi e
 * verifica se esiste una tripla tale che la somma tra due elementi
 * sia compresa fra 10 e 20 (estremi esclusi) e che due eleenti della tripla siano uguali
 *
 * Input: una sequenza e la sua lunghezza //******** MANCANO I TIPI DEGLI ELEMENTI DELL'ARRAY -0.6
 * Pre-Condizioni: lunghezza>=0
 * Output: un intero "esiste"
 * Post_ù-Condizioni: restituisce 1 se la tripla che soddisfa la condizion estiste; 0 altrimenti
 //******** LA POST-CONDIZIONE NON DICE NULLA -0.5
 * TIPO DI PROBLEMA: Verifica esistenziale*/


#include <stdio.h>

/*funzione solo due uguali*/
int isUguali(int array[], int i){
	return ((array[i]==array[i+1])&&(array[i]!=array[i+2]) && (array[i]!=array[i-1]));
}                                                     ///***** QUEST'ULTIMA NON C'ENTRA NIENTE! -0.5




/*FUnzione*/
int ugualiCompresi(int array[], int lunghezza){

	int i=0;		//variabile contatore
	int esiste=0;	// variabile esistenza

	while(i<lunghezza-2 && esiste){
		/* controlla se solo due numeri uguali in un tripla e la somma di due numeri di essa è maggiore di 10 e minore di 20*/
		if ((isUguali //********* DEVI RICHIAMARE LA FUNZIONE CON I PARAMETRI -1
					  //********* LA isUguali PER COME E' SCRITTA DOVREBBE ESSERE RICHIAMATA SULLE TRE COMBINAZIONI -1.5
		&& ((((array[i]+array[i+1]>10 && array[i]+array[i+1]<20)
		|| (array[i]+array[i+2]>10 && array[i]+array[i+2]<20)
		|| (array[i+1]+array[i+2]>10 && array[i+1]+array[i+2]<20)))) ||
		//***** ARRIVATO QUI HAI PROVATO TUTTE LE COMBINAZIONI, A COSA SERVONO QUELLE DOPO? SI RIPETONO
		//***** //******** ESTREMI INCLUSI -0.3
		 (((array[i]+array[i+1]>10 && array[i]+array[i+1]<20)
		 || (array[i]+array[i+2]>10 && array[i]+array[i+2]<20)
		 || (array[i+1]+array[i+2]>10 && array[i+1]+array[i+2]<20))) ||
		(((array[i]+array[i+1]>10 && array[i]+array[i+1]<20)
		|| (array[i]+array[i+2]>10 && array[i]+array[i+2]<20)
		|| (array[i+1]+array[i+2]>10 && array[i+1]+array[i+2]<20)))))
			esiste=1;
		/* se non esiste passa al prossimo intero*/
		else
			i++;
	}
	return esiste;
}

/*Funzioone Main*/
int main()
{
	int lunghezza;		//lunghezza array
	/*INput*/
	printf("inserisci lunghezza array\n");
	scanf("%d", &lunghezza);

	int array[lunghezza];		//array da leggere
	/* ciclo di lettura array*/
	for(int i=0;i<lunghezza;i++){
		printf("inserisci un intero\n");
		scanf("%d" , &array[i]);
	}

	/*Output*/

	/*se la condizione è soddisfatta*/
	if (ugualiCompresi(array,lunghezza))
		printf("esiste una tripla in cui ci sono due interi uguali e la somma di due elementi della tripla e' compresa tra 10 e 20, estremi esclusi\n");
	else
		printf("non esiste una tripla in cui ci sono due interi uguali e la somma di due elementi della tripla e' compresa tra 10 e 20, estremi esclusi\n");

}
