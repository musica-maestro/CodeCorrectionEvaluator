/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................10
*/
/*SPECIFICA
 * INPUT l,array di tipo int
 * Pre-condizioni: l √® la lunghezza dell'array,l>2
 * OUTPUT: variabile esiste(variabile booleana)
 * Post-condizioni: esiste vale 1 se  data una tripla di interi
 * esistono esattamente 2 elementi uguali tra loro e almeno due elementi
 * della tripla hanno somma compresa tra 10 e 20, vale 0 altrimenti.
 * TIPO DI PROBELMA:.. problema di verifica esistenziale*/
#include <stdio.h>


/*Funzione che  data una sequenza di interi verifica se
 *esiste una tripla in cui vi sono esattamente 2 elementi uguali tra loro
 *e almeno due elementi della tripla hanno somma compresa tra 10 e 20*/
int ugualiCompresi(int array[],int l){
	int esiste=0;//variabile booleana per la verifica della propriet√
	int i;//contatore
	i=1;//inizializzazione
	while(i<l-1&&!esiste){
		/* se la condizione viene soddisfatta esci dal ciclo e esiste diventa vera*/
		if(((array[i]==array[i+1])&& (array[i]+array[i+1]>=10 && array[i]+array[i+1]<=20)&&(array[i]!=array[i-1]))
			||((array[i-1]==array[i+1])&&(array[i-1]+array[i+1]>=10 && array[i-1]+array[i+1]<=20)&&(array[i-1]!=array[i]))
			||((array[i]==array[i-1])&&(array[i-1]+array[i]>=10 && array[i-1]+array[i]<=20)&&(array[i-1]!=array[i+1])))
			esiste=1;
					//******** CONDIZIONE TROPPO RESTRITTIVA: NON DEVONO ESSERE NECESSARIAMENTE UGUALI I DUE ELEMENTI CHE
					//******** HANNO SOMMA COMRESA TRA 10 E 20.  -1

			/*altrimenti vai avanti*/
		else
			i++;
	}
	return esiste;
}

/*funzione principale*/
int main(){
	/*INPUT*/
	int i;//contatore
	int l;//lunghezza array
	printf("Salve utente sono un programma che data una sequenza di interi verifica se \n");
	printf("esiste una tripla in cui vi sono esattamente 2 elementi uguali tra loro\n");
	printf ("e almeno due elementi della tripla hanno somma compresa tra 10 e 20\n\n");
	printf("Quanti interi vuoi inserire\n");
	/*acquisizione array da tastiera*/
	scanf("%d",&l);
	int array[l];
	printf("va bene adesso inserisci gli interi\n");
	for( i=0;i<l;i++){
		printf("Inserisci l'intero di indice %d \n",i);
		scanf("%d",&array[i]);
	}
	/*OUTPUT*/
	if(ugualiCompresi(array,l)){
		printf("esiste una tripla in cui vi sono esattamente 2 elementi uguali tra loro\n");
		printf ("e almeno due elementi della tripla hanno somma compresa tra 10 e 20\n\n");
	}
	else{
		printf("non esiste una tripla in cui vi sono esattamente 2 elementi uguali tra loro\n");
		printf ("e almeno due elementi della tripla hanno somma compresa tra 10 e 20\n\n");
	}



}
