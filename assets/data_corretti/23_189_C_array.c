/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......0
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............3.8
*/
/*SPECIFICA*
*input: un intero lunghezza e una sequenza di interi*
*pre-condizione: lunghezza rappresenta la grandezza dell'array* //******* GLI INTERI DEVONO ESSERE POSITIVI -0.2
*output: un intero risultato*
*post-codizione: intero è 1 se l'istanza è positiva altrimenti vale 0*
*il problema in questione è una verifica universale*/

#include <stdio.h>

/*funzione che controlla un array di interi e verifica se tutte le triple hanno almeno due numeri con una cifra*/
int dueUnaCifra(int seq[], int lunghezza){
	int risultato=0;   /*variabile di universalità*/ //***
	int i=0;           /*variabile indice array*/

	//***** CONFRONTI LA LUNGHEZZA CON IL CONTENUTO DELL'ARRAY -1.5
	while(seq[i]<lunghezza-3 && !risultato)     /*scorro l'array */ //****** lunghezza<=3 -0.5
	if(seq[i]<='9' && seq[i]>='0' && seq[i+1]<='9' && seq[i+1]>='0' && seq[i+2]<='9' && seq[i+2]>='0')    /*condizione da verificare*/
		//******** CONDIZIONE SBAGLIATA -1.5 //******* CONFRONTI UN INTERO CON UN CARATTERE! -1.5
	risultato=1;  /*condizione verificata*/  //******* QUESTA E' UNA VERIFICA ESISTENZIALE -2
	else
		i++ /*condizione non verificata faccio scorrere l'array*/

		return risultato;

}




int main(){
	   int lunghezza;   /*lunghezza dell'array*/
       printf("utente inserisca quanti interi bisogna aggiungere\n");
       scanf("%d",&lunghezza);    /*input quanto sarà grande l'array*/
       printf("adesso inserisci gli interi\n");
       int sequenza[lunghezza];   /*dichiarazione dell'array che avrà indice la lunghezza fornita da tastiera*/
       for(int i=0;i<lunghezza;i++){  /*ciclo for per l'input*/

   	    scanf("%d",&sequenza[i]);

        }
        if(dueUnaCifra (sequenza, lunghezza))    /*richiamo la funzione di controllo triple*/
        	printf("caro utente tutte la triple sono state verificate e ognuna ha almeno due interi con una cifra\n");   /*condizione verificata vera*/
        else
        	printf("caro utente tutte la triple sono state verificate e non in alcune ci sono meno di due interi con una cifra\n"); /*condizione verificata falsa*/
        	return 0;




}

