/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3.3
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................7.8
*/
// NOME: Pentimalli Gabriel

/* SPECIFICA
 * INPUT: array di interi e la relativa dimensione
 * PRE-CONDIZIONE: l'array ha dimensione finita, maggiore o uguale a 3 e contiene solo numeri interi
 * OUTPUT: numero intero
 * POST-CONDIZIONE: l'intero è uguale a 1 se all'interno dell'array esiste una tripla di elementi consecutivi che contiene
 * almeno due elementi il cui valore è compreso fra -10 e 10 (estremi inclusi) e che contiene esattamente due elementi
 * multipli di 3, mentre restituisce 0 se la condizione non è soddisfatta.
 *
 * TIPO DI PROBLEMA: problema di verifica esistenziale
*/

//******** SE LA FUNZIONE LA SCRIVI DOPO, DEVI DICHIARARE IL PROTOTIPO PRIMA DI RICHIAMARLA -0.5

#include <stdio.h>
#include <stdlib.h>

// FUNZIONE PRIMARIA
int main(int argc, char **argv)
{
	// DIMENSIONE DELL'ARRAY
	int dim;
	printf("Quanti numeri vuoi inserire all'interno dell'array?\n");
	scanf("%d", &dim);

	// DICHIARAZIONE DELL'ARRAY CON LA DIMENSIONE INSERITA DALL'UTENTE
	int lista[dim];

	// INSERIMENTO DEI SINGOLI ELEMENTI
	printf("\nOra puoi inserire i singoli elementi!\n");
	for(int i = 0; i < dim; i++)
	{
		printf("Inserimento numero %d: ", i + 1);
		scanf("%d", &lista[i]);
	}

	// OUTPUT
	int valore;
	valore = compresiMultipli3(lista, dim);
	if(valore == 1)
	{
		printf("\nCONDIZIONE RISPETTATA!\n\n");
	}
	else
	{
		printf("CONDIZIONE NON RISPETTATA...\n\n");
	}

//******** OUTPUT MOLTO POVERO -0.5


	return 0;
}

// FUNZIONE SECONDARIA
int compresiMultipli3(int lista[], int dim)
{
	// VARIABILE CONTATORE PER SCORRERE L'ARRAY
	int i = 0;

	// VARIABILE DI VERIFICA ESISTENZIALE (INIZIALIZZATA A 0)
	int esiste = 0;

	// CICLO WHILE PER LA VERIFICA
	while(i <= dim - 3 && !esiste)
	{
		// VERIFICA DELLA CONDIZIONE
		if((((lista[i] >= -10 && lista[i] <= 10) && (lista[i + 1] >= -10 && lista[i + 1] <= 10)) ||
		((lista[i + 1] >= -10 && lista[i + 1] <= 10) && (lista[i + 2] >= -10 && lista[i + 2] <= 10)) ||
		((lista[i] >= -10 && lista[i] <= 10) && (lista[i + 2] >= -10 && lista[i + 2] <= 10)) ||
		((lista[i] >= -10 && lista[i] <= 10) && (lista[i + 1] >= -10 && lista[i + 1] <= 10)
		//******** E' UNA RIPETIZIONE DELLA PR IMA CONDIZIONE -0.2
		&& (lista[i + 2] >= -10 && lista[i + 2] <= 10)))
		//******** IL TERZO ELEMENTO DELLA TRIPLA DEVE NECESSARIAMENTE ESSERE COMPRESO TRA -10 E 10? -1
		&&
		(((lista[i] % 3 == 0) && (lista[i + 1] % 3 == 0))
		|| ((lista[i + 1] % 3 == 0) && (lista[i + 2] % 3 == 0))
		|| ((lista[i] % 3 == 0) && (lista[i + 2] % 3 == 0))))
		//******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO DIVISIBILI PER 3 ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
        //******** ES. se la tripla e' 3 12 6 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
		{
			esiste = 1;
		}
		else
		{
			i++;
		}


	}


	return esiste;
}
