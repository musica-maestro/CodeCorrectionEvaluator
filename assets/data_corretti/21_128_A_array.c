/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.7
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................10.7
*/
/* SPECIFICA
 *input: una sequenza di interi v e la sua lunghezza l
 *pre-condizione: l>=0
 *output: un intero 'vero'
 *post-condizione: vero=1 se esiste una tripla di interi consecutivi all'interno della sequenza tale che la somma di
 *almeno due valori sia compresa tra 10 e 20 e che esattamente due valori siano uguali tra loro; vero=0 altrimenti;
 * TIPO DI PROBLEMA: verifica esistenziale */
#include <stdio.h>
int ugualiCompresi(int vet[],int lung)
{

	int c,vero=0 ;                  //inizializzo un contatore e una variabile esistenziale
	/*effettuo un controllo su tutte le triple della sequenza, e se ne trovo una che soddisfa le condizioni del problema assegno 1 alla variabile esostenziale */
	for(c=0;c<lung-2 && vero==0;c++){
		if((vet[c]+vet[c+1]<20 && vet[c]+vet[c+1]>10)
		|| (vet[c]+vet[c+2]<20 && vet[c]+vet[c+2]>10)  //********* //******** ESTREMI INCLUSI -0.3
		|| (vet[c+1]+vet[c+2]<20 && vet[c]+vet[c+2]>10))
			if((vet[c]==vet[c+1] && vet[c]!=vet[c+2])
			|| (vet[c]==vet[c+2] && vet[c+1]!=vet[c])
			|| (vet[c+2]==vet[c+1] && vet[c]!=vet[c+1])){
				vero=1;
			}

	}
	return vero;
}
int main()
{
	int lung,c;
	printf("inserisci la lunghezza della sequenza: \n");
	scanf("%d",&lung);
	int vet[lung];
	printf("inserisci i valori della sequenza: \n");
	for(c=0;c<lung;c++){
		scanf("%d",&vet[c]);
	}
	/*controllo se la sequenza inserita dall'utente risulta positiva alla funzione 'ugualicompresi'*/
	if (ugualiCompresi(vet,lung)==1){
		printf("esiste una tripla di interi consecutivi all'interno della sequenza tale che");
		printf(" la somma di almeno due valori sia compresa tra 10 e 20 e che esattamente due valori siano uguali tra loro \n");
	}
	else{
		printf("non esiste una tripla di interi consecutivi all'interno della sequenza tale che");
		printf(" la somma di almeno due valori sia compresa tra 10 e 20 e che esattamente due valori siano uguali tra loro \n");
	}
}
