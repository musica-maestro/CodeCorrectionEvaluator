/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..0 //***** MANCANTE
   FUNZIONE (max 6):.......3.5
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................6.5
*/

/*SPECIFICA: programmam che verifica se esiste una tripla
 * di elementi consecutivi chew contiene almeno due elemnti
 * il cui valore è compreso tra -10 e 10 inclusi e che
 * contenga 2 multipli di 3
 *
 * input: una sequenza di numeri interi e la sua lunghezza
 * pre-condizione: lunghezza array almeno >=3
 * output:tripla esiste o non esiste
 * post-condizione: se esiste e vale 1, se non esite e vale 0*///******** LA POST-CONDIZIONE NON DICE NULLA -0.5

int compresiMultipli3(int arr[], int lung){
	int j;
	for(int i=0; i<lung-2; i++){
		if ((arr[i]>=-10 && arr[i]<=10) && (arr[i+1]>=-10 && arr[i+1]<=10) && (arr[i+2]>=-10 && arr[i+2]<=10)){
			//***** CONDIZIONE NON CORRETTA: DEVONO ESSERE ALMENO 2 COMPRESI, NON TUTTI E TRE -1.5
			int contatore=0;
			for(int j=i; j<i+3; j++){
				if(arr[j]%3==0){
					contatore = contatore+1;
				}
				if(contatore==2){
					return 1; //****** UN SOLO RETURN ALLA FINE DELLA FUNZIONE
				}             //****** QUESTO PERCHE' NON USI LA VARIABILE BOOLEANA PER TERMINARE IL CICLO -1
			}
		}
	}
	return 0;
}



#include <stdio.h>

int main()
{
	/*INPUT*/
	int lung;
	printf("quanti interi ha la sequenza?\n");
	scanf("%d", &lung);
	int arr[lung];

	/*PRE-CONDIZIONE*/
	if(lung<3){
		printf("la sequenza e' troppo corta\n\n");
	}

	for (int i=0; i<lung; i++){
		printf("inserisci un intero: ");
		scanf("%d", &arr[i]);
	}

	compresiMultipli3(arr, lung);

	/*OUTPUT*/
	if((compresiMultipli3(arr, lung))==1){
		printf("esiste una tripla\n\n"); //******** OUTPUT MOLTO POVERO -0.5
	}else{
		printf("tripla non esiste\n\n");
	}
}
