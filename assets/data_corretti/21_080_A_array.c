/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................11
*/
/* SPECIFICA
 * INPUT:una sequenza di interi,un intero l per la sua lunghezza;
 * Pre-condizione: l>=0;
 * Output: un intero "esiste";
 * Post-condizione: se esiste almeno una tripla di elementi consecutivi tale che almeno due elementi
 * hanno una somma comprese tra 10 e 20 ed esattamente due elementi uguali tra loro esiste sarà uguale a 1,
 * 0 altrimenti;
 * TIPO DI PROBLEMA:VERIFICA ESISTENZIALE
 * */



#include <stdio.h>
/*funzione da richiamare */
int ugualiCompresi(int interi[],int l) {
	int i=1;		//variabile contatore
	int esiste=0;   // variabile di esistenza
	/* controllo ogni tripla */
	while(i<l-1 && !esiste) {
		if(((interi[i-1]+interi[i]>=10 && interi[i-1]+interi[i]<=20)
		|| (interi[i]+interi[i+1]>=10 && interi[i]+interi[i+1]<=20)
		|| (interi[i-1]+interi[i+1]>=10 && interi[i-1]+interi[i+1]<=20))
		&& ((interi[i]==interi[i-1] && interi[i]!=interi[i+1])
		|| (interi[i]==interi[i+1] && interi[i]!=interi[i-1])
		|| (interi[i-1]==interi[i+1] && interi[i-1]!=interi[i])))
			esiste=1;
		else // se non è verificata vado aventi
			i++;
	}
	return esiste;
}


/*funzione main*/

int main() {
	int lunghezza;  //intero per la lunghezza dell'array
	printf("Ciao utente sono un programma che controlla se esiste almeno una tripla di elementi consecutivi tale che almeno due elementi hanno una somma comprese tra 10 e 20 ed esattamente due elementi uguali tra loro\n") ;
	printf("Tra quanti interi vuoi controllare?\n");
	scanf("%d", &lunghezza);
	int x[lunghezza];  //array
	/*inserisco intero nell'array */
	for(int i=0;i<lunghezza;i++) {
		printf("introduci un intero:");
		scanf("%d", &x[i]);
	}
	if(ugualiCompresi(x,lunghezza))
		printf("\nEsiste almeno una terna che soddisfa la richiesta\n");
	else
		printf("\nNon esiste almeno una terna che soddisfa la richiesta\n");
}