/* SPECIFICA (max 1):......0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3
   MAIN PROGRAM (max 2):...1
   TOTALE (10).............5.7
*/
/* SPECIFICA
	* Input: una sequenza s e una lunghezza l.
	* Pre-condizione: Inserire almeno 3 valori per svolgere la verifica richiesta.
	* Output: esce un singolo valore: 1 (se è verificata) oppure 0 (se non è verificata).
	* Post-condizione: esce un singolo valore.
	//******** POST CONDIZIONE NON CORRETTA -0.3

	* Tipo di problema: verifica universale. */

#include <stdio.h>

// Funzione per i multipli
int multipli (int interi[], int lunghezza){
	int i;																									// Variabile contatore
	int multiplo=0;																							// Variabile multiplo e lo inizializzo a 0
	int m_1, m_2, m_3;																						// Casistiche per la moltiplicazione in una terna
	int risultato;																							// Indica se la condizione è rispettata o meno
	m_1=(interi[i-1])*(interi[i+1]);																		// Moltiplicazione tra il primo e il terzo valore della terna
	m_2=(interi[i])*(interi[i+1]);																			// Moltiplicaziome tra il secondo e il terzo valore della terna
	m_3=(interi[i])*(interi[i-1]);																			// Moltiplicazione tra il secondo e il primo valore della terna

	for (i=1; i<lunghezza; i++){//******** INDICE DELL'ARRAY FUORI DAI LIMITI, DEVE ESSERE i<lunghezza-1 -1
	//******** CONDIZIONE SBAGLIATA -1.5
		if ((interi[i]=m_1)||(interi[i-1]=m_2)||(interi[i+1]=m_3)){											// Condizione generale
			risultato=1;																					// La condizione è verificata
		}
		else{
			risultato=0;																					// La condizione non è verificata
		}
	//******** RESTITUISCI IL VALORE CALCOLATO SULL'ULTIMA TRIPLA -1.5
	}
	return risultato;

}

int main (){
	int lunghezza;																							// E' la lunghezza totale dell'array
	int interi;																								// Sono tutti i valori che compongono l'array
	int i;																									// Variabile contatore

	// INPUT
	printf("Caro utente, io verifico, in una terna di numeri, se ci sono multipli fra di loro");
	printf("Attenzione, inserisci almeno tre valori!");
	printf("Di quanti elementi vuoi che sia formato l'array?");
	scanf("%d", &lunghezza);

	do{
		int sequenza[lunghezza];//********** DICHIARI L'ARRAY NEL CICLO! -1
		for(int i=0; i<lunghezza; i++){
		printf("Inserisci un valore:");
		scanf("\n %d", &interi[i]);
		}
	} while (!(lunghezza>=3));																				// Entra nel ciclo solamente se l'utente ha inserito almento 3 valori per l'array

	if (multipli (interi, lunghezza)){
		printf("La sequenza introdotta riespetta la condizione, tutte le terne hanno un multiplo");
	}
	else{
		printf("La sequenza introdotta non riespetta la condizione, non tutte le terne hanno un multiplo");
	}
}