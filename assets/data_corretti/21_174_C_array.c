/* SPECIFICA (max 1.5):....0 //****** MANCANTE
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3.3
   MAIN PROGRAM (max 2.5):.0
   TOTALE..................4.3
*/
#include <stdio.h>
/*LUCA OLIVERI*/
/*Programma che verifica se esiste una tripla di elementi consecutivi che contiene almeno due elementi
 * il cui valore è compreso fra 10 e -10 e che contiene esattamente due elementi multipli di 3*/
 /*problema di verifica esistenziale*/

 int compresiMultipli3 (int sequenza[], int lunghezza){
int compresi=0;
int i=0;
while(i<=lunghezza-3 && !compresi){
if ((sequenza[i]>=-10||sequenza[i]<=10)&&(sequenza[i+1]>=-10
||sequenza[i+1]<=10)&&(sequenza[i+2]<=-10||sequenza[i+2]>=10))
//****** MANCA UNA COMBINAZIONE -1
if((sequenza[i]%3==0)&&(sequenza[i+1]%3==0)&&(sequenza[i+2]%3==1))
//***** MANCANO DUE COMBINAZIONI -1.5
compresi=1;
else
	i++;
	else    //******** INDENTATO MALE -0.2
		i++;
		return compresi;
}
 }
int main()
{
	int i;
	int lunghezza;
	int sequenza[lunghezza]; //******** DEVI LEGGERE LA LUNGHEZZA DA INPUT PRIMA DI DICHARARE L'ARRAY -1
	printf("introduci il numero di interi della tua sequenza: \n");
	scanf("%d", &lunghezza);
	printf("introduci gli interi: \n"); //***** MANCA L'ITERAZIONE -1
	scanf("%d", &sequenza[i]);
	compresiMultipli3(sequenza[lunghezza], lunghezza);
	}

compresimultipli3(int sequenza[], int lunghezza){
    printf("esiste");    //*** OUTPUT MOLTO POVERO -0.5

	printf("non esiste");
}
