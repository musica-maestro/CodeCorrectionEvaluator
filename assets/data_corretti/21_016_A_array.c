/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......0
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................4.5
*/
/*SPECIFICA
 * Input: Una sequenza di interi 'arr' ed un intero 'arr_lenght'
 * Pre-condizione: 'arr_lenght' è la lunghezza della sequenza di interi
 * Output: Un valore booleano
 * Post-condizione: Se il valore è uno allora esiste una tripla di elementi consecutivi tale che almeno due elementi
 * della tripla hanno una somma compresa fra 10 e 20 (estremi esclusi) e esattamente
 * due elementi della tripla sono uguali fra loro. Altrimenti il valore è 0
 * TIPO DI PROBLEMA: Problema di verifica esistenziale */

#include <stdio.h>


// FUNZIONE CHE VEDE SE I NUMERI CONSECUTIVI SONO UGUALI
int numCons(int arr[], int arr_lenght) {
	for(int i = 0; i < arr_lenght - 2; i++) {
		if((arr[i] != arr[i+1] || arr[i+1] != arr[i+2]) && (arr[i] == arr[i+1] && arr[i+1] == arr[i+2])) {

			return 0;
		}
		else
			return 1; //******** CON IL RETURN  ALL'INERNO DEL CICLO TI FERMI ALLA PRIMA ITERAZIONE -2
	}
//********* COSA VUOL DIRE? NON DEVI CONTROLLARE TUTTO L'ARRAY, MA CIASCUNA TRIPLA
//********* COMUNQUE LA FUNZIONE NON VERIFICA SE CI SONO DUE CONSEUTIVI UGUALI -2
}


int ugualiCompresi(int arr[], int arr_lenght) {
	for(int i = 0; i < arr_lenght - 2; i++) {
		//******** RICHIAMI LA FUNZIONE numCons SENZA PARAMETRI -2
		if((numCons == 1) && (arr[i] + arr[i+1] >= 10 && arr[i] + arr[i + 1] <=20) || ((arr[i+1] + arr[i+1] >= 10 && arr[i+1] + arr[i + 2] <=20))) {
				return 1;                                                                        //*** i+2 -0.5
		}                          //******** MANCA UNA COMBINAZIONE (i, i+2) -0.5

		else
			return 0;

	}

}





int main(int argc, char **argv) {

	//Sequenza di massimo 1000 interi
	int arr[1000];   //******** DEVI LEGGERE LA LUNGHEZZA DA INPUT -0.5

	//Lunghezza della sequenza di interi
	int arr_lenght;

	printf("Salve utente! Quanti interi ha la sequenza che vuoi introdurre? ");

	scanf("%d", &arr_lenght);

	printf("Perfetto! Introduci gli interi\n");

	for(int i = 0; i < arr_lenght; i++) {

		printf("Intero numero %d: ", i);

		scanf("%d", &arr[i]);
	}
	int risposta = ugualiCompresi(arr, arr_lenght);
	if(risposta == 0) {
		printf("Mi spiace, non esiste nella sua sequenza una tripla di elementi consecutivi tale che almeno due elementi");
		printf("della tripla hanno una somma compresa fra 10 e 20 ed esattamente due elementi della tripla sono uguali fra loro");
	}
	else
		printf("Nella sequenza esiste una tripla di elementi consecutivi tale che almeno due elementi della tripla hanno");
		printf("una somma compresa fra 10 e 20 ed esattamente due elementi della tripla sono uguali fra loro");

	return 0;
}
