/* SPECIFICA (max 1.5):....0.9
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......2.5
   MAIN PROGRAM (max 2.5):.1.5
   TOTALE..................5.9
*/
#include <stdio.h>
/*Data una sequenza di interi, il programma verifica se ogni tripla di elementi consecutivi
 * contiene esattamente due elementi maggiori o uguali a 5 ed almeno due elementi pari
 *
 * Specifica
 * Input: una sequenza di interi
 * Pre-condizione: dim > 0
 * Output: 1 se ogni tripla inserita dall'utente è verificata, 0 altrimenti
 * Post-condizione: un valore booleano //**** OUTPUT E POST SCAMBIATE, COMUNQUE LA POST-CONDIZIONE NON DICE NINETE -0.6
 * Tipo di problema: verifica universale*/

int maggiori5Pari (int array[] , int dim)
{
	int verifica = 1;		//variabile esistenziale
	int i = 0; 				//contatore
	while (verifica = 1) //******** SE TUTTE LE TRIPLE VERIFICANO LA CONDIZIONE IL CICLO NON SI FERMA MAI! -2
	{
		if ( ((array[i]>=5) && (array[i+1]>=5)) || ((array[i]>=5) && (array[i+2]>=5)) || ((array[i+1]>=5) && (array[i+2]>=5)) ) //se contiene esattamente 2 elementi nella tripla maggiori o uguali a 5
		{//******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO >=5 ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE <5)
	     //******** ES. se la tripla e' 10,20,30 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
			if( ((array[i]%2==0) && (array[i+1]%2==0)) || ((array[i]%2==0) && (array[i+2]%2==0)) || ((array[i+1]%2==0) && (array[i+2]%2==0)) )	//se 2 elementi nella tripla sono pari
			{
				i++;		//vado avanti nella sequenza
			}
		}
		else
		{
			verifica = 0;	//altrimenti mi fermo perchè non è più verificata la condizione
		}
	}

	return verifica;
}


int main(int argc, char **argv)
{
	int dim;		//dim >0
	printf("Quanti numeri interi vuoi inserire? \n");
	scanf("%d", &dim);

	int array[dim];
	for(int i = 0 ; i < dim ; i++)		//Chiedo i numeri da inserire e li inserisco nell'array
	{
		printf("Inserisci un intero \n");
		scanf("%d", &array);  //******** &array[i] -1
	}

	if ( maggiori5Pari(array, dim) == 1 ) //prendo il valore booleano dalla funzione e se è vero significa che la condizione è sempre verifica
	{
		printf("Ogni tripla di interi contiene esattamente due elementi maggiori o uguali a 5 ed almeno due elementi pari");
	}
	else								//altrimenti falso
	{
		printf("Ogni tripla di interi NON contiene esattamente due elementi maggiori o uguali a 5 ed almeno due elementi pari");
	}
}
