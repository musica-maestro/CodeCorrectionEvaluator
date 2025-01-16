/* SPECIFICA (max 1):......0.3
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.3
*/

/*SPECIFICA
*INPUT: una sequenza di n interi(X1,X2..Xn)
*PRE-CONDIZIONE  //***** MANCA -0.2
*OUTPUT          //***** MANCA -0.25
*POST-CONDIZIONE //***** MANCA -0.25

*TIPO DI PROBLEMA: Verifica esistenziale*/









#include <stdio.h>

/*funzione che verifica se in una sequenza di interi esiste o meno una tripla di interi adiacenti
in cui uno dei tre è il resto della divisione degli altri due*/
int restoDivisione(int*seq, int l){
	int i=0;       //variabile contatore
	int esistente=0;  //variabile booleana da restituire

	/*guarda triple fino a quando ce ne sono oppure fino a quando non ne trovi una buona*/
	while(i<l-2 && !esistente)
		/*uno dei tre elementi è il resto della divisione degli altri?*/
		if((seq[i]%seq[i+1]==seq[i+2])||(seq[i]%seq[i+2]==seq[i+1])||
		   (seq[i+1]%seq[i+2]==seq[i])||(seq[i+1]%seq[i]==seq[i+2])||
		   (seq[i+2]%seq[i]==seq[i+1])||(seq[i+2]%seq[i+1]==seq[i]))
			/*esiste!*/
			esistente=1;
		else
			/*vai alla tripla successiva*/
			i++;

	return esistente;

}


/*funzione principale*/
int main(){
	int lunghezza;     //lunghezza della sequenza
	int esiste;        //valore booleano da restituire

	/*quanti elementi ha la sequenza?*/
	printf("Ciao utente, prima di cominciare  quanti interi vuoi introdurre?: ");
	scanf("%d", &lunghezza);

	int sequenza[lunghezza];     //array per la sequenza

    /*leggi interi fino a lunghezza*/
    for(int i=0; i<lunghezza; i++){
    	printf("Dammi un intero: ");
    	scanf("%d", &sequenza[i]);
    }

    /*Esiste una tripla che soddisfa la proprietà?*/
    esiste=restoDivisione(sequenza, lunghezza);

    /*output*/
    if(esiste==1){
    	printf("Nella sequenza esiste una tripla di interi consecutivi in cui ");
    	printf("uno dei tre e' uguale al resto della divisione degli altri due.");
    }
    else{
    	printf("Nella sequenza non esiste una tripla di interi in cui ");
        printf("uno dei tre e' uguale al resto della divisione degli altri due.");
    }


}