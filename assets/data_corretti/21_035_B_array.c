/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................11
*/
#include <stdio.h>
/*SPECIFICA PROBLEMA:
 * INPUT:sequenza di interi "array",valore inetro "l";
 * PRE-CONDIZIONI:la sequenza deve contenere solo interi,l indica la lunghezza della sequenza e l>=3;
 * OUTPUT:valore booleano "verifica";
 * POST-CONDIZIONI:il valore booleano è uguale a 1 se ogni tripla di elementi  consecutivi contiene esattamente due elementi maggiori o uguali a 5 ed almeno due pari,è uguale a 0 altrimenti;*/
 /*TIPO DI PROBLEMA:Verifica universale*/
/*funzione che restituisce  1 se ogni tripla di elementi  consecutivi contiene esattamente due elementi maggiori o uguali a 5 ed almeno due pari, 0 altrimenti*/
int maggiori5Pari(int array[],int l){
	int i;  //contatore
	int verifica;   //variabile booleana universale
	verifica=1;   //inizializziamo la variabile come vera
	i=0;
	while(i<l-2 && verifica){
		//se non è vero che ogni tripla di elementi consecutivi contiene esattamente due elementi maggiori o uguali a 5 ed almeno due pari
		if(!(((array[i]>=5 && array[i+1]>=5 && array[i+2]<5)||(array[i]>=5 && array[i+1]<5 && array[i+2]>=5) ||(array[i]<5 && array[i+1]>=5 && array[i+2]>=5))&&((array[i]%2==0 && array[i+1]%2==0)	||(array[i]%2==0 && array[i+2]%2==0)	||(array[i+2]%2==0 && array[i+1]%2==0)||(array[i]%2==0 && array[i+1]%2==0 && array[i+2]%2==0))))
		//*********** L'ULTIMA CONDIZIONE E' RIDONDANTE
			   verifica=0;  //variabile booleana falsa
		else
			i++;
	}
return verifica;
}




int main()
{
 int l;  //lunghezza
 printf("La lunghezza che desideri:  ");
 scanf("%d", &l);

int array[l]; //sequenza di interi
int i; //contatore
for(i=0;i<l;i++){
	printf("%d%c intero della sequenza %c:  ",i+1,167,138);
	scanf("%d", &array[i]);

}
/*invoco la funzione*/
	if(maggiori5Pari(array,l))
		printf("Ogni tripla di elementi consecutivi contiene esattamente due elementi maggiori o uguali a 5 ed almeno due pari");
	else
		printf("Non %c vero che ogni tripla di elementi contiene esattamente due elementi maggiori o uguali a 5 ed almeno due pari",138);
}
