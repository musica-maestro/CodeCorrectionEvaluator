/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.8
*/
/*SPECIFICA

input: sequenza v[dim]=x1, x2, ..., xn  //**** n=dim -0.2
pre-condizione: sequenza di interi
output: variabile esito 1 o 0
post-condizione: 1 se esiste una tripla in cui uno dei tre elementi è
				 il resto della divisione degli altri due
				 0 se non esiste una tripla in cui uno dei tre elementi è
				 il resto della divisione degli altri due

TIPO DI PROBLEMA: verifica esistenziale
*/
#include<stdio.h>

int restoDivisione(int vet[], int dim){

	int esito=0;
	int i=0;

	while((i<dim-2) && !(esito)){

		if((vet[i]%vet[i+1]==vet[i+2]) || (vet[i]%vet[i+2]==vet[i+1]) ||
		   (vet[i+1]%vet[i]==vet[i+2]) || (vet[i+1]%vet[i+2]==vet[i]) ||
		   (vet[i+2]%vet[i]==vet[i+1]) || (vet[i+2]%vet[i+1]==vet[i]))
			esito=1;
		else
			i++;
	}

	return esito;
}

int main(){

	int d;

	printf("inserisci dimensione array: \n");

	scanf("%d", &d);

	int v[d];

	for(int i=0; i<d; i++){

	printf("inserisci valore: \n");
	scanf("%d", &v[i]);

	}

	if(restoDivisione(v, d))
		printf("esiste una tripla in cui uno dei tre elementi e' il resto della divisione degli altri due");
	else
		printf("non esiste una tripla in cui uno dei tre elementi e' il resto della divisione degli altri due");
	}