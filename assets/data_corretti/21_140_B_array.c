/* SPECIFICA (max 1.5):....1,3
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................10.4
*/
#include <stdio.h>

//problema di verifica universale
/*INPUT: una sequenza di interi e un intero l
 * pre-cond: l è pari alla lunghezza dell'array e l >= 3
 * OUTPUT: un valore di verità: verificato
 * post-cond: verificato vale 1 se ogni tripla di elementi consecutivi contiene esattamente due elementi >= 5 ed almeno due elementi pari*/
//******** POST-CONDIZIONE NON COMPLETA (0 ALTRIMENTI) -0.2

int maggiori5Pari (int array[], int l){

	int i;  //variabile per scandire la sequenza
	i = 0;

	int verificato;   //variabile di universalità
	verificato = 1;



	while((i < l-2) && verificato){
		if ((array[i] >= 5 && array[i+1] >= 5) || (array[i+1] >= 5 && array[i+2] >= 5) || (array[i+2] >= 5 && array[i] >= 5)){
			if (array[i] >= 5 && array[i+1] >= 5 && array[i+2] >= 5)
				verificato = 0;
			else{
			   if ((array[i]%2==0 && array[i+1]%2==0) || (array[i+1]%2==0 && array[i+2]%2==0) || (array[i]%2==0 && array[i+2]%2==0))
				i++;

			  else  //******** INDENTATO MALE -0.2
				verificato = 0;
		 }
			}
		else //******** INDENTATO MALE -0.2
			verificato = 0;
	}
	return verificato;
}

int main(int argc, char **argv)
{
	printf("Caro utente questo programma verifica se ogni tripla di elementi consecutivi \n");
	printf("in una sequenza di interi contiene esattamente due elementi maggiori o uguali a %d \n", 5);
	printf("e almeno due numeri pari");

	int l;
	printf("quanti interi vuoi inserire%c\n", '?');
	scanf("%d", &l);

	int array[l];
	printf("quali interi vuoi inserire%c\n", '?');
	for (int i=0; i<l; i++)
		scanf("%d", &array[i]);

	int res;

	res=maggiori5Pari(array,l);

	if (res == 1)
		printf("nella sequenza la proprieta' e' verificata\n");
	else
		printf("la proprieta' non e' verificata");
	return 0;
}
