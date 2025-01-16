/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................8.5
*/
/* Algoritmo dove viene controllato se in una tripla di numeri consecuivi vi sono almeno
 * due elementi la cui somma e' compresa tra 10 e 20 e che in questa tripla vi siano due elementi uguali
 * Input: Sequenza interi e dimensione array
 * Pre-condizione: sequenza interi e' seq e dimensione array e' l
 * Output: 1 se la condizione e' verificata, 0 se non lo e'
											 //******** LA POST-CONDIZIONE MANCA -0.5
 * Tipo di problema:verifica esistenziale*/
#include <stdio.h>

/*Funzione ugualiCompresi che controllera' se in una tripla di una sequenza di interi vi sono almeno due elementi la cui somma
 * e' compresa tra 10 e 20 (inclusi estremi) e esattamente due elementi di essi siano uguali*/
int ugualiCompresi(int seq[], int l){
	int i=0;                //contatore per tenere l'ndice dell'elemento dell'array analizzato
	int ver=0;              //variabile ver che sarà il risultato della funzione
	while(i<l-1){           //controllo se vi siano almeno due elementi la cui somma e' compresa tra 10 e 20
	//******** NON USI LA VARIABILE BOOLEANA PER TERMINARE IL CICLO -1
		if((seq[i]+seq[i+1]>=10 && seq[i]+seq[i+1]<=20) || ((seq[i+1]+seq[i+2]>=10 && seq[i+1]+seq[i+2]<=20)) || (seq[i]+seq[i+2]>=10 && seq[i]+seq[i+2]<=20)){
			if((seq[i]==seq[i+1] && seq[i]!=seq[i+2]) || (seq[i+1]==seq[i+2] && seq[i+2]!=seq[i]) || (seq[i+2]==seq[i] && seq[i+2!=seq[i+1]])){//verifico se vi sono solo 2 elementi uguali
				ver=1;                          //nel caso entrambe le condizioni siano verificate la variabile ver sara' uguale a 1 e si interrompera' il ciclo
				break; //******** BREAK NON PERVENUTO! -0.5
			}
		}

		i++;
	}
	return ver; //restituisco il risultato
}
/* Funzione main che chiede all'utente l'inserimento della dimensione di una sequenza di interi e gli elementi al suo interno.
 * Dopodiché verifichera' invocando la funzione ugualiCompresi se la sequenza contiene una tripla la cui somma di almeno due numeri e' compresa tra 10 e
 * 20 e che solo 2 elementi di quella tripla siano uguali*/
int main()
{
	int l;            //variabile l che indichera' la lunghezza dell'array
	printf("Benvenuto\n");
	printf("Inserisci la lunghezza della sequenza di interi \n");
	scanf("%d",&l);       //chiedo la dimensione dell'array
	int seq[l];
	printf("Ora dovrai inserire i valori nella sequenza\n");
	int i=0;
	while(i<l){    //ciclo per inizializzare gli elementi dell'array
		printf("Inserisci un numero intero\n");
		scanf("%d",&seq[i]);
		i++;
	}
	int ver=ugualiCompresi(seq,l); //richiamo la funzione ugualiCompresi
	if(ver==1){                    //mando in output il risultato
		printf("Vi %c una tripla che soddisfa le condizioni\n",138); //******* OUTPUT MOLTO POVERO -0.5
	}
	else{
		printf("Non vi %c una tripla che soddisfa le condizioni\n",138);
	}
}
