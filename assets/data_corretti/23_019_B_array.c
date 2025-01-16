/* SPECIFICA (max 1):......0.2
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......2.5
   MAIN PROGRAM (max 2):...0
   TOTALE (10).............2.7
*/
/*SPECIFICA
*Input: Due numeri positivi in una sequenza di tre //****** NO, UNA SEQUENZA DI INTERI E LA SUA LUNGHEZZA -0.3
*Pre - Condizione:
*Output: Due numeri positivi = 1 Non due numeri positivi = 0  //**** QUI SI RICHIEDE LA VARIAIBILE BOOLEANA -0.2
//********* MANCA LA POST CONDIZIONE -0.3
*Tipo di problema: E' un problema di Verifica Esistenziale //******** E' UNIVERSALE -1
*/



#include <stdio.h>

int DuePositivi(int sequenza[], int lunghezza) {
  for ( int i = 0; i <= lunghezza -3; i++){
    if ( sequenza[i] + sequenza [i+1] >= 0 || sequenza [i] + sequenza [i+2] >= 0 || sequenza[i+1] + sequenza[i+2] >= 0)
  {//****** COSI' VERIFICHI SE CI SONO ALMENO DUE POSITIVI, NON ESATTAMENTE DUE -1.5
  return 1;
  }
 }//****** COSA RESTITUISCE SE NESSUNA TERNA SODDISFA LA CONDIZIONE? -2
}


int main(int sequenza[]) {
   int lunghezza;
    printf("Scrivere quanti interi ha la sequenza:\n");
     scanf("%d", &lunghezza);
//******** MANCA LA DICHIARAZIONE DELL'ARRAY -1

     printf(" Scrivere gli interi separati dallo spazio: \n"); //******* MANCA IL CICLO DI LETTURA -1
      scanf("%d", &sequenza[lunghezza]);
//******* COSI' LEGGI UN VALORE CHE NON FA NEMMENO PARTE DELL'ARRAY -1

    int DuePositivi(int sequenza[], int lunghezza) { //********** NO!!!! STAI NEL MAIN
      if ( int i >= 0; i < lunghezza; i++) {
         printf(" In tutte le triple di interi ci sono due numeri positivi \n");
         scanf("%d", &sequenza[lunghezza]);  //******* COSE'E'???

      else ( int i < 0; i < lunghezza; i++ )
         printf(" Non in tutte le triple di interi ci sono due numeri positivi\n");
        scanf("%d", &sequenza[lunghezza]);   //****** COS'E'???
      }
        {
        return 0;
        }
   }

}