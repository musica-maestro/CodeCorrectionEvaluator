/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............9.5
*/
/*programma che verifica se ogni tripla di interi contiene esattamente due positivi*/


/*SPECIFICA

*INPUT: lunghezza e sequenza di interi
*PRE-CONDIZIONE: la lunghezza corrisponde al numero di interi nella sequenza, e deve essere maggiore a tre
*OUTPUT: variabile booleana "verificato"
POST-CONDIZIONE: "verificato" è 1 se per ogni tripla ci sono esattamente due positivi, sennò 0

*TIPO DI PROBLEMA: verifica universale
*/


#include <stdio.h>


/*funziona che verifica che sia rispettata la proprietà*/
int duePositivi(int array[],int dim){

	int nPositivi, verificato=1;

	/*analizzo tutte le terne finché o finisce la sequenza o trovo una terna per cui non vale*/
	for(int i=0; i+2<dim && verificato; i++){
		nPositivi=0;

		/*conto quanti positivi ci sono con una for che fa tre giri*/
		for(int k=i; k<i+3; k++){
			if(array[k]>=0)
				nPositivi++;

		}

		if(nPositivi!=2) //la proprietà
			verificato=0;

	}

	return verificato;
}


/*funzione main che gestisce interfaccia con l'utente*/
int main(){
	int dim;   //variabile per lunghezza
	int i,v;   //variabile ausiliarie

	printf("Caro utente, questo programma verifica se una sequenza di numeri interi da te inserita soddisfa la propriet%c:",133);
	printf("\nper ogni terna ci sono esattamente due numeri positivi\nQuanti numeri vuoi scrivere: ");
	scanf("%d",&dim);

 	/*controllo che ci sia almeno una terna*/
	while(dim<3){
		printf("Numero non valido, riprova: ");
		scanf("%d",&dim);
	}

	int array[dim];

	printf("Ora inserisci i numeri\n");
	for(i=0;i<dim;i++){
		printf("Numero[%d]:",i);
		scanf("%d",&array[i]);
	}

	v=duePositivi(array,dim);

	if(v)
		printf("La propriet%c %c rispettata\n",133,138 );
	else
		printf("La propriet%c non %c rispettata\n",133,138);
}       //************ OUTPUT NON ESPLICATIVO -0.5
