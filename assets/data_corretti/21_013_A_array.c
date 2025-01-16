/* SPECIFICA (max 1.5):....0.5
   TIPO PROBLEMA (max 1):..0  //******* MANCA
   FUNZIONE (max 6):.......4.2
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................7.2
*/
#include <stdio.h>
/*Specifica
 * il programma analizza le triple consecutive e verifica se esistono almeno due valori uguali e due valori la cui somma e' compresa tra 10 e 20
 * INPUT: sequenza di numeri "numeri" e la sua lunghezza "lung"
 * PRE: numeri tipo int e lung tipo int
 * OUTPUT: messaggio di stampa //******** OUTPUT DEVE RESTITUIRE UN BOOLEANO -0.5
 * POST: risultato boolean 1 se esiste la terna, 0 se non esiste la terna  */
//******** LA POST-CONDIZIONE NON DICE NULLA -0.5
/*funzione*/


int ugualiCompresi (int sequenza[], int lunghezza) {
	int risultato=0;
	for (int i=0; i<lunghezza-2 && risultato==0;i++) {
		//condizione che verifica l'esistenza nella terna di due numeri uguali e due numeri la cui somma e' compresa tra 10 e 20
		if ((sequenza[i]==sequenza[i+1] || sequenza[i]==sequenza[i+2] || sequenza[i+1]==sequenza[i+2])
		//******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO UGUALI ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
		//******** ES. se la tripla e' 5 5 5 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
		&& ((sequenza[i]+sequenza[i+1]>10 && sequenza[i]+sequenza[i+1]<20) || (sequenza[i]+sequenza[i+2]>10 && sequenza[i]+sequenza[i+2]<20) || (sequenza[i+1]+sequenza[i+2]>10 && sequenza[i+1]+sequenza[i+2]<20)))
			//******** ESTREMI INCLUSI -0.3
		risultato=1; //se verificata
		else
			risultato=0; // se non verificata
		//******** EVITA DI ASSEGNARE NUOVAMENTE LA VARIABILE AL VALORE INIZIALE!
		}

	return risultato;

}




int main(int argc, char **argv)
{
	int lung; //lunghezza sequenza numerica
	int ris;  //risultato booleano
	printf("Inserisci la dimensione della sequenza \n");
	scanf ("%d", &lung);
	int numeri[lung]; //dichiarazione array
	//ciclo di riempimento dell'array
	for(int i=0;i<lung;i++) {
		printf("Inserisci il valore %d\n", i+1);
		scanf("%d", &numeri[i]);
	}
	ris =  ugualiCompresi(numeri, lung); //viene richiamata la funzione ugualiCompresi
	//viene valutato il valore restituito dalla funzione
	if (ris==1)
		printf("esiste una tripla con almeno due elementi uguali e con almeno due elementi la cui somma e' compresa tra 10 e 20 \n");
	else
		printf("non esiste una tripla con almeno due elementi uguali e con almeno due elementi la cui somma e' compresa tra 10 e 20 \n");

}
