/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................10
*/
/*SPECIFICA
 * Un programma che data una sequenza di interi
 * e la sua lunghezza, verifica se esiste una
 tripla di elementi mconsecutivi che contiene
  * almeno due elementi il cui valore è compreso fra
  * -10 e 10 (estremi inclusi) e che contiene
  * esattamente due elementi multipli di 3
  * Input: un'array di interi e  lunghezza
  * Pre-condizioni: lunghezza è la lunghezza dell'array
  * Output: 0 o 1
  * Post-condizioni: 0 se istanza negativa, 1 se istanza positiva//******** LA POST-CONDIZIONE NON DICE NULLA -0.5
  * TIPO DI PROBLEMA: Verifica esistenziale*/

#include <stdio.h>
 //funzione che vede se n è compreso tra -10 e 10
int compreso(int n){
	if(n>=-10 && n<=10){ //******** 2 RETURN PER 4 RIGHE DI CODICE! -0.5
		return 1;
	}
	else
		return 0;
}

//funzione che vede se n è multiplo di 3
int multiplo3(int n){
	if(n%3==0){//******** 2 RETURN PER 4 RIGHE DI CODICE! -0.5
		return 1;
	}
	else
		return 0;
}

//funzione per gestire l'array
int compresiMultipli3(int array[], int lunghezza){
	int vero=0;  //variabile di verifica
	int i=0;    //variabile contatore


	//scorro l'array
	while(i<lunghezza-2 && !vero){
		//se nella tripla corrente almeno due sono compresi tra -10 e 10 verifico anche che solo due siano multipli altrimenti vado avanti
		if((compreso(array[i]) && compreso(array[i+1]))
		|| (compreso(array[i]) && compreso(array[i+2]))
		|| (compreso(array[i+1]) && compreso(array[i+2]))){

			//ho torvato che nella tripla ci sono almeno due compresi tra -10 e 10 ora controllo che solo due siano multipli di 3, se lo sono allora ho trovato una tripla che soddisfa
			if((multiplo3(array[i]) && multiplo3(array[i+1]) && array[i+2]%3!=0)
			|| (multiplo3(array[i]) && multiplo3(array[i+2]) && array[i+1]%3!=0) ||
			(multiplo3(array[i+1]) && multiplo3(array[i+2]) && array[i]%3!=0)){
				vero=1;
			}
		}
		i++;
	}
return vero;
}

//funzione main
int main(){
	printf("Ciao utente, quanti elementicontiene il tuo array? (minimo 3): \n");
	int l;
	scanf("%d", &l);
	int a[l];
	for(int i=0;i<l;i++){
		printf("Inserisci il %d elemento dell'array: ", i+1);
		scanf("%d", &a[i]);
	}
	if(compresiMultipli3(a,l)){
		printf("ISTANZA POSITIVA!\n");//******** OUTPUT MOLTO POVERO -0.5
	}
	else{
		printf("ISTANZA NEGATIVA!\n");
	}
}
