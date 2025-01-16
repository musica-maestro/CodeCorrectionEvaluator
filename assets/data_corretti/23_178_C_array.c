/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.8
*/
/*Programma che data una sequenza di interi positivi, verifica che in ogni tripla di elementi adiacenti della sequenza siano presenti almeno due numeri composti da una
sola cifra.*/
/*SPECIFICA
*INPUT:una sequenza di interi s con lunghezza l
*PRE-CONDIZIONE:l è la lunghezza di s //******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
*OUTPUT:un intero "due"
*POST CONDIZIONE:"due" restituisce 1 se in tutte le triple di elementi adiacenti della sequenza sono presenti almeno due numeri composti da una sola cifra,0 altrimenti
TIPO DI PROBLEMA:Verifica Universale
*/
#include <stdio.h>

int dueUnaCifra(int seq[],int lun){
int due=1;
int i=0;

while(i<lun-2 && due){
if(!((seq[i]>= 0 && seq[i]<=9)&&(seq[i+1]>=0 && seq[i+1]<=9)||
	((seq[i]>=0 && seq[i]<=9)&&(seq[i+2]>=0 &&seq[i+2]<=9))||
	(seq[i+1]>=0 && seq[i+1]<=9)&&(seq[i+2]>=0 && seq[i+2]<=9)))

	due=0;


	else

		i++;



}

return due;

}


int main(){
	int len;
	int i;

	printf("Ciao utente,sono un programma che data una sequenza di interi verifica che in ogni tripla di elementi adiacenti della sequenza siano presenti\n");
	printf("almeno due numeri composti da una sola cifra\n");
	printf("Introduci la lunghezza della sequenza: ");
	scanf("%d",&len);

	int array[len];
	for(i=0;i<len;i++){
		printf("Introduci un intero: ");
		scanf("%d",&array[i]);


}
		if(dueUnaCifra(array,len))
			printf("In tutte le triple sono presenti almeno due numeri composti da una sola cifra\n");
		else
			printf("Non sono presenti almeno due numeri composti da una sola cifra");
	}

