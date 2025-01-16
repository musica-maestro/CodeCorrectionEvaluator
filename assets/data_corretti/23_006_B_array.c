/* SPECIFICA (max 1):......0.3
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......2
   MAIN PROGRAM (max 2):...0
   TOTALE (10).............3.3
*/
//ESONERO DEL 2 MAGGIO 2023 - COMPITO B - ALESSANDRO BARILARO

/*Programma che, data una sequenza di interi, verifica se in ogni tripla di elementi adiacenti contiene esattamente due numeri positivi*/

/*SPECIFICHE DEL PROBLEMA
*PRE-CONDIZIONI: Una sequenza di n interi;
*DATI DI INPUT: Variabili booleane 0 e 1; //********* NO, NON CI SONO BOOLEANI IN INPUT -0.2
*POST-CONDIZIONI: Ogni tripla contiene esattamente due interi positivi;
*DATI DI OUTPUT: 1 se ogni tripla contiene esattamente due positivi, 0 altrimenti;
//******* CONFONDI PRE E POST CONDIZIONE -0.5

*TIPO DI PROBLEMA: Verifica universale*/

#include <stdio.h>

/*Funzione che restituisce 1 se in tutte le triple di elementi adiacenti della sequenza ci sono esattamente 2 numeri positivi, 0 altrimenti*/
int duePositivi(int interi[], int n){ //funzione che ha come parametri una sequenza e la sua lunghezza
int verificato; //variabile booleana
int i; //contatore
verificato==1; //****** verificato=1; -0.5
for(i=0; i<n-2; i++){
	if(interi[i]>0 && interi[i+1]>0 && interi[i+2]>0 && verificato)
		printf("Tutti gli interi da te inseriti sono positivi, inserisci un'altra sequenza!\n");
		verificato==0;
	if(interi[i]>0 && interi[i+1]>0 && interi[i+2]<0 && verificato)
		printf("Tutte le triple contengono esattamente due interi positivi|\n");
		verificato==1;
	if(interi[i]>0 && interi[i+1]<0 && interi[i+2]>0 && verificato)
		printf("Tutte le triple contengono esattamente due interi positivi\n");
		verificato==1;
	if(interi[i]<0 && interi[i+1]>0 && interi[i+2]>0 && verificato)
		printf("Tutte le triple contengono esattamente due interi positivi\n");
		verificato==1;  //****** STAMPA UN MESSAGGIO PER OGNI TERNA CHE ESAMINA! -2
}
return verificato;
} //******* IL TESTO RICHIEDE CHE LA STAMPA VENGA FATTA NEL MAIN, NON NELLA FUNZIONE  -1.5

/*Fuzione che gestisce l'interazione con l'utente*/
int main(){
int n; //lunghezza array
int interi[n];  //sequenza di interi  //******** PRIMA DI DICHIARARE L'ARRAY DEVI SAPERE QUANTO VALE n -0.5
int verificato; //variabile booleana

printf("Ciao utente, quanti interi vuoi introdurre?\n");
scanf("%d", &n);

for(int i=0; i<n; i++){
	printf("Inserisci i tuoi interi\n");
	scanf("%d", &interi[n]);  //******** interi[i] -0.5
}
duePositivi(interi, n)==verificato;  //******** L'ASSEGNAZIONE DEVE ESSERE AL CONTRARIO! -1
}
//PURTROPPO IL PROGRAMMA NON STAMPA NULLA, NON SONO RIUSCITO A PORTARLO A TERMINE