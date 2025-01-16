/* SPECIFICA (max 1.5):....0.4
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9.9
*/
/* SPECIFICA:
 * Input: una sequenza s e un intero l //******** MANCA IL TIPO DEGLI ELEMENTI DELLA SEQUENZA -0.3
 * Pre-condizione: l è la lughezza di s
 * Output: un messaggio di stampa //******** OUTPUT DEVE RESTITUIRE UN BOOLEANO -0.5
 * Post-condizione: ciò che viene stampato dipende dal valore
 *                  booleano restituito dalla funzione "compresiMultipli3"
 //******** POST-CONDIZIONE DA SPECIFICARE -0.3
 * TIPO DI PROBLEMA: verifica esistenziale */

#include <stdio.h>

/*funzione che controlla se esiste\nuna tripla consecutiva di interi avente esattamente
* due multipli di 3 e almeno due interi compresi tra -10 e 10*/
int compresiMultipli3(int array[],int lungh)
{
	int trovato=0;      //valore che verrà restituito alla fine
	int multipli3=0;   //variabile per contare i multipli di 3 in una tripla
	int compresi=0;   //variabile per contare i valori compresi tra -10 e 10 in una tripla

	for(int i=0; i<lungh-2 && !trovato; i++){
		multipli3 = (array[i]%3==0)+(array[i+1]%3==0)+(array[i+2]%3==0);
		compresi = (array[i]<=10 && array[i]>=-10)+(array[i+1]<=10 && array[i+1]>=-10)+(array[i+2]<=10 && array[i+2]>=-10);
		/*se soddisfa la proprietà abbiamo trovato
		 * la nostra tripla */
		if((multipli3==2)&&(compresi==2 || compresi==3)){
			trovato=1;
		}
	}
	return trovato;
}


int main(int argc, char **argv)
{
	int lungh;
	/*chiedo all'utente il necessario per creare l'array */
	printf("Ciao, sono un programma che controlla se esiste\nuna tripla consecutiva di interi avente esattamente\ndue multipli di 3 e almeno due interi compresi tra -10 e 10\n");
	printf("Per prima cosa dimmi quanto e' lunga la tua sequenza: ");
	scanf("%d", &lungh);
	int array[lungh];
	for(int i=0; i<lungh;i++){
		printf("\nInserisci un valore: ");
		scanf("%d", &array[i]);
	}
	/*stampo il risultato in base ai due casi */
	if(compresiMultipli3(array,lungh)){
		printf("\nEsiste una tripla consecutiva di interi avente esattamente\ndue multipli di 3 e almeno due interi compresi tra -10 e 10!");
	}
	else{
		printf("\nNon esiste una tripla che soddisfa la proprieta' descritta.");
	}
}