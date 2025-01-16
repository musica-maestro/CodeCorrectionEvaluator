/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2
   TOTALE.................10.8
*/
/*SPECIFICA PROBLEMA
 * INPUT: UNA SEQUENZA DI INTERI x1,x2,...xn
 * PRE-CONDIZIONI: n è la dimensione della sequenza
 * OUTPUT:valore booleano  "ESISTE"
 * POST:CONDIZIONI:"ESISTE"  vale true se esiste almeno una tripla di elementi consecutivi che contiene
 * almeno due elementi il cui valore è compreso tra -10 e 10(estremi inclusi) e che contiene esattamente due elementi multipli  di tre, false altrimenti.*/
 /*TIPO DI PROBLEMA: VERIFICA ESISTENZIALE*/

#include <stdio.h>

/*funzione che verifica se esiste  una tripla di interi consecutivi che contiene
 * almeno due elementi il cui valore è compreso tra -10 e 10 e che contiene esattamente due elementi multipli  di tre */
 int compresiMultipli3(int seq[], int lunghezza){
	 //pre: lunghezza è lla lunghezza della sequenza

	 int i; //variabile contatore
	 int esiste; // variabile di esistenza
	 esiste=0; // all'inizio non abbaimo trovato alcuna tripla che soddisfa la proprietà richiesta

	 i=0;
	 /*processiamo la stringa fintanto che non abbiamo trovato alcuna tripla interessante*/
	 while(i<lunghezza-2 && !esiste){
		 if(((seq[i]>=-10 && seq[i]<=10 && seq[i+1]>=-10 && seq[i+1]<=10 )
		 ||(seq[i]>=-10 && seq[i]<=10 && seq[i+2]>=-10 && seq[i+2]<=10 )||
		 (seq[i+2]>=-10 && seq[i+2]<=10 && seq[i+1]>=-10 && seq[i+1]<=10 ))
		 && ((seq[i]%3==0 && seq[i+1]%3==0 && seq[i+2]%3!=0)||
		 (seq[i]%3==0 && seq[i+2]%3==0 && seq[i+1]%3!=0)
		 ||(seq[i+2]%3==0 && seq[i+1]%3==0 && seq[i]%3!=0)))
			 esiste=1;
			 else // altrimenti vai avanti
			 i++;
	 }
	 return esiste;
 }
 /*funzione principale*/
int main()
{
	int lunghezza;  // per la lunghezza della sequenza

	/*INPUT*/
	printf("Quanti interi vuoi inserire?");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];

	for(int i=0;i<lunghezza;i++){
		printf("Inserisci un intero: ");
		scanf("%d",&sequenza[i]);
	}

	/*OUTPUT*/
	if(compresiMultipli3(sequenza,lunghezza))
		printf("Esiste una tripla di interi consecutivi che soddisfa la proprieta'!");
		else
			printf("Non esiste alcuna tripla di interi consecutivi che soddisfa la proprieta'!");
}
//******** OUTPUT MOLTO POVERO -0.5