/* SPECIFICA (max 1):......0.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.5
*/
/*SPECIFICA:
 *input: dimensione sequenza, sequenza{a1,a2,...,an}.  //******** MANCA IL TIPO -0.2
 *pre-condizione: a1,a2,...,an sono interi reali e la dimensione deve essere almeno 3 o maggiore.
 *output: risultato{0,1}.                              //******* MANCA POST CONDIZIONE -0.3
 *TIPO DI PROBLEMA: universale.
 */

#include <stdio.h>
/*funzione duePositivi che ha come parametri un array 'a' e la lunghezza 'L'*/

/*funzione ausiliare alla funzione duePositivi*/
int espBl(int a,int b, int c){
	/*restituisce 1 se in una tripla ci sono esattamente due numeri positivi, altrimenti 0*/
	return ((a>0&&b>0&&c<0)||(a>0&&c>0&&b<0)||(b>0&&c>0&&a<0));
}
/*funzione con l'algoritmo risolutivo al problema*/
int duePositivi(int a[],int L){
	int risultato;	//valore di ritorno
	int i;	//contatore

	risultato=1;	//inizializzo risultato a 1
	i=0;	//inizializzo contatore
	/*vedi ogni tripla di numeri consecutivi finche risultato è false*/
	while(i<L-2&&risultato){
		/* se l'spressione viene true allora risultato è false;
		 * altrimenti passa alla tripla successiva*/
		if(!espBl(a[i],a[i+1],a[i+2]))
			risultato=0;	//false
		else
			i++;	//passa avanti
	}
	return risultato;
}
/*funzione che gestisce l'interazione con l'utente*/
int main(){
	int n;	//dimensione array
	int i;	//indice//contatore

	printf("ciao utente, data una sequenza, sono un programma che ti dice\nse in ogni tripla di numeri consecutivi ci sono esattamente due numeri positivi.\n");
	printf("\ndunque scriviamo una sequenza:\n");

	/*ciclo finche non inserisci dimensione almeno 3*/
	do{
		printf("quanti valori vuoi (almeno 3):  ");
		scanf("%d",&n);	//INPUT:dimensione array
		if(n<3)
			printf("non va bene, riprova\n");
	}
	while(n<3);

	int seq[n];	//sequenza

	/*ciclo che legge la sequenza inserita dall'utente*/
	for(i=0;i<n;i++){
		printf("utente inserisci un valore:  ");
		scanf("%d",&seq[i]);//INPUT:sequenza//array
	}

	printf("nella sequenza che hai scritto, in ogni tripla di numeri consecutivi \nci sono esattamente due valori positivi");
	printf("|vero == 1  falso == 0| --> Calcolato: %d",duePositivi(seq,n)); //OUTPUT: {0,1}

}