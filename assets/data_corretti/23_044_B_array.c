/* SPECIFICA (max 1):......0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.7
*/
/*SPECIFICA
 *input: un numero naturale che rappresenta la lunghezza dell'array e una serie di numeri interi inseriti nell'array
 *pre-condizione: gli elementi dell'array devono essere almeno 3 numeri interi
 *output:un intero tra 0 e 1
 *post-condizione: ila funzione consegna o 1 (in caso la funzione sia vera) e 0 (in caso sia falsa)*/
 //******** POST CONDIZIONE NON CORRETTA -0.3
 //il problema è di verifica universale

#include <stdio.h>

int duePositivi(int *array, int n){ //funzione duePositivi

	int i;
	int risultato=0; //variabile che conteggia le triple da 2 numeri positivi
	int verita=0; //dice se ogni tripla dell'array ha 2 numeri positivi (1=vero e 0=falso)


	for(i=0; i<n-2; i++){
		if(array[i]>0 && array[i+1]>0 && array[i+2]<0){
			risultato++;
		}
		else{
			if(array[i]>0 && array[i+1]<0 && array[i+2]>0){
				risultato++;
			}
			else{
				if(array[i]<0 && array[i+1]>0 && array[i+2]>0){
					risultato++;
				}
			}    //****** PIUTTOSTO COMPLICATA MA CORRETTA
		}
	}

	if(risultato==n-2){
		verita=1;
	}

	return verita;

}

int main(){ //funzione main

	int n; //lunghezza array
	int i; //variabile contatore

	printf("quanti interi vuoi inserire nell'array? (devono essere almeno 3)\n");
	scanf("%d", &n);    //legge la lunghezza dell'array

	int array[n]; //array

	//legge un elemento dell'array per ogni i++
	printf("iserisci i numeri dell'array\n");
	for(i=0; i<n; i++){
		scanf("%d", &array[i]);
	}

	/*for(i=0; i<n; i++){
		printf("%d", array[i]);
	}*/

	if(duePositivi(array, n)){
		printf("tutte le triple dell'array hanno due numeri positivi");
	}
	else{
		printf("non tutte le triple dell'array hanno due numeri positivi");
	}

}