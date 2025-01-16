/* SPECIFICA (max 1):......0 //**** MANCA
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............7
*/
#include <stdio.h>

/* data una sequenza di interi positivi, ogni tripla di elementi adiacenti devono essere composte da almeno 2 interi con 1 cifra */

/* verifica universale */

int dueUnaCifra(int seq[], int lunghezza){
	/* condizioni di validita', possono essere compresse con OR ||, se valide, non cambia 'valido'
	   possono essere ribaltate con un NOT ! con gli appropriati cambiamenti */
	for(int i=0; i<lunghezza-2; i++){
		if(seq[i]<10 && seq[i+1]<10) ; //******** 3 PARTI IF MACANTI (MOLTO BRUTTO) -1.5
		else if(seq[i]<10 && seq[i+2]<10) ;
		else if(seq[i+1]<10 && seq[i+2]<10) ;
		else return 0;								//se le condizioni non sono confermate, esce dal for e ritorna 0
	}

	return 1;  //******** 2 RETURN NON E' PROGRAMMAZIONE STRUTTURATA -0.5
}

int main(){
	printf("Questo programma richiede una sequenza di numeri positivi. \n");
	printf("Quanto e' lunga la tua sequenza? ");
	int lunghezza;
	scanf("%d", &lunghezza);
	int seq[lunghezza];

	/* Input sequenza di numeri */
	for(int i=0; i<lunghezza; i++){
		printf("Dammi un numero: ");
		scanf("%d", &seq[i]);
	}

	/* Condizione di positivita' */
	int positive=1;
	for(int i=0; i<lunghezza && positive==1; i++){
		if(seq[i]<0) positive=0;
	}

	if(positive==1){
		if(dueUnaCifra(seq, lunghezza)==1) printf("Complimenti! In tutte le triple di elementi adiacenti ci sono almeno due numeri a singola cifra. \n");
		/* meglio con un else, ma preferisco esplicitarlo solo a scopo di esame */
		if(dueUnaCifra(seq, lunghezza)==0) printf("Peccato! Non in tutte le triple di elementi adiacenti ci sono almeno due numeri a singola cifra. \n");
	}
	else printf("Errore: La tua sequenza ha almeno un numero negativo \n");		//errore autoesplicativo

	return 0;
}