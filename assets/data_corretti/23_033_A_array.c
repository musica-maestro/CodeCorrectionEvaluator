/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
/*specifica del problema
dati input:una sequenza di  interi di lunghezza n
precondizioni:n e' un intero maggiore uguale di tre
dati output:una variabile booleana 'verificato'
post condizioni:verificato vale 1 se in ogni terna di interi consecutivi c'e' almeno un elemento della terna multiplo di uno degli altri due
tipo di problema: verifica universale
*/
#include<stdio.h>
/*funzione che riceve come prametro un riferimento ad un array di interi e la sua lunghezza
restituendo 1 se in ogni terna c'e' almeno un elemento multiplo di uno degli altri due altrimenti restiuisce 0*/
int multipli(int a[],int dim){
	//pre:dim>=3
	int i=0; //indice per scorrere elementi delal sequenza di interi
	int verificato=1; //variabile che diventa 0 appena trovo una terna di cosnecutivi tale da non rispetta la proprieta
	int proprieta; //una variabile booleana che memorizza 1 se e' verificata la proprieta' altrimenti 0


	/*ciclo parte da elemento di posizione i=0 e avanza fino al terzultimo elemento per analizzare
	 ogni terna di consecutivi e si interrompe quando finiscono gli elementi dell'array oppure viene trovata
     una terna che non rispetta la proprieta'*/
	for(i=0;i<dim-2&&verificato;i++){
		/*inzializzo */
		proprieta=(a[i]%a[i+1]==0 ||a[i]%a[i+2]==0||a[i+1]%a[i]==0||a[i+1]%a[i+2]==0||a[i+2]%a[i]==0||a[i+2]%a[i+1]==0);
		/*se non si verifica nella terna */
		if(!proprieta )
			verificato=0;
	}
	return verificato;

}
int main(){
	int lunghezza; //lunghezza della sequenza

	/*INPUT*/
	printf("ciao utente digita la lunghezza della sequenza di interi(almeno tre interi devono far parte della sequenza): ");
	scanf("%d",&lunghezza);

	/*creazione array*/
	int array[lunghezza];
	for(int i=0;i<lunghezza;i++){
		printf("inserire numero intero: ");
		scanf("%d",&array[i]);
	}

	/*invocazione funzione */
	/*se la proprieta' si verifica su ogni terna di interi consecutivi */
	if(multipli(array,lunghezza))
		printf("in tutte le terne di numeri consecutivi si verifica la proprieta'");
	else
		printf("non si verifica la proprieta' in tutte le terne di consecutivi");

}