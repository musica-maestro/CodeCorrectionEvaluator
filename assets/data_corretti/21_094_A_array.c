/* SPECIFICA (max 1.5):....1.3
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................8.3
*/
/*INPUT: l, unasequenza di interi
 * PRE-CONDIZIONE: l>=0, l e' la lunghezza della sequenza
 * OUTPUT: esiste (valore booleano)
 * POST-CONDIZIONE: esiste=1 se esiste almenouna tripla tale che almeno due elementi hanno somma compresa fra 10 e 20, e con esattamente due elementi uguali
 *                                   //******** POST-CONDIZIONE NON COMPLETA (0, altrimenti) -0.2
 *TIPOLOGIA: verifica esistenziale */

 #include <stdio.h>

int ugualiCompresi(int *a,int l){
	int esiste = 0;

	for(int i=0;i<l-2;i++) //******** NON USI LA VARIABILE BOOLEANA PER TERMINARE IL CICLO -1
		if(((a[i]+a[i+1]+a[i+2])<20 && (a[i]+a[i+1]+a[i+2])>10) //******** CONDIZIONE ERRATA E INUTILE: CALCOLI LA SOMMA
		|| ((a[i]+a[i+1])<20 && (a[i]+a[i+1])>10)               //******** DI TUTTI E TRE GLI ELEMENTI DELLA TRIPLA  -1
		|| ((a[i]+a[i+2])<20 && (a[i]+a[i+2])>10) |
		| ((a[i+1]+a[i+2])<20 && (a[i+1]+a[i+2])>10))
			if((a[i]==a[i+1] && a[i]!=a[i+2]) || (a[i]==a[i+2] && a[i]!=a[i+1]) || (a[i+2]==a[i+1] && a[i]!=a[i+2]))
				esiste =1;

	return esiste;

//******** NON USI LA VARIABILE BOOLEANA PER TERMINARE IL CICLO -1
}

int main(){
	int l;

	printf("Quanti interi deve contenere la sequenza?\n");
	scanf("%d",&l);

	int a[l];
	printf("scrivi gli elementi della sequenza\n");
	for(int i=0; i<l; i++)
		scanf("%d",&a[i]);


	if(ugualiCompresi(a,l))
		printf("la tripla esiste"); //******** I/O MOLTO POVERO -0.5
	else
		printf("la tripla NON esiste");
}
