/* SPECIFICA (max 1):......0
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......0
   MAIN PROGRAM (max 2):...0
   TOTALE (10).............0
*/
#include<stdio.h>
/*programma che verifica se all'interno della sequenza esiste una tripla di elementi adiacenti
in cui uno dei 3 e' il resto della divisione (int) degli altri due*/
/*TIPO DI PROBLEMA problema di verifica universale*/ //***** NO, E' ESISTENZIALE -1

int restoDivisione(int interi[],int lunghezzaarray) //funzione
{
	int num1,num2,num3;  //**** MANCA L'ITERAZIONE -3
	int risultato;       //**** NON E' UNA VERIFICA ESISTENZIALE -2
	if ((num1/num2==num3) || (num2/num3==num1) || (num3/num1==num2))
		risultato=1;    //******** CONDIZIONE SBAGLIATA -1.5
	else
		risultato=0;


}
/*funzione principale*/
int main()
{
	/*INPUT*/
	int sequenza;
	int interisequenza[20];//******** L'ARRAY LO DEVI DICHIARARE SOLO DOPO AVER ACQUISITO LA LUNGHEZZA -0.5
	//chiede all'utente quanti interi ha la sequenza
	printf("quanti interi ha la sequenza?\n");
	scanf("%d",&sequenza);
	// fa introdurre all'utente gli interi
	printf("introduci gli interi della sequenza\n");
	//memorizza gli interi della sequenza in un array
	scanf("%d",&interisequenza);  //******* MANCA ITERAZIONE PER LETTURA ARRAY -1

	/*OUTPUT*/
	 restoDivisione(int sequenza,int interisequenza); //****** IN QUALE VARIABILE VIENE MEMORIZZATO IL RISULTATO? -0.5
	if (risultato=1)
	printf("nella sequenza esiste una terna di elementi in cui uno dei tre e' il resto della divisione degli altri due\n");
	else
	printf("nella sequenza NON esiste una terna di elementi in cui uno dei tre e' il resto della divisione degli altri due\n");

}

