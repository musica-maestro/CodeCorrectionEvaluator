/* SPECIFICA (max 1.5):....0.9
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................10.4
*/
/* SPECIFICA
 * imput: una sequenza di s elementi e la sua lunghezza l//******** MANCANO I TIPI DEGLI ELEMENTI DELL'ARRAY -0.6
 * Pre-condizione: s è la lunghezza di l
 * Output: un intero verificatA
 * Post-condizione: verificata=1 se ogni tripla di elementi
 * consecutivi contiene esattamente due elementi maggiori o uguali a 5
 * ed almeno due elementi pari, verificata=0 altrimenti
 * TIPO DI PROBLEMA: Verifica Universale */
#include <stdio.h>
/* funzione che riceve come paramaetro un intero e verifica se è
 * pari*/
int isPari(int x){
	return x%2==0;
}

/* funziomne che rioceve come parametro una sequenmza di interi e verifica se ogni tripla di elementi
 * consecutivi contiene esattamente due elementi maggiori o uguali a 5 ed almeno due elementi pari*/
int maggiori5pari(int interi[],int l){
	int i;                                                 // variabile contatore
	int verificata;                                        // variabile universale
	verificata=1;
	// eamino tutti gli elementi per vedere se c?è una tripkla che non soddisfa i requisiti
	i=1;
	while(i+1<l && verificata){
		// se solo due elemnti della tripla sono maggiori o uguali a 5
		//********** COMPLICATA MA CORRETTA
		if((interi[i-1]>=5 && interi[i]<5 && interi[i+1]<5)
		|| (interi[i-1]<5 && interi[i]<5 && interi[i+1]>=5)
		|| (interi[i-1]<5 && interi[i]>=5 && interi[i+1]<5)
		|| (interi[i-1]<5 && interi[i]<5 && interi[i+1]<5)
		|| (interi[i-1]>=5 && interi[i]>=5 && interi[i+1]>=5))
			verificata=0;

		else
			// se almeno due elementi sono pari
			if((isPari(interi[i-1]) && !isPari(interi[i]) && !isPari(interi[i+1]))
			|| (!isPari(interi[i-1]) && !isPari(interi[i]) && isPari(interi[i+1]))
			|| (!isPari(interi[i-1]) && isPari(interi[i]) && !isPari(interi[i+1]))
			|| (!isPari(interi[i-1]) && !isPari(interi[i]) && !isPari(interi[i+1])))
				verificata=0;
	i++;
	}
	// se l'array ha meno di tre elementi
	if(l<3)
		verificata=0;
	return verificata;
}

/* funzione main che gestisce l'interazione con l'utente */
int main(){
	int l;
	printf("Ciao utente, questo %c un programma che riceve in imput una sequenza di elementi e verifica se ogni tripla di elementi\n", 138);
	printf("consecutivi contiene esattamente due elementi maggiori o uguali a 5 ed almeno due elementi pari\n");
	// chiedo all'utente di scrivere la lunghezza della sequenza
	printf("Scrivi la lunghezza della sequenza: ");
	scanf("%d",&l);
	int Interi[l];
	// chiedo all'utente di introdurre gli elementi
	for(int i=0;i<l;i++){
		printf("Introduci un elemento: ");
		scanf("%d",&Interi[i]);
	}
	// invoco la funzione all'interno dell'if
	if(maggiori5pari(Interi,l))
		printf("Ogni tripla di elementi consecutivi contiene esattamente due elementi maggiori o uguali a 5 ed almeno due elementi pari\n");
	else{
		printf("C'%c una tripla di elementi consecutivi che non contiene esattamente due elementi maggiori o uguali a 5 ed almeno\n", 138);
		printf("due elementi pari, oppure l'array ha meno di tre elementi\n");
	}
}