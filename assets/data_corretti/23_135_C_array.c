/* SPECIFICA (max 1):......0.7
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......2.5
   MAIN PROGRAM (max 2):...1.4
   TOTALE (10).............4.6
*/
/*
   *Input :dimensione array e i suoi valori.
   *Pre-condizione: interi dell'array e della sua dimensione. //******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
   *Post-condizione: verifica che ci siano, all'interno di una terna, almeno due numeri composti da una sola cifra.
   *Output: 1 se nella tripla sono presenti almeno due cifre, oppure 0 in caso contrario.
    *TIPO DI PROBLEMA:  verifica esistenziale*/ //**** ALMENO DUE NUMERI CON UNA SOLA CIFRA -0.1
    //***** NO, E' UNIVERSALE -1
#include <stdio.h>

int dueUnaCifra (int seq[], int lunghezza) {  /*funzione che verifica se nella terna sono presenti almeno due numeri da una sola cifra*/
int risultato;
for (int i = 0; i < lunghezza-2; i++)
{
	if ((0<=seq[i]<=9 && 0<=seq[i+1]<=9 && 0<=seq[i+2]<=9)|| //**** ESSERE COMPRESI TRA 0 E 9 SI SCRIVE seq[i]>=0 && seq[i]<=9  -2
	    (seq[i]>=10 && 0<=seq[i+1]<=9 && 0<=seq[i+2]<=9)||
	    (0<=seq[i]<=9 && seq[i+1]>=10 && 0<=seq[i+2]<=9)||
	    (0<=seq[i]<=9 && 0<=seq[i+1]<=9 && seq[i+2]>=10))
    {
	risultato=1; /*in questo caso sono presenti due numeri da una sola cifra*/
    }															//******** RESTITUISCI IL VALORE CALCOLATO SULL'ULTIMA TRIPLA -1.5

    else risultato=0; /*in questo caso non sono presenti due numeri da una sola cifra*/

}


return risultato; /*la variabile risultato va nella funzione main con valore 1 o 0*/
}


 int main()
{
	int lunghezza;
	printf("Ciao user, quanti elementi deve contenere la sequenza?\n");
	scanf("%d", &lunghezza); /* l'utente iserisce la lunghezza dell'array*/

	int seq[lunghezza];
	for (int i = 0; i < lunghezza; i++)
	{
		printf("digita un numero della sequenza:");  /*ciclo grazie al quale l'utente riempie l'array*/  //***** APPICCICATO -0.1
		scanf("%d", &seq[i]);
	}

dueUnaCifra(seq, lunghezza);  /*invocazione della funzione che verificherà la terna*/ //****** NON SERVE A NULLA!

if (dueUnaCifra(seq, lunghezza)==1)
{
	/*1*/
	printf(" %c un istanza positiva\n ", 138); //************ OUTPUT NON ESPLICATIVO -0.5
}
else{
    /*0*/
	printf(" non %c un' istanza positiva\n", 138);  /*il programma stamperà il messaggio di possibile negatività o positività dell'istanza*/
}

}
