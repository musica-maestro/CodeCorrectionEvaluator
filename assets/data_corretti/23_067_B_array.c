/* SPECIFICA (max 1):......0.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3.5
   MAIN PROGRAM (max 2):...1
   TOTALE (10).............6
*/
/*SPECIFICA: data una sequenza di interei verificare se in ogni tripla ci sono esattamente due positivi
*input:un array di interi //******** MANCA LA LUNGHEZZA -0.2
*Pre:array con almeno tre interi
*output:vero se esiste falso se non esiste
*Post:                   //******* MANCA POST CONDIZIONE -0.3
*Tipo Di Problema: problema di verifica universale*/
#include <stdio.h>

int esattamentedue(int a, int b, int c){
	return((a>0 && b>0 && c<=0)||(a>0 && c>0 &&b<=0)||(b>0 && c>0 && a<=0));
}

//funzione che riceve un array e la sua lunghezza e verifica
//se in ogni tripla ci sono esattamente sue positivi
int duePositivi(int a[],int l){
	int risp=1;
	for (int i = 0; i < l; ++i) //******** INDICE DELL'ARRAY FUORI DAI LIMITI, DEVE ESSERE i<l-2 -1
	{
		if (!esattamentedue(a[i],a[i+1],a[i+2]))
		{
			risp=0;
		}else
			risp=1;  //******** RESTITUISCI IL VALORE CALCOLATO SULL'ULTIMA TRIPLA -1.5
	}
	return risp;
}

//funzione main che interagisce con l'utente e richiama la funzione duePositivi
int main(int argc, char const *argv[])
{
	//INPUT
	int l;
	printf("ciao utente quanti interi vuoi inserire: ");
	scanf("%d",&l);
	int a[l];
	for (int i = 0; i < l; ++i)
	{
		printf("inserire un intero: ");
		scanf("%d",&a[i]);
	}

	//OUTPUT
	if (duePositivi(a,l))
	{
		printf("esiste\n");
}//************ OUTPUT NON DICE NULLA E MANCA L'ELSE -1