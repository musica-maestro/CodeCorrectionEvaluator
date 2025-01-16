/* SPECIFICA (max 1):......0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......1.3
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............4.5
*/
/*

SPECIFICA

*Input: Grandezza array, array di interi

*Pre-condizione: La grandezza dell'array deve essere maggiore di 3

*Output: Deve restituirmi un valore 0 o 1 in base al responso della funzione

*Post-Condizione: se non esistono triple, stampa un messaggio di errore
//***** POSTCONDIZIONE NON CORRETTA -0.3

Il problema sottoposto è un problema di verifica esistenziale
*/



#include <stdio.h>


//funzione per definire il risultato della divisione
int restoDivisione(int *arr, int size){
if (size>=3){
	for (int i = 0; i < size; i++){ //***** i<size-2  -1

		if (arr[i]%arr[i+1]==arr[i+2] || arr[i+2]%arr[i+1]==arr[i]
			||arr[i+1]%arr[i]==arr[i+2] || arr[i+2]%arr[i]==arr[i+1]
			||arr[i+2]%arr[i+1]==arr[i] //**** MANCA UNA VERIFICA -0.5
             //*** QUESTA SI RIPETE -0.5
		 ){


			return 1;   //***** DUE RETUN NON E' PROGRAMMAZIONE STRUTTURATA  -0.5


		}
else {         //**** L'INDENTAZIONE -0.2
	return 0;
}   //**** IN QUESTO MODO ESCI DOPO IL PRIMO CONTROLLO, VERIFICHE SOLO LA PRIMA TRIPLA -2


	}

}

else
{
	printf("\nNon hai inserito una grandezza ammissibile, il programma si interrompe!\n");

}

}



//inizio main
int main(){
int i = 0;
int size = 0;


printf("Inserisci la grandezza dell'array\n");

scanf("%d", &size);

int arr[size];
//compilazione array

 printf("Ora inserisci i valori all'interno dell'array\n");
for ( i = 0; i < size; i++){

	scanf("%d", &arr[i]);
}


if(restoDivisione(arr,size)==1){


	printf("L'istanza ha un valore vero, esiste almeno  una terna di elementi adiacenti tali che uno dei tre è il resto della divisone degli altri tre");
}
else {
if (restoDivisione(arr,size)==0)
{
	printf("Non esiste nessuna tripla che soddisfa i requisiti"); //**** QUALI REQUISITI? -0.5
}


}


return 0;



}