/* SPECIFICA (max 1):......0.6
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.2
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............8.8
*/
/*specifica del problema
input: una sequenza s di interi e una lunghezza l
pre-condizione: la lughezza l è > 0
output: il programma prende una tripla di elementi e verifica se uno dei tre è il resto della divisione tra glòi altri due
post-condizione: viene restituito 1 se l'istanza è positiva, 0 se è negativa
//****** CONFONDI OUTPUT E POSTCONDIZIONE -0.4

tipo di problema: verifica esistenziale*/

#include <stdio.h>

int restoDivisione(int *v, int lunghezza){
	int risultato; //verifica l'esistenza della terna di numeri
	for(int i=0; i<lunghezza-2; i++){
		if((v[i]%v[i+1]==v[i+2]) || (v[i+1]%v[i]==v[i+2]) ||
		   (v[i]%v[i+2]==v[i+1])  || (v[i+1]%v[i+2]==v[i])  ||
		   (v[i+2]%v[i]==v[i+1])  || (v[i+2]%v[i+1]==v[i])){

			risultato= 1;
		}
	} if(risultato==1){
		return 1;

	}else{              //******** 2 RETURN NON E' PROGRAMMAZIONE STRUTTURATA -0.5
		risultato =0;   //******* A CHE SERVE SE POI RESTITUISCI DIRETTAMENTE 0? -0.3
		return 0;
	}

}

int main(){
	int lunghezza;
	printf("ciao utente inserisci la lunghezza della sequenza: \n");
	scanf("%d", &lunghezza);

	int v[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("inserisci un numero: \n");
		scanf("%d", &v[i]);
	}

	if(restoDivisione(v, lunghezza)){
		printf("esiste una terna di numeri adiacenti nella sequenza in cui uno dei tre e' il resto della divisione degli altri due");
	}else{
		printf("non esiste una terna di numeri adiacenti nella sequenza in cui uno dei tre e' il resto della divisione degli altri due");
	}
	return 0;
}
