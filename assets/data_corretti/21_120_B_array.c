/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................8
*/

/* problema che verifica se ogni tripla di elementi consecutiv contiene esattamente due elementi
 * maggiori o uguali a 5 ed almeno due elementi pari
 * SPECIFICA:
 * INPUT: un array arr e di lunghezza lenght
 * PRE-CONDIZIONI: l'array deve contenere minimo 3 valori interi
 * OUTPUT: un booleano per la futura istanza
 * POST-CONDIZIONI: il booleano assegna 1 alla sequenza ideale e 0 alla sequenza errata
 * TIPO DI PROBLEMA: verifica universale  //******** DEVI SPECIFICARE BENE LA POST-CONDIZIONE  -0.5
 *

/* funzione che verifica l'istanza del problema*/
#include <stdio.h>
int maggiori5Pari(int arr[], int lenght) {
	int i=0; //variabile contatore
	int verificata =1;//all'inizio istanza positiva
		while (i<=lenght-3 && verificata) { //procedi fino al terzultimo elemento dell'array
			if (!(((arr[i]<=5 && arr[i+1]>=5 && arr[i+2]>=5)||  //se le condizioni non sono soddisfatte
			       (arr[i]<=5 && arr[i+1]>=5 && arr[i+2]>=5) ||//********* HAI RIPETUTO LA PRECEDENTE -0.5
				(arr[i]>=5 && arr[i+1]<=5 && arr[i+2]>=5)) &&
				((arr[i]%2==0 && arr[i+1]%2==0 && arr[i+2]%2!=0) ||
				(arr[i]%2==0 && arr[i+1]%2!=0 && arr[i+1]%2==0) ||
				(arr[i]%2!=0 && arr[i+1]%2==0 && arr[i+2]%2==0))))
				//******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO PARI ALMENO DUE ELEMENTI
                //******** ES. NEL TUO CASO CON 4,10,20 LA TUA CONDIZIONE NON E' SODDISFATTA  -1.5
					verificata=0; //assegna 0 al valore booleano
			else //sennò vai avanti ed esegui maggiorazione
				i++;
		}
	return verificata; //restituisci booleano

}

/*FUNZIONE MAIN PER INTERAZIONE CON UTENTE*/

int main(int argc, char** argv) {
	int i;
	int lung;

	/*INPUT*/
	printf("ciao utente, quanti numeri vuoi inserire nel vettore?\n");
	scanf("%d", &lung);
	int vett[lung];
		for (i=0; i<lung; i++) { //iterazione per acquisizione dei valori
			printf("inserisci l'elemento in posizione %d: \n", i);
			scanf("%d", &vett[i]); //registrazione valori nelle celle della memoria riservata al vettore
		}
	/* OUTPUT */
	if (maggiori5Pari(vett, lung)==1) //intervento della funzione non principale
		printf("la sequenza che ha inserito rappresenta un'istanza positiva\n");
	else
		printf("la sequenza che ha inserito NON rappresenta un'istanza positiva\n");
}//******** OUTPUT MOLTO POVERO -0.5



