/* SPECIFICA (max 1.5):....0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......0.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................4.7
*/
/*SPECIFICA
 * Input: una sequenza s e un intero l //******** MANCA IL TIPI DEGLI ELEMENTI DELL'ARRAY  -0.6
 * Pre-Cond:l è la lunghezza rispettiva di s
 * Output:1 o 0
 * Post-cond:1 se ogni tripla di s ha due elementi maggiori o uguali a  5 e due elementi pari,altrimenti 0
 * Tipo di problema: verifica universale/ //**** ESATTAMENTE -0.2
*/
#include <stdio.h>

 /*funzione che mi calcola se OGNI TRIPLA contiene due numeri pari e due elementi maggio o uguali a 5*/
int maggiori5Pari(int array[],int lunghezza){
         int i; //contatore
		 int trovato=1; //il nostro output
		 int k;

		 i=0;
		 //[1,2,3]
		 while(i<=lunghezza-3 && trovato){

			for(k=i+1;k<=lunghezza;k++){ //**** COSI' NON ESAMINA UNA TERNA, MA TUTTO IL RESTO DELL'ARRAY
			//******* NON SERVE IL FOR, SE VOLEVI USARE k BASTAVA SCRIVERE k=i+1; -1.5
			//******* ACCEDE FUORI DAI LIMITI DELL'ARRAY -1
				//se abbiamo o 1 pari o 3 pari termino
				if((array[k]%2==0 && array[k+1]%2!=0 && array[k-1]%2!=0)
				|| (array[k]%2!=0 && array[k+1]%2==0 && array[k-1]%2!=0)
				|| (array[k]%2!=0 && array[k+1]%2!=0 && array[k-1]%2==0) ||
				   (array[k]%2==0 && array[k+1]%2==0 && array[k-1]%2==0)){
					   trovato=0;
				   }
              //ora abbiamo due pari esatti //********* ERA RICHIESTO ALMENO 2 PARI ED ESATTAMENTE 2 >=5! -1
             else {  //******* >=5 -0.5
				if((array[k]>5 && array[k+1]<5 && array[k-1]<5)
				|| (array[k]<5 && array[k+1]>5 && array[k-1]<5) |
				| (array[k]<5 && array[k+1]<5 && array[k-1]>5) ||
				   (array[k]>5 && array[k+1]>5 && array[k-1]>5)){
					   trovato=0; //**** STAI VERIFICANDO CHE NON CI SIANO ALMENO 2 >=5?
					              //**** IN QUESTO CASO L'ULTIMA CONDIZIONE E' SBAGLIATA -1.5
			 }

			}

		 }
		 i++;
		 }
		 return trovato;
}

int main(int argc, char **argv)
{
	printf("Salve utente sono un programma che ti dice se all'interno della tua sequenza ogni tripla è costituita da due numeri pari e da due numeri maggiori di 5!\n \n");
	int lunghezza;
	printf("Dimmi quanti numeri vuoi inserire:\n");
	scanf("%d", &lunghezza);

	if(lunghezza<3){
		printf("Non te lo posso calcolare!\n");
		return 0;
	}
	int sequenza[lunghezza];
	for(int i=0;i<lunghezza;i++){
		printf("Dammi il %d%c elemento: ",i+1,167);
		scanf("%d", &sequenza[i]);
	}

	if(maggiori5Pari(sequenza,lunghezza)){
		printf("ISTANZA POSITIVA\n");
	}
	else {
		printf("ISTANZA NEGATIVA\n");
	}

}
