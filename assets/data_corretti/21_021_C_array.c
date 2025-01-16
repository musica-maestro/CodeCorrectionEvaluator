/* SPECIFICA (max 1.5):....1.3
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9.8
*/
/*SPECIFICA
 * INPUT: una sequenza di interi s e la sua lunghezza l
 * PRECOND:
 * OUTPUT:esiste
 * POST-COND:esiste vale true se la sequenza contiene due elemnti
 * in una tripla con valore compreso tra -10 e 10 e contiene esattamente due valori multipli di 3
 //******** POST-CONDIZIONE NON COMPLETA (0, ALTRIMENTI) -0.2
 * TIPO DI PROBLEMA: verifica esistenziale.
 * Damiano Sartini 5/02/'21
 * */
 /*Funzione che data una sequenza di interi dice se esiste una tripla nella sequenza in cui due valori sono
  * compresi tra 10 e -10 e esattamente due sono multipli di 3*/
int compresiMultipli3(int seq[], int lung){
	int i=0;        // per il contatore
	int esiste=0;  //variabile di esistenza

	while(i<lung-2&&!esiste){
		//condizione per vedere se due numeri in una tripla sono compresi
		//tra 10 e -10 e se esattamente due sono multipli di 3



		if(((seq[i]<=10 && seq[i]>=-10 && seq[i+1]<=10 && seq[i+1]>=-10 && !(seq[i+2]<=10&&seq[i+2]>=-10))) ||
		  ((seq[i+1]<=10 && seq[i+1]>=-10 && seq[i+2]<=10 && seq[i+2]>=-10 && !(seq[i]<=10 && seq[i]>=-10))) ||
		  ((seq[i]<=10 && seq[i]>=-10 && seq[i+2]<=10 && seq[i+2]>=-10 && !(seq[i+1]<=10&&seq[i+1]>=-10)))
		  //******* ALMENO 2, NON ESATTAMENTE 2 COMPRESI TRA -10 E 10 -1
		  &&
		  ((seq[i]%3==0 && seq[i+1]%3==0 && seq[i+2]%3!=0) || (seq[i]%3==0 && seq[i+2]%3==0 && seq[i+1]%3!=0) ||
		  (seq[i+1]%3==0&&seq[i+2]%3==0&&seq[i]%3!=0)))
	        esiste=1;

			else
				//passo al prossimo indice
				i++;
	}
}





#include <stdio.h>
int main(){
	int lunghezza;

	/*input*/
    printf("Caro utente questo programma vede se ci sono due elemnti in una tripla compresi fra 10 e -10");
	printf("e se esattamente due sono multipli di 3");
	printf("quanto deve essere lunga la sua sequenza? ");
    scanf("%d", &lunghezza);

	//inizializzo solo dopo aver saputo la sua dimensione
	int sequenza[lunghezza];

	//ciclo per riempire la sequenza
	for (int i=0; i<lunghezza; i++){

		printf("introduca un intero:");
	    scanf("%d", &sequenza[i]);

	}

    /*output*/
    if(compresiMultipli3)
		printf("esistono due elementi compresi tra 10 e -10 e due multipli di 3");
		else
			printf("non esistono due elementi multipli di 3 e compresi tra 10 e -10");
}
