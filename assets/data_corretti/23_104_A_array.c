/* SPECIFICA (max 1):......0.6
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............8.1
*/
/* SPECIFICA : data una sequenza di interi verificare se per ciascuna terna di elementi adiacenti , ci sia almeno un elemento della terna multiplo degli altri due.
*input: sequenza vet e la sua lunghezza l //******* MANCA LA SPECIFCA DEL TIPO -0.2
*pre-condizione:l è la lunghezza della sequenza
*output: 1 o 0 in base se viene trovato in tutte le terne almeno un elemento multiplo degli altri due
*Post-condizione://**** MISCHI OUTPUT E POST-CONDIZIONE -0.2
* TIPO DI PROBLEMA: verifica universale
*/

#include <stdio.h>

int multipli(int v[],int n);

int main()
{
	int l; //variabile usata per memorizzare la lunghezza dell' array


	printf("Ciao utente sono un programma che data");
	printf("numero una sequenza di interi verifica se ogni terna adiacente ci sia almeno");
	printf("un elemento multiplo degli alti due\n");

	printf("quanti interi contiene la tua sequenza? ");
	scanf("%i",&l);
	int vet[l];

	for(int i=0;i<l;i++) //inserimento degli elementi dentro all'array
	{
		printf("inserisci il %i numero: ",i+1);
		scanf("%i",&vet[i]);
	}

	if(multipli(vet,l))
		printf("in tutte le terne degli elementi c'e' almeno un elemento multiplo delgi altri due");
	else
		printf("in tutte le terne degli elementi non e' stato trovato almeno un elemento multiplo delgi altri due");

}


int multipli(int v[],int n)
{
	int cont;
	for(int i=0;i<n-2;i++) //ciclo for che parte dal primo elemento
	{
		cont=0; //variabile che si azzera a ogni terna per contare i multipli trovati
		for(int j=i;j<i+2;j++)		//ciclo for che parte da i e controlla la terna adiacente
			if(v[j]%v[j+1]==0 || v[j+1]%v[j]==0)//****** COSI' FAI 4 CONTROLLI, INVECE CE NE VOGLIONO 6 -1
				cont++; //se un multiplo viene trovato incremento cont di uno
		if(cont<1) // se cont è minore di uno alla fine dell ciclo
			return 0; // vuoldire che non è stato trovato almeno un elemento multiplo degli altri e quindi ritorno 0
	}
//******** 2 RETURN NON E' PROGRAMMAZIONE STRUTTURATA -0.5
	return 1; // arrivati fino a questo vuoldire che in tutte le terne c'è almeno un elemento multiplo degli altri due
}