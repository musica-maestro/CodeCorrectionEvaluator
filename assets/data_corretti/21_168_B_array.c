/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................8
*/
#include <stdio.h>

/*
 * Data una sequenza di interi, verificare se ogni tripla di elementi consecutivi
 * contiene esattamente due elementi maggiori o uguali a 5 ed almeno 2 pari
 * */

/*
 * Specifica
 * Input: sequenza di interi e lunghezza
 * Pre-condizione: lunghezza è la lunghezza della sequenza di interi, lunghezza > 3
 * Output: int verificato
 * Post-condizione: verificato se è 0 la sequenza non soddisfa la condizione, altrimenti se è 1 la soddisfa
 * Tipo problema: verifica universale
 * */

/*	funzione che verifica se un numero è maggiore uguale a 5*/
int verificaMaggioreDi5(int a){
	int maggiore = 0; //********BASTAVA SCRIVERE  return a>=5;
	if(a>=5){
		maggiore = 1;
	}
	return maggiore;
}

/*	funzione che verifica se un numero è pari*/
int pari(int a){      //******** COME SOPRA
	int pari=0;
	//controllo se è divisibile per 2
	if(a%2==0){
		pari = 1;
	}
	return pari;
}

int maggiori5Pari(int vet[], int lunghezza){

	int i=1, verificato=1;									//dichiarazione e inizializzazione variabile contatore e verificato

	//scorro il vettore finchè non lo finisco o la condizone non viene rispettata
	while((i<lunghezza-1) && (verificato==1)){
		//se la tripla risulta avere almeno un numero maggiore uguale di 5
		if(((verificaMaggioreDi5(vet[i-1])) && (verificaMaggioreDi5(vet[i])))
		|| ((verificaMaggioreDi5(vet[i+1])) && (verificaMaggioreDi5(vet[i])))
		|| ((verificaMaggioreDi5(vet[i+1])) && (verificaMaggioreDi5(vet[i-1])))){
		//******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO UGUALI ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
        //******** ES. se la tripla e' 5 5 5 LA TUA CONDIZIONE E' SODDISFATTA  -1.5

			//se la tripla ha almeno 2 pari
			if(((pari(vet[i-1]))&&(pari(vet[i])))
			|| ((pari(vet[i-1]))&&(pari(vet[i+1])))
			|| ((pari(vet[i]))&&(pari(vet[i+1])))){
				//controllo l'elemento successivo
				i++;
			    //*********** SE LA CONDIZIONE NON E' SODDISFATTA LA VARIABILE verificato NON VIENE MODIFICATA -1.5
			}
		}
		//se non soddisfa la condizione di avcere almeno 2 num maggiori uguali di 5
		else{
			//pongo verificato a 0 e faccio uscire dal ciclo while
			verificato=0;
		}
	}
	//restituisco il valore ottenuto
	return verificato;
}

int main(int argc, char **argv)
{

	printf("Caro utente, in questo programma viene verificata se, nella sequenza di numeri inseriti ogni tripla di elementi consecutivi contiene esattamente due elementi maggiori o uguali a 5 ed almeno 2 pari\n");
	int lunghezza=0, i;												//dichiarazione contatore e inizializzazione variabile lunghezza
	printf("Per prima cosa inserisci quanto deve essere lunga la sequenza di interi: ");
	scanf("%d", &lunghezza);				//l'utente mi inserisce la lunghezza della sequenza
	int array[lunghezza];
	printf("Bene! Ora inserisci i valori della sequenza: \n");
	//carica gli elementi della sequenza
	for(i=0; i<lunghezza; i++){
		printf("Inserisci il valore %d: ", i+1);
		scanf("%d", &array[i]);
	}

	//stampo la sequenza ottenta
	printf("La sequenza inserita ");

	for(i=0; i<lunghezza; i++){
		printf("[%d]", array[i]);
	}
	//richiamo la funzione e controlla se la sequenza soddisfa la condizione
	if(maggiori5Pari(array, lunghezza)){
		printf(" soddisfa la condizione!");
	}
	//se non la soddisfa
	else{
		printf(" non soddisfa la condizione :(");
	}

	return 0;
}
