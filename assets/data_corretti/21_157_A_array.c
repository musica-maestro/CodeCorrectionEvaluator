/* SPECIFICA (max 1.5):....1.3
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9.8
*/
#include <stdio.h>
/*SPECIFICA:
 * Input: una sequenza di l interi, l è la lunghezza
 * Pre-condizione: l è i numeri della sequenza sono interi, l>=0  //******** ESPRESSA UN PO' MALE -0.2
 * Output: una booleana trovata
 * Post-condizioni: trovata vale 1 se esiste una tripla di elementi consecutivi
 * tale che almeno due elementi della tripla hanno una somma compresa fra 10 e 20 (estremi inclusi), ed esattamente
 * due elementi della tripla sono uguali tra loro, 0 altrimenti
 * TIPO DI PROBLEMA: verifica esistenziale*/

/*funzione di verifica*/
int ugualiCompresi(int seq[], int l){
	/*l è la lunghezza dell'array*/

	/*dichiarazioni*/
	int i;			//variabile contatore
	int trovata;	//variabile di verifica esistenziale

	/*inizializzazioni*/
	i=0;			//primo elemento da guardare
	trovata=0;		//inizialmente nessuna tripla soddisfa la condizione

	/*fino a che non termina la sequenza o nessuna tripla soddisfa la condizione*/
	while(i<l-2 && !trovata){
		/*Almeno due elementi della tripla hanno una somma compresa fra 10 e 20? (prima condizione)*/
		if((seq[i]+seq[i+1]>=10 && seq[i]+seq[i+1]<=20) || (seq[i]+seq[i+2]>=10 && seq[i]+seq[i+2]<=20)
		|| (seq[i+2]+seq[i+1]>=10 && seq[i+2]+seq[i+1]<=20)|| (seq[i]+seq[i+1]+seq[i+2]>=10 && seq[i]+seq[i+1]+seq[i+2]<=20)){
															//******** CONDIZIONE ERRATA E INUTILE: CALCOLI LA SOMMA DI TUTTI E TRE GLI ELEMENTI DELLA TRIPLA  -1
			/*Ci sono esattamente due elementi uguali nella tripla(seconda condizione)?*/
			if((seq[i]==seq[i+1] && seq[i+2]!=seq[i] )|| (seq[i]==seq[i+2]  && seq[i+1]!=seq[i]) ||( seq[i+2]==seq[i+1] && seq[i]!=seq[i+1])){
				trovata=1;		//ho trovato una tripla che soddisfa la condizione
			}
			else
				i++;
		}
		else
			i++;
	}
	return trovata;
}
/*funzione principale*/
int main()
{
	int i;	//variabile contatore
	int lunghezza; 	//lunghezza della sequenza
	printf("Ciao sono un programma che verifica l'esistenza di una tripla di elementi consecutivi tale che almeno due elementi\n");
	printf("della tripla hanno una somma compresa fra 10 e 20 (estremi inclusi), ed esattamente due elementi uguali tra loro.\n");
	/*lettura della lunghezza della sequenza*/
	printf("Caro utente inserisci la lunghezza della sequenza:\n");
	scanf("%d",&lunghezza);

	/*dichiarazione array*/
	int sequenza[lunghezza];

	/*lettura della sequenza*/
	for(i=0; i<lunghezza; i++){
		printf("Caro utente inseriusci il %d%c elemento della sequenza:\n",i+1,167);
		scanf("%d", &sequenza[i]);
	}
	/*invocazione della funzione e output*/
	 printf("-------------------------------------------------------------------------------------------------\n");
	if(ugualiCompresi(sequenza,lunghezza)){
		printf("Esiste una tripla di elementi consecutivi tale che almeno due elementi della tripla hanno\n");
		printf("una somma compresa fra 10 e 20 (estremi inclusi), ed esattamente due elementi uguali tra loro\n. ");
	}
	else{
		printf("Non esiste una tripla di elementi consecutivi tale che almeno due elementi della tripla hanno\n");
		printf("una somma compresa fra 10 e 20 (estremi inclusi), ed esattamente due elementi uguali tra loro.\n ");
	}

}