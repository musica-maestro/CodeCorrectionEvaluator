/* SPECIFICA (max 1.5):....0.4
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9.9
*/
#include <stdio.h>
/*Specifica problema
 * input: lunghezza della sequenza ed elementi della sequenza //******** MANCANO I TIPI DEGLI ELEMENTI DELL'ARRAY -0.6
 * prec: n>=3
 * output: 1 se la sequenza contiene essattamente due elementi maggiori o uguali a 5 ed almeno due elementi pari,0 altrimenti
 * postc:  //******* L'OUTPUT E' UN INTERO. TU HAI SCRITTO LA POST-CONDIZIONE -0.5
 *
 * Problema di verifica universale*/

int maggiori5Pari(int seq[],int l){
	//pre:  l è la lunghezza di seq
	int k=1;
	int i=0;
	while(i<l && k){
	if(((seq[i]<=5 && seq[i+1]<=5)
	|| (seq[i]<=5 && seq[i+2]<=5)
	|| (seq[i+1]<5 && seq[i+2]<=5)
	|| (seq[i]>5 && seq[i+1]>5 && seq[i+2]>5))
	&&
		((seq[i]%2==1 && seq[i+1]%2==1)|| (seq[i]%2==1 && seq[i+2]%2==1) || (seq[i+1]%2==1 && seq[i+2]%2==1)))
			k=0;

		else
			i++;

	}

	return k;

}






int main(int argc, char **argv)
{
	int lunghezza;    //lunghezza della sequenza
	printf("Utente inserisci la quantita' di numeri che si vogliono inserire nella sequenza\n");
	/* input */
	scanf("%d",&lunghezza);
	int sequenza[lunghezza];
	printf("Utente inserisci ora gli interi che si voglioono inserire nella sequenza\n");
	for(int i=0;i<lunghezza;i++)
		scanf("%d",&sequenza[i]);

	/*output */
	if(maggiori5Pari(sequenza,lunghezza))
		printf("La sequenza contiene essattamente due elementi maggiori o uguali a 5 ed almeno due elementi pari");
	else
		printf("La sequenza NON contiene essattamente due elementi maggiori o uguali a 5 ed almeno due elementi pari");



}
