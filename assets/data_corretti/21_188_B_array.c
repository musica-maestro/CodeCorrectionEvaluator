
/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................10.5
*/
#include <stdio.h>

int isPari(int i){
	return i%2==0;
}
int maggiore5(int i){
	return i>=5;
}
/*funzione che restituisce 1 se ogni tripla della seq è composta da esatt. due elementi >=e e almeno due elementi pari e 0 altrimenti*/
int maggiore5Pari(int seq[ ], int lunghezza) {
	int i;                //indice array
	i=0;                 //inizializzo l'indice al primo elemento della seq.
	int ogniTripla=1;   //inizialmente tutte le triple soddisfano la proprieta'

	while(i<lunghezza-2 && ogniTripla) {   //fintanto che la seq non e' terminata e le triple soddisfano la proprieta'
		if((maggiore5(seq[i]) && maggiore5(seq[i+1]) && !(maggiore5(seq[i+2])) )
		|| (maggiore5(seq[i]) && maggiore5(seq[i+2]) && !(maggiore5(seq[i+1])))
		|| (maggiore5(seq[i+1]) && maggiore5(seq[i+2]) && !(maggiore5(seq[i])))) {
           if((isPari(seq[i]) && isPari(seq[i+1])) || (isPari(seq[i]) && isPari(seq[i+2])) || (isPari(seq[i+1]) && isPari(seq[i+2])))
              i++;         //passo all'elemento successivo perchè la tripla appena esaminata soddisfa la proprieta'
		}
		else
			ogniTripla=0;   //ho trovato una tripla che non soddisfa la proprieta'
	}

	return ogniTripla;

 }
 /*programma che chiede all'utente di inserire una sequenza di interi e verifica se ogni tripla ha esatt. 2 elementi>=5 e almeno due elementi pari*/
 /*SPECIFICA:
  * input:  una sequenza di interi e la sua lunghezza l
  * precondizione: l>=0
  * output: variabile booleana 'ogniTripla'
  * postcondizione: ogniTripla =1 se ogni tripla della seq. soddisfa la proprieta' e =0 altrimenti
  * tipo di problema: verifica universale*/   //******** LA POST-CONDIZIONE NON DICE NULLA (QUALE PROPRIETA'?) -0.5

int main(){
	int l; //lunghezza della sequenza;
	/*acquisisco la lunghezza della seq, dall'utente*/
	printf("Ciao!Di quanti numeri %c composta la tua sequenza?\n",138);
	scanf("%d",&l);
	int sequenza[l];  //dichiaro l'array
	/*acquisisco gli elementi della seq, dall'utente*/
	for(int i=0;i<l;i++) {
		printf("Inserisci l'intero:\n");
		scanf("%d",&sequenza[i]);
	}
	/*verifico se la seq. rispetta la proprieta' per ogni tripla*/
	int ogniTripla=maggiore5Pari(sequenza,l);
	/*output*/
	if(ogniTripla==1)
		printf("Bene! In ogni tripla della tua sequenza almeno due elementi sono pari ed esattamente due maggiori o uguali di 5.\n");
	else
		printf("Mi dispiace ma nella tua sequenza non in tutte le triple esattamente due elementi sono maggiori o uguali a 5 e almeno due pari.\n");


}
