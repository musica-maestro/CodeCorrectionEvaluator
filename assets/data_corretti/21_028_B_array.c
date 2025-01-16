/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3.5
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................8
*/

#include <stdio.h>
/* TIPO DI PROBLEMA: Verifica Universale
 * SPECIFICHE PROBELMA:

 * Input: una sequenza di interi lunga n
 * Pre-condizione: la sequenza deve essere lunga n>=0
 * Output:risultato
 *  Post-condizione:risultato vale 1 se ogni tripla contiene esattamente due numeri maggiori o = 5 e almeno due elementi pari
 */
 int maggiori5Pari(int interi[],int lunghezza){
	 int i=0; // indice array inizializzato a 0
	 int ris=1; //variabile inizializzata inizialmente a

	 while((i<lunghezza-2)&&(ris==1)){
		 /*verifico se ci sono solamente due numeri >=5*/
	 if(((interi[i]>=5)&&(interi[i+1]>=5)&& !(interi[i+2]>=5))||((interi[i+1]>=5)&&(interi[i+2]>=5)&& !(interi[i]>=5))){
		 //******** MANCA UNA COMBINAZIONE (!(interi[i+1]>=5)&&(interi[i+2]>=5)&& (interi[i]>=5)) -0.5
		 //******** IF VUOTO!! -1
		}else{
		 ris=0;
	 }
	 /*verifico se ci sono almeno due numeri pari*/
	 if((interi[i]%2==0)&&(interi[i+1]%2==0)||(interi[i]%2==0)&&(interi[i+2]%2==0)||(interi[i+2]%2==0)&&(interi[i+1]%2==0)){
		//******** IF VUOTO!! -1
		}else{
			 ris=0;
		 }
		 i++;
 }
 /*ritorno la variabile booleana*/
 return ris;
 }
 int main(){
	 int lung=0;
	 int risultato=0;
	 printf("Benvenuto! In questo programma verifica che in una sequenza ci sono\n");
	 printf("esattamente due numeri >=5 e almeno due numeri pari in ogni tripla\n\n");
	 /*Input*/
	 printf("Quanto e' lunga la sequenza?\n");
	 scanf("%d",&lung);
	 int array[lung];
	 /*riempimento array*/
	 for (int i=0;i<lung;i++){
		 printf("Inserisci numero\n");
		 scanf("%d",&array[i]);
	 }
	 risultato=maggiori5Pari(array,lung); //richiamo la funzione maggiori5pari
	 /*Output*/
	 if(risultato==1){
		 printf("la sequenza contiene almeno due numeri pari e due numeri >=5");
	 }else{
		 printf("la sequenza non contiene almeno due numeri pari e due numeri >=5");
	 }//******** OUTPUT ESPRESSO MALE -0.5


 }