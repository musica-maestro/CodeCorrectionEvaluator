/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9.5
*/
/* SPECIFICA
 * Input: Una sequenza s di interi e sua lunghezza l
 * Pre-condizioni: l lunghezza di s,l>=3
 * Output: Un intero ugualeCom
 * Post-condizioni: ugualeCom vale 1 se esiste una tripla di elementi
 * consecutivi tale che almeno due elementi della tripla hanno somma
 * compresa tra 10 e 20,con esattamente due elementi della tripla uguali;
 * 0 altrimenti
 * TIPO DI PROBLEMA: Verifica esistenziale
 */
#include <stdio.h>

/* La funzione ugualeCompresi restituisce 1 se esiste una tripla di elementi
 * consecutivi tale che almeno due elementi della tripla hanno somma
 * compresa tra 10 e 20(estremi inclusi),con esattamente due elementi della tripla uguali;
 * 0 altrimenti
 */
int ugualiCompresi(int interi[],int lunghezza)
{
	/* Variabile di esistenzialità */
	int ugualeCom=0;
	int i=0; /* Variabile contatore */

	/* Fintanto che la stringa non è terminata e ugualeCom è uguale a 1*/
	while(i<lunghezza-2 && !ugualeCom)
	{

		if(((interi[i]+interi[i+1] >= 10 && interi[i]+interi[i+1] <= 20)
		|| (interi[i+1]+interi[i+2] >= 10 && interi[i+1]+interi[i+2] <= 20)
		|| (interi[i]+interi[i+2] >= 10 && interi[i]+interi[i+2] <= 20)) &&
			((!(interi[i]==interi[i+1])==interi[i+2])
			||(!(interi[i+1] == interi[i+2])==interi[i])
			|| (!(interi[i]==interi[i+2])==interi[i+1])))
		//******** LE INTENZIONI SONO BUONE MA NON FUZIONA PERCHE' IL RISULTATO DEL CONFRONTO E' 0/1
		//******** E NON IL VALORE EFFETTIVO DELLA COMPONENTE DELL'ARRAY -1.5
			ugualeCom=1; /* Esiste una tripla che rispetta la sequenza */
		else
			i++; /* Proseguo avanti */
	}

	return ugualeCom;
}

int main(int argc, char **argv)
{
	/* Input */
	int lunghezza; /* Dimensione array */
	printf("Caro utente,questo programma verfica se esiste ");
	printf("una tripla di elementi consecutivi nell'array,");
	printf("tali che esattamente due fra loro siano uguali, ");
	printf("con somma compresa tra 10 e 20\n");

	printf("Quanti elementi si desidera inserire? ");
	scanf("%d", &lunghezza);
	/* Dichiarazione array */
	int interi[lunghezza];

	/* Ciclo for per inserimento interi nell'array */
	for(int i=0;i<lunghezza;i++)
	{
		printf("Inserire intero: ");
		scanf("%d", &interi[i]);
	}

	/* Invocazione funzione ugualiCompresi */
	if(ugualiCompresi(interi,lunghezza) == 1)
		printf("Nella sequenza esiste una tripla con somma tra 10 e 20,con due caratteri uguali\n");
	else
		printf("Nella sequenza non esiste una tripla con somma tra 10 e 20,con due caratteri uguali\n");

	return 0;

}
