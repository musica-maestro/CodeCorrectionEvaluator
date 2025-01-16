/* SPECIFICA (max 1.5):....0.7
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.1
   TOTALE..................9.8
*/
#include <stdio.h>
//Input: sequenza di ineteri x1, x2, ... xn
// Problema di tipo: Verifica esistenziale (si ferma quando l'istanza del problema risulta verificata)
//Output: 1 se l'istanza del problema è verificata, 0 se l'istanza del problema non è verificata
//***** MANCANO PRE E POST CONDIZIONI -0.8

int compresiMultipli3(int array[],  int lunghezza){
	int i=0;
	int esiste =0;
	while(i<(lunghezza-2) && !esiste){
		//verifico che almeno due elementi della tripla sono compresi tra -10 e 10
		if(((array[i]>=-10 && array[i]<=10) && (array[i+1]>=-10 && array[i+1]<=10))
		|| ((array[i+1]>= -10 && array[i+1]<=10) && (array[i+2]>=-10 && array[i+2]<=10))
		|| ((array[i]>=-10 && array[i]<=10) && (array[i+2]>=-10 && array[i+2]<=10)))
			//verifico che solo due elementi della tripla sono multipli di 3
			if(((array[i]%3==0) && (array[i+1]%3==0) && (array[i+2]%3!=0))
			|| ((array[i]%3==0) && (array[i+1]%3!=0) && (array[i+2]%3==0)) |
			| ((array[i]%3!=0) && (array[i+1]%3==0) && (array[i+2]%3==0))){
				//abbiamo trovato una tripla
				esiste =1;
			}
	}
	// lo verifico per tutta la sequenza
	i++;
return esiste;
}


int main(int argc, char **argv)
{
	int l;
	printf("Ciao utente sono un programma che analizza una sequenza di interi e restituisce 1 se in unsa tripla consecutiva almeno due elementi hanno valore compreso tra -10 e 10\n");
	printf("e che contiene esattamente due interi multipli di 3, altrimenti restituisco 0\n");
	printf("\n");
	printf("inserisci il numero di interi della sequenza\n");
	scanf("%d", &l);	 // leggo la lunghezza della sequenza
	int sequenza[l];
	printf("adesso inserisci i valori della sequenza\n");
	for(int i=0; i<l; i++)		//leggo i valori della sequenza con un ciclo for e una variabile per scorrere l'array
		scanf("%d", &sequenza[i]);
		if(compresiMultipli3(sequenza, l)==1)  //******INDENTAZIONE ERRATA -0.2
			printf("Nella sequenza di interi esiste una tripla che verifica l'istanza del problema!!!\n");
			else //******INDENTAZIONE ERRATA -0.2
				printf("Nella sequenza di interi che hai inserito non ci sono triple che verificano l'istanza del problema\n");

}

