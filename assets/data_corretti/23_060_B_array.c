/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2):...1.5
   TOTALE (10).............7.8
*/
/*Specifica:
*Input: una serie di interi x (x1, x2, ..., xn) e una lughezza
*Pre-Condizioni:lughezza>3 e i<l-2
*Output: un valore booleano
*Post condizioni: se in ogni tripla di elementi esistono almeno due positivi  //***** ESATTAMETE DUE POSITIVI, FALSO ALTRIMENTI -0.2
*Tipo di problema: verifica universale*/
#include <stdio.h>


/*funzione che verifica se in ogni tripla esistono almeno due positivi*/
int duePositivi(int s[], int l){
	int verifica; //variabile di verifica
	int i; //contatore
	verifica=1; //inizializziamo verifica come vero
	i=0;
	while(verifica&&i<l-2){ //ciclo che esce quando trova un risultato di falso
		if((s[i]>0&&s[i+1]>0)||(s[i+2]>0&&s[i]>0)||(s[i+1]>0&&s[i+2]>0))
		//****** COSI' VERIFICHI SE CI SONO ALMENO DUE POSITIVI, NON ESATTAMENTE DUE -1.5
			i++;
		else
		verifica=0;
	}
	return verifica;
}

/*funzione main che chiede quanti numeri si vogliono inserire*/
int main(){
	/*input*/
	int dimensione; //lunghezza della sequenza
	printf("Quanti numeri vuoi inserire?\n");
	scanf("%d", &dimensione);

	int a[dimensione];
	int i;
	for(i=0; i<dimensione; i++){ //ciclo che ci fa inserire i numeri
		printf("Inserisci un numero.\n");
		scanf("%d", &a[i]);
	}
	/*output*/
	if(duePositivi(a, dimensione))
		printf("Rispetta l'istanza");
	else
		printf("Non rispetta l'istanza");//************ OUTPUT NON ESPLICATIVO -0.5

}