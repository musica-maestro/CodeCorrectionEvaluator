/* SPECIFICA (max 1.5):....0.2
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......1.5
   MAIN PROGRAM (max 2.5):.0
   TOTALE..................2.7
*/
/*SPECIFICA
 * INPUT:SEQUENZA //******** MANCA TIPO DEGLI ELEMENTI -0.5
 * PRECONDIZIONE:SEQUENZA DI INTERI
 * OUTPUT: VERIFICA DELLA SEQUENZA  //******** OUTPUT DEVE RESTITUIRE UN BOOLEANO -0.5
 * POST CONDIZIONE:OGNI TRIPLA DI ELEMENTI CONSECUTIVI DELLA SEQUENZA CONTIENE ESATTAMENTE DUE MAGGIORI O UGUALI A 5 ED ALMENO DUE PARI
//******* L'OUTPUT VALE 1 SE.... VALE 0 SE.... -0.3

 * TIPO DI PROBLEMA:VERIFICA UNIVERSALE
 * */

#include <stdio.h>

int maggiori5Pari (int array[],int lunghezza);//Funzione//
int i;//intero che rappresenta la lunghezza dell'array//
int pari;  //******* A COSA E' INIZIALIZZATO PARI? -1
i=0;
for (i=0,i<=lunghezza-2,i++){ //******** LIMITI ITERAZIONE NON CORRETTI DEVE ESSERE i<lunghezza-2   -0.5
	if ((array[i]=pari && array[i+1]=pari) //********** ==, NON =   -0.5
	||(array[i+1]=pari && array[i+2]=pari)
	||(array[i]=pari && array[i+2]=pari));
	for(i=0;i<lunghezza-2;i++){ //******* INDICE DELL'ARRAY SBAGLIATO, NON PUO' ESSERE i: for(int j=0; j<2; j++) array[i+j] -1.5
		if (((array[i]>=5 || array[i+1]>=5)&&(array[i+2]>=5))||((array[i+1]>=5 || array[i+2]>=5)&&(array[i]>=5))||((array[i]>=5 || array[i+2]>=5)&&(array[i+1]>=5)));
		maggiori5Pari=1  //***** MANCA ; -0,3 //********* COSI' NON CONTROLLI CHE ESATTAMENTE 2 SIANO >=5,
		else maggiori5Pari=0;                 //********* POSSONO ANCHE ESSERE TUTTI E TRE >=5 -1
			else maggiori5Pari=0;
			}
}

//GESTISCE L'INTERAZIONE CON L'UTENTE//
int main(){{
	int lunghezza;
	int n;
	int k;
	lunghezza=n, //********* NON SAI QUANTO VALE N -1
	printf("Inserisci la lunghezza della sequenza\n");
	scanf("%d", &n);
	int array[k]; //********* NON SAI QUANTO VALE N -1
	int maggiori5Pari;
	for(n=0;n<=lunghezza;n++);
		printf("Inserisci  un numero\n");
		scanf("%d", &k);  //********* NO!!!! -2
		return 0;
	}
	printf("La sequenza da lei inserita risulta essere %d\n", &maggiori5Pari);
}