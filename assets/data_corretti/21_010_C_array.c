/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................9
*/
#include <stdio.h>
/*SPECIFICA
 * INPUT:una sequenza di interi s e la sua lunghezza l
 * PRE-COND:l rappresenza la dimensioine di s
 * OUTPUT: un valore booleano verifica, true o false
 * POST-COND:il valore verifica è uguale a 1 se la tripla da esito positivo alla proprietà, 0 altrimenti
 * TIPO: problema di verifica esistenziale.*/ //******** CHE VUOL DIRE ESITO POSITIVO, QUALE TRIPLA -0.5

/*funzione che verifica se la tripla rispetta la proprietà*/
int compresimultipli3(int *sequenza, int lunghezza){
	int verifica = 0;											//variabile esistenziale inizializzata

	int i=0;
		while(i<lunghezza && !verifica){
			if(((sequenza[i]>=-10 && sequenza[i]<=10)&&(sequenza[i+1]>=-10 && sequenza[i+1]<=10))&&(!(sequenza[i+2]>=-10 && sequenza[i+2]<=10)) ||
//******** DEVI CONTROLLARE CHE ALMENO 2 SIANO COMRESI TRA -10 E 10, NON ESATTAMENTE 2 -1
				((sequenza[i+1]>=-10 && sequenza[i+1]<=10) &&(sequenza[i+2]>=-10 && sequenza[i+2]<=10)&&(!(sequenza[i]>=-10 && sequenza[i]<=10)))||
				((sequenza[i]>=-10 && sequenza[i]<=10) && (sequenza[i+2]>=-10 && sequenza[i+2]<=10)&&(!(sequenza[i+1]>=-10 && sequenza[i+1]<=10)))&&
				((sequenza[i]%3==0 && sequenza[i+1]%3==0 && sequenza[i+2]%3!=0)
				|| (sequenza[i]%3==0 && sequenza[i+2]%3==0 && sequenza[i+1]%3!=0)||
				(sequenza[i+1]%3==0 && sequenza[i+2]%3==0 && sequenza[i]%3!=0)))
				verifica= 1;
		else
			i++;

		}
	return verifica;
}

/*funzione principale*/
int main()
{
	int lunghezza;							//dimensione array
	 printf("ciao sono unn programma che verifica se esiste almeno,\n");
	 printf("una tripla nella sequenza che rispetta la proprieta'\n");
	 printf("inserisci la lunghezza della tua sequenza: ");
	 scanf("%d", &lunghezza);

	 /*dichiarazione dell'array*/
	 int sequenza[lunghezza];
		for(int i=0; i<lunghezza; i++){
			printf("inserisci un valore:");
			scanf("%d", &sequenza[i]);
		}

	/*richiamo e stampa della funzione */
	if(compresimultipli3(sequenza, lunghezza))
	  printf("la tua sequenza ha dato esito positivo\n\n");
	else
		 printf("la tua sequenza ha dato esito negativo\n\n");
}//******** OUTPUT MOLTO POVERO -0.5
