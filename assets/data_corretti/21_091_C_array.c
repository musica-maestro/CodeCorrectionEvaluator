
/*Specifica
 /* SPECIFICA (max 1.5):....1,3
    TIPO PROBLEMA (max 1):..1
    FUNZIONE (max 6):.......4.5
    MAIN PROGRAM (max 2.5):.2.1
    TOTALE..................8.9
*/
 * Input: una sequenza s di interi con lunghezza l
 * Pre-condizione:l e' la lunghezza della sequenza
 * Output:un valore booleano
 * Post-condizione:questo valore definisce se nella sequenza sono presenti triple di elementi che contengono almeno 2 elementi compresi fra -10 e 10 e 2 elementi multipli di 3
 * Tipo di problema:Verifica esistenziale e conteggio  //****** 0, ALTRIMENTI -0.2
 * */
#include <stdio.h>
int compresiMultipli3 (int array[], int lunghezza){
	//pre: lunghezza e' la lunghezza dell'array
	int compresi=1;
	int multipli3=1;//****** PER CONTARE DEVI PARTIRE DA 0! -1
	int verificato=0;
	for(int i=0; i<lunghezza-2; i++){ //controlla tutti gli indici dell'array tranne gli ultimi 2 elementi poiche' non sono una tripla
		for(int j=i; j<i+2; j++){		//e tutte le triple di quell'indice
			if(array[j]<=10 && array[j]>=-10)	//se il valore e' compreso tra -10 e 10
			compresi++;							//aumenta il valori dei compresi di 1
			if((array[j])%3==0)					//se il valore e' multiplo di
			multipli3++;						//aumenta il valore dei multipli di 1
		}
		if(compresi==2 && multipli3==2){		//se in questo tripla di elementi ci sono 2 compresi e 2 multiplidi3
			verificato=1;						//il valore verificato diventa 1
	  //***** compresi>=2 -0.5
	}
		else									//se non ci sono 2 compresi e 2 multiplidi3 resetta i contatori di entrambi
			compresi=1; //***** =0
			multipli3=1;//***** =0

	}


	return verificato;

}

int main()
{
	/*input*/
	int lunghezza;
	printf("inserire la lunghezza dell'array\n");	//viene chiesta la lunghezza dell'array
	scanf("%d", &lunghezza);
	int array[lunghezza];

	printf("Inserire la sequenza \n");
	for(int i=0; i<lunghezza; i++)					//viene chiseto di inserire la sequenza
		scanf("%d", &array[i]);
	/*output*/
	if(compresiMultipli3(array, lunghezza)==1)				//viene stampato il valore di output
		printf("l'istanza del problema %c positiva", 138);
	else
		printf("l'istanza del problema %c negativa", 138);
	            //******** OUTPUT MOLTO POVERO -0.4
	return 0;
}
