/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9.5
*/
#include <stdio.h>

/*SPECIFICA
 * input: sequenza di interi s e una lunghezza s
 * pre-condizioni: l è la lunhgezza della sequenza e l>=0
 * output: intero
 * post condizioni: ritorna 1 se  esiste una tripla di elementi consecutivi
 * 								che contiene almeno due elementi il cui valore è compreso fra -10 e 10 (estremi inclusi)
 * 								e che contiene esattamente due elementi multipli di tre
 * 					ritorna 0 altrimenti
 * problema di: Verifica Esistenziale


/*funzione che verifica se esiste una tripla di elementi consecutivi
 * che contiene almeno due elementi il cui valore è compreso fra -10 e 10 (estremi inclusi)
 * e che contiene esattamente due elementi multipli di tre*/
int compresiMultipli3(int a[], int l){
	//pre: l è la lunghezza della sequenza
	int i=0; //iteratore per scorrere la sequenza
	int esiste = 0;  //variabile di ritorno inizializzata a 0

	/*fino a quando ci sono triple da visitare nella sequenza*/
	while( i< l-2  && !esiste){
		/*se rispetta la propretà la tripla corrente*/
		if((((a[i]>=-10 && a[i]<=10) && (a[i+1]>=-10 && a[i+1]<=10))
		|| ((a[i+1]>=-10 && a[i+1]<=10) && (a[i+2]>=-10 && a[i+2]<=10))
		|| ((a[i]>=-10 && a[i]<=10 && a[i+2]>=-10 && a[i+2]<=10)))
			&& ((a[i]%3 == 0 && a[i+1]%3 == 0)  || (a[i+1]%3 == 0 && a[i+2]%3 == 0) || (a[i]%3 == 0 && a[i+2]%3 == 0))){
		//******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO DIVISIBILI PER 3 ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
		//******** ES. se la tripla e' 3 12 6 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
				esiste = 1;
			}
			i++;  //altrimenti passa alla prossima tripla
	}
return esiste;
}



/*funzione principale*/
int main(){
	int lunghezza; // variabile per la lunghezza della sequenza
	printf("Caro Utente sono un app che verifica se nella sequenza da te introdotta  esiste una tripla di elementi consecutivi\n");
    printf("che contiene almeno due elementi il cui valore è compreso fra -10 e 10 (estremi inclusi)\n");
    printf("e che contiene esattamente due elementi multipli di tre\n");
	//INPUT
	printf("Introduci la lunghezza della tua sequenza: ");
	scanf("%d", &lunghezza);

	int sequenza[lunghezza];   //array per la sequenza di interi

	for (int i = 0; i<lunghezza; i++){
		printf("Introduci un intero: ");
		scanf("%d", &sequenza[lunghezza]);
	}

	//OUTPUT
if(compresiMultipli3(sequenza, lunghezza)){
	printf("Si la tua sequenza contiene tale tripla\n");
}
else{
	printf("Mi dispiace la tale tripla non esiste nella tua sequenza\n");
}
}
