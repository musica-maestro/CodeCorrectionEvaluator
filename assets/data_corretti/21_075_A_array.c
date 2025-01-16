/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.4
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9.4
*/
/*SPECIFICA
 * INPUT: un sequenza di interi ed un intero lung
 * PRE-CONDIZIONE: 	lung indica la lunghezza della sequenza
 * OUTPUT:	un intero isCompresi
 * POST-CONDIZIONE: isCompresi vale 1 se nella sequenza esiste una tripla di elementi consecutivi tale che almeno due elementi della tripla
 * hanno una somma compresa tra 10 e 20 ed esattamente due elementi della tripla sono uguali fra loro, 0 altrimenti
 * TIPO DI PROBLEMA: verifica esistenziale */



#include <stdio.h>

int ugualiCompresi(int seq[], int lung){
	/* inizializzazione variabili */
	int i=0;
	int isCompresi=0;
	/* scorro l'array*/
	while(i<lung-2){  //******** NON USI LA VARIABILE BOOLEANA PER TERMINARE IL CICLO -1
		/* faccio il controllo e se positivo aggiorno la variabile da restituire ed esco dal ciclo*/
		if(((seq[i]+seq[i+1]>=10 && seq[i]+seq[i+1]<=20)
		||(seq[i]+seq[i+2]>=10 && seq[i]+seq[i+2]<=20)
		||(seq[i+1]+seq[i+2]>=10 && seq[i+1]+seq[i+2]<=20)) &&
			(((seq[i]==seq[i+1]) && seq[i]!=seq[i+2])
			||((seq[i]==seq[i+2]) && seq[i]!=seq[i+1])
			||(((seq[i+2]==seq[i+1]) && seq[i+2]!=seq[i])))){ //******* MOLTE PARENTESI INUTILI -0.1
			isCompresi=1;
			break;  //******** BREAK NON PERVENUTO! -0.5
		}
		/*altrimenti vado avanti di una posizione e controllo di nuovo*/
		else{
			i++;
		}
	}
	return isCompresi;
}



int main(int argc, char **argv)
{
	int lung; /*lunghezza dell'array*/
	int finale; /*variabile per il controllo finale*/
	printf("inserire la lunghezza della sequenza.\n");
	scanf("%d", &lung);
	int seq[lung];
	printf("inserire gli elementi della sequenza.\n");
	for(int i=0;i<lung;i++){
		scanf("%d", &seq[i]);
	}
	finale=ugualiCompresi(seq, lung);
	if(finale==1){
		printf("nella sequenza esiste una tripla di elementi consecutivi tale che almeno due elementi della tripla hanno una somma compresa tra 10 e 20 ed esattamente due elementi della tripla sono uguali fra loro.\n");
	}
	else{
		printf("nella sequenza non esiste una tripla di elementi consecutivi tale che almeno due elementi della tripla hanno una somma compresa tra 10 e 20 ed esattamente due elementi della tripla sono uguali fra loro.\n");
	}

}
