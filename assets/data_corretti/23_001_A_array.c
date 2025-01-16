/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
/*SPECIFICA
INPUT:una sequenza'sequenza di interi e un intero n
pre-condizioni: n è la lunghezza di 'sequenza'
OUTPUT: un intero tutti
podt-condizioni: tutti vale 1 se in tutte le triple eiste almeno un elemento che è multiplo di un altro, vale 0 altrimenti
TIPO DI PROBLEMA: verifica universale
*/

#include <stdio.h>

/*funzione che dati due numeri ci dice se uno è multiplo dell'altro*/
int isMultiplo(int a,int b){
	int multiplo=0;
	if(a%b==0 || b%a==0)
		multiplo=1;

	return multiplo;
}

/*funzione che verifica se in tutte le triple di una sequenza di interi di lunghezza l
esiste almeno un elemento che è multiplo dell'altro*/
int Multipli(int *sequenza,int l){
	int i=0;		//variabile contatore
	int tutti=1;	//variabile universale

	while(i+2<l && tutti){
		/*se non accade che almeno un elemento è multiplo dell'altro nella terna allora
		inizializza tutti=0*/
		if(!(isMultiplo(sequenza[i],sequenza[i+1]) || isMultiplo(sequenza[i+1],sequenza[i+2]) || isMultiplo(sequenza[i],sequenza[i+2]))){
			tutti=0;
		}
		/*se ciò non accade passa alla prossima terna*/
		else
			i++;
	}
	return tutti;
}

int main(){
	int i,n;		//dichiarazione variabili

	//INPUT
	printf("inserisci il numero degli elementi della tua sequenza\n");
	scanf("%d",&n);
	int sequenza[n];		//dichiarazione sequenza
	printf("inserisci gli elementi della tua sequenza\n");
	for(i=0;i<n;i++)
		scanf("%d",&sequenza[i]);

	//OUTPUT
	if(Multipli(sequenza,n))
		printf("in tutte le triple della seqeunza c'%c almeno un elemento che %c multiplo dell'altro\n",138,138);
	else
		printf("esiste almeno una tripla della sequenza in cui nessun elemento %c multiplo dell'altro",138);
}