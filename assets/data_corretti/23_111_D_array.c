/* SPECIFICA (max 1):......0.3
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.8
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.1
*/
#include <stdio.h>
/*SPECIFICA
 *Input: n-elementi interi  //******** MANCA LA LUNGHEZZA -0.2
 *Pre-condizione: in ogni tripla dei n-elementi, controllare se esiste un elemento uguale
                  al resto della divisione tra gli altri due  //**** QUESTA NON E' UNA PRECONDIZIONE -0.2
 *Output: un valore intero
 *Post-condizione: il valore deve essere o 0 o 1 //******** LA POST CONDIZIONE NON E' QUESTA -0.3
 *TIPO DI PROBLEMA: verifica esistenziale                                                   */

//---------------------- insValori ----------------------
// Funzione di tipo void che si occupa dell'inserimento dei valori da parte dell'utente
void insValori(int *x,int n){
	printf("Ora inserisci i valori:");
	for(int i=0;i<n;i++){                  //i = variabile di conteggio degli elementi all'interno dell'array
		printf("\nValore n.%d: ",i+1);
		scanf("%d",&x[i]);                 //input dei valori all'interno dell'array
	}
}

//---------------------- restoDivisione ----------------------
int restoDivisione(int *x,int n){
	int ris=0;                  //variabile di tipo int di valore 0, siccome inizialmente non si e' ancora verificata la pre-condizione
	for(int i=1;i<n-1;i++){ //****** SENZA LA VAR. BOOLEANA NELLA CONDIZIONE, ANCHE SE TROVI UNA TERNA CHE NON SODDISFA LA PROPRIETA' VAI AVANTI A CONTROLLARE -0.2
		//se If trova una tripla che soddisfa la pre-condizione, ris avra' come valore 1, quindi la pre-condizione sara' verificata
		if( (x[i]%x[i-1]==x[i+1]) || (x[i-1]%x[i]==x[i+1]) ||
		    (x[i]%x[i+1]==x[i-1]) || (x[i+1]%x[i]==x[i-1]) ||
		    (x[i-1]%x[i+1]==x[i]) || (x[i+1]%x[i-1]==x[i]) )
			ris=1;
	}
	return ris;
}

//---------------------- main ----------------------
int main(){
	int n;                       //il numero di valori inseriti dall'utente
	int esito;                   //il risultato che si ottiene da restoDivisione
	printf("Ciao utente. Inserisci il numero di valori: ");
	scanf("%d",&n);
	int x[n];                    //array di tipo int che puo' contenere n valori
	insValori(x,n);              //invocazione della funzione che si occupa dell'input
	esito=restoDivisione(x,n);   //"esito" invoca la funzione restoDivisione, ed ottiene come valore 0 o 1

	//Se esito=1, allora la funzione ha trovato una tripla dei n-elementi che soddisfa la pre-condizione
	if(esito==1)
		printf("Esiste una terna di valori consecutivi in cui uno dei tre e' il resto della divisione degli altri due.");
	else
		printf("NON esiste una terna di valori consecutivi in cui uno dei tre e' il resto della divisione degli altri due.");
}