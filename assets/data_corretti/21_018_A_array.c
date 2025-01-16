/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......6
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE.................10.5
*/

/* SPECIFICA
 * Input: Una sequenza s con lunghezza l
 * Pre-condizione: l è la lunghezza di s
 * Output: un intero esiste
 * Post-Condizione: esiste vale 1 se, 0 altrimenti //******** LA POST-CONDIZIONE NON DICE NULLA -0.5
 * TIPO DI PROBLEMA: verifica esistenziale
*/

#include <stdio.h>

/* funzione che riceve come parametro un array di interi e la sua lunghezza, restituise 1 se esiste una tripla
 * di elementi consecutivi tale che almeno due elementi hanno somma compresa fra 10 e 20 (estremi inclusi)
 * ed esattamente due elementi della tripla sono fra loro uguali, 0 se tale tripla non esiste*/
int ugualiCompresi(int interi[], int dimensione) {
	int esiste;					//variabile da restituire
	int i;						//variabile contatore

	/* pongo che inizialmente non esiste nessuna tripla nella sequenza che rispetti le post-condizioni */
	esiste = 0;

	/* verifico tutte le triple della sequenza */
	i = 0;
	while(i<dimensione-2 && !esiste) {
		if( ((interi[i]+interi[i+1] >=10 && interi[i]+interi[i+1] <=20) || (interi[i]+interi[i+2] >=10 && interi[i]+interi[i+2] <=20)
			|| (interi[i+1]+interi[i+2] >=10 && interi[i+1]+interi[i+2] <=20)) && (((interi[i] == interi[i+1]) && (interi[i+2] != interi[i]))
			|| ((interi[i] == interi[i+2]) && (interi[i+1] != interi[i])) || ((interi[i+1] == interi[i+2]) && (interi[i] != interi[i+1])) ) )
				esiste = 1;
		else
			i++;				//passo alla tripla seuccessiva
	}
	return esiste;
}

/* funzione che legge una sequenza di interi da tastiera (dopo aver chiesto all'utente da quanti interi sia composta tale sequenza),
 * verifica se esiste una tripla di elementi consecutivi tale che almeno due elementi hanno somma compresa fra 10 e 20 (estremi inclusi)
 * ed esattamente due elementi della tripla sono fra loro uguali, o se non esiste*/
int main() {
	int lunghezza;				//lunghezza della sequenza

	/* specifica del funzionamento del programma */
	printf("Ciao utente, sono un programma che legge una sequenza di interi e verifica se nella sequenza\n");
	printf("esiste una tripla di elementi consecutivi tale che almeno due elementi hanno somma compresa fra 10 e 20 (estremi inclusi)\n");
	printf("ed esattamente due elementi della tripla sono fra loro uguali, o se non esiste!\n\n");

	/* legge la lunghezza della sequenza */
	printf("Da quanti interi vuoi che sia composta la sequenza?\t");
	scanf("%d", &lunghezza);
	/* se la sequenza non ha almeno 3 interi il programma non viene svolto correttamente, quindi chiedere una ulteriore lunghezza */
	if(lunghezza<3) {
		printf("La sequenza deve avere almeno 3 interi quindi dammi un'altra lunghezza per la sequenza: ");
		scanf("%d", &lunghezza);
	}

	/* legge la sequenza */
	printf("\nBene ora inserisci la sequenza!\n");
	int sequenza[lunghezza];
	for(int i=0; i<lunghezza; i++) {
		printf("Inserisci il %d%c intero: ", i+1, 167);
		scanf("%d", &sequenza[i]);
	}

	/* invocazione della funzione ugualiCompresi con stampa del messaggio che informa l'utente del risultato di tale funzione */
	if(ugualiCompresi(sequenza, lunghezza)) {
		printf("Esiste una tripla di elementi consecutivi tale che almeno due elementi hanno somma compresa fra 10 e 20\n");
		printf("(estremi inclusi) ed esattamente due elementi della tripla sono fra loro uguali\n");
	}
	else {
		printf("Non esiste una tripla di elementi consecutivi tale che almeno due elementi hanno somma compresa fra 10 e 20\n");
		printf("(estremi inclusi) ed esattamente due elementi della tripla sono fra loro uguali\n");
	}
}
