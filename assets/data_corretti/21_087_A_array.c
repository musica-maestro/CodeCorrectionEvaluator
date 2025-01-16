/* SPECIFICA (max 1.5):....0.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3.3
   MAIN PROGRAM (max 2.5):.1.5
   TOTALE..................6.3
*/
/*SPECIFICA*/
/*input: sequenza di interi /
 * pre condizione: i numeri sono interi
 * output: valore della tripla //******** QUI CI VA UN BOOLEANO -0.5
 * post condizione: valore booleano //******** LA POST-CONDIZIONE NON DICE NULLA -0.5
 * tipo di problema: verifica esistenziale*/
 #include <stdio.h>
 int ugualiCompresi(int s[], int lunghezza);
 int i; \\variabile di esistenza   //******** NON E' INDENTATO! -0.2
 int trovato;
 /*inizializzazione*/
 i=0;
 trovato=0;

 /*input*/

while((i<=lunghezza-2 && !trovato){  //******* NON CI VA L'UGUALE -0.5
	/*la funzione restituisce 1 se esiste almeno una tripla di elementi consecutivi tale che la somma di almeno due di loro sia un valore compreso tra 10 e 20
	 * ed esattamente due elementi della tripla sono uguali, 0 altrimenti*/
	if((((s[i]+s[i+1]<=20) && (s[i]+s[i+1]>=10))
	|| ((s[i]+s[i+2]<=20) && (s[i]+s[i+2]>=10)) ||
	((s[i+1]+s[i+2]<=20)&&(s[i+1]+s[i+2]>=10)))
	&& ((s[i]=s[i+1]) ||(s[i]=s[i+2])||(s[i+1]=s[i+2]))))
	//******* = INVECE DI == -0.5
	//******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO UGUALI ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
	//******** ES. se la tripla e' 5 5 5 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
		trovato=1;
		else
			i++;
			return trovato;
}
int main()
{
	printf("ciao utente, quanti interi vuoi inserire?\n");
	scanf("%d", &lunghezza);
	int sequenza[lunghezza];
	for(i=0; i<=lunghezza; i++)
		printf("introduci gli interi: \n");
		scanf("%d", &sequenza ); //******** &sequenza[i] -1
		if(ugualiCompresi(sequenza, lunghezza))
			printf("esiste una tripla con almeno due elementi che hanno somma compresa tra 10 e 20, ed esattamente due elementi uguali");
			else
				printf("non esiste una tripla con almeno due elementi che hanno somma compresa tra 10 e 20, ed esattamente due elementi uguali");

	return 0;
}
