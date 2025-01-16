/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
#include <stdio.h>
/*specifiche del problema:
	INPUT: una sequenza di interi da 1 a n;
	PRE-CONDIZIONI: almeno 3 interi n>=3;
	OUTPUT: tMulti, variabile booleana;
	POST-CONDIZIONI: tMulti è vera se per ogni terna consecutiva ci sia un numero che è multiplo di un'altro numero appartenenete alla terna, altrimenti è falsa

tipo di problema: verifica universale*/

/*funzione che prende come paramentro un array e un intero che rappresenta la lunghezza dell'array
 e restituisce una variabile booleana con un valore 1 o 0 se rispetta o meno le post-condizioni*/
int multipli(int a[], int l){
	int i; //variabile che indica la posizione del elemento nell'array
	int tMulti=1; //variabile boolena di ritorno della funzione inizializza a 1

	/*finchè i non arriva al terzultimo elemento ed tMulti è vera*/
	for(i=0; i<l-2 && tMulti; i++)

		//se esiste una tripla in cui non c'è nessun numero multiplo di un'altro tMulti è falsa
		if((a[i]%a[i+1]!=0&&a[i]%a[i+2]!=0)&&(a[i+1]%a[i]!=0&&a[i+1]%a[i+2]!=0)&&(a[i+2]%a[i]!=0&&a[i+2]%a[i+1]!=0))
			tMulti=0;

	return tMulti;
}

int main(){

	//INPUT
	int n; //numero di interi che inserisce l'utente
	int uscita=1; //variabile che indica se l'utente vuole inserire un'altra sequenza

	while(uscita){
		printf("Ciao utente, questo programma verifica se in una sequenza di interi ogni terna consecutiva di numero ci sia almeno un numero che e' multiplo di uno dei 2 numeri\n");
		printf("quanti numeri vuoi inserire ?\n");
		scanf("%d", &n);

		//verifica che l'utente inserisca almeno 3 interi
		while(n<3){
			printf("questo programma funziona se inserisci almeno 3 interi\n");
			printf("quanti numeri vuoi inserire ?\n");
			scanf("%d", &n);
		}

		int array[n]; //creo l'array

		//l'utente inserisci i numeri fino da 0 a n-1
		for(int i=0 ; i<n ; i++){
			printf("inserisci il %d%c numero : ", i+1, 167);
			scanf("%d", &array[i]);
		}
		/*invoco la funzione di verifica*/
		//OUTPUT
		if(multipli(array, n))
			printf("La sequenza contiene tutte terne consecutive in cui c'%c un numero multiplo dell'altro", 138);
		else
			printf("la sequenza non contiene per ogni terna consecutiva un numero multiplo di uno dei due numeri nella terna\n");

		printf("\nvuoi inserire un'altra sequenza ?\n");
		printf("-- digita 1 per 'si' oppure 0 per 'no' --\n");
		scanf("%d", &uscita);
	}
}