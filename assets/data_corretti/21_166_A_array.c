/* SPECIFICA (max 1.5):....1.4
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......1.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................6.4
*/
#/* SPECIFICA
 * Input: Inserire il numero di interi e gli interi contenuti nella sequenza //******** NON DEVI DIRE "INSERIRE" -0.1
 * Pre-condizione: La sequenza deve avere elementi esclusivamente numerici
                   e ci devono essere almeno 3 interi
 * Output: Stampare 1 se la sequenza ha almeno due elementi che sommati fra loro
		   hanno una somma compresa fra 10 e 20 e contiene esattamente due elementi
		   uguali fra loro.
 *Tipo di Problema: Verifica Esistenziale
 */

 #include <stdio.h>

 /* Programma che data una sequenza di interi verifica se esiste una tripla di elementi consecutivi
    tale che almeno due elementi della tripla sono fra loro uguali e che almeno due elementi della
	tripla abbiano una somma compresa fra 10 e 20 */

 int ugualiCompresi(int interi[], int lunghezza) {
	 int i; //Variabile contatore
	 int sommaCompresa; //Valore della somma compresa fra 10 e 20
	 int dueUguali; //Valore dell'uguaglianza
	 int proprietà = 0; //Indicatore della proprietà

	 /* Inizializzazione */
	 sommaCompresa = 0; //Valore iniziale prima del riscontro di un elemento valido
	 dueUguali = 0; //Valore iniziale prima del riscontro di un elemento valido

	 /* Inizia a guardare i numeri */
	 for(int i=0; i<lunghezza; i++) { //******** NON USI LA VARIABILE BOOLEANA PER TERMINARE IL CICLO -1
		/* Cerca due numeri nella tripla uguali fra loro*/
		if(interi[i]==interi[i+1] || interi[i]==interi[i+2] || interi[i+1]==interi[i+2])
			dueUguali = 1;
		//******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO UGUALI ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
		//******** ES. se la tripla e' 5 5 5 LA TUA CONDIZIONE E' SODDISFATTA  -1.5

		/* Verifica che due numeri consecutivi nella tripla abbiano una somma fra 10 e 20 */
		if(10 <= (interi[i] + interi[i+1] || interi[i+1] + interi[i+2]) <= 20)
			sommaCompresa = 1;
		//******** CONDIZIONE ERRATA -2 (vuoi esprimere che la somma dei primi due o del secono e terzo
		//******** è compresa tra 10 e 20? non si esprime così in C. Inoltre manca il controllo tra i primo e il terzo elemento
	 }
		/* Se entrambe le verifiche risultano positive cambia il valore di proprietà */
		if(sommaCompresa==1 && dueUguali==1)
			proprietà = 1;


	 return proprietà;
 }

 /* Funzione principale che permette all'utente di inserire i dati dell'array e
    stampa un messaggio di comunica */

	int main() {
		int lunghezza; //Valore dell'array che deve inserire l'utente
		int proprietà = 0; //Valore che rappresenta se la proprietà è soddisfatta

		/* Input */
		printf("Caro utente sono un programma che una volta inserita una tripla");
		printf("stampa 1 se ci sono almeno due elementi uguali e due hanno una ");
		printf("somma compresa fra 10 e 20 altrimenti stampo 0\n");
		printf("Dichiara la lunghezza del tuo array");
		scanf("%d", &lunghezza);

		/* Crea Array */
		int interi[lunghezza];
		for(int i=0; i<lunghezza; i++) {
			printf("Inserisci il %d numero del tuo array", i+1);
			scanf("%d", &interi[i]);
		}

		/* Invoca funzione */
		proprietà = ugualiCompresi(interi, lunghezza);

		/* Output */
		if(proprietà==1)
			printf("Caro utente nel tuo array ci sono due elementi uguali consecutivi e almeno due hanno una somma compresa fra 10 e 20!");
		else
			printf("Caro utente, nel tuo array non ci sono due elementi consecutivi e nessuno sommato ad un altro ha una somma fra 10 e 20!");
	}





