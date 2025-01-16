/* SPECIFICA (max 1):......0.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5.5
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............8.5
*/
#include<stdio.h>

/*Algoritmo che data una sequenza di array individua se all'interno esista almeno una tripla di numeri consecutivi all'interno della quale il resto della divisione tra due dei tre numeri sia uguale al terzo numero*/
/*Problema di verifica esistenziale*/
/*Input: sequenza di numeri interi>=3.*/ //******** MANCA LA LUNGHEZZA -0.2
/*Precondizione: Sequenza di interi>=3*/
/*Output: 1 se vero, 0 se falso.*/
/*Postcondizione: Numeri interi e variabile che vale 1 o 0.*/ //******** POST CONDIZIONE NON CORRETTA -0.3

int restoDivisione(int x[],int l1){
	int i=0; //Contatore i che parte dalla prima posizione.
	int vero=0; //Valore di vero inizializzato a 0.
	for(i=0;i<l1-1&&!vero;i++){  //******* i<l1-2  -0.5
		if((x[i]%x[i+1]==x[i+2])||(x[i+1]%x[i]==x[i+2])||
		   (x[i+1]%x[i+2]==x[i])||(x[i+2]%x[i+1]==x[i])||
		   (x[i]%x[i+2]==x[i+1])||(x[i+2]%x[i]==x[i+1])) //Valori booleani che ricoprono tutti i casi.
			vero=1; //Se è verificata almeno una volta esce dal ciclo for.
	}
	return vero;
}

int main(){
int l;
int i=0;

printf("Caro utente, quanti numeri desideri inserire?: \n");
scanf("%d",&l);
int vettore[l];
	for(i=0;i<l;i++){
		printf("Inserisci un numero: \n");
		scanf("%d",&vettore[i]);
	}
if(restoDivisione(vettore,l))
	printf("\nEsiste almeno una tripla il quale resto della divisione tra due dei tre numeri %c equivalente al terzo numero\n",138 );
else
	printf("\nLa proposizione non %c verificata",138); //************ OUTPUT NON ESPLICATIVO (L'UTENTE NON LI VEDE ENTRAMBI) -0.5

}