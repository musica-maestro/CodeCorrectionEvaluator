/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................11
*/
/*SPECIFICA DEL PROBLEMA
 *TIPO DEL PROBLEMA: Verifica Esistenziale
 *INPUT: Una sequenza "v" di interi
 *PRE-CONDIZIONE: Una sequenza "v" di interi di lunghezza "n" >0
 *OUTPUT: Un valore "esistenza" booleano
 *POST-CONDIZIONE: "esistenza" ha val.1 se esiste una tripla di elementi in cui la somma di due elementi è compresa tra 10 e 20 ed esattamente due elementi sono uguali tra loro, 0 altrimenti.
 */

#include <stdio.h>
/*Definizione della funzione "ugualiCompresi" con parametro di ritorno "int". */
int ugualiCompresi(int v[], int n){

	int esistenza=0; //Variabile utilizzata per la verifica esistenziale
	/*Dichiarazione con inizializz. della variabile contatore a 0 e controllo del valore di "esistenza". Finchè è pari a 0 continua il ciclo, fermandoti ad "n-2". */
	for(int i=0; i<n-2 && esistenza==0; i++)
		if(((v[i]+v[i+1]>=10 && v[i]+v[i+1]<=20)
		|| (v[i]+v[i+2]>=10 && v[i]+v[i+2]<=20)
		|| (v[i+1]+v[i+2]>=10 && v[i+1]+v[i+2]<=20))
		&& ((v[i]==v[i+1] && v[i]!=v[i+2])
		|| (v[i]==v[i+2] && v[i]!=v[i+1])
		|| (v[i+1]==v[i+2] && v[i+1]!=v[i])))
	       esistenza=1;

		/*Ritorno del valore alla funzione principale, main. */
		return esistenza;

}

/*Funzione principale */
int main()
{
	/*Dichiarazione della funzione "ugualiCompresi"*/
	int ugualiCompresi(int v[], int n);
	int a,n;
	/*Inserimento della lunghezza dell'Array */
	printf("Inserisci la lunghezza dell'Array: \n");
	scanf("%d",&n);
	/*Dichiarazione dell'Array di Interi */
	int v[n];

	/*Caricamento dell'Array di interi */
	for(int i=0; i<n; i++){
		printf("Inserisci l'elemento di posizione %d nell'Array: \n",i+1);
		scanf("%d",&v[i]);
	}
	/*Invocazione della funzione "ugualiCompresi" con passaggio dei parametri attuali "v,n" ai parametri formali. */
    a=ugualiCompresi(v,n);

	/*Stampa del risultato con valore di ritorno in "a". */
	if(a==1)
		printf("Esiste una tripla di interi in cui almeno la somma di due elementi %c compresa tra 10 e 20 ed esattamente due elementi sono uguali tra loro. \n",138);
	else
		printf("Nessuna tripla di interi contiene due elementi la cui somma %c compresa tra 10 e 20 ed esattamente due elementi uguali tra loro. \n",138);

}
