/* SPECIFICA (max 1.5):....0.9
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................7.9
*/
#include <stdio.h>

/*INPUT:una sequenza s e la sua lunghezza//******** MANCANO I TIPI DEGLI ELEMENTI DELL'ARRAY-0.6
 *PRE_CONDIZIONI: l è la lumghezza di s >0
 *OUTPUT:un valore che rappresenta 1 o 0
 *POST_COMDIZIONI: vale 1 se esiste una tripla di elementi  consecutivi di cui
 * almeno due elementi siano compresi tra -10 e 10 e ci siano anche due elementi
 * multipli di 3. Vale 0 altrimenti
 *TIPO DI PROBLEMA: problema di verifica esistenziale*/



int compresiMultipli3(int seq[], int lunghezza)
{
	int i;
	int multipli;

	i=0;
	multipli=0;

	while(i<lunghezza-2 && !multipli){
		if(((seq[i]<=10 || seq[i]>=-10) && (seq[i+1]<=10 || seq[i+1]>=-10) && (seq[i+2]<=10 || seq[i+2]>=-10))
		//******** CONDIZIONE SBAGLIATA: || HA PRIORITA' MINORE DI && E LA CONDIZIONE SI LEGGE COME
		//********seq[i]<=10 || (seq[i]>=-10)&&(seq[i+1]<=10)  ||  (seq[i+1]>=-10)&&(seq[i+2]<=10 )  || seq[i+2]>=-10
		//******** ANCHE METTENDO LE PARENTESI NON SAREBBE CORRETTA. -2.5
		&&
 ((seq[i]%3==0 && seq[i+1]%3==0  && seq[i+2]%3!=0) || (seq[i]%3==0 && seq[i+2]%3==0 && seq[i+1]%3!=0)  || (seq[i+1]%3==0 && seq[i+2]%3==0 && seq[i]%3!=0)))

		multipli=1;
	else
			i++;
		}
	return multipli;


}



int main()
{
	int lunghezza;
	printf("ciao utente, questo %c un programma che verifica se in una tripla ", 138);
	printf("di interi ne esistono almeno due compresi fra -10 e 10 ");
	printf("ed esattamente due multipli di 3\n");
	printf("quanti interi vuoi inserire:");
	scanf("%d",&lunghezza);

	int sequenza[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("inserisci un intero:");
		scanf("%d", &sequenza[i]);
		}

	if(compresiMultipli3(sequenza, lunghezza))
		printf("\nEsistono almeno due numeri il cui valore %c compreso fra -10 e 10 e due il cui valore %c multiplo di 3", 138, 138);

		else
			printf("\nNon esistono almeno due numeri il cui valore %c compreso fra -10 e 10 e due il cui valore %c multiplo di 3", 138, 138);


}
