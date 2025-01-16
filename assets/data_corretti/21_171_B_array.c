/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4,1
   MAIN PROGRAM (max 2.5):.2.3
   TOTALE..................8,9
*/
#include <stdio.h>
/*SPECIFICA:
 * INPUT:una sequenza di interi vet e l intero, la sua lunghezza
 * PRE-CONDIZIONE: l e' la lunghezza di vet e l>3
 * OUT-PUT:un intero c he puo' essere o 0 o 1
 * POSTO-CONDIZIONE: se all'interno della sequenza tutte le triple di elementi contengono esattamente due elementi maggiori o uglali a 5 ed almeno due elementi pari
 * TPO DI PROBLEM: verifica universale
 * */
int maggiori5Pari(int vet[], int l){
	int c=0; /*contatore per verificare che non vi siano piu' di due elementi maggioriu uguali a 5*/
	for(int i=0;i<l;i++){
		c=0;
	for(int j=i; j<i+3; j++) {  //******** INDENTATO MALE -0.2
		if (vet[j]>=5){
			c=c+1;}

		}
		if (!(c==2)) {
			return 0;                  /*se non vi sono esattamente 2 elementi maggiori uguali a 5 ritorno 0*/
			} else {//******** INDENTATO MALE -0.2
				if (!((vet[i]%2==0 && vet[i+1]%2==0)||(vet[i]%2==0 && vet[i+2]%2==0)||(vet[i+1]%2==0 && vet[i+2]%2==0))) {    /*se non vi sono almeno 2 elementi pari ritorno 0*/
					return 0;
					}
//******** 3 RETURN NON E' PROGRAMMAZIONE STRUTTURATA -1.5
				}

}
return 1; //******** 3 RETURN -0.4
}

int main(int argc, char **argv)
{
	printf("Caro utente sono un programma che calcola se all'inyternoi della sequenza che inserirai tutte le triple di elementi contengono esattamente due elementi maggiori o uglali a 5 ed almeno due elementi pari\n");
	int l; /*lunghezza dell array*/
	printf("Per favore inserire lnghezza\n");
	scanf("%d", &l);

	int vet[l];
	for(int i=0;i<l;i++){
		printf("Per favore inserire n.%d\n", i+1);
		scanf("%d", &vet[i]);
		}
		if (maggiori5Pari(vet, l)== 1) {
				printf("La sequenza inserita rispetta le caratteristiche richieste\n"); /*istanza positiva del problema */
			} else {  //******** INDENTATO MALE -0.2
				printf("La sequenza inserita NON rispetta le caratteristiche richieste\n"); /*istanza negativa del problema */
				}

	return 0;
}
