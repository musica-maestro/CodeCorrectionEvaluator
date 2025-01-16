/* SPECIFICA (max 1):......0.6
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.1
*/
/*SPECIFICA
*Input:Una sequenza di interi //******** MANCA LA LUNGHEZZA -0.2
*Pre-condizione:la sequenza deve essere formata da almeno 3 interi//******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
*Output:valore 1 o 0
*Post-condizione:il valore è 1 se in tutte le triple di elementi adiacenti
sono presenti almeno due numeri composti da una sola cifra, altrimenti 0
*TIPO DI PROBLEMA: verifica universale*/

#include <stdio.h>

/*funzione che restituisce 1 se in tutte le triple di elementi
*adiacenti della sequenza son presenti almeno due numeri composti
*da una sola cifra, altrimenti 0*/
int dueUnaCifra(int interi[], int lunghezza){
	int risultato=1;		//vale 1 se estistono almeno 2 interi con una sola cifra,
							//0 altrimenti
	/*se la lunghezza è minore di 3 non si fa niente*/
	if (lunghezza>3){
		/*leggo gli interi*/
		for(int i=0; i<lunghezza-2; i++){
			/*se almeno due numeri hanno una sola cifra, ovvero minore o uguali a 9*/
			if (!((interi[i]<=9 && interi[i+1]<=9)||(interi[i]<=9 && interi[i+2]<=9)
				||(interi[i+2]<=9 && interi[i+1]<=9)) && risultato) //&& risultato VA NELLA CONDIZIONE DEL FOR, NON QUI -0.5
				risultato=0;
		}
	}
	return risultato;
}
/*funzione principale*/
int main ( ) {
	int lunghezza;
	printf("Sono un programma che verifica se in una tripla\n");
	printf("ci sono almeno due numeri con una sola cifra\n");
	printf("Per iniziare, quanto vuoi che sia lunga la sequenza: ");
	scanf("%d", &lunghezza);

	int sequenza[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Inserisci l'intero dell'indice %d: ", i);
		scanf("%d", &sequenza[i]);
	}
	/*invoco funzione*/
	int risultato=dueUnaCifra(sequenza, lunghezza);

	if (risultato==0)
		printf("La sequenza non contiene almeno 2 numeri con una sola cifra in ogni tripla\n");
	else
		printf("La sequenza contiene almeno 2 numeri con una sola cifra in ogni tripla\n");
}