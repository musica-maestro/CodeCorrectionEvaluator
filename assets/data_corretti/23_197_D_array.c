/* SPECIFICA (max 1):......0.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............8
*/
/*
SPECIFICA: bisogna trovare almeno una tripla in cui uno dei tre numeri sia il resto della divisione tra gli altri due numeri della tripla
Dati di Ingresso: array[n1, n2, n...] //******** MANCA LA LUNGHEZZA -0.2
pre-condizione: i numeri inseriti dall'utente devono essere interi e devono essere minimo 3
Dati di uscita: 1 se esiste almeno una tripla che soddisfi la proprietà o 2 se non estite neanche una tripla che soddisfi la proprietà
post-condizione: //******** CONFONDI OUTPUT E POST CONDIZIONE, -0.3
Tipo di problema: verifica esistenziale
*/

#include <stdio.h>

int restoDivisione(int *array, int n){

	int risposta = 0;

	for(int i=0; i<(n-2); i++){

		//verifica se la tripla controllata
		if ( ( (array[i])%(array[i+1]) )==(array[i+2]) || ( (array[i])%(array[i+2]) )==(array[i+1]) ||
		     ( (array[i+2])%(array[i+1]) )==(array[i])
			|| ( (array[i+1])%(array[i]) )==(array[i+2]) ||
			 ( (array[i+2])%(array[i]) )==(array[i+1]) || ( (array[i+1])%(array[i+2]) )==(array[i]) )
	{
		risposta =1;
	}


	}

	printf("%d ", risposta);
	if(risposta == 1){


		printf("esiste almeno una tripla che abbia al suo interno il resto della divisione tra gli altri due numeri\n");

	}else{

		printf("non esiste neanche una tripla che abbia al suo interno il resto della divisione tra gli altri due numeri\n");
	}                    //******* IL TESTO RICHIEDE CHE LA STAMPA VENGA FATTA NEL MAIN, NON NELLA FUNZIONE -1.5

	return risposta;
}

int main(){

	int n=0;

	//prende in input la dimensione dell'array
	printf("quanti numeri vuoi inserire?(min 3)\n\n");
	scanf("%d", &n);

	//controlla che l'utente abbia creato un array da almeno 3 numeri
	if(n<3){

		printf("\nti ho detto detto che mi servono minimo tre numeri\n\n");

		//fa ripetere la richiesta all'utente finche non crea un array da almeno 3 numeri
		do{

			printf("quanti numeri vuoi inserire?(min 3)\n");
			scanf("%d", &n);

		}while(n<3);

	}


	//crea l'array della dimensione voluta dall'utente
	int array[n];

	for(int i=0; i<n; i++){

		printf("inserire il numero\n");
		scanf("%d", &array[i]);

	}

	restoDivisione(array, n);

}