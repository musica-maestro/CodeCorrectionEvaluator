/* SPECIFICA (max 1.5):....0
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3
   MAIN PROGRAM (max 2.5):.1.5
   TOTALE..................5.5
*/
 /*
  *Specifica: Verificare che tre elementi consecutivi siano compresi tra -10 e 10 ( estremi inclusi ) e che due siano multipli di 3
  *Input: i numeri da controllare e verificare		// **** MANCA IL CONCETTO DI SEQUENZA -0.5
  *output: se l'istanza è positiva o negativa		// ***** CHE VUOL DIRE? -0.5
  //********** MANCANO PRE E POSTCONDIZIONI -1
  *Tipo di problema: verifica esistenziale
  */

  #include <stdio.h>

  int comrpesiMultipli3(int *v, int i);

  int main(){

	  //dichiarazione variabili
	  int i;
	  printf("Inserisci il numero di numeri: ");
	  scanf("%d",&i);

	  int vettore[i];

	  //caricamento vettore
	  for(int n=0; n < i; n++){

		  printf("Inserisci un numero: ");
		  scanf("%d",&vettore[n]);
	  }

	  //chiamata a funzione
	  int c = comrpesiMultipli3(vettore, i);

	  //esecuzione del controllo del risultato della funzione
	  switch(c){ //********* switch-case NON PERVENUTA! -0.5

		  case 0:

		  printf("Non esiste una tripla! ");
		  for(int n=0; n < i; n++)
		  printf("%d ",vettore[n]);

		  break;//********* break NON PERVENUTO! -0.5

		  case 1:

		  printf("Esiste una tripla! ");
		  for(int n=0; n < i; n++)
		  printf("%d ",vettore[n]);

		  break;

		  default:
		  printf("Errore! ");
		  break;
	  }

	  return 0;
  }

//funzione
int comrpesiMultipli3(int *v, int i){

	int check=0, counter_consecutivi=0, counter_multipli=0, j=0;

	while(check!=1 && j<i){  //********* FAI IL CONTROLLO SU TUTTO L'ARRAY, NON SU CIASCUNA TERNA! -3

		//controllo delle condizioni
		if( v[j]>=-10 && v[j]<=10 ){

			counter_consecutivi++;

			if(v[j]%3==0){
				counter_multipli++;
			}
			if( counter_consecutivi==3 && counter_multipli==2 ){
			check=1;
			}

			else{
				check=0;
			}
		}
		j++;		//incremento
	}

	return check;
}
