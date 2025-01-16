/* SPECIFICA (max 1.5):....0  //******* MANCANTE
   TIPO PROBLEMA (max 1):..0  //******* MANCANTE
   FUNZIONE (max 6):.......0
   MAIN PROGRAM (max 2.5):.1.5
   TOTALE..................
*/
#include <stdio.h>

int ugualiCompresi(int array[], int lunghezza){
	int array[lunghezza];  //******** GIA' LO PASSI COME PARAMETRO, NON LO DEVI DICHIARARE -1
	int consecutivi;
	int somma;
	consecutivi=-1; //********* DEVI INIZIALIZZARLA A 0 PERCHE' E' UNA VERIFICA ESISTENZIALE -1
	somma=array[0]+array[1]+array[2]; //******** FUORI DAL CICLO?
	for(int i=0;i<lunghezza; i++)
	somma=array[0-1]+array[1-2]+array[2-3]; //******* GLI INDICI DELL'ARRAY DEVONO DIPENDERE DALLA i -2

	if (somma== 10 && somma==20)  //********* COME PUO' ESSERE CONTEMPORANEAMENTE UGUALE A 10 E A 20? E' SEMPRE FALSA -2
       consecutivi=1;
	else             //******* FA PARTE DEL CICLO FOR? NON CI SONO LE PARENTESI...
		i++;
	return consecutivi;
}

int main()
{

	int lunghezza;
	printf(" questo programma dice se esiste una tripla di elementi consecutivi\n  ");
	printf("che almeno due sono compresi fra 10 e 20 e due elementi sono uguali:");
	printf("quanti interi ha la sequenza\n");
	scanf("%d",&lunghezza);
	int array[lunghezza];
	printf("introduci gli interi della sequenza \n");
	for(int i=0; i<lunghezza i++){
	    scanf("%d",&array[i]);}
		//*********** NON RICHIAMI LA FUNZIONE! -1
		printf("la sequenza esiste una tripla di elementi consecutivi che almeno due sono compresi fra 10 e 20 e due elementi sono uguali: %d",ugualiCompresi(array[],lunghezza));
}
