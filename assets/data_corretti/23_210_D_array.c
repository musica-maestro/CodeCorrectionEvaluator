/* SPECIFICA (max 1):......0.3
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............7.3
*/
/*Specifica Problema: Data una sequenza di interi, verificare che all'interno della sequenza esista una tripla
di elementi adiacenti in cui uno dei tre è il resto della divisione (tra elementi di tipo int) degli altri due.
*input: una sequenza S di interi I.//******** MANCA LA LUNGHEZZA -0.2
*pre-condizione: interi I.
*Dati in uscita: un messaggio che dice all'utente se la condizione è verificata o no. //**** NO -0.3
*Post-condizione: Un valore true o false. //**** QUESTO E' L'OUTPUT -0.2
Tipologia Problema: Verifica esistenziale.*/

#include <stdio.h>
#include <math.h>


/*funzione che verifica se almeno una tripla ha un elemento che equivale al resto della
*divisione degli altri due elementi*/

int restoDivisione(int* seq, int l){
	int esistenza=0; //variabile da restituire al main
	int i=0; //variabile per scorrere la sequenza

	/*leggi tutte le triple finchè la la condizione noon è verificata, o termina le triple adiacenti*/
	while(i<l-2 && esistenza){
      if (((int)seq[i]%(int)seq[i+1]!=(int)seq[i+2])||((int)seq[i]%(int)seq[i+2]!=(int)seq[i+1])||((int)seq[i+1]%(int)seq[i]!=(int)seq[i+2])||((int)seq[i+1]%(int)seq[i+2]!=(int)seq[i])||
      	((int)seq[i+2]%(int)seq[i]!=(int)seq[i+1])||((int)seq[i+2]%(int)seq[i+1]!=(int)seq[i])){
      	esistenza=0;      //***** &&, NON || -1.5
      	//******* METTERE LA VARIABILE A 0 E' PERICOLOSO E NON SERVE (PERCHE' GIA' E' A 0), MA TI SALVI
		//******* PERCHE' HAI MESSO IL BOOLEANO NELLA CONDIZIONE DEL CICLO -0.5
      	i++;

      }else{
      	esistenza=1;

      }
	}
  return esistenza;
}




/*funzione principale*/
int main(){
	/*Interfaccia iniziale che si presenta all'utente*/
	printf("Caro utente, l'applicazione data una sequenza di interi verifica se in almeno una\n");
	printf("tripla di interi adiacenti, un intero vale il resto della divisione degli altri due elementi.\n");
	printf("\n");
	/*INPUT*/
	int l; // lunghezza della variabile
	printf("Quanti interi hai a portata di mano? ");
	scanf("%d", &l);
    printf("\n");
	int seq[l];
	for (int i = 0; i < l; i++){
		printf("Inserisci un intero: ");
		scanf("%d",&seq[i]);
	}
    /*OUTPUT*/
	if (restoDivisione(seq , l)){
		printf("La funzione non ha nessuna tripla che soddisfa la condizione\n");
	}else{
        printf("La funzione ha almeno una tripla che soddisfa la condizione.\n");
	}
	return 0;
}