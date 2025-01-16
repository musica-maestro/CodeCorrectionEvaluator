/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............9.8
*/
#include<stdio.h>

/* SPECIFICA
*Input: interi e l //******* una seqenza di interi -0.1
*Pre-condizione: l e la lunghezza  della sequenza
*Output: valore boleanno esiste
*Post-condizione: se esiste=1 allora abbiamo verificato che abbiamo una tripla addiacente dove uno dei tre
  e uguale al resto della divisione tra gli altri due elementi, //*** FALSO ALTRIMENTI -0.1
*TIPO DI PROBLEMA : Esistenziale*/



/* funzione che verifica se abbiamo una tripla addiacente dove uno dei tre
 sara uguale al resto della divisione tra gli altri due elementi*/
int restoDivisione(int sequenza[],int l) {
	int i; // variabile che ci aiuta a passare al succesivo se la condizione non e verificata
	int esiste; // valore boleanno

	esiste=0;
    for(i=0;i<l-2 && !esiste;i++) {
		if((sequenza[i]%sequenza[i+1]==sequenza[i+2] ) || (sequenza[i+1]%sequenza[i]==sequenza[i+2]) ||
			(sequenza[i]%sequenza[i+2]==sequenza[i+1]) || (sequenza[i+2]%sequenza[i]==sequenza[i+1]) ||
			(sequenza[i+2]%sequenza[i+1]==sequenza[i]) || (sequenza[i+1]%sequenza[i+2]==sequenza[i])) {
			esiste=1;
		}
	}
return esiste;

}





int main() {
  int i;
  int l; // lunghezza sequenza
  int uguale; // valore boleanno


  printf("Ciao sono un programma che verifica se esiste tra una tripla di elementi adiacenti\n");
  printf("dove uno dei tre sia uguale all resto della divisione degli altri due\n");

  printf("Quanto vuoi che la tua sequenza sia lungha?\n");
  scanf("%d",&l);

  int sequenza[l];
  for(i=0;i<l;i++) {
  	printf("Inserci un intero:\n");
  	scanf("%d",&sequenza[i]);
  }

 uguale=restoDivisione(sequenza,l);

 if(uguale==1) {
 	printf("SI esiste una terna di elementi adicaenti nella sequenza in cui uno dei tre");
    printf("%c il resto della divisione degli altri due",138);
    }

 else {
 	printf("NON esiste una terna di elementi adicaenti nella sequenza in cui uno dei tre");
 	printf("%c il resto della divisione degli altri due",138);

 }

}