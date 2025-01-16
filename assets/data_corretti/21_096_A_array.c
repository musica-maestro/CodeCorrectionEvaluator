/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................7.5
*/
#include <stdio.h>
/*SPECIFICA:
 * INPUT:un sequenza di interi 'sequenza' e un intero 'lunghezza'
 * Pre-condizione: 'lunghezza' è la dimensione della sequenza
 * OUTPUT: un intero 'contiene'
 * Post-condizione: 'contiene' restituisce 1 se nella sequenza è presente una tripla di elementi consecutivi tale che due elementi
 * della tripla hanno somma compresa fra 10 e 20 ed esattamente due elementi della tripla sono uguali fra di loro
 * Tipo di problema: Verifica Esistenziale
 */

 /* funzione che riceve come parametro un array di interi(e la sua lunghezza) e verifica se nella sequenza
  * esiste una tripla di elementi consecutivi tale che la somma di almeno due lementi è compresa tra 10 e 20
  * ed esattamente due elementi sono uguali */
 int UgualiCompresi(int seq[],int l) {

/* l è la dimensione della sequenza */

int contiene; /* variabile di esistenza */
contiene=0;

int i; /* variabile contatore */
i=0;

while(i<l-2 && !contiene)  {
	/*è soddisfatta la proprietà?*/
	if((10<seq[i]+seq[i+1]<20 || 10<seq[i]+seq[i+2]<20 || 10<seq[i+1]+seq[i+2]<20)
	//******** QUESTA ESPRESSIONE NON ESPRIME "ESSERE COMPRESO TRA"
	//******** A PARTE CHE DOVREBBE ESSERE 10<=seq[i]+seq[i+1]<=20
	//******** MA IL C CALCOLA ALTRO (((10<=seq[i])+ seq[i+1]) <=20) -1.5
	&& (seq[i]==seq[i+1] || seq[i]==seq[i+2] || seq[i+1]==seq[i+2]))
//******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO UGUALI ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
//******** ES. se la tripla e' 5 5 5 LA TUA CONDIZIONE E' SODDISFATTA  -1.5

		contiene=1;
		else
			i++; /* passa al prossimo */
			}
			return contiene;
			}

/* funzione principale */
int main()
{
	int lunghezza; /* variabile che indica la dimensione della sequenza */
	printf("Salve utente, sono un programma che riceve una sequenza di elementi e verifica che nella sequenza esiste una tripla di elementi consecutivi\n");
	printf("tale che almeno due elementi della tripla hanno somma compresa fra 10 e 20 ed esattamente due elementi della tripla sono uguali.\n");
	printf("Da quanti elementi %c composta la sequenza?\n",138);
	scanf("%d",&lunghezza);
	int sequenza[lunghezza];
	for(int i=0;i<lunghezza;i++) {
		printf("Inserisci l'elemento n.%d: ",i+1);
		scanf("%d",&sequenza[i]);
		}
		/* invoca la funzione UgualiCompresi */
		int UgualiCompresi(sequenza,lunghezza); //******** QUESTA ISTRUZIONE NON SERVE A NIENTE, LA FUNZIONE LA INVOCHI DOPO -0.5

		/* OUTPUT */
		if(UgualiCompresi(sequenza,lunghezza)) {
			printf("Nella sequenza esiste una tripla di elementi consecutivi tale che la somma di almeno due elementi della tripla\n");
			printf("%c compresa tra 10 e 20 ed esattamente due elementi della tripla sono uguali.\n",138); }
			else {
				printf("Nella sequenza non esiste una tripla di elementi consecutivi tale che la somma di almeno due elementi della tripla\n");
			printf("%c compresa tra 10 e 20 ed esattamente due elementi della tripla sono uguali.\n",138); }

	}
