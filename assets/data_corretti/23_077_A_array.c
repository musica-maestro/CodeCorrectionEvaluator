/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
/*La funzione riceve un array e la sua lunghezza e verifica se se per ciascuna terna di elementi adiacenti ci sono
almeno un elemento della terna multiplo di uno degli altri due.

SPECIFCA:
Input: un valore intero n e una sequenza di interi
Pre-condizione: n>=3
Output: un valore booleano "tutti"
Post-condizione: un valore booleano "tutti": 1 se per ciascuna terna di elementi adiacenti della
sequenza ci sono almeno un elemento della terna multiplo di uno degli altri due;
0 altrimenti

TIPO DI PROBLEMA: VERIFICA UNIVERSALE
*/
#include<stdio.h>
int multipli(int *sequenza, int n){	//dalla funzione invocante prendo l'array e la sua lunghezza
	int tutti=1;					//variabile booleana di universalità inizializzata
	int i;							//contatore

	for(i=0;tutti&&i<n-2;i++)		//analizzo ogni tripla della sequenza e se tutti=1

		if(! ((sequenza[i]%sequenza[i+1]==0)+(sequenza[i]%sequenza[i+2]==0)+
		(sequenza[i+1]%sequenza[i+2]==0)+(sequenza[i+1]%sequenza[i]==0)+
		(sequenza[i+2]%sequenza[i]==0)+(sequenza[i+2]%sequenza[i+1]==0)  >=1) ) //******* più semplice scrivere if( (...+...+...)==0)
		/*Se non accade che nella terna di elementi adiacenti ci sono almeno un elemento della terna multiplo di uno degli
		altri due allora si pone la variabile di univeralità uguale a 0*/
			tutti=0;

	return tutti;
}
int main(){
	int n;							//lunghezza array
	int i;							//contatore

	//INPUT
	printf("Benvenuto! Sono un programma che data una sequenza di interi verifico se per ciascuna terna di elementi adiacenti ci sono almeno un elemento della terna multiplo di uno degli altri due.\nInserisci la lunghezza della tua sequenza: ");
	scanf("%d",&n);
	int sequenza[n];				//dichiarazione array
	for(i=0;i<n;i++){
		printf("Inserisci un valore: ");
		scanf("%d",&sequenza[i]);
	}

	//OUTPUT
	if(multipli(sequenza,n))
		printf("\nNella sequenza ciascuna terna di elementi adiacenti ha almeno un elemento multiplo di uno degli altri due.");
	else
		printf("\nNella sequenza NON accade che ciascuna terna di elementi adiacenti ha almeno un elemento multiplo di uno degli altri due.");

}