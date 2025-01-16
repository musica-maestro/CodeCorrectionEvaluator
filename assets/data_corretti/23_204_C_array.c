/* SPECIFICA (max 1):......0.6
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............9.1
*/
/* SPECIFICA DEL PROBEMA
*INPUT: sequenz di n interi  //******** MANCA LA LUNGHEZZA -0.2
*PRECONDIZI0NE: //   //******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
*OUTUT: valore booleano
*POSTCONNDIZIONE: vale 1 se per ogni tripla consecutiva esistono due numeri
*composti da una sola cifra, vale 0 altrimenti
*TIPO PROBLEMA:  verificq universale */

#include <stdio.h>

/* funzione che verifca se la seuqenza ntrodotta dall' utente soddisfa la condizioni richieste */
int DueUnacifra(int* array, int n){

	int verificato=1;			// variabile di verifca universale

	int i=0;					// indice dell' array

	while( i<n-2 && verificato==1){

		if(((array[i]<=9 && array[i]>=0) && (array[i+1]<=9 && array[i+1]>=0))
			||((array[i+1]&& array[i+1]>=0)&&(array[i+2]<=9 && array[i+2]>=0))
			||(( array[i]<=9 && array[i]>=0) && (array[i+2]<=9 && array[i+2]>=0)))
				i++;
		else
			verificato=0;

	}

	return verificato;
}


/* funzione principale */
int main (){

	int n;			// lunghezza dell' array scelta dall' utente

	/* insermento lunghezza dell' array */

	printf(" Utente, quanti numeri desiderri inserire?\n");
	scanf("%d", &n);

	/*dichiarazione array*/
	int array[n];

	/* inserimento valorI */
	for(int i=0; i<n;i++){
		printf(" inserisci il valore:");
		scanf("%d", &array[i]);
	}

	/* output algoritmo */

	if(DueUnacifra(array, n)){
		printf(" La tua sequenza di numeri soddisfa le condizioni\n");
	}         //************ OUTPUT NON ESPLICATIVO -0.5
	else{
		printf(" la tua sequenza di numeri NON soddifa le condizioni\n");
	}

return 0;

}