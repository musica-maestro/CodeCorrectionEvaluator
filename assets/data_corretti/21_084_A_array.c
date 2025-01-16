/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................11
*/
/*SPECIFICA
 * Dati in ingresso: una sequenza "array" di interi di lunghezza l
 * Pre-condizione: l>=3
 * Dati in uscita: un intero "verificata"
 * Post-condizione: l'intero vale 1 se nella sequenza è presente almeno una tripla che possiede due
 * elementi la cui somma è compresa tra 10 e 20 ed esattamente due elementi di essa devono essere uguali,
 * altrimenti restituisce 0
 *
 * Tipo di problema: verifica esistenziale
 */

 #include <stdio.h>

 /*funzione che controlla se in una tripla sono presenti esattamente due valori uguali*/
 int DueUguali(int i, int array[]){
	 return (((array[i]==array[i+1])&&(array[i]!=array[i+2]))||((array[i+1]==array[i+2])&&(array[i+1]!=array[i]))||
	 ((array[i]==array[i+2])&&(array[i]!=array[i+1])));
 }


 /*programma che, dati in ingresso un array e la sua lunghezza, verifica se esiste una tripla
  * che possiede due elementi la cui somma è compresa tra 10 e 20 (estremi inclusi) e due elementi
  * di essa sono uguali*/
  int UgualiCompresi(int l, int array[]){

	  //pre: l=lunghezza array

	  /*dichiarazione ed inizializzazione variabili*/
	  int i=0;                //variabile contatore
	  int verificata=0;     //variabile esistenza

	  /*si controllano tutti le terne per cercare quella che soddisfa la proprietà*/
	  while((i<l-2)&&(verificata==0)){

            /*se esiste una terna che soddisfa la proprietà si aggiorna la variabile di esistenza*/
		  if(((((array[i]+array[i+1])<=20)&&(array[i]+array[i+1])>=10)||(((array[i+1]+array[i+2])<=20)&&(array[i+1]+array[i+2])>=10)||
		  (((array[i+1]+array[i+2])<=20)&&(array[i+1]+array[i+2])>=10)) && DueUguali(i,array))
			  verificata=1;

			/*altrimenti si passa al prossimo elemento*/
            else i++;
	}

     /*output funzione*/
	return verificata;
}



/*funzione principale*/
int main(){

	/*dichiarazione variabili*/
	int lung;  //variabile lunghezza array

	/*input*/
	printf("Sono un programma che calcola se una tripla di una sequenza possiede due elementi che hanno la somma compresa tra 10 e 20 \n");
	printf("e che la stessa tripla possieda esattamente due numeri uguali \n");

	printf("Caro utente, quanti interi vuole inserire?: ");
	scanf("%d",&lung);

	/*se l'utente inserisce meno di 3 interi il programma termina*/
	if(lung<3)
		printf("si devono inserire almeno 3 interi \n");

	else{

		/*dichiarazione e riempimento array*/
		int array[lung];
		for(int i=0;i<lung;i++){
			printf("inserire il %d %c elemento della sequenza: ",i+1,167);
			scanf("%d",&array[i]);
		}

	/*richiamo funzione ed output*/
	if(UgualiCompresi(lung,array))
		printf("nella stringa e' presente almeno una tripla che possiede due elementi uguali e due elementi che \nhanno somma compresa tra 10 e 20 \n");

	else printf("nella stringa non e' presente una tripla che possiede due elementi uguali e due elementi che \nhanno somma compresa tra 10 e 20 \n");



	}
}
