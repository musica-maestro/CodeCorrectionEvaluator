/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.8
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.8
*/
/* SPECIFICA
* Input: sequenza di n numeri interi
* Pre-condizione: n è la lunghezza della sequenza
* Output: 'verifica' variabile booleana
* Post-condizione: 'verifica' assume valore 1 se per ogni terna di elementi adiacenti nella sequenza c'è almeno un elemento che è multiplo di un  degli altri due, 0 altrimenti
* TIPO DI PROBLEMA: VERIFICA UNIVERSALE */
#include<stdio.h>

int proprietà(int a[], int ind){
	return (a[ind]%a[ind+1]==0 || a[ind]%a[ind+2]==0 || a[ind+1]%a[ind]==0 || a[ind+1]%a[ind+2]==0 || a[ind+2]%a[ind]==0 || a[ind+2]%a[ind+1]==0);
}

int multipli(int array[], int dimensione){
	int i; //variabile per scorrere gli indici
	int check=1; //dichiarazione e inizializzazione a true della variabile booleana

	for(i=0;i<dimensione-2 && check;i++){

		/*per ciascun elemento verifichiamo la proprietà che vi sia un multiplo di uno degli altri due elementi*/
		if(proprietà(array, i)==0) //****** à NON E' UN CARATTERE ASCII -0.2
			check=0;
	}
	return check;

}
int main(){
	int lunghezza; //dimensione della sequenza
	int i;  //variabile contatore per scorrere gli indici
	int verifica;  //variabile booleana

/* Input */
	printf("Ciao utente, quanti interi desideri introdurre nella tua sequenza? ");
	scanf("%d", &lunghezza);

	int sequenza[lunghezza];

	/*realizziamo la sequenza*/
	for(i=0;i<lunghezza;i++){
		printf("\nAdesso inserisci l'elemento %d: ", i+1);
		scanf("%d", &sequenza[i]);
	}

	verifica=multipli(sequenza, lunghezza);

/* Output */
	if(verifica)
		printf("\nAllora utente, in tutte le terne di elementi adiacenti della sequenza %c presente almeno un elemento multiplo degli altri due!", 138);
	else
		printf("\nAllora utente, almeno in una terna di elementi adiacenti della sequenza non %c presente almeno un elemento multiplo degli altri due!", 138);

}