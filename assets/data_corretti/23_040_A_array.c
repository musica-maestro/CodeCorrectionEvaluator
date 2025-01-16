/* SPECIFICA (max 1):......0.5
   TIPO PROBLEMA (max 1):..0
   FUNZIONE (max 6):.......4
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............6.5
*/
/*SPECIFICA
*INPUT:sequenza di valori //******** MANCA LA LUNGHEZZA -0.2
*PRE-CONDIZIONE: che siano valori interi
*OUTPUT: esiste=1 o esiste=0
*POST-CONDIZIONE: esistenza o non esistenza di un multiplo di un altro numero nelle terne di valori
//******** POST CONDIZIONE NON CORRETTA -0.3

*TIPO DI PROBLEMA: verifica esistenziale*/  //******* NO E' UNIVERSALE -1
#include<stdio.h>
int multipli(int array[],int lun){
	int esiste=0; //dichiaro variabile in int per verificare la condizione di esistenza
	int i; //variabile contatore per il ciclo for
	for(i=0;i<lun-2;i++){
		if((array[i]%array[i+1]==0)||(array[i]%array[i+2]==0)||
			(array[i+1]%array[i]==0)||(array[i+1]%array[i+2]==0)||
			(array[i+2]%array[i]==0)||(array[i+2]%array[i+1]==0))
			esiste=1; //dopo aver verificato se le terne presentano almeno un multiplo di un altro numero al loro interno, esistenza diventa 1 perchè verificata la condizione
	}//******* QUESTA E' UNA VERIFICA UNIVERSALE E TU L'HAI TRATTATA COME ESISTENZIALE -2

return esiste; //riporto nel main la variabile esiste
}
int main(){
	int n; //dichiaro in int la lunghezza della sequenza
	int i; //variabile contatore per il ciclo for
	int esiste;
	printf("inserire lunghezza della sequenza: ");
	scanf("%d",&n);
	int array[n];
	for(i=0;i<n;i++){
		printf("inserire valore [%d]",i);
		scanf("%d",&array[i]);
	}
	esiste=multipli(array,n); //invocazione della funzione multipli
	if(esiste==1) //verifico la condizione di esistenza
	  printf("la condizione di esistenza di un multiplo %c verificata quindi: %d",138,esiste);
    else
      printf("la condizione di esistenza di un multiplo non %c verificata quindi: %d",138,esiste);

}

