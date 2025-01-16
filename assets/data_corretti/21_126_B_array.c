/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9.5
*/
#include <stdio.h>
/*programma che verifica se all'interno di una sequenza di interi, ogni tripla di elementi
 * consecutivi contiene esattamente due elementi maggiori o uguali a 5 e almeno due elementi pari.
 * SPECIFICA:
 * INPUT: una sequenza x0,x1...xl, con l sua lunghezza
 * PRE: sequenza di interi e la sua lunghezza, con l>=3
 * OUTPUT:valore booleano verificato
 * POST: verificato vale 1 se ogni tripla di elementi
 * consecutivi contiene esattamente due elementi maggiori o uguali a 5 e almeno due elementi pari, altrimenti vale 0
 * TIPO DI PROBLEMA: verifica universale*/

/*funzione che per ogni tripla di elementi consecutivi verifica se contiene esattamente due elementi maggiori o uguali a 5 e almeno due elementi pari.*/
int maggiori5Pari(int seq[], int l){           //l lunghezza della sequenza, l>=3
	int verificato=1;                          //variabile di universalit√
	int i=0;                                    //variabile contatore
	while(i<=l-3&&verificato){
		/*se la funzione non contiene esattamente due elementi>=5 e almeno due pari vale 0, altrimenti 1*/
         if(!((seq[i]>=5&&seq[i+1]>=5)||(seq[i]>=5&&seq[i+2]>=5)||(seq[i+2]>=5&&seq[i+1]>=5))
         //******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO UGUALI ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
		 //******** ES. se la tripla e' 5 5 5 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
         &&((seq[i]%2==0&&seq[i+1]%2==0)||(seq[i+2]%2==0&&seq[i+1]%2==0)||(seq[i]%2==0&&seq[i+2]%2==0)
         ||(seq[i]%2==0&&seq[i+1]%2==0&&seq[i+2]==0))) //******** QUEST'ULTIMA CONDIZIONE NON SERVE
			 verificato=0;
           else
             i++;

	}
}


/*funzione principale*/
int main(int argc, char **argv)
{
	int lunghezza;       //lunghezza della sequenza
	printf("caro utente sono un programma che verifica se all'interno di una sequenza di interi, ogni tripla di elementi consecutivi contiene esattamente due elementi maggiori o uguali a 5 e almeno due elementi pari.  \n");
	printf("quanti interi vuoi inserire?\n");
	scanf("%d",&lunghezza);
	int sequenza[lunghezza];
	for(int i=0;i<lunghezza;i++){
		printf("inserisci un intero:");
		scanf("%d",&sequenza[i]);
	}
	if(maggiori5Pari(sequenza,lunghezza))                                                        //invoco la funzione maggiori5Pari e stampo il risultato
		printf("ogni tripla di elementi consecutivi contiene esattamente due elementi maggiori o uguali a 5 e almeno due elementi pari.");
	else
        printf("non ogni tripla di elementi consecutivi contiene esattamente due elementi maggiori o uguali a 5 e almeno due elementi pari.");

}
