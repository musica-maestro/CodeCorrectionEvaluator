/* SPECIFICA (max 1):......1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2):...1.8
   TOTALE (10).............9.8
*/
//SPECIFICA
//Input:numero che inica la lunghezza della sequenza , numeri che compongono la sequenza
//Pre-condicione:i numeri della sequenza devono essere interi
//Output:vaiabile booleana
//Post-condizione: la variabile booleana vale 1 se nella sequenza ogni tripla di elementi consecutivi contiene almeno un elemento che e' multiplo di uno degli altri due; vale 0 altrimenti
//E' un problema di verifica universale


#include<stdio.h>


int Multipli(int a[],int n){
	int i;
	int verifica=1;
	for(i=0;i<n-2&&verifica;i++){
		if(!(a[i]%a[i+1]==0||a[i]%a[i+2]==0||a[i+1]%a[i]==0||a[i+1]%a[i+2]==0||a[i+2]%a[i]==0||a[i+2]%a[i+1]==0))
			verifica=0;

	}
	return verifica;
}

int main(){
	int n;
	int verifica;
	printf("da quanti numeri e' composta la sequenza?");
	scanf("%d",&n);//****** MANCA SPAZIO -0.1
	int a[n];
	for(int i=0;i<n;i++){
		printf("inserisci un numero:"); //****** MANCA SPAZIO -0.1
		scanf("%d",&a[i]);
	}
    verifica=Multipli(a,n);
    if(verifica)
    	printf("in tutte le terne di elementi adiacenti e' presente almeno un elemento multiplo di uno degli altri due");
    else
    	printf("non in tutte le terne di elementi adiacenti e' presente almeno un elemento multiplo di uno degli altri due");
}