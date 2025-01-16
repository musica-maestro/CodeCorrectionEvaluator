/* SPECIFICA (max 1.5):....1.3
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2
   TOTALE.................10.3
*/

#include <stdio.h>
/* SPECIFICA
 * Input: array di interi di lunghezza l
 * Pre-condizione: l>=3
 * Output: true/false
 * Post-condizione: true se esiste una tripla che contiene almeno due elementi compresi tra
 * -10 e 10 ed esattamente due elementi multipli di 3  //******** POST-CONDIZIONE NON COMPLETA (FALSE, ALTRIMENTI) -0.2
 * Tipo: verifica esistenziale */
 /* funzione che calcola se un valore è compreso tra -10 e 10*/
 int isCompreso(int n){
	 return (n>=(-10) && n<=10);
 }

 /*funzione che calcola se un intero è multiplo di 3*/
 int isMultiplo3(int n){
	 return (n%3==0);
 }

 /* funzione che riceve una sequenza di interi e determina
  * se esiste almeno una tripla contenente 2 numeri compresi tra -10 e 10
  * ed esattamente due interi multipli di 3 */
  int compresiMultipli3(int seq[], int dim){
	  int esiste=0; //variabile di esistenza
	  int i=0; // indice array
	  while(i<dim-2 && esiste==0){
		  /*almeno due elementi compresi tra -10 e 10*/
		  if ((isCompreso(seq[i]) && isCompreso(seq[i+1])) || (isCompreso(seq[i+1]) && isCompreso(seq[i+2])) || (isCompreso(seq[i]) && isCompreso(seq[i+2]))){
			  /*esattamente due elementi multipli di 3*/
			  if (((isMultiplo3(seq[i]) && isMultiplo3(seq[i+1])) && !isMultiplo3(seq[i+2]))
			  || ((isMultiplo3(i) && isMultiplo3(seq[i+2])) && !isMultiplo3(seq[i+1]))
			  || ((isMultiplo3(seq[i+2]) && isMultiplo3(seq[i+1])) && !isMultiplo3(seq[i]))){
				  esiste =1;
			  }else{ // se non esattamente 2 elementi sono multipli di 3
				  i++; //passa oltre
			  }
		  }else{ // se più di 2 elementi non sono compresi
		  i++;
		}
	}
	return esiste;
  }

 /* funzione principale */
int main(int argc, char **argv)
{
	int dim=0; // lunghezza array
	printf("Quanti interi vuoi inserire? ");
	scanf("%d", &dim);
	int seq[dim]; // creazione array
	for (int i=0; i<dim; i++){
		printf("Inserisci un intero: ");
		scanf("%d", &seq[i]);
	}
	if (compresiMultipli3(seq, dim)){
		printf("Esiste almeno una tripla che soddisfa le proprietà!\n");
	}else{
		printf("Non esiste alcuna tripla che soddisfa la proprietà!\n");
	}
}

//******** OUTPUT MOLTO POVERO -0.5