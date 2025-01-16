/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............8.5
*/
/*
INPUT: intero n che indica la lunghezza della sequenza, e la sequenza di numeri
PRECONDIZIONI: n>=3
OUTPUT: Intero DuePos
POSTCONDIZIONI: DuePos vale 1 se in ogni tripla di elementi adiacenti ci sono esattamente due interi positivi, 0 altrimenti.

TIPO DI PROBLEMA: Verifica Universale

*/
#include <stdio.h>

int positivi (int a, int b, int c){
return (a>0 && b>0 || a>0 && c>0 || b>0 && c>0);  //se sono presenti esattamente due numeri positivi
}//****** COSI' VERIFICHI SE CI SONO ALMENO DUE POSITIVI, NON ESATTAMENTE DUE -1.5


int duePositivi(int a[], int n){
int i=0;  //contatore
int DuePos=1;  //variabile di ouput impostata ad 1 per verifica universale
	while(i<n-2 && DuePos)   //ciclo fino a che il contatore non è minore della lunghezza meno 2 e la variabile è =1
		if(positivi(a[i],a[i+1],a[i+2]))
			i++;  //incremento
		else
			DuePos=0;
return DuePos;
}

int main(){
int n;  //lugnhezza array
printf("Caro Utente, questo programma ti dice se nella sequenza di numeri, in ogni tripla sono presenti esattamente due numeri positivi \n");
printf("Inserisci la lunghezza dell'array: ");
scanf("%d",&n);  //acquisizione lunghezza array
int array[n];  //definizione array
	for(int i=0;i<n;i++){  //riempimento array
		printf("Inserisci un numero: ");
		scanf("%d",&array[i]);
	}
		if(duePositivi(array,n))   //verifica proprietà
			printf("In ogni tripla di elementi adiacenti sono presenti esattamente due numeri positivi");
		else
			printf("Non è vero che in ogni tripla di elementi adiacenti sono presenti esattamente due numeri positivi");
}