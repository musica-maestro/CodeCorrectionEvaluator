/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............8.8
*/
/*
SECIFICA:
Input: una sequenza A di n elementi
Precondizionioni: gli elementi di a devno essere interi positivi
Output: variabile booleana x
Postcondizioni: x=0 se e solo se ogni tripla di elementi consecutivi contiene almeno due numeri di una sola cifra //**** x=1! -0.2
Tipo di problema: verifica universale

*/


#include<stdio.h>
#include<stdlib.h>

int DueUnaCifra(int A[], int n){
	int x=0;
	int i=0;
	while(x==0 && i<n-2){
		if((A[i]>=10 && A[i+1]>=10)||(A[i]>=10 && A[i+2]>=10)||(A[i+1]>=10 && A[i+2]>=10)){
			x=1;
		}          //**** HAI INVERITO IL RUOLO DEI VALORI DI VERITA', MA IN MODO COERENTE -1
		i++;
	}
	return(x);
}

int main(){
	int n, x;
	printf("\nCiao utente, di quanti elementi vuoi che sia composta la sequenza?\n");
	scanf("%d",&n);
	int A[n];
	printf("\nInserisci %d interi positivi:\n", n);
	for(int i=0; i<n; i++){
		scanf("%d",&A[i]);
	}
	x=DueUnaCifra(A,n);
	if(x==0){
		printf("\nSì. Ogni tripla della sequenza ha almeno due numeri di una sola cifra.");
	}else{
		printf("\nNo. Alcune triple non hanno due numeri di una sola cifra.");
	}
}