/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..0  //******** MANCANTE
   FUNZIONE (max 6):.......4.8
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................7.8
*/
#include <stdio.h>
/*funzione che dato un array di interi,verifica se ogni tripla contiene esattamente due elementi maggiori
 * di 5 e almeno due elementi pari
 * Input:La lunghezza dela sequenza e una sequenza di interi
 * pre-condizione:tutti gli elementi devono essere interi
 * output:valore booleano 1 se vera,0 altrimenti*/
 //******** LA POST-CONDIZIONE MANCA -0.5

 int Maggiore5(int seq[],int l){
int i=0;//variabile contatore
int trovato=1;//se uguale a 0 una terna non rispetta propriet√
while(i!=l-1&&trovato==1){ //leggo la stringa //***** NON E' UNA STRINGA -0.2
//******** INDICE DELL'ARRAY FUORI DAI LIMITI, DEVE ESSERE i<l-2.   -1
	if((((seq[i]>=5&&seq[i+1]>=5)&&(seq[i+2]<5))
	||((seq[i+1]>=5&&seq[i+2]>=5)&&(seq[i]<5))
	||((seq[i]>=5&&seq[i+2]>=5)&&(seq[i+1]<5))
	&&((seq[i]%2==0&&seq[i+1]%2==0)||(seq[i+1]%2==0&&seq[i+2]%2==0)||(seq[i]%2==0&&seq[i+2]%2==0))))
		 i++;
		 else
			 trovato=0;
}
return trovato;
 }
int main(int argc, char **argv){
int l;
//INPUT
printf("Utente inserisci la lunghezza della stringa:\n");
scanf("%d",&l);
printf("ora inserisci la tua stringa:\n");
int seq[l];
for(int i=0;i<=l-1;i++){
	printf("Inserisci l'elemento: ");
	scanf("%d",&seq[i]);
}
if(Maggiore5(seq,l))
	printf("Le terne presenti nella tua stringa soddisfano le caratteristiche richieste");
	else
		printf("Le terne presenti nella stringa non soddisfano le caratteristiche richieste");

	//******** I/O MOLTO POVERO -0.5

}


