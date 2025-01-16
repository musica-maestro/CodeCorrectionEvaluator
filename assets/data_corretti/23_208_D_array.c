/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
/*SPECIFICA
	Input: Sequenza di interi x1...xn
	Pre-condizione: La sequenza deve essere composta da almeno 3 valori interi
	Output: variabile booleana "esiste"
	Post-condizione: "esiste" è true se nella sequenza di interi esiste una tripla di elementi adiacenti tale che uno dei tre è il resto della divisione degli altri due, altrimenti è false

	TIPO DI PROBLEMA: Verifica esistenziale
*/

#include <stdio.h>
/*Funzione che controlla tutte le terne di elementi e restituisce 0 o 1*/
int restoDivisione(int* interi, int lunghezza){

	int esiste=0;
	int i=0;

	while(i<lunghezza-2 && !esiste) {
		/*Calcolo il resto di ogni coppia di interi della terna e controllo se coincide con il terzo valore rimasto */
		if((interi[i]%interi[i+1]==interi[i+2]) ||
			(interi[i+1]%interi[i]==interi[i+2]) ||
			(interi[i]%interi[i+2]==interi[i+1]) ||
			(interi[i+2]%interi[i]==interi[i+1]) ||
			(interi[i+2]%interi[i+1]==interi[i]) ||
			(interi[i+1]%interi[i+2]==interi[i]))
			esiste=1;
		else
			i++;
	}

	return esiste;
}

int main(){

	int lunghezza;

	printf("Quanti interi vuoi inserire? \n");
	scanf("%d", &lunghezza);
	int interi[lunghezza];

	printf("Inserisci gli interi: \n");
	/*Ciclo per far inserire tutti gli interi all'utente*/
	for(int i=0; i<lunghezza; i++)
		scanf("%d", &interi[i]);

	/*Controllo se restoDivisione() mi restituisce 0 o 1 e comunico all'utente se esiste o meno la tripla di elementi cercata*/
	if(restoDivisione(interi, lunghezza))
		printf("Esiste nella sequenza inserita una tripla di elementi adiacenti tale che uno dei tre e' il resto della divisione degli altri due");
	else
		printf("Non esiste nella sequenza inserita una tripla di elementi adiacenti tale che uno dei tre e' il resto della divisione degli altri due");
}