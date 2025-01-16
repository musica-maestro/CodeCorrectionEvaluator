/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................10.5
*/
#include <stdio.h>
/*SPECIFICA
 * input: una sequenza s di interi di lunghezza l
 * pre-condizione:l è la lunghezza di s
 * output: un valore 1 o 0
 * post-condizione: il valore sarà 1 se esiste una tripla di elementi consecutivi che contiene almeno
 *                   due elementi due elementi il cui valore è compreso fra -10 e 10 e che contiene
 *                   esattamente due elementi multipli di 3, altrimenti vale 0*/
 /*TIPO DI PROBLEMA: problema di verifica esistenziale*/

 /*funzione che calcola se esiste una tripla di elementi consecutivi che contiene almeno
 *due elementi due elementi il cui valore è compreso fra -10 e 10 e che contiene
 *esattamente due elementi multipli di 3*/
int compresiMultipli3(int seq[],int dim){
	int i=0;
	int multipli=0;
	while(i<dim-3 && !dim){ //******** NON CONSIDERI L'UTIMA TRIPLA, DEVE ESSERE i<=dim-3 -0.5
		if(((((-10<=seq[i] && seq[i]<=10)&&(-10<=seq[i+1] && seq[i+1]<=10))||
		   (-10<=seq[i] && seq[i]<=10)&&(-10<=seq[i+2] && seq[i+2]<=10))||
		   (-10<=seq[i+1] && seq[i+1]<=10)&&(-10<=seq[i+2] && seq[i+2]<=10))&&
		   ((seq[i]%3==0 && seq[i+1]%3==0 && seq[i+2]%3!=0)||
		   (seq[i+1]%3==0 && seq[i+2]%3==0 &&seq[i]%3!=0)||
            (seq[i]%3==0 && seq[i+2]%3==0 && seq[i+1]%3!=0)))

		    multipli=1;
		else
			i++;
    return multipli;
	}

}
/*funzione principale*/
int main(){
	int dim;
	/*INPUT*/
	printf("Quanti interi ha la sequenza: ");
	scanf("%d",&dim);

	int seq[dim];
	for(int i=0;i<dim;i++){
		printf("Introduci un intero: ");
	    scanf("%d",&seq[i]);
	}

	/*OUTPUT*/
	if(compresiMultipli3(seq,dim))
		printf("esiste una tripla di elementi consecutivi che contiene almeno due elementi il cui valore è compreso fra -10 e 10 e che contiene esattamente due elementi multipli di 3\n");
	else
		printf("NON esiste una tripla di elementi consecutivi che contiene almeno due elementi il cui valore è compreso fra -10 e 10 e che contiene esattamente due elementi multipli di 3\n");

}
