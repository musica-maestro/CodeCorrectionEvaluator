/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......2.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............6.3
*/
/*	SPECIFICA Data una sequenza di valori interi messi in input,
			  verificare che per ogni tripla di numeri adiacenti ci siano solamente due positivi.

	INPUT: Un'Array sequenza e i valori in esso contenuti; //******** MANCA IL TIPO DEGLI ELEMENTI -0.2
	PRE-CONDIZIONE: Array Sequenza >= 0;
	OUTPUT: Una variabile booleana Esiste;
	POST-CONDIZIONE: Se ogni tripla adiacente della sequenza presenta esattamente due numeri
					 positivi Esiste=1, altrimenti Esiste=0;

	TIPO DI PROBLEMA: Verifica Universale;
*/



#include <stdio.h>
/* FUNZIONE DUEPOSITIVI che analizza ogni tripla e assegna Esiste=1 se sono presenti sempre e solo due positivi*/
int duePositivi (int SequenzaBase[], int lunghezzaBase){
	int Esiste=0;  		//Variabile booleana di esistenza
	int Contatore=0;	//Contatore utilizzato per evitare che ci siano 3 numeri positivi

	//Incrementiamo il Contatore se due o tre numeri sono positivi
	for (int i=0; i<lunghezzaBase-2; i++){
		if ((SequenzaBase[i]>0 && SequenzaBase[i+1]>0)||(SequenzaBase[i]>0 && SequenzaBase[i+2]>0)||(SequenzaBase[i+1]>0 && SequenzaBase[i+2]>0))
			Contatore=1;
		else
			Contatore=0;
	}      //******** RESTITUISCI IL VALORE CALCOLATO SULL'ULTIMA TRIPLA -1.5

	//Eliminiamo i casi in cui tutti e tre i numeri siano positivi
	for (int i=0; i<lunghezzaBase-2; i++){
		if (SequenzaBase[i]>0 && SequenzaBase[i+1]>0 && SequenzaBase[i+2]>0)
			Contatore=0;
	}  //****** Contatore=0 ANCHE SE TROVI NUMERI NEGATIVI (CONTROESEMPIO: -1,-1,3,3,-1 RESTITUISCE VERO!)
	   //****** TROPPO COMPLICATO -2
	if (Contatore==1)
		Esiste=1;
	else
		Esiste=0;

	return Esiste;
}



/* FUNZIONE MAIN che interagisce con l'utente, in modo da scegliere la lunghezza della sequenza e i numeri che ne fanno parte */
int main (){
	int lunghezza;		//lunghezza dell'array che conterrà la sequenza

	printf("Salve Utente, quanti numeri verrano inseriti nella sequenza?   ");
	scanf("%d", &lunghezza);

	int Sequenza[lunghezza]; //Sequenza di numeri da analizzare
	for (int i=0; i<lunghezza; i++){
		printf("Inserisca un numero:  ");
		scanf("%d", &Sequenza[i]);
	}

	int Esiste=duePositivi(Sequenza, lunghezza); //Invocazione dell'altra funzione
	if (Esiste==1)
		printf("\nIn tutte le triple di elementi adiacenti della \nsequenza ci sono esattamente due positivi.\n");
	else
		printf("\nIn tutte le triple di elementi adiacenti della \nsequenza non ci sono esattamente due positivi.\n");
	printf("  Grazie.\n");
}