/* SPECIFICA (max 1.5):....0  //******* MANCANTE
   TIPO PROBLEMA (max 1):..0  //******* MANCANTE
   FUNZIONE (max 6):.......4
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................6.5
*/
#include <stdio.h>

int ugualiCompresi(int array[],int lung){
	int var=0;
	int i=0;
	while(i<lung-2&&!var){
		if((array[i]+array[i+1]>=10&&array[i]+array[i+1]<=20)
		||(array[i+1]+array[i+2]>=10&&array[i+1]+array[i+2]<=20)
		//******** MANCA UNA COMBINAZIONE (array[i+1],array[i+2]) -0.5
		&&(array[i]==array[i+1]||array[i+1]==array[i+2])){
		//******** MANCA UNA COMBINAZIONE, MA LA CONDIZIONE NON VA BENE:
		//******** E' RICHIESTO CHE SIANO UGUALI ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
		//******** ES. se la tripla e' 5 5 5 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
			var=1;
			}
		i++;
		}
	return var;
	}

int main(){
	int lunghezza;
	printf("ciao sono un programma che verifica in un array l'esistenza di una tripla di elementi \n");
	printf("consecutivi tale che almeno due elementi della tripla hanno una somma compresa tra 10 e 20 \n");
	printf("ed esattamente due elementi della tripla sono uguali \n");
	printf("introduci il numero di elementi dell'array \n");
	scanf("%d",&lunghezza);
	if(lunghezza<3)
		printf("gli elementi non sono sufficienti da formare una tripla \n");
	else{
		int array[lunghezza];
		for(int i=0;i<lunghezza;i++){
			printf("inserisci \n");
			scanf("%d",&array[i]);
			}
		if(ugualiCompresi(array,lunghezza)){
			printf("verificato \n");
			}
		else
			printf("non verificato \n");
		}
	}

