/* SPECIFICA (max 1.5):....1.3
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3.8
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................8,6
*/
/*specifica
 * input:sequenza di interi e lunghezza della sequenza
 * precondizione:lunghezza della sequenza maggiore di 3 e elementi della sequenza interi
 * output:variabile di risultato  //******** MANCA IL TIPO  -0.2
 * postcondizione: variabile di controllo vale 1 se tutte le triplette di numeri consecutivi
 * contengono almeno 2 numeri maggiori di cinque e almeno un numero pari, altrimenti vale 0.
 * tipo di problema: verifica universale
 */



#include <stdio.h>

int maggiorePari5(int ar[],int l){
	int i=0;
	int r=1;
	while(i<l-2){ //******** NON USI LA VARIABILE BOOLEANA PER TERMINARE IL CICLO -1
		if(((ar[i]>=5&& ar[i+1]>=5)
		||(ar[i]>=5&& ar[i+2]>=5)
		||(ar[i+1]>=5&& ar[i+2]>=5))
		//******** DEVI CONTROLLARE CHE ESATTAMENTE 2 SIANO >=5, NON ALMENO 2 -1
		&&((ar[i]%2==0&&ar[i+1]%2==0)||(ar[i+1]%2==0&&ar[i+2]%2==0)||(ar[i]%2==0&&ar[i+2]==0))){
			i++;
		}else{
			r=0;
			i++; //********* POTEVI METTERE i++ UNA SOLA VOLTA FUORI DALL'IF -0.2
		}
	}
	return r;
}

int main(){
	int length;
	int res;
	printf("\nInserisci lunghezza della sequenza: ");
	scanf("%d",&length);
	int seq[length];
	for(int i=0;i<length;i++){
		printf("\nInserisci l'elemento %d della sequenza: ",i);
		scanf("%d",&seq[i]);
		printf("\n");
	}
	res=maggiorePari5(seq,length);
	if(res==1){
		printf("\nNella sequenza tutte le triplette hanno almeno 2 numeri maggiori o uguali a 5 e 2 numeri pari.");
	}else{
		printf("\nNella sequenza NON tutte le tripletta hanno almeno 2 numeri maggiori o uguali a 5 e 2 numeri pari.");
	}
	return 0;
}
