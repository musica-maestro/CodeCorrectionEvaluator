/* SPECIFICA (max 1.5):....0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................7.7
*/
#include <stdio.h>
/*SPECIFICA DEL PROBLEMA:
 * INPUT:la lunghezza di una esequenza
 * PRE-CONDIZIONE:una sequenza di interi
 * POST CONDIZIONE:controlla se ci sono due multipli di tre e due numeri compresi tra -10 e 10 //******** POST-CONDIZIONE NON CORRETTA (specificare) -0.3
 * OUTPUT: una stampa che informa l'utente se esiste //******** OUTPUT DEVE RESTITUIRE UN BOOLEANO -0.5
 *
 * TIPO DI PROBLEMA: verifica esistenziale
 */

/*funzione che verifica se all'intero di una tripla ci sono due interi compresi tra -10 e 10 e due multipli di tre*/
int compresiMultipli3(int array[], int lunghezza){
	int i=0;			//vatiabile contatore
	int trovato=0;			//inizializzazione variabili

	/*finchè non è finita la stringa*/
	while(i!=lunghezza && !trovato){ //******** CONDIZIONE SULL'INDICE ERRATA i<lugnhezza-2  -1.5
		/*la stringa rispetta le condizioni?*/
		if((array[i]>=-10 && array[i]<=10 && array[i+1]>=-10 && array[i+1]<=10 && array[i]%3==0 && array[i+1]%3==0 ||
			(array[i+1]>=-10 && array[i+1]<=10 && array[i+2]>=-10 && array[i+2]<=10 && array[i+1]%3==0 && array[i+2]%3==0)||
			(array[i]>=-10 && array[i]<=10 && array[i+2]>=-10 && array[i+2]<=10 && array[i]%3==0 && array[i+2]%3==0 )))
				trovato=1;
		//******** CONDIZIONE TROPPO RESTRITTIVA: NON DEVONO ESSERE NECESSARIAMENTE GLI STESSI DUE ELEMENTI
		//******** COMPRESI TRA -10 E 10 E MUTIPLI DI 3. NEL TUO CASO 6,12,8 SAREBBE UN'ISTANZA NEGATIVA -1


		/*altrimenti vai avanti*/
		else
			i++;
	}
	return trovato;
}


int main(int argc, char **argv)
{
	int lunghezza;
	printf("ciao utente! questo e' un programma che controlla se esiste una tripla di elementi tale che ci siano almeno due elementi compresi tra -10 e 10 e che ci siano due multipli di tre...\n");
	/*input*/
	printf("Inserisci pure la lunghezza della sequenza da ispezionare: \n");
	scanf("%d", &lunghezza);
	int array[lunghezza];  //dichiaro l'array
	printf("adesso puoi inserire gli interi...\n");
	/*ciclo per memorizzare gli interi nell'array*/
	for(int i=0; i<lunghezza; i++){
		printf("inserisci: ");
		scanf("%d", &array[i]);
	}
	/*output*/
	if(compresiMultipli3(array, lunghezza))
		printf("la tripla esiste!\n\n");
	else
		printf("la tripla non esiste...\n");


}
