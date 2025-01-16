/* SPECIFICA (max 1):......0.6
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......2.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............6.1
*/
// Tipo di problema: Verifica Universale

/* Specifica del Problema:


INPUT: Sequenza di numeri interi  //****** MANCA LA LUGHEZZA -0.2
PRE CONDIZIONI: Tutti gli elementi devono essere numeri interi
OUTPUT: Intero booleano 0 o 1 per verificare se la sequenza e ogni sua terna rispetta le post condizioni(1) oppure no(0)
POST CONDIZIONI: Ogni terna della sequenza deve avere elementi multipli adiacenti
//****** NON COMPLETA IL BOOLEANO E' 1 QUANDO... 0 ALTRIMENTI. -0.2

*/
#include <stdio.h>

void multipli(int sequenza[], int dimensione){

int verificaBooleana; // variabile intera per verifica la positività o negativa della istanza
int i; // variabile contatore
for(i = 0; i<dimensione;i++){ //***** dimensione -2 -1
	if((sequenza[i]%sequenza[i+1]==0) || (sequenza[i+1]%sequenza[i+2]==0) || (sequenza[i]%sequenza[i+2]==0)){
	//******* MANCANO ALTRE 3 CONDIZIONI -1
		verificaBooleana = 1;
	}else{
		verificaBooleana = 0; //******* COSI' RESTITUISCI IL RISULTATO DELL'ULTIMA TERNA VISTO CHE RIASSEGNI SEMPRE LA VAR BOOLEANA -1.5
	}
}

	if(verificaBooleana == 1){
		printf("Bene la tua sequenza ha tutte le terne per cui ciascuna ha multipli adiacenti! %d", verificaBooleana);

	}else if(verificaBooleana == 0){
		printf("Purtroppo non tutte le terne della tua sequenza hanno multipli adiacenti! %d", verificaBooleana);
	}
//***** LA STAMPA E' RICHIESTA NEL MAIN, NON NELLA FUNZIONE -1
}

int main(){

int dimensione; // dimensione array
printf("Utente, inserisci la dimensione della tua sequenza di interi: ");
scanf("%d",&dimensione);
int sequenza[dimensione];

// Assegno un valore ad ogni elemento dell'array
int i; // variabile contatore
for(i = 0; i<dimensione;i++){
printf("Digita %d valore della sequenza: ", i+1);
scanf("%d",&sequenza[i]);

}

// prendo i valori della sequenza e la sua dimensione come paramentri attuali
multipli(sequenza,dimensione);
}