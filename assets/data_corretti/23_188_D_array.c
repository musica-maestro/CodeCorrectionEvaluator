/* SPECIFICA (max 1):......0.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...1.7
   TOTALE (10).............9.2
*/
/*SPECIFICA
 * input: sequenza s di lunghezza l //******** MANCA IL TIPO -0.2
 * pre-condizine: s di lunghezza l
 * output: se esiste istanza positiva altriment negativa //********* L'OUTPUT DEVE ESSERE UN BOOLEANO -0.2
 * post-condizione: se esiste almeno una terna in cui e' presente
   almeno un numero pari alla differza tra gl'altri due //********** FALSO, ALTRIMENTI -0.1
 * tipologia: esistenziale
*/
#include <stdio.h>

int restoDivisione(int sequenza[], int lunghezza){
	int esiste=0;

	/*post condizione: */
	/* verfico se almeno uno dei numeri nella terna e' uguale al resto della divisione fra gl'altri due */
	for(int i=1; i<lunghezza-1 && esiste==0; i++){
		if(sequenza[i]==sequenza[i-1]%sequenza[i+1] || sequenza[i]==sequenza[i+1]%sequenza[i-1]
			|| sequenza[i-1]==sequenza[i]%sequenza[i+1] || sequenza[i-1]==sequenza[i+1]%sequenza[i]
			|| sequenza[i+1]==sequenza[i]%sequenza[i-1] || sequenza[i+1]==sequenza[i-1]%sequenza[i])
			esiste+=1;
	}
	return esiste;
}

int main()
{
	int lunghezza; //variabile associata alla lunghezza dell'array
	int sequenza[lunghezza]; //array con lunghezza scelta dell'utente

	/* INPUT */
	printf("Ciao utente, sono un programma che verifica se all'interno della sequenza\n");
	printf("esiste una tripla di elementi interi adiacenti in cui uno dei tre e' il resto della\n");
	printf("divisione degli altri due.\n\n");

	/* pre-condizione */
	/* l'utente inserisce la lunghezza */
	printf("Inserire la lunghezza della sequenza: ");
	scanf("%d", &lunghezza);

	/* l'utente inserisce i numeri un per volta */
	for(int i=0; i<lunghezza; i++){
		printf("Inserire il %d' numero\n", i+1);
		scanf("%d", &sequenza[i]);
	}

	restoDivisione(sequenza, lunghezza); //****** NON SERVE A NIENTE -0.3

	/* OUTPUT */
	if(restoDivisione(sequenza, lunghezza))
		printf("Nella sequenza inserita esiste una terna di elementi adiacenti in cui uno dei tre e' il resto della divisione degl'altri due");
	else
		printf("Nella sequenza inserita non esiste una terna di elementi adiacenti in cui uno dei tre e' il resto della divisione degl'altri due");



	return 0;
}