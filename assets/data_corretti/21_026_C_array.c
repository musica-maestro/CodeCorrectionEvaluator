/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................8
*/
#include <stdio.h>

/* SPECIFICA: Data una sequenza di interi verifica se esiste una tripla di elementi consecutivi che contiene due
 * elementi il cui valore è compreso fra -10 e 10 (estremi inclusi) e che contiene esattamente due elementi multipli di 3
 * input: interi x1,x2,....,xl
 * prec: l>=3, l è la lunghezza della sequenza
 * output: una variabile booleana true o false
 * post: true se esiste tale tripla che contiene due interi che soddisfano la proprietà richiesta, false altrimenti
 * TIPO PROBLEMA: verifica esistenziale
 */

/* Funzione che riceve come parametro una sequenza di interi, calcola se nella sequenza esiste una tripla costituita
 * da esattamente due interi il cui valore è compreso tra -10 e 10 e due elementi multipli di 3 */
int compresiMultipli3(int interi[], int lunghezza)
{
	int compresi;	// variabile di esistenza - esiste una tripla contente due interi compresi tra -10 e 10 e due multipli di 3?
	int i;			// per scorrere la sequenza

	/* inizializzazione */
	compresi=0;		// inizialmente si assume che non esista alcuna tripla che soddisfa tale proprietà
	i=0;			// inizia a scorrere la sequenza partendo dal primo elemento

	/* scorri la stringa fintanto che non è terminata e che compresi non è verificata */
	while(i<lunghezza && !compresi){//******** INDICE DELL'ARRAY FUORI DAI LIMITI, DEVE ESSERE i<lunghezza-2 -1
		/* nell'if:
		 * 1) la tripla che stai visitando contiene almeno due interi consecutivi il cui valore è compreso tra -10 e 10?
		 * 2) esiste esattamente una coppia di elementi multipli di 3? */
		 if((((interi[i]>=10 || interi[i]<=-10) && (interi[i+1]>=10 || interi[i+1]<=-10))
		 //***** PER ESSERE COMPRESI DOVEVI SCRIVERE (interi[i]<=10 && interi[i]>=-10) -1.5
		 ||((interi[i]>=10 || interi[i]<=-10) && (interi[i+2]>=10 || interi[i+2]<=-10))
		 ||((interi[i+1]>=10 || interi[i+1]<=-10) && (interi[i+2]>=10 && interi[i+2]<=-10)))
		 &&
		 ((interi[i]%3==0 && interi[i+1]%3==0)
		 ||(interi[i]%3==0 && interi[i+2]%3==0)
		 ||(interi[i+1]%3==0 && interi[i+2]%3==0)))
		 //******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO DIVISIBILI PER 3 ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
		 //******** ES. se la tripla e' 3 12 6 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
			 compresi=1;
		else	// altrimenti passa alla prossima tripla
			i++;
	}
	return compresi;	// variabile di ritorno alla funzione invocante (main)
}

/* Funzione principale */
int main(int argc, char **argv)
{
	int l;	// la lunghezza della sequenza

	/* presentazione */
	printf("Questa applicazione chiede di introdurre una sequenza di interi e verifica se nella sequenza da te introdotta esiste una tripla tale che:\n");
	printf("1) Contiene almeno due elementi il cui valore %c compreso tra 10 e -10.\n", 138);
	printf("2) Contiene esattamente due elementi multipli di 3.\n");

	/* leggi la dimensione della sequenza */
	printf("Quanti interi vuoi introdurre?\n");
		scanf("%d", &l);

	/* si vogliono introdurre almeno 3 interi? */
	if(l<3)
		do{
			printf("Valore introdotto non valido. Puoi introdurre almeno 3 elementi.\n");
			printf("Inserisci un nuovo valore: ");
				scanf("%d", &l);
		}while(l<3);

	/* leggi gli elementi della sequenza */
	int sequenza[l];
	for(int i=0; i<l; i++){
		printf("Inserisci il %d%c intero: ", i+1, 167);
			scanf("%d", &sequenza[i]);
	}

	/* output - con invocazione della funzione */
	if(compresiMultipli3(sequenza, l)){
		printf("Nella sequenza esiste una tripla che contiene due elementi il cui valore %c compreso", 138);
		printf(" tra -10 e 10, e una coppia di elementi multipli di 3.\n");
	}
	else{
		printf("Nella sequenza non esiste una tripla di interi che contiene due elementi il cui valore %c compreso tra 10 e -10, e una coppia ", 138);
		printf("di elementi multipli di 3.\n");
	}
}
