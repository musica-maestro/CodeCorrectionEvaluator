/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............10
*/
/*SPECIFICA:
 * input:lunghezza della seuenza e la sequenza di interi
 * pre-condizioni:....
 * output: esiste variabile booleana
 * post condizioni: esiste=1 se almeno un elemento della terna di elementi adiacenti della
 * sequenza è multiplo di uno degli altri due. altrimenti esiste=0
 * TIPO DI PROBLEMA:verifica universale
 */
 #include <stdio.h>
int multipli(int v[],int l){
	int i=0; //contatore per lettura array
	int esiste=1; //variabile booleana
    /*finche contatore è minore della lunghezza-2 e esiste è 1*/
	while(i<l-2 && esiste){
		/*un elemento nella terna non è multiplo di uno degli altri due?*/
		if(!(v[i]%v[i+1]==0||v[i+1]%v[i]==0||v[i]%v[i+2]==0||v[i+2]%v[i]==0||v[i+2]%v[i+1]==0||v[i+1]%v[i+2]==0)){
			esiste=0; //uno o più elementi della terna non è multiplo di uno degli altri
		}
		/*altrimenti vai avanti*/
		else
			i++; //incremento la variabile contatore
	}
	//alla funzione che ha invocato multipli, gli ritornerà il valore di esiste
	return esiste;
}
int main(){
	int i; //contatore per inserimeno elemnti
	int esiste=0; //variabile booleana che prendere l'esisto della funzione multipli
	int n=0; //lunghezza dell'array

	printf("quanti interi vuoi inserire?\n");
	scanf("%d",&n); //inserimento valore lunghezza

	int vet[n]; // dichiarazione array con lunghezza n
	/*inserimento elementi all'interno dell'array vet[n]*/
	for(i=0; i<n; i++){
		printf("inserisci un intero\n");
		scanf("%d",&vet[i]);
	}
	/*invocazione funzione multipli*/
	esiste=multipli(vet,n);
	/*esiste è =0, cioè in una terna non esiste almeno un elemento che è multiplo di uno dei due*/
	if(esiste==0)
		printf("nelle terne di elementi adiacenti della sequenza NON c'%c almeno un elemento multiplo di uno degli altri due",138);
	else
		printf("nelle terne di elementi adiacenti della sequenza ESISTE almeno un elemento multiplo di uno degli altri due");
}