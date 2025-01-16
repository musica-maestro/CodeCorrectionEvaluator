/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.5
*/
/*SPECIFICA

*Input: sequenza di interi fino ad una lunghezza l

*Pre condizione: tutti i numeri inseriti devono essere interi

*Output: un intero che sia uguale ad uno o zero

*Post-condizione: riceviamo uno se l'istanza risulta positiva(tutte le terne hanno almeno un multiplo degli altri due numeri), altrimenti zero se l'istanza risulta negativa(non tutte le terne hanno
almeno un numero che sia multiplo degli altri due)

*TIPO DI PROBLEMA: VERIFICA UNIVERSALE*/

#include<stdio.h>
#include<math.h>

/*funzione che verifica se in ogni terna è presente un multiplo degli altri due numeri*/

int multipli(int interi[], int dimensione){
	int i=0; //contatore
	int multipli=1; //inizialmente le terne soddisfano la proprietà
	while(i<=dimensione-3 && multipli){
		if(interi[i]%interi[i+1]==0 || interi[i+1]%interi[i+2]==0 || interi[i]%interi[i+2]==0 ||
		   interi[i+1]%interi[i]==0 || interi[i+2]%interi[i+1]  || interi[i+2]%interi[i]==0)
			i++;                 //**** manca l'uguaglianza a zero, quindi se non è multiplo
		else                     //**** ti restituisce un valore maggiore di zero che risulta vero -0.5
			multipli=0;

	}return multipli;
}
/*funzione principale*/
int main(){
	int lunghezza;
	printf("Quanto vuoi che sia lunga la tua sequenza? \n");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];
	printf("Quali numeri vuoi inserire? \n");
	for(int i=0; i<lunghezza; i++)
		scanf("%d", &sequenza[i]);
	if(multipli(sequenza, lunghezza)){
		printf("Ogni terna ha almeno un numero multiplo degli altri due \n");
	}else{
		printf("Non tutte le terne hanno almeno un numero multiplo degli altri due \n");
	}
}