/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......1.3
   MAIN PROGRAM (max 2.5):.0
   TOTALE..................3.3
*/
#include <stdio.h>
/*funzione che ha come parametri un array e la sua lunghezza,
 * che e restituisce il valore 1 se esiste una tripla di elementi consecutivi tale che almeno due elementi della tripla
 * hanno una somma compresa tra 10 e 20(estremi inclusi) ed esattamente due elementi della tripla sono fra loro
 * uguali,restituisce 0 altrimenti*/
int ugualiCompresi(int interi[],int lunghezza){
//pre:lunghezza dell'array>=3
	int esiste=0;                                         //espressione booleana inizializzata a 0
	int i=0;                                              //variabile contatore
	int somma=0;                                           //somma neutra
	while(esiste=0 && i<=lunghezza-2){ //****** esiste==0 -0.2
		somma=interi[i]+interi[i+1]+interi[i+2];
	if((somma>=10 && somma<=20) && ((i==i+1 && i!=i+2) || (i!=i+1 && i==i+2))) //******* interi[i], NON i -1
	//****** LA SOMMA DI ALMENO DUE, NON DI TUTTI E TRE -2
	//****** LA CONDIZIONE ANDAVA VERIFICATA PER TUTTE LE COMBINAZIONI DELLA TERNA -1.5
		esiste=1;
	else
		i++;
	}
	return esiste;
}

int main(){
	int n;
	int i=0;
	int interi[i]; //******DICHIARI UN ARRAY CON 0 COMPONENTI! -1
	int esito=0;
	printf("Gentile utente, quanti numeri vuole inserire?\n");
	scanf("%d",&n);
	printf("Quali numeri vuole inserire?\n");
	for(i=0;i<n;i++)
		scanf("%d",&interi[i]);
	esito=ugualiCompresi(interi[i],n); //********interi, NON interi[i] COSI' PASSI UNA SOLO COMPONENTE -1
	printf("l'esito della sua ricerca %c %d", 138, esito); //***** OUTPUT MOLTO PIU' ESPLICITO -0.5
}
/*Specifica
 * Input:sequenza di interi
 * Pre:numero di interi maggiore uguale di 3
 * Output: espressione booleana con valore 1 o 0
 * Post:                  //******** MANCANTE -0.5
 * Tipo Problema: Problema di esistenza*/