/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................9.5
*/
#include <stdio.h>

/*SPECIFICA
 * INPUT:una sequenza di interi x_1,...x_n; un intero n.
 * PRE:n è la lunghezza dell'array.
 * OUTPUT:una variabile booleana.
 * POST:true se ogni tripla di elementi consecutivi contiene esattamente due elementi maggiori o uguali a 5 ed
 * almeno due elementi pari, altrimenti false*/
 /*TIPO DI PROBLEMA:verifica universale*/


/*funzione che data una sequenza di interi, verifica se ogni tripla di elementi consecutivi contiene esattamente due elementi maggiori o uguali a 5 ed
 * almeno due elementi pari*/
int maggiori5Pari(int seq[], int dim){

	int maggiori=1;    //variabile di verifica
	int i=0;          //variabile contatore

	while (i<dim-2&&maggiori){
		if (!((seq[i]>=5&&seq[i+1]>=5)||(seq[i+1]>=5&&seq[i+2]>=5)||(seq[i]>=5&&seq[i+2]>=5))
		//******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO UGUALI ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
		//******** ES. se la tripla e' 5 5 5 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
		&&((seq[i]%2==0&&seq[i+1]%2==0)||(seq[i]%2==0&&seq[i+2]%2==0)||(seq[i+1]%2==0&&seq[i+2]%2==0)))
			maggiori=0;
		else
			i++;

	}
	return maggiori;
}









 /*funzione principale*/
int main(int argc, char **argv)
{
	printf("Ciao utente sono un programma che verifica se ogni tripla di elementi consecutivi contiene esattamente due elementi maggiori o uguali a cinque ed almeno due elementi pari\n ");
	int lunghezza;    //per la lunghezza
	printf("Utente dimmi quanto vuoi sia lunga la tua sequenza\n");
		scanf("%d",&lunghezza);

	int arr[lunghezza];
	for(int i=0; i<lunghezza; i++){
		printf("Inserisci un intero\n");
			scanf("%d",&arr[i]);
	}

	if(maggiori5Pari(arr,lunghezza))
		printf("Ogni tripla di elementi consecutivi contiene esattamente due elementi maggiori o uguali a cinque ed almeno due elementi pari\n");

	else
		printf("Non tutte le triple di elementi consecutivi contengono esattamente due elementi maggiori o uguali a cinque ed almeno due elementi pari\n");

}
