/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................7.5
*/
#include <stdio.h>
/* il problema richiede di controllare se ogni tripla della sequenza di interi contiene esattamente  2 elementi maggiori o uguali a 5*/
//***************** RICHIEDE ANCHE DI VERIFICARE SE CI SONO ALMENO DUE PARI IN CIASCUNA TRIPLA! ***************************
/*e' un problema di verifica universale*/

/*SPECIFICA
 * Input : una sequenza di n interi (x1,x2...xn)
 * Pre-condizione : n>=3
 * Output : un valore booleano
 * Post-condizione  tutti */ //******** LA POST-CONDIZIONE NON DICE NULLA -0.5


int maggiori5Pari(int array[],int len){
	int tutti =1;

	for (int i=1;i<len-1;i++){//******** NON USI LA VARIABILE BOOLEANA PER TERMINARE IL CICLO -1
		if ( !((array[i]>=5 && array[i+1]>=5 && array[i-1]<5)||
		(array[i]<5 && array[i+1]>=5 && array[i-1]>=5)||
		(array[i]>=5 && array[i+1]<5 && array[i-1]>=5))){
			tutti=0;
		} //******** NON VERIFICHI SE CI SONO ALMENO DUE PARI! -2

	}
	return tutti;
	}
int main()
{	int len ;

	printf("Salve quanti interi si vogliono inserire ?\n");
	scanf("%d",&len);
	int array[len];
	for (int i=0;i<len;i++){
		printf("Prego inserire il %d numero",i+1);
		scanf("%d",&array[i]);
		}
	if (maggiori5Pari(array,len)==1){
		printf("SI, ogni tripla contiene 2 elementi maggiori o uguali a 5\n");}
	else
		printf("NO, ogni tripla contiene 2 elementi maggiori o uguali a 5\n");
	   //**** COERENTE CON LA FUNZIONE!!!!
	return 0;
}
