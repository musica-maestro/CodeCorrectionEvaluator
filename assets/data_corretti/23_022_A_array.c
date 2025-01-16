/* SPECIFICA (max 1):......0.5
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......1.5
   MAIN PROGRAM (max 2):...0.8
   TOTALE (10).............2.8
*/
/*SPECIFICA
* INPUT: una sequenza s di lunghezza l detta dall'utente
* PRE-CONDIZIONE: la sequenza s deve essere di l>=3
* OUTPUT: comunicazione all'utente, della verifica della condizione
//********** NOME DELLA VARIABILE DI OUTPUT? -0.2
* POST-CONDIZIONE: almeno uno di 3 numeri adiaceni deve essere u multiplo di un altro
//********** LA VARIABILE E' VERA SE... FALSA ALTRIMENTI -0.3
* TIPO DI PROBLEMA: verifica esistenziale
//********* E' UNA VERIFICA UNIVERSALE! -1

*/

#include <stdio.h>

int multipli (int interi[], int lunghezza){
int c=0; //contatore multipli
int m1;
int m2;
int m3;
	for (int i = 0; i < lunghezza; ++i)
	{
		int limite= i+3;
		for (int p=i; p<limite; p++)
			{
			//******* mancano i commenti e non si capisce, ma comunque manca una terza combinazione da verificare -1
				if ((interi[p]%interi[p+1]==0) && (!(p+1>limite)))
				{
					return 1;
				}
				else
				{
					return 0;
				}
				if ((interi[p]%interi[p+2]==0) && (!(p+2>limite)))
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}//******** 4 RETURN NON E' PROGRAMMAZIONE STRUTTURATA -1.5
             //******** esci non appena trovi la condizinoe soddisfatta, ma deve essere una verifica universale, non
             //******** esistenziale -2
	}
}

int main()
{
	int l;
	int s[l]; //******** l'array lo devi dichiarare solo dopo aver acquisito la lunghezza -0.5
	printf("questo programma ti dira se nelle sequenze di terne nella stringa ci sono dei numeri che sono i multipli di altri\n");
	printf("inserisci la lunghezza della sequenza: ");      //****** non è una stringa -0.2
	scanf("%d", &l);
	printf("\nora inserisci i numeri della sequenza\n");
	for(int j=0; j<l; j++)
		 {
		 	scanf("%d", &s[j]);
		 }
		 multipli(s, l); //******* questa non serve
	if (multipli(s, l)==1)
	{
		printf("nella sequenza tutte le terne contengono multipli");
	}
	else
	{
		printf("nella sequenza non ci sono multipli");
	} //************ output non chiaro -0.5
}