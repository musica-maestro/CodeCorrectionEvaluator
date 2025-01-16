/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............9
*/
/*SPECIFICA
*Input : Un intero n che determinerà la lunghezza della serie di interi
ed una sequenza di interi seq memorizzata in un array;
*Pre-condizione: n intero positivo maggiore o uguale a 3;
*Output: un valore v ;
*Post-condizione: il valore v varra' 1 se in ogni tripla della sequenza sono presenti
almeno due numeri da una cifra, 0 se invece non sara' rispettata la condizione;
*TIPO DI PROBLEMA : verifica universale */

#include <stdio.h>

// funzione utilizzata per verificare se la condizione sia rispettata
int dueUnaCifra(int * seq,int n){
/*variabile che restituiremo alla fine del ciclo e varra' 1 se in ogni tripla sono presenti
almeno due numeri da una sola cifra*/
    int v=1;
//contatore usato per controllare le triple dell'array per questo lo facciamo partire da 1
int i=1;
/*ciclo che continua finche' non troviamo una tripla che non rispetta la condizione
 oppure finche' non arriviamo al penultimo elemento dell'array dato che dobbiamo ispezionare
 ogni volta insiemi da tre
 */
while(i<n-1 && v!=0){

//contatore b che usiamo per tenere conto dei numeri a cifra singola presenti nella tripla
int b=0;
if(seq[i-1]-10<0){         //******* L'INDENTAZIONE! -0.5
	b++;
}
if(seq[i]-10<0){
	b++;
}
if(seq[i+1]-10<0){
	b++;
}
// se sono meno di 2 allora v diventera' 0 terminando il ciclo
if(b<2){
     v=0;
}

	i++;
}
	return v;
}



int main(){
	//INPUT
	//la lunghezza della sequenza di interi
int n;
printf("Inserire la lunghezza della serie di interi : \n");
scanf("%d",&n);

int seq[n];
for(int l=0;l<n;l++){
      printf("Inserire elemento numero %d della serie : \n",l+1);
      scanf("%d",&seq[l]);

                        }
//OUTPUT
if(dueUnaCifra(seq,n)){
	printf("Ogni tripla rispetta la condizione"); //************ OUTPUT NON ESPLICATIVO -0.5
}else{
    printf("Non tutte le triple rispettano la condizione");
}



}