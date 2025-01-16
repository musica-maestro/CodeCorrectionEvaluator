/* SPECIFICA (max 1.5):....1.2
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................10.7
*/
#include <stdio.h>
/*SPECIFICA:
 * input: sequenza s e intero l  //******** MANCA IL TIPO DEGLI ELEMENTI DELLA SEQUENZA -0.3
 * pre-condizioni: l>=3 rappresenta la lunghezza di s
 * output: valore intero booleano "compresi"
 * post-condizioni: compresi vale 1 se esiste una tripla di elementi consecutivi
 * tale che almeno due elementi della tripla hanno somma compresa fra
 * 10 e 20 compresi ed esattamente due elementi della tripla uguali fra loro, 0 altrimenti.
 * Problema: verifica esistenziale.
 * */

//funzione che riceve due interi e verifica che la loro somma sia compresa tra 10 e 20
int somma (int a, int b){
	return (a+b>=10 && a+b<=20);
}

/*funzione che restituisce un valore booleano "compresi"
 * che vale 1 se esiste una tripla di elementi consecutivi
 * tale che almeno due elementi della tripla hanno somma compresa fra
 * 10 e 20 compresi ed esattamente due elementi della tripla uguali fra loro, 0 altrimenti. */
 int ugualiCompresi (int array[], int lunghezza){
	 int i=0; //variabile contatore inizializzata
	 int compresi=0; //valore booleano inizializzato

	 //leggo la sequenza finchè il valore booleano non cambia o finisce la sequenza
	 while (!compresi && i<lunghezza-2){
		 //ne ho esattamente due uguali in una tripla di interi consecutivi?
		 if ((array[i]==array[i+1] && array[i]!=array[i+2]) ||
		 (array[i]==array[i+2] && array[i]!=array[i+1]) ||
		 (array[i+1]==array[i+2] && array[i]!=array[i+1])){
			 //almeno due nella tripla hanno una somma che varia tra 10 e 20 compresi?
			 if (somma(array[i], array[i+1]) || somma(array[i], array[i+2]) || somma(array[i+1], array[i+2])){
				 //se si finisce il ciclo
				 compresi = 1;
			 }
			 else
				 //se no vado avanti
				 i++;
		 }
		 else
			 //se no vado avanti
			 i++;

	 }
	 return compresi;
 }


//funzione principale
int main(int argc, char **argv)
{
	int l; //intero che rappresenta la lunghezza della sequenza
	printf("Ciao utente! sono un programma che verifica se in una sequenza di interi da te inserita (di almeno 3 numeri)\n");
	printf("esita una tripla di elementi consecutivi tale che almeno due elementi della tripla hanno somma compresa fra\n");
	printf("10 e 20 compresi ed esattamente due elementi della tripla uguali fra loro.\n");
	printf("Comincia dicendomi la lunghezza della tua sequenza: ");
	scanf("%d", &l); //richiedo lunghezza

	//se l'utente indica una lunghezza minore di 3 la richiedo
	while(l<3){
		printf("Mi dispiace ma devi inserire almeno 3 interi! Riprova: ");
		scanf("%d", &l);
	}

	int s[l]; //dichiaro la sequenza

	//leggo la sequenza
	printf("Ora dimmi gli elementi della sequenza\n");
	for (int i=0;i<l;i++)
		scanf("%d", &s[i]);

	if (ugualiCompresi(s, l)){
		printf("La tua sequenza contiene una tripla con esattamente due elementi uguali e con due elementi la cui somma %c compresa tra 10 e 20 inclusi!\n", 138);
	}
	else
		printf("La tua sequenza NON contiene una tripla con esattamente due elementi uguali e con due elementi la cui somma %c compresa tra 10 e 20 inclusi.\n", 138);

}
