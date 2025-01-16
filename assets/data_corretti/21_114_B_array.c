/* SPECIFICA (max 1.5):....1,5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9.5
*/
/*SPECIFICA:
 * Input: sequenza di interi e la sua lunghezza
 * Pre-condizione: lunghezza è la lunghezza della sequenza
 * Output: intero verificata
 * Post-condizione: verificata vale 1 se ogni tripla di elementi consecutivi contiene esattamente due elementi maggiori o uguali a 5 ed almeno due elementi pari, 0 altrimenti
 * Tipo di problema: verifica universale*/

#include <stdio.h>
/*funzione che riceve come input una sequenza di interi e la sua lunghezza e verifica se ogni tripla di elementi consecutivi
 contiene esattamente due elementi maaggiori o uguali a 5 ed almeno due elementi pari*/

int maggiori5Pari(int sequenza, int lunghezza){
	int verificata;//variabile universale, tutti gli elementi della sequenza soddisfano le proprietà
	verificata=1;//inizializzazione, inizialmente sì

	/*visita la sequenza fino a che non termina e la variabile ha valore 1*/
	int i=0;
	while(i<lunghezza-2 && verificata){
		if(!((sequenza[i]>=5) && (sequenza[i+1]>=5))||
		((sequenza[i]>=5) && (sequenza[i+2]>=5))||
		((sequenza[i+1]>=5) && (sequenza[i+2]>=5)))//verifica se elemento corrente non soddisfa la prima proprietà: due elementi >= 5
			{//******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO UGUALI ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
			 //******** ES. se la tripla e' 5 5 5 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
			if(!((sequenza[i]%2==0) && (sequenza[i+1]%2==0))
				|| ((sequenza[i]%2==0) && (sequenza[i+2]%2==0))
				|| ((sequenza[i+1]%2==0) && (sequenza[i+2]%2==0)))//verifica se elemento corrente non soddisfa la seconda proprietà: almeno due elementi pari
				verificata=0;
		}
		else
			i++;
	}
	return verificata;
}


/*funzione principale*/

int main(int argc, char **argv)
{
	int lunghezza;//lunghezza della sequenza di interi

	printf("Ciao utente, sono un programma che legge una sequenza di interi e verifica se ogni tripla di elementi\n");
	printf("\nconsecutivi contiene esattamente due elementi maggiori o uguali a 5 ed almeno due elementi pari.\n\n");
	printf("\n\nQuanto deve essere lunga la sequenza?\n");
	scanf("%d", &lunghezza);

	int sequenza[lunghezza];

	/*riempimento array da tastiera*/

	for(int i=o;i<lunghezza;i++){
		printf("\nInserisci un intero: \n");
		scanf("%d", &sequenza[i]);
	}

	/*output*/
	if(maggiori5Pari(sequenza,lunghezza)){
		printf("\nTutte le triple di elementi consecutivi nella sequenza contengono esattamente due elementi maggiori o uguali a 5\n");
		printf("ed almeno due elementi pari.\n");
	}
	else
	{
		printf("\nNon tutte le triple di elementi consecutivi nella sequenza contengono esattamente due elementi maggiori o uguali a 5\n");
		printf("ed almeno due elementi pari, c'%c una tripla che non soddisfa le propriet%c richieste.\n", 138, 133);
	}

}
