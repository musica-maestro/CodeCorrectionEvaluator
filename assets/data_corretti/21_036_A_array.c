/* SPECIFICA (max 1.5):....0.7
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......1
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................4.2
*/
#include <stdio.h>
/*SPECIFICA
 * il programma riceve in input una sequenza di interi e cerca una tripla di interi consecutivi contenente due numeri uguali
 * e due numeri la cui somma è compresa tra 10 e 20
 * input: un array di interi e la sua lunghezza
 * pre condizione
 * output: 1 se la sequenza rispetta le condizioni, 0 se non la rispetta   //******** OUTPUT NON CORRETTO -0.3
 * post condizione //******** LA POST-CONDIZIONE MANCA -0.5
 * tipo: ricerca universale*/  //******** VERIFICA ESISTENZIALE -1

 int UgualiCompresi(int s[], int l){
     int i=0;//variabile di controllo
     int Uguali=1; //variabile universale //******** LA TRATTI COME UNA VERIFICA UNIVERSALE
      while((s[i+2]<l)&&(Uguali==1)){//se la condizione non è soddisfatta e la sequenza non è finita
          if ((s[i]==s[i+1])||(s[i]==s[i+2])||(s[i+1]==s[i+2])){//se due numeri della terna sono uguali
          //******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO UGUALI ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
		  //******** ES. se la tripla e' 5 5 5 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
            if ((10<=s[i]+s[i+1]<=20)||(10<=s[i+1]+s[i+2]<=20)||(10<=s[i+1]+s[i+2]<=20))//se due numeri sommati danno tra 10 e 20
			    //******** QUESTA ESPRESSIONE NON ESPRIME "ESSERE COMPRESO TRA"
			    //******** IL C CALCOLA ALTRO (((10>=s[i])+ s[i+1]) <=20) -1.5
            i++;
          else
              Uguali=0;;        //******* QUESTA E' UNA VERIFICA UNIVERSALE -2
          }
           else Uguali=0;
      }
      printf("%d", Uguali);
      return Uguali; //restituisci il valore
 }

int main(int argc, char **argv)
{
    int l;//lunghezza array
    int j=0;//variabile di controllo
	printf("Benvenuto Utente, di che lunghezza vuoi la sequenza?\n");
    while (l<3){//se la sequenza è minore di 3
        printf("Inserisci un valore maggiore o uguale a 3\n");
        scanf("%d", &l);//inserimento della lunghezza
    }
    int interi[l];//array
    for (j=0;j<l;j++){//inserisco i valori nell'array
        printf("Inserisci il valore %d della sequenza\n", j+1);
        scanf("%d", &interi[j]);
    }
    if (UgualiCompresi(interi, l)==1)//invoco la funzione e controllo il risultato
        printf("Esiste una tripla di interi che contiene due numeri uguali e due numeri la cui somma %c compresa tra 10 e 20", 138);
        else
             printf("Non esiste una tripla di interi che contiene due numeri uguali e due numeri la cui somma %c compresa tra 10 e 20", 138);
	return 0;
}
