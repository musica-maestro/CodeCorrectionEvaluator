/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......2.5
   MAIN PROGRAM (max 2.5):.2.3
   TOTALE..................7,3
*/
//Data una sequenza di interi,verifica se ogni tripla di elementi consecutivi contiene esattamente due interi maggiori o uguali a 5 ed almeno due elementi pari.
/*Specifica
 * Input: una sequenza di interi s e la sua lunghezza l
 * Pre-condizione:l>=3
 * Output: int verificato
 * Post-condizioni: verificato vale 1 se Data una sequenza di interi,verifica se ogni tripla di elementi consecutivi contiene esattamente due interi maggiori o uguali a 5 ed almeno due elementi pari,altrimenti vale 0
 * Tipo di problema:Verifica universale
 */
#include <stdio.h>


//FUNZIONE DI SUPPORTO
int maggiori5Pari(int sequenza[],int lunghezza){
	int verificato=1;  //rispetta la condizione iniziale
	int i=1;   //inizializzazione

	//controlla se non rispetta la condizione
	while(i<lunghezza && verificato){ //******** L'INDICE DELL'ARRAY DEVE ESSERE i<lUNGHEZZA-1  -1
		if((sequenza[i-1]<5 && sequenza[i]<5) //******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO >=5 ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE <5)
											  //******** ES. se la tripla e' 2,4,4 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
		|| (sequenza[i]<5 && sequenza[i+1]<5)
		|| (sequenza[i-1]<5 && sequenza[i+1]<5)
		||  //*********** DEVONO ESSERE SODDISFATTE ENTRAMBE LE CONDIZIONI  -1
		   ((sequenza[i-1]%2!=0 && sequenza[i]%2!=0)
		   || (sequenza[i-1]%2!=0 && sequenza[i+1]%2!=0)
		   || (sequenza[i]%2!=0 && sequenza[i+1]%2!=0))){
			   verificato=0;

		   }
			   i++;   // passa al prossimo
	}
	return verificato;

	}



int main(int argc, char **argv)
{
	int lunghezza;   // lunghezza della sequenza
	//input*/
	printf("Ciao,sono un programma che data una sequenza di interi,verifica se ogni tripla di elementi consecutivi contiene esattamente due interi maggiori o uguali a 5 ed almeno due elementi pari. \n");
	printf("Inserisci la lunghezza della sequenza:\n");
	scanf("%d",&lunghezza);

int sequenza[lunghezza];
//legge la sequenza
printf("\n");
for(int i=0;i<lunghezza;i++){
	printf("Inserisic la sequenza:\n");
	scanf("%d",&sequenza[i]);
}
//output
if(maggiori5Pari(sequenza,lunghezza))
	printf("Verificato.");
	else   //******** INDENTATO MALE -0.2
		printf("Non verificato:\n");

}
