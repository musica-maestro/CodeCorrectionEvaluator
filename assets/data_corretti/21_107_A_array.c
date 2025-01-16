/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................8.5
*/
#include <stdio.h>

/*SPECIFICA
 * Input: un array di interi e la sua lunghezza
 * Pre-condizione: lunghezza>=0
 * Output: un booleano trovato
 * post-condizione: trovato=1 se esiste una tripla che soddisfa la proprietà
 *                                              //******** LA POST-CONDIZIONE NON DICE NULLA -0.5
 * TIPO DI PROBLEMA: verifica esistenziale*/


/*Funzione che restituisce 1 se esiste una tripla di elementi consecutivi tale che
 * almeno due elementi della tripla hanno una somma compresa fra 10 e 20 (estremi inclusi)
 * ed esattamente due elementi della tripla sono fra loro uguali*/
 int ugualiCompresi (int interi[], int lunghezza) {
	 int i;
	 int trovato;
	 trovato=0;

	 i=0;
	 while (i<lunghezza-2 && !trovato) {  //leggo le triple finchè una soddisfi la proprietà
		 /*se ls soddisfa mi fermo*/
		 if (((interi[i]+interi[i+1]>=10&&interi[i]+interi[i+1]<=20)||(interi[i+1]+interi[i+2]>=10&&interi[i+1]+interi[i+2]<=20)||(interi[i]+interi[i+2]>=10&&interi[i]+interi[i+2]<=20))
		 &&((interi[i]==interi[i+1])||(interi[i+1]==interi[i+2])||(interi[i]==interi[i+2])))
		 //******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO UGUALI ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
		 //******** ES. se la tripla e' 5 5 5 LA TUA CONDIZIONE E' SODDISFATTA  -1.5

			 trovato=1;
		/*altrimenti vado avanti*/
		else
			i++;
	 }
	 return trovato;
 }



/*Funzione principale*/
int main() {
	int lunghezza;   //input
	printf("Quanti interi vuoi inserire?\n");
	scanf("%d", &lunghezza);   //lunghezza dell'array

	int interi[lunghezza];
	for (int i=0; i<lunghezza; i++) {   //leggo ogni intero che fa parte dell'array
		printf("Inserisci un intero: ");
		scanf("%d", &interi[i]);
	}
	if (ugualiCompresi(interi, lunghezza))    //output
		printf("Esiste una tripla che soddisfa la proprieta'\n");
	else
		printf("Non esiste una tripla che soddisfa la proprieta'");
}       //******** I/O MOLTO POVERO -0.5
