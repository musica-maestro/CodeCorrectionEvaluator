/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......3
   MAIN PROGRAM (max 2.5):.2.3
   TOTALE..................7.3
*/
/*SPECIFICA:
 * *input:una sequenza di interi e la sua lunghezza
 * * pre-condizione: lun ghezza è la lunghezza della sequenza
 * output: se ogni tripla di elementi consecutivi nella sequenza contiene almeno esattamente due elementi maggiori o uguali a 5 e almeno due elementi pari
//******** OUTPUT DEVE RESTITUIRE UN BOOLEANO -0.5
 * post-condizione: se ogni tripla di elementi consecutivi nella sequenza contiene almeno esattamente due elementi maggiori o uguali a 5 e almeno due elementi pari stampa 1, o altrimenti.
 * tipo di problema:verifica universale, poiche verifico una proprietà*/
 #include <stdio.h>
int maggiori5Pari(int interi[], int lung){
	int i=0;
	int verificato=1;//inizialmente tutti soddisfano la proprieta
	while((i<lung)&&verificato){
		/*se non sono numerici va avanti*/
	if(!((interi[i]>='0')&&(interi[i]<='9'))) //******** SONO GIA' INTERI, NON SONO CARATTERI! -1
		i++;
		else{
			if(((interi[i])&&(interi[i+1])>=5)||((interi[i])&&(interi[i+2])>=5)||((interi[i+1])&&(interi[i+2])>=5)){
			//******** NON E' LA SINTASSI CORRETTA: DOVEVI SCRIVERE (interi[i])>=5&&(interi[i+1])>=5 -1.5
			//******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO UGUALI ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
            //******** ES. se la tripla e' 5 5 5 LA TUA CONDIZIONE E' SODDISFATTA  -1.5
				if(((interi[i]%2==0)&&(interi[i+1]%2==0))||((interi[i]%2==0)&&(interi[i+2]%2==0))||(interi[i+1]%2==0)&&(interi[i+2]%2==0)){
					verificato=1;}} //******** NON SERVE! -0.5
					else{
						verificato=0;}}
					}
						i++;
	return verificato;}

int main(){
int lunghezza;
printf("caro utente,quanti interi vuoi inserire?");
scanf("%d", &lunghezza);
int sequenza[lunghezza];
for (int i=0; i<lunghezza; i++){
	printf("inserisci gli interi della sequenza");
	scanf("%d", &sequenza[i]);}
	if(maggiori5Pari(sequenza,lunghezza))
		printf("ogni tripla di elementi consecutivi nella sequenza contiene almeno esattamente due elementi maggiori o uguali a 5 e almeno due elementi pari");
		else //******** INDENTATO MALE -0.2
			printf("ogni tripla di elementi consecutivi nella sequenza NON contiene almeno esattamente due elementi maggiori o uguali a 5 e almeno due elementi pari");

}
