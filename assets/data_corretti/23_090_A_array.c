/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............8.3
*/
/*SPECIFICA:
  input: una sequenza e una lunghezza //****** MANCANO I TIPI -0.2
  pre-cond: lunghezza è la lunghezza della sequenza
  output: 0 o 1
  post-cond: resituisce 1 quando l'istanza del problema è positiva
             (esiste almeno un multiplo di uno degli altri due in ogni terna consecutiva)
             restituisce 0 altrimenti
  TIPO DI PROBLEMA:verifica universale*/

  #include <stdio.h>
int multipli(int sequenza[],int lunghezza){
	int i=0;
	int multipli=1;        //dichiaro le variabili
        //******** INDICE DELL'ARRAY FUORI DAI LIMITI, DEVE ESSERE i<lunghezza-2 -1
	while(i<lunghezza&&multipli==1){   //ciclo while che prosegue fino alla fine della stringa o finche vale la variabile multipli
	if(!(sequenza[i]%sequenza[i+1]==0||sequenza[i]%sequenza[i+2]==0||
	     sequenza[i+1]%sequenza[i]==0||sequenza[i+1]%sequenza[i+2]==0||
	     sequenza[i+2]%sequenza[i]==0||sequenza[i+2]%sequenza[i+1]==0))
	     multipli=0;                                                             //se non funziona il problema cambia la varibile multipli in 0
	     else
	     i++;	                         //altrimenti prosegue nella sequenza

	}
}
int main(){
	int lunghezza;
	printf("ciao utente inserisci la lunghezza della sequenza\n");
	scanf("%d",&lunghezza);                          //salvo la lunghezza della sequenza
	int sequenza[lunghezza];                         //dichiaro la sequenza con la lunghezza appena inserita
	for(int i=0;i<lunghezza;i++){                   //ciclo for per salvare la sequenza
		printf("|INSERISCI INTERO|\n");
		scanf("%d",&sequenza[i]);
	}

	if(multipli(sequenza,lunghezza))
		printf("la sequenza inserita ha risulatato positivo!(1)\n");
	else
		printf("la sequenza inserita ha risultato negativo!(0)\n");
}     //************ OUTPUT NON ESPLICATIVO -0.5
