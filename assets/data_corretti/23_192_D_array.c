/* SPECIFICA (max 1):......0.4
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.4
*/
#include<stdio.h>
/*SPECIFICA

*Input: Una sequenza di interi

*Pre-condizione: La sequenza deve essere di interi e lunga un minimo di 3

*Output: Una frase asseconda del risultato della funzione restoDivisione //**** asseconda è la terza persona del verbo assecondare, volevi scrivere secondo il risultato....
//*** NO, L'OUTPUT DEVE ESSERE UNA VARIABILE INTERA, NON UNA FRASE -0.3

*Post-condizione: Asseconda del risultato la sequenza deve avere o meno una terna di elementi adiacenti di cui uno è il resto della divisione degli altri e due
//********** LA VARIABILE E' VERA SE... FALSA ALTRIMENTI -0.3

*TIPO DI PROBLEMA: Una verifica esistenziale
*/

int restoDivisione(int* array, int l){



	int resto=0;
	for(int i=0; i<=l-3;i++){
		if((array[i]==(array[i+1]%array[i+2]))||(array[i]==(array[i+2]%array[i+1]))||
		   (array[i+1]==(array[i]%array[i+2]))||(array[i+1]==(array[i+2]%array[i]))||
		   (array[i+2]==(array[i]%array[i+1]))||(array[i+2]==(array[i+1]%array[i])))
			resto=1;
	}
	return resto;
}
int main(){
/*INPUT*/
	int l;
	printf("Quanto %c lunga la tua sequeza di interi: ", 138);
	scanf("%d", &l);
	int array[l];
	printf("\nOra dammi una sequenza di interi: ");
	for(int i=0; i<=l-1;i++)
		scanf("%d", &array[i]);
	/*OUTPUT*/
	if(l<=2)
		printf("\nLa tua sequenza di interi %c troppo corta per essere analizzata", 138);

	if(restoDivisione(array, l))
		printf("\nEseiste una terna di elementi adiacenti nella sequenza in cui uno %c\nil resto della divisione degli altri due", 138);
	else
		printf("\nNon esiste alcuna terna di elementi consecutivi in cui uno %c\nil resto della divsione degli altrie due", 138);

}