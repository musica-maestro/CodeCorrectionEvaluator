/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.2
   TOTALE.................10.7
*/
#include <stdio.h>
/*SPECIFICA
 * input: n1,n2,n3...nx
 * Pre-condizione: n1,n2,n3...nx interi
 * Output: valore booleano esiste
 * Post-condizione: esiste vale:
 * 0) se non esiste una tripla di interi conseguitivi che contiene almeno due elementi il cui valore è compreso
 * tra -10 e 10 e essatmente due elementi multipli di 3
 * 1) se esiste una tripla come descritta sopra
 * Tipologia: verifica esistenziale*/
int compresiMultipli3(int array[], int n){
	int esiste=0;
	/*Ciclo che esamina tutti gli elementi di mezzo dell array*/
	for(int i=1;i<(n-1) && esiste==0;i++){
		int c=0; // contatore numeri compresi tra 10 e -10
		int c3=0;  // contatore numeri multipli 3
		/*Ciclo che conta quanti elelemtni di ogni tripla sono compresi tra -10 e 10 e quanti sono multipli di 3*/
		for (int p=i-1;p<i+2;p++){
			if (array[p]<=10 && array[p]>=-10){
				c++;
			}
			if (array[p]%3==0){
				c3++;
			}
		}
		if(c>=2 && c3==2){
			esiste=1;
		}
	}
	return(esiste);
}
int main(int argc, char **argv)
{
int n; // numero interi
printf("Inserisci numero interi: ");
scanf("%d", &n);
int array[n];
/*ciclo che legge e memorizza interi in un array*/
for (int i=0;i<n;i++){
	printf("Inserisci intero: ");
	scanf("%d", &array[i]);
}
if(compresiMultipli3(array,n)){
	printf("Esiste una tripla di interi conseguitivi che contiene almeno due elementi il cui valore %c compreso tra -10 e 10 e che contiene esattamente 2 elementi mulitipli di 3 \n",138);
}
else{
	printf("Non esiste una tripla di interi conseguitivi come la si cerca\n");
}   //******** I/O UN PO' POVERO -0.3
}