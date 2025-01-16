/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......2.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............6.5
*/
/*SPECIFICA
*Input: una sequenza di interi e la sua lunghezza n
*pre-condizione: n deve essere la lunghezza di interi[] e n>=3
*Output: un intero multiplo
*post-condizione: la funzione restituisce 1 se in tutte le terne adiacenti della sequenza e' presente almeno un elemento multiplo di uno degli altri due, 0 altrimenti
*TIPO DI PROBLEMA: verifica universale*/
#include <stdio.h>
int funzioneMultipli(int interi[], int lunghezza){
	int multiplo; //multiplo (se esiste) della tripletta
	//inizializzo multiplo
	multiplo=0;
	for(int i=0;i<lunghezza-2;i++){  //******** CONDIZIONE SBAGLIATA -1.5
		if((interi[i]==2*interi[i+1])||(interi[i]==2*interi[i+2])||(interi[i+1]==2*interi[i])||(interi[i+1]==2*interi[i+2])||(interi[i+2]==2*interi[i])||(interi[i+2]==2*interi[i+1]))
			multiplo=1;
	}                   //******* QUESTA E' UNA VERIFICA UNIVERSALE, MA TU LATRATTI COME ESISTENZIALE -2
	return multiplo;
}

int main()
{
	int n; //dimensione dell'array
	printf("Caro utente, di quanti interi e' composta la sequenza?\n");
	scanf("%d",&n);

	int interi[n]; //array di dimensione n
	for(int i=0;i<n;i++){
		printf("utente introduci un intero:\n");
		scanf("%d",&interi[i]);
	}
	funzioneMultipli(interi,n);
	if(funzioneMultipli(interi,n))
		printf("In tutte le terne di elementi adiacenti della sequenza c'e' almeno un multiplo\n\ndegli altri due");
	else
		printf("Non esistono terne in cui c'e' un multiplo deegli altri due.\n");
}