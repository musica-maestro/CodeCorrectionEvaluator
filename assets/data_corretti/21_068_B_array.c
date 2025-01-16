/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..0 //******** MANCANTE
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................10
*/
/*SPECIFICA
 * Input:sequenza di interi s e lunghezza l
 * Pre-condizione: l è lunghezza di s
 * Output: variabile maggioripari
 * Post-condizione: maggioripari è pari ad 1 se ogni tripla contiene esattamente due elementi
 * maggiori o uguali a 5 ed almeno due elementi pari, altrimenti è uguale a 0*/

#include <stdio.h>


/*Funzione che verifica se un numero è pari*/
int isPari(int n){
	return n%2==0;
}
/*Funzione che legge una sequenza di interi e verifica se contiene esattamente due elementi
 * maggiori o uguali a 5 ed almeno due elementi pari*/
int maggiori5Pari(int interi[], int l){

	int i; //variabile contatore
	int maggioripari=1; //variabile booleana

	/*Scorro la sequenza fino al terz'ultimo elemento, esco se ne trovo una che non rispetta la proprietà*/
	for(i=0;i<l-2&&maggioripari;i++){
		/*Controllo se ci sono esattamente due elementi>=5*/
		if((interi[i]>=5&&interi[i+1]>=5)||(interi[i]>=5&&interi[i+2]>=5)||(interi[i+1]&&interi[i+2]>=5)){
			/*Se almeno un elemento della tripla è minore di 5*/
			if((interi[i]<5)||(interi[i+1]<5)||(interi[i+2]<5)){//*****COMPLICATA MA CORRETTA
				/*Controllo se ci sono almeno due pari*/
				if((isPari(interi[i])&&isPari(interi[i+1]))||(isPari(interi[i]&&isPari(interi[i+2])))||(isPari(interi[i+1]&&isPari(interi[i+2])))){
					maggioripari=1; //******** EVITA DI RIASSEGNARE IL VALORE CON CUI HI INIZIALIZZATO LA VARIABILE.
				}
				else
					maggioripari=0; //non ha almeno due pari
			}
			else
					maggioripari=0; //non c'è un elemento minore di 5
		}
		else
					maggioripari=0; //non ha due elementi maggiori o uguali a 5
	}
	/*Output*/
	return
		maggioripari;
}

int main()
{
	int i; // Variabile contatore
	int lunghezza; //lunghezza sequenza

	printf("Caro utente questo programma legge una sequenza di interi e verifica se contiene esattamente due elementi\nmaggiori o uguali a 5 ed almeno due elementi pari\n");
	printf("Quanto %c lunga la sequenza? ",138);
	scanf("%d",&lunghezza);

	int sequenza[lunghezza];
	/*Leggo la sequenza*/
	for(i=0;i<lunghezza;i++){
		printf("Inserisci il %d%c numero: ",i+1,167);
		scanf("%d",&sequenza[i]);
	}
	/*Stampo output*/
	if (maggiori5Pari(sequenza,lunghezza))
		printf("\nOgni tripla contiene esattamente due elementi maggiori o uguali di 5 e almeno due pari");
	else
		printf("\nAlmeno una tripla non contiene esattamente due elementi maggiori o uguali di 5 e almeno due pari");
}
