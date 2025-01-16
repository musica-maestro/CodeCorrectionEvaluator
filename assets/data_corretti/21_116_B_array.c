/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................11
*/
/*SPECIFICA DEL PROBLEMA
 * Input: array di interi 'sequenza' e lunghezza 'lunghezza'
 * Pre-Condizioni: 'lunghezza' Ã¨ la lunghezza della sequenza
 * Output: intero 'verificato'
 * Post-Condizioni: 'verificato' restituisce 1 se ogni tripla di elementi consecutivi contiene esattamente due ellementi maggiori o uguali a 5ed almeno due elementi pari, altrimenti restituisce 0
 * Tipo di problema: verifica universale
 */

 #include<stdio.h>
 /*funzione che restituisce 1 se ogni tripla di elementi consecutivi contiene esattamente due ellementi maggiori o uguali a 5ed almeno due elementi pari, altrimenti restituisce 0*/
 int maggiori5Pari( int interi[], int lunghezza){
	 int i; //contatore
	 int verificato; //valore da restituire
	 i=0;
	 verificato=1;
	 /*vai avanti fino alla fine della sequenza di interi e fino a quando verificato vale 1*/
	 while(i<lunghezza-2 && verificato){
		 /*la proprietà è falsa?*/
		 if(!(((interi[i]>=5 && interi[i+1]>=5 && interi[i+2]<5)
		 || (interi[i]>=5 && interi[i+2]>=5 && interi[i+1]<5) |
		 |(interi[i+1]>=5 && interi[i+2]>=5 && interi[i]<5))
		 && ((interi[i]%2==0 && interi[i+1]%2==0) || (interi[i]%2==0 && interi[i+2]%2==0) || (interi[i+1]%2==0 && interi[i+2]%2==0) || (interi[i]%2==0 && interi[i+1]%2==0 && interi[i+2]%2==0))))
			 verificato=0;   //***** L'ULTIMA CONDIZIONE NON SERVE, E' RIDONDANTE
		 else
			 i++;
	 }
	 return verificato;
 }

/*funzione pricipale*/
int main(int argc, char**argv){
	int lunghezza;
	/*Input*/
	printf("Caro utente sono un programma che verifica che in una sequenza ogni tripla contiene esattamente due elementi maggiori o uguali di 5 e almeno due pari\n");
	printf("Inserisci la lunghezza dlla sequenza\n");
	scanf("%d",&lunghezza);
	int sequenza[lunghezza];
	for(int i=0;i<lunghezza;i++){
		printf("Introduci un intero \n");
		scanf("%d",&sequenza[i]);
	}
	/*Output*/
	if(maggiori5Pari(sequenza,lunghezza)){
		printf("Ogni tripla della sequenza rispetta le caratteristiche\n");
	}
	else{
		printf("Non tutte le triple della sequenza rispettano le caratteristiche\n");
	}
}