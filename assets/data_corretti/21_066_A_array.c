/* SPECIFICA (max 1.5):....1.2
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................10.7
*/
/*SPECIFICA
 *Input: una sequenza di valori "array" e un intero "Lunghezza".  //******** MANCA IL TIPO DEGLI ELEMENTI DELLA SEQUENZA -0.3
 * Pre-condizioni: Lunghezza è la lunghezza dell'array, Lunghezza>2
 * Output: un intero "Risultato" di valore 1 o 0
 * Post-condizioni: "Risultato" assume il valore "1" e restituisce un messaggio positivo
 * se in almeno una tripla di valori consecutivi esistono almeno due valori
 * la cui somma sia compresa tra 10 e 20 e esattanente due valori sono uguali,
 * assume valore "0" e restituisce un messaggio negativo altrimenti.
 * TIPO DI PROBLEMA: verifica esistenziale
 */

 #include <stdio.h>

int ugualiCompresi(int array[], int n){
	//dichiarazioni
	int i; //variabile di scorrimento dell'array
	int Risultato; //variabile di risultato dell'istanza

	//inizializzazione
	Risultato=0; //******** I NOMI DELLE VARIABILI INIZIANO CON LA MINUSCOLA PER CONVENZIONE!

	//inizio ciclo di verifica
	for(i=0; (i<n-2)&&Risultato==0; i++){
		//cerco innanzitutto che nella tripla di valori valutata ce ne siano esattamente due uguali
		if((array[i]==array[i+1]&&array[i]!=array[i+2])
		||(array[i]==array[i+2]&&array[i]!=array[i+1])
		||(array[i+1]==array[i+2]&&array[i]!=array[i+1])){
			//se è verificato controllo che la somma di due valori sia compresa tra 10 e 20
			if((array[i]+array[i+1]>=10)&&(array[i]+array[i+1]<=20)
			||(array[i]+array[i+2]>=10)&&(array[i]+array[i+2]<=20)
			||(array[i+2]+array[i+1]>=10)&&(array[i+2]+array[i+1]<=20)){
			Risultato=1;
			}
		}
	}
return Risultato;}
int main(int argc, char **argv)
{
	//dichiarazioni
	int Lunghezza; //lunghezza dell'array
	int Risultato; //risultato dell'istanza

	//input
	printf("buongiorno utente, sono un programma che legge una sequenza di valori\n");
	printf("e ti dice se in almeno una tripla di valori consecutivi si verificano le sequenti condizioni:\n");
	printf("-la somma di almeno due di quegli elementi e' compresa tra 10 e 20\n");
	printf("-esattamente due di questi elementi sono uguali tra loro\n");
	printf("bene, quanti valori devo valutare?\n");

	//acquisisco Lunghezza
	scanf("%d", &Lunghezza);

	//creo l'array
	int array[Lunghezza];

	for(int i=0; i<Lunghezza; i++){
		printf("bene, quale e' il tuo valore %d di %d?\n", i+1, Lunghezza);
		scanf("%d", &array[i]);
	}

	Risultato=ugualiCompresi(array, Lunghezza);

	if(Risultato==1)
		printf("esiste almeno una tripla di valori con le caratteristiche desiderate!\n");

	if(Risultato==0)
		printf("non esiste nessuna tripla di valori con le caratteristiche deriderate!\n");
	return 0;
}
