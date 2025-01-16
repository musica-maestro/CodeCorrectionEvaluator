/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9.5
*/
#include <stdio.h>

/*SPECIFICA:

* INPUT: sequenza di interi x1, .. xn

* PRE-CONDIZIONI: n>=3

* OUTPUT: un valore booleano tripla

* POST-CONDIZIONI: tripla vale true se esiste una tripla di elementi consecutivi

* che contiene almeno due elementi il cui valore è compreso fra -10 e 10(estremi inclusi),

* e che contioene esattamente due elementi multipli di 3; tripla vale false altrimenti

* TIPO DI PROBLEMA: verifica esistenziale*/

/*funzione che restituisce 1 se esiste una tripla di elementi consecutivi

* che contiene almeno due elementi il cui valore è compreso tra -10 e 10,

* e che contiene esattamente due elementi multipli di 3, restituisce 0 altrimenti*/

int compresiMultipli3(int seq[], int lunghezza)

{
	 int i;    //variabile contatore

         int tripla;    //variabile di esistenza

         i=0;

	 tripla=0;

	 /*guardo la sequenza*/

	 while(i<lunghezza-2 && !tripla)

	 {

		 if(((-10<=seq[i]<=10 && -10<=seq[i+1]<=10 )
		 || (-10<=seq[i]<=10 && -10<=seq[i+2]<=10 )
		 || (-10<=seq[i+1]<=10 && -10<=seq[i+2]<=10 )) 	//******** QUESTA ESPRESSIONE NON ESPRIME "ESSERE COMPRESO TRA"
			    										//******** MA IL C CALCOLA ALTRO (((-10<=seq[i])<=10) -1.5

		 &&
		 ((seq[i]%3==0 && seq[i+1]%3==0 && seq[i+2]%3!=0)
		 || (seq[i]%3==0 && seq[i+1]%3!=0 && seq[i+2]%3==0)
		 || (seq[i]%3!=0 && seq[i+1]%3==0 && seq[i+2]%3==0)))

			 tripla=1;     //ho trovato la tripla che soddisfa la condizioni

		else

			i++;

	 }

	 return tripla;

}
int main(int argc, char **argv)

{

	int lunghezza;    //lunghezza della sequenza

	printf("Caro utente, sono un programma che data una sequenza di interi ");

	printf("verifica se esiste una tripla di elementi consecutivi che contiene almeno due elementi ");

	printf("il cui valore %c compreso tra -10 e 10(estremi inclusi), e che contiene esattamente due elementi multipli di 3!!\n\n", 138);

	/*input*/

	printf("Quanto %c lunga la tua sequenza? ", 138);

	scanf("%d", &lunghezza);

	int sequenza[lunghezza];

	for(int i=0; i<lunghezza; i++)

	{

		printf("Introduci un intero: ");

		scanf("%d", &sequenza[i]);

	}

	/*output*/

	if(compresiMultipli3(sequenza,lunghezza))
       {

                printf("\nEsiste una tripla che contiene almeno due elementi il cui valore %c compreso fra -10 e 10,estremi inclusi, ", 138);

		printf("e che contiene esattamente due elementi multipli di 3!!\n");

	}

	else {

	printf("\nNon esiste una tripla che contiene almeno due elementi il cui valore %c compreso fra -10 e 10,estremi inclusi, ,", 138);

		printf("e che contiene esattamente due elementi multipli di 3!!\n");

        }


}
