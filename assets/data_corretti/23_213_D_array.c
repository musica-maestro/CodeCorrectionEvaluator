/* SPECIFICA (max 1):......0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............9.2
*/
#include<stdio.h>
/*
SPECIFICA
*Input: una sequenza di interi //******** MANCA LA LUNGHEZZA -0.2
*precondizione:la sequenza deve contenere almeno tre elementi
*Output: 1 o 0 se è rispettivamente verificata o meno
*Postcondizione: esiste una tripladi numeir consecutivi con uno degli elementi pari al resto fra altri due
//********** FALSO, ALTRIMENTI -0.1
*TIPO : verifica esistenziale*/
int restoDivisione(int seq[], int n){
	int i=0;/*variabile contatore*/
	int ver=0;/*variabile che indica conferma la condizione*/
	/*ciclo che guarda tutte le triple di numeri consecutive o tutte quelle prima della conferma della postcondizione*/
	while(i<=n-3&&!ver){
		if((seq[i]%seq[i+1]==seq[i+2])||(seq[i]%seq[i+2]==seq[i+1])||
		   (seq[i+1]%seq[i]==seq[i+2])||(seq[i+1]%seq[i+2]==seq[i])||/*if verifica che esista una un numero paria l resto degli altri due all' interno della tripla corrente*/
		   (seq[i+2]%seq[i]==seq[i+1])||(seq[i+2]%seq[i+1]==seq[i]))
			{ver=1;}
		else
			{i++;}/*in caso contrario vado al prossimo elemento*/
	}
	return ver;
}


int main(){
	int n;
	int i=0;
	printf("inserisci la lunghezza della sequenza\n");
	scanf("%d",&n);
	int seq[n];
	while(i<n){
		printf("inserisci un elemento ");
		scanf("%d", &seq[i]);
		i++;
	}
	if(restoDivisione(seq, n)==1)
		printf("esiste una tripla di interi che soddisfa la condizione\n");
	else
		printf("non esiste una tripla di interi che soddisfa la condizione\n");
          //****** QUALE CONDIZIONE? -0.5

}
