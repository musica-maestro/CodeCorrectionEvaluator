/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.8
*/
/*SPECIFICA
*Input: Una sequenza di interi e la lunghezza della sequenza.
*Pre-condizioni: I numeri della sequenza sono interi.//******* GLI INTERI DEVONO ANCHE ESSERE POSITIVI -0.2
*Output: Una variabile booleana verif.
*Post-condizioni: verif è true se ogni tripla di elementi adiacenti della sequenza siano presenti almeno due numeri composti da una sola cifra, altrimenti verif è false
*Tipo di problema: Verifica universale*/
#include<stdio.h>
/*funzione ausiliaria che restituisce 1 se ogni tripla della sequenza rispetta la proprietà*/
int dueUnaCifra(int*arr,int l){
	int verif=1; /*variabile di universalità*/
	for (int i = 0; i < l-2; i++)
	{
		if((arr[i]>=10&&arr[i+1]>=10)
			||(arr[i+2]>=10&&arr[i+1]>=10)    /*condizione che non deve avverarsi se ogni tripla della sequenza rispetta le proprietà*/
			||(arr[i]>=10&&arr[i+2]>=10))
			verif=0;
	}
	return verif;
}
/*funzione main che gestisce le interazioni con l'utente*/
int main(){
	/*INPUT*/
	int lunghezza;
	printf("utente dimmi quanti numeri vuoi inserire: ");
	scanf("%d",&lunghezza);
	int array[lunghezza];
	for (int i = 0; i < lunghezza; i++)
	{
		printf("dammi un numero e premi invio: ");
		scanf("%d",&array[i]);
	}
	/*Richiamo della funzione ausiliaria*/
	int verifica=dueUnaCifra(array,lunghezza);
	/*OUTPUT*/
	if(verifica){
		printf("utente in tutte le triple di elementi adiacenti \n");
		printf("della sequenza sono presenti almeno due numeri composti da una sola cifra ");
	}
	else
		printf("utente NON in tutte le triple di elementi adiacenti della sequenza sono presenti almeno due numeri composti da una sola cifra");
}