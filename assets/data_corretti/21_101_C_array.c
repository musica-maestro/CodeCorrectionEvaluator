/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9,5
*/
#include <stdio.h>

/*programma che chiede all'utente di inserire una serie di interi e verifica se in essa è presente almeno una tripla di elementi consecutivi in cui:
 * almeno 2 elementi sono compresi tra 10 e -10 estremi inclusi
 * se ci sono esattamente 2 valori divisibili per 3*/

/*
 * specifica:
 * input:una serie di interi
 * pre-condizione:la lungheza dell'array deve essere un valore positivo e l'array deve contenere solo valori inteiri
 * output:verifica o smentita della condizione
 * post:condizione: l'output deve valere per la serie di interi inserita dall'utente
 */                          //******** LA POST-CONDIZIONE NON DICE NULLA -0.5
 //tipo:problema di verifica esistenziale

 int CompresiMultipli3 (int serie2 [],int lunghezza2){
	 int ver=0;	//variabile di verifica
	 /*scorrimento dell'array*/
	 for(int i=0;i<lunghezza2-2&&!ver;i++){
		 /*prima condizione*/
		if ((serie2 [i]<=10&&serie2 [i]>=-10)&&(serie2 [i+1]<=10&&serie2 [i+1]>=-10)){
			/*seconda condizione*/
			if (serie2 [i]%3==0&&serie2 [i+1]%3==0&&serie2 [i+2]%3!=0){
				 ver=1;
			}
			/*seconda condizione*/
			if (serie2 [i]%3==0&&serie2 [i+2]%3==0&&serie2 [i+1]%3!=0){
				 ver=1;
				}
			/*seconda condizione*/
			if (serie2 [i+2]%3==0&&serie2 [i+1]%3==0&&serie2 [i]%3!=0){
				 ver=1;
				}
		}
		/*prima condizione*/
		if ((serie2 [i]<=10&&serie2 [i]>=-10)&&(serie2 [i+2]<=10&&serie2 [i+2]>=-10)){
			/*seconda condizione*/
			if (serie2 [i]%3==0&&serie2 [i+1]%3==0&&serie2 [i+2]%3!=0){
				 ver=1;
				}
				/*seconda condizione*/
			if (serie2 [i]%3==0&&serie2 [i+2]%3==0&&serie2 [i+1]%3!=0){
				 ver=1;
				}
				/*seconda condizione*/
			if (serie2 [i+2]%3==0&&serie2 [i+1]%3==0&&serie2 [i]%3!=0){
				 ver=1;
				}
		}
		/*prima condizione*/
		if ((serie2 [i+2]<=10&&serie2 [i+2]>=-10)&&(serie2 [i+1]<=10&&serie2 [i+1]>=-10)){
			/*seconda condizione*/
			if (serie2 [i]%3==0&&serie2 [i+1]%3==0&&serie2 [i+2]%3!=0){
				 ver=1;
				}
				/*seconda condizione*/
			 if (serie2 [i]%3==0&&serie2 [i+2]%3==0&&serie2 [i+1]%3!=0){
				 ver=1;
				}
				/*seconda condizione*/
			if (serie2 [i+2]%3==0&&serie2 [i+1]%3==0&&serie2 [i]%3!=0){
				 ver=1;
				}
		}
//******* LA VERIFICA E' TROPPO COMPLICATA! RIPETI TRE VOLTE LE STESSE CONDIZIONI -1
	}
	/*restituzione della variabile di controllo*/
	return ver;
}


int main(int argc, char **argv)
{
	printf("questo programma chiede una serie di elementi all'utente e verifica se esiste una tripla in cui:\n");
	printf("-almeno 2 elementi sono compresi tra -10 e 10  estremi inclusi\n");
	printf("-esattamente 2 elementiu sono divisibili per 3\n\n");
	printf("quanti interi vuoi inserire? ");
	int lunghezza;	//lunghezza dell'array
	scanf("%d",&lunghezza);
	/*dichiarazione dell'array*/
	int serie [lunghezza];
	/*riempimento dell'array*/
	for(int i=0;i<lunghezza;i++){
		printf("inserisci un intero: ");
		scanf("%d",&serie[i]);
	}
	/*controllo del risultato*/
	if (CompresiMultipli3(serie,lunghezza)){
			/*output caso 1*/
			printf("la serie inserita contiene almeno una tripla che rispetta la condizione");
	}else{
			/*output caso 2*/
			printf("la serie inserita non contiene almeno una tripla che rispetta la condizione");
	}
	return 0;
}
