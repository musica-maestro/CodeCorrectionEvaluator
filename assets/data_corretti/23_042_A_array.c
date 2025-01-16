/* SPECIFICA (max 1):......0.6
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.6
*/
/*Verificare se in tutte le terne consecutive di numeri ci sia almeno un elemento che
è multiplo di uno degli altri due*/
/* SPECIFICA
* Input: Una sequenza "sequenza" di "n" elementi //***** MANCA IL TIPO DEGLI ELEMENTI -0.2
* Pre-condizione: n>=0
* Output: una variabile booleana "multiplo"
* Post-condizione: Multiplo vale "1" se la condizione è verificata, 0 altrimenti
//******* DEVI ESPRIMERE LA CONDIZIONE -0.2
* Tipo di problema: Verifica universale
*/

#include <stdio.h>

int condizione(int a,int b,int c){		//Funzione che indica se nella terna ci sta un numero multiplo di un'altro
	int verificato=0;
	if(a%b==0 || a%c==0 || b%a==0 || b%c==0 || c%a==0 || c%b==0)
		verificato=1;
	return verificato;
}

int multipli(int *array,int lunghezza){		//Funzione che verifica se in tutte le terne adiacenti ci sta almeno un elemento multiplo di un'altro
	int multiplo=1; //variabile booleana
	for(int i=0;i<lunghezza-2;i++){
		if(!condizione(array[i],array[i+1],array[i+2]))
			multiplo=0;
	}
	return multiplo;
}

int main(){
	/*Input*/
	int n;
	printf("Inserisci una sequenza di elmenti e ti dirò se in ogni terna di elementi adiacenti ci sta almeno un elemento che %c multiplo degli altri due \n",138);
	printf("Quanti elementi vuoi inserire?: ");
	scanf("%d",&n);
	int sequenza[n];
	//Iniziaizzo l'array di "n" elementi
	for(int i=0;i<n;i++){	//Inserisco gli elementi nel vettore
		printf("Inserisci l'elemento di posizione [%d] della sequenza: ",i);
		scanf("%d",&sequenza[i]);
	}
	/*Output*/
	if(multipli(sequenza,n))
		printf("Nella sequenza di elementi tutte le terne adiacenti hanno almeno un elemento multiplo di uno degli altri due\n");
	else
		printf("Nella sequenza di elementi non tutte le terne adiacenti hanno almeno un elemento multiplo di uno degli altri due\n");
}