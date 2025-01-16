/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................11
*/

#include <stdio.h>
/*SPECIFICA
 * Input: sequenza di interi e relativa lunghezza
 * Pre-condizione: la lunghezza dell'array deve essere maggiore o uguale a 3
 * Output: variabile esiste
 * Post-condizione: la variabile esiste vale 1 ne caso in cui esiste una tripla di elementi consecutivi che contiene almeno due elementi il cui valore e' compreso fra -10 e 10, 0 altrimenti
 * Tipo di problema: verifica esistenziale
 * */
int intervallo(int numero){		//Funzione che controlla se un numero appartiene all'intervallo (-10,10)
	int risultato = 0;
	if((numero >= -10) && (numero <= 10)){
		risultato = 1;
	}
	return risultato;
}


int compresiMultipli3(int stringa[],int lun){
	int esiste = 0;
	for(int i = 0 ; (i < lun-2) && (esiste == 0); i++){
		int numeri = 0;							//contatore numero di elementi dell'intervallo -10, 10 di una tripla
		int multipli = 0;						//contatore numero di elementi multipli di 3
		for(int j = i ; j < i+3 ; j++){			//controllo di ogni tripla
			if(intervallo(stringa[j]) == 1){	//il numero appartiene all'intervallo?
				numeri++;
			}
			if(stringa[j]%3==0){				//il numero e' multiplo di 3?
				multipli++;
			}
		}

		if (numeri >= 2 && multipli==2){
			esiste = 1;
		}

	}
	return esiste;
}
int main(int argc, char **argv)
{
	int lunghezza;
	printf("Programma che verifica se esiste una tripla\ndi elementi consecutivi\n");
	printf("che contiene almeno due elementi il cui\nvalore e' compreso fra -10 e 10\n");
	printf("e che contiene esattamente due numeri multipli di 3\n");
	printf("Quanti numeri si vogliono inserire nella se quenza? ");
	scanf("%d",&lunghezza);
	while(lunghezza < 3){
		system("cls");
		printf("la lunghezza della sequenza deve essere >= 3 reinseriscila: ");
		scanf("%d",&lunghezza);
	}
	int sequenza[lunghezza];
	printf("Inserisci la sequenza\n");
	for(int i = 0 ; i < lunghezza ; i++){
		system("cls"); //******** BRUTTO CLS DENTRO IL CICLO!
		printf("\nInserisci il %d elemento della sequenza: ", i+1);
		scanf("%d",&sequenza[i]);
	}
	if(compresiMultipli3(sequenza,lunghezza)){
		printf("esiste una tripla di elementi consecutivi\nche contiene almeno due elementi il cui\nvalore e' compreso fra -10 e 10");
	}else{
		printf("NON esiste una tripladi elementi consecutivi\nche contiene almeno due elementi il cui\nvalore e' compreso fra -10 e 10");
	}
	return 0;
}
