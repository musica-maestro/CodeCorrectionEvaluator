/* SPECIFICA (max 1.5):....1.2
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.1.9
   TOTALE..................9.1
*/

/* Funziona che restituisce 1 se in almeno una tripla esistono 2 interi la cui somma e' compresa fra 10 e 20 e se esistono ESATTAMENTE 2 interi uguali nella estessa tripla
 * Input: Array di interi, lunghezza array
 * Pre-condizione: Lunghezza array > 2, interi nell'array
 * Output: 1 o 0, Valore booleano
 * Post-condizione: Se esiste una tripla con esattamente 2 interi la cui somma e' compresa fra 10 e 20 e se esistono ESATTAMENTE 2 interi uguali nella estessa tripla, allora l'isanza e' positia.
 * Tipo di problema: Verifica universale //******** TIPO DI PROBLEMA ERRATO, e' esistenziale -1
*/
//******** POST-CONDIZIONE NON CORRETTA (almeno due interi, non esattamente) -0.3


#include <stdio.h>
int ugualiCompresi(int *a, int l)
{
	int i=0;
	int compresi=0;
	// Continua fino a che finisce l'array o se compresi e' falso
	while (i<l-2 && !compresi)
	{
		//se la somma fra almeno 2 numeri della tripla sono 20
		if ((a[i]+a[i+1]>=10 && a[i]+a[i+1]<=20) || (a[i]+a[i+2]>=10 && a[i]+a[i+2]<=20) || (a[i+1]+a[i+2]>=10 && a[i+1]+a[i+2]<=20))
		{
			//se esattamente 2 sono uguali
			if ((a[i]==a[i+1] && a[i]!=a[i+2]) || (a[i]==a[i+2] && a[i]!=a[i+1]) || (a[i]!=a[i+1] && a[i+1]==a[i+2]))
			{
				//trovato
				compresi=1;
			}
		}
		i++;

	}
	return compresi;
}
int main()
{
	int lunghezza;  //******** MANCANO COMMENTI -0.3
	int x;
	printf("Inserisci numero di interi: "); //******** I/O UN PO' POVERO -0.3
	scanf("%d", &lunghezza);
	int array[lunghezza];
	for (x=0; x<lunghezza; x++)
	{
		printf("Inserisci il %d numero: ", x+1);
		scanf("%d", &array[x]);
	}
	if (ugualiCompresi(array, lunghezza))
	{
		printf("\n\nL'instanza e' positiva, nella sequenza esiste una tripla con esattamente 2 interi la cui somma e' compresa fra 10 e 20 e esistono esattamente 2 interi uguali nella estessa tripla");
	}
	else
	{
		printf("\n\nL'instanza e' negativa, nella sequenza NON esiste una tripla con esattamente 2 interi la cui somma e' compresa fra 10 e 20 o NON esistono esattamente 2 interi uguali nella estessa tripla");
	}
	return 0;
}
