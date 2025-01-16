/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................10.5
*/
/*SPECIFICA DEL PROBLEMA:
 * INPUT: una sequenza di interi e la sua lunghezza
 * PRE-CONDIZIONE:lunghezza>=3
 * OUTPUT:intero booleano
 * POST-CONDIZIONE: l'intero vale 1 se l'istanza è positiva, 0 se l'istanza è negativa //******** LA POST-CONDIZIONE NON DICE NULLA -0.5
 * TIPO DI PROBLEMA: verifica esistenziale*/

#include <stdio.h>

/*funzione ugualiCompresi: la funzione prende in input un'array e la sua lunghezza e verifica se esiste almeno una tripla di elementi consecutivi tale che almeno due elementi
 * della tripla hanno una somma compresa fra 10 e 20 (estremi inclusi) ed esattamente due elementi della tripla sono fra loro uguali; restituisce 1 quando l'istanza è positiva, 0 altrimenti*/
 int ugualiCompresi(int sequenza[], int lunghezza) {
	 int i=0;		//variabile contatore
	 int esiste=0;		//variabile da restituire in output

	 /*controlla gli elementi della sequenza finchè non trovo una tripla "buona"*/
	 while(i<lunghezza-2 && !esiste) {
		/*se la tripla contiene almeno due interi tale che la loro somma sia compresa tra 10 e 20, e due interi sono esattamente uguali*/
			if(((sequenza[i]+sequenza[i+1]>=10 && sequenza[i]+sequenza[i+1]<=20) || (sequenza[i]+sequenza[i+2]>=10 && sequenza[i]+sequenza[i+2]<=20) || (sequenza[i+1]+sequenza[i+2]>=10 && sequenza[i+1]+sequenza[i+2]<=20)) &&
			((sequenza[i]==sequenza[i+1] && sequenza[i+1]!=sequenza[i+2]) || (sequenza[i]==sequenza[i+2] && sequenza[i+2]!=sequenza[i+1]) || (sequenza[i+1]==sequenza[i+2] && sequenza[i+2]!=sequenza[i]))) {
				esiste=1; //allora hai trovato una tripla "buona"
			}
			else{
				i++; //se ancora non l'hai trovata, passa al successivo
			}
	 }
	 return esiste;
 }

/*funzione principale*/
int main() {
	int lunghezza;
	/*input: chiedi all'utente la lunghezza della sua sequenza*/
	printf("Caro utente, inserisci la lunghezza della tua sequenza d'interi: ");
	scanf("%d", &lunghezza); //memorizza la lunghezza

	/*inizializza la sequenza e chiedi all'utente di riempirla*/
	int sequenza[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Inserisci l'elemento numero %d: ", i+1);
		scanf("%d", &sequenza[i]);
	}
	printf("\n");

	/*output: invoca la funzione ugualiCompresi e informa l'utente del risultato*/
	if(ugualiCompresi(sequenza, lunghezza))
		printf("Bene, nella sequenza che hai inserito esiste una tripla di elementi consecutivi tale che almeno due elementi della tripla hanno somma compresa tra 10 e 20 (estremi compresi) ed esattamente due elementi sono fra loro uguali.\n");
	else
		printf("Spiacenti, nella sequenza che hai inserito nonesiste una tripla di elementi consecutivi tale che almeno due elementi della tripla hanno somma compresa tra 10 e 20 (estremi compresi) ed esattamente due elementi sono fra loro uguali.\n");
}
