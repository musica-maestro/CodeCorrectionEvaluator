/* SPECIFICA (max 1.5):....1.2
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................10,7
*/
#include <stdio.h>

/*INPUT: un intero n e una sequenza di n elementi  //******** MANCA IL TIPO DEGLI ELEMENTI DELLA SEQUENZA -0.3
 * PRE-CONDIZIONI: n>=3 , la sequenza deve avere n elementi
 * OUTPUT: un booleano esiste
 * POST-CONDIZIONI: esiste=1 se nella sequenza esiste una tripla di elementi consecutivi tali che la somma di due elementi
 * sia compresa tra 10 e 20 (inclusi) e due elementi siano uguali
 * TIPO DI PROBLEMA: verifica esistenziale*/

 /*Funzione che riceve come parametro un array di interi e restituisce 1 se esiste una tripla di elementi consecutivi tale che
  * la somma di due elementi sia compresa tra 10 e 20 e due elementi siano uguali*/
  int ugualiCompresi(int a[],int l){
	  int i=0;//contatore
	  int esiste=0;//variabile d'esistenza

	  while(i<l-2 && !esiste){
		  /*se la tripla relativa all'indice i possiede due elementi uguali e due elementi che hanno somma tra 10 e 20
		   * la variabile esiste sarà uguale a 1 e quindi il ciclo si interromperà*/
		   if( ((a[i]==a[i+1] && a[i+2]!=a[i]) || (a[i]==a[i+2] && a[i+1]!=a[i]) || (a[i+1]==a[i+2] && a[i]!=a[i+1]))
		   && ( (a[i]+a[i+1]>=10 && a[i]+a[i+1]<=20) || (a[i]+a[i+2]>=10 && a[i]+a[i+2]<=20) || (a[i+1]+a[i+2]>=10 && a[i+1]+a[i+2]<=20)) )
			   esiste=1;
			else//altrimenti analizzo l'elemento successivo
				i++;
	  }

	  return esiste;
  }


 /*Funzione principale*/
int main(){
	int i=0;// contatore
	int n;//lunghezza della sequenza

	/*chiedo all'utente di inserire i dati di input*/
	printf("Caro utente sono un programma che verifica se nella tua stringa esiste almeno una tripla di elementi consecutivi\n");
	printf("tali che la somma di due elementi sia compresa tra 10 e 20, inserisci la lunghezza della sequenza\n");
	scanf("%d", &n);
	int interi[n];//array che conterrà gli elementi che l'utente deve inserire
	while(i<n){
		printf("Inserisci l'elemento in posizione %d:\n", i);
		scanf("%d", &interi[i]);
		i++;
	}

	if(ugualiCompresi(interi,n)==1)
		printf("Nella sequenza esiste almeno una tripla tale che la somma di due elementi sia compresa tra 10 e 20 e due elementi sono uguali\n");
	else
		printf("Nella sequenza NON esiste nemmeno una tripla tale che la somma di due elementi sia compresa tra 10 e 20 e due elementi sono uguali\n");
}
