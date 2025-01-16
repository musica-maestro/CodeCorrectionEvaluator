/* SPECIFICA (max 1):......0
   TIPO PROBLEMA (max 1):..0.4 (vedi foglio)
   FUNZIONE (max 6):.......1.8
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............3.7
*/
#include<stdio.h>

int duePositivi(int numeri[], int lunghezza){

	int positivi;  //varabile che indica o no la presenza di due numeri positivi adiacenti

    positivi = 1; //all'inizio i nermi adiacenti sono positivi


    //controllo che il primo e l'ultimo elemento non siano negativi
    if((numeri[0] < 0) || (numeri[lunghezza -1] < 0) )  //****** A COSA SERVE? SE HO -1 2 3 -4 LA PROP E' SODDISFATTA -0.5

        positivi = 0;

    else{

        int i = 1; //variabile contatore per scorrere gli elementi della sequenza

        while(i < lunghezza || !positivi){ //***** i<lunghezza-1 && positivi  -1.5

        //condiziome che verifica se i due numeri adiacenti siano positivi
        if((numeri[i-1] < 0  && numeri[i] > 0 && numeri[i+1] < 0) ||  //******* SE C'E' UNO 0? -0.2
           (numeri[i-1] < 0  && numeri[i] < 0 && numeri[i+1] < 0) ||
           (numeri[i-1] < 0  && numeri[i] > 0 && numeri[i+1] > 0) ||
           (numeri[i-1] > 0  && numeri[i] > 0 && numeri[i+1] < 0) )

            positivi = 0;  //esiste una almeno una tripla d lementi i cui numeri adiacenti sono negativi

        else      //****** QUESTA E' UNA VERIFICA ESISTENZIALE, NON UNIVERSALE -2

            i++;  //la tripla di elementi ha come adiacenti due muneri postivi controllo la prossima tripla
                  //****** NON E' QUESTA LA PROPRIETA' DA VERIFICARE
        }

        return positivi;

    }
}

int main(){

    int lunghezza; //lunghezza della sequenza

    //INPUT: lunghezza della sequenza
    printf("Ciao inserisci quanti numeri vuoi inserire\n");
    scanf("%d", &lunghezza);

    int numeri[lunghezza]; //sequenza dei numeri inserita

    //inserimento sequenza dei numeri
    for(int i = 0; i < lunghezza; i++){

        printf("Inserire il numero\n");
        scanf("%d", &numeri[i]);

    }

    //richiamo della funzione per il controllo dell'esitenza di due positivi adiacenti
    if(duePositivi(numeri,lunghezza) == 1){

        printf("tutte le triple della sequenza hanno come elemntoa adiacente un numero positivo");
    }  //********* CHE VUOL DIRE CHE UNA TRIPLA HA COME ADIACENTE UN POSITIVO? -0.5
    else{

        printf("non tutte o nessuna  tripla della sequenza hanno come elemnto adiacente un numero positivo");
    }
}