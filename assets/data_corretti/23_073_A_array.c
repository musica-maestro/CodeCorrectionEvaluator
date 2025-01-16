/* SPECIFICA (max 1):......0.6
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2):...1.7
   TOTALE (10).............8.3
*/
/*Programma che verifica se in ogni tripla di elementi adiacenti, un elemento è multiplo
  di uno degli altri due
*SPECIFICA:
*INPUT: sequenza di interi //***** LA LUGHEZZA VA QUI -0.1 NELLA PRE-COND SCRIVI CHE LUNGHEZZA>0
*PRE COND: sequenza di interi (seq), lunghezza dell'array (lunghezza)
*OUTPUT: sequenza vale 1 se rispetta la proprietà, altrimenti 0
*POST COND: intero multiplo dei suoi adiacenti
//******** LA POST CONDIZIONE NON E' QUESTA -0.3
TIPO DI PROBLEMA: verifica universale */
#include <stdio.h>
int Multipli(int *seq, int lunghezza){
	int esiste=1;
	int i=0;
	while(i<lunghezza-2 && esiste){//******** CONDIZIONE INCOMPLETA mancano altre due combinazioni -1
		if(!((seq[i]%seq[i+1]==0)||(seq[i+1]%seq[i]==0)|| (seq[i+1]%seq[i+2]==0)||
			(seq[i+2]%seq[i+1]==0))){
			esiste=0;
		}
		else
			i++;
	}
	return esiste;
}
int main() {
	int lunghezza;
	printf("Ciao utente sono un programma che verifica se, data una sequenza di interi,\n");
	printf("esiste un elemento che e\' multiplo del suo adiacente. \n");
	printf("Quanti interi vuoi introdurre?\n");
	scanf("%d", &lunghezza);
	int seq[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Dammi un intero: \n");
		scanf("%d", &seq[i]);
	}
	if(Multipli(seq, lunghezza))
		printf("Esiste un elemento multiplo del suo adiacente\n");
	else
		printf("Non esiste un elemento multiplo del suo adiacente\n");
}      //**** NON E' CIO' CHE ERA STATO RICHIESTO! -0.3