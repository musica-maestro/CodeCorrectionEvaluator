/* SPECIFICA (max 1.5):....1
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......1
   MAIN PROGRAM (max 2.5):.2
   TOTALE..................5
*/
/*Specifica
 * input: n interi
 * pre-condizione: nessuna
 * output: 0 o 1
 * post-condizione: se l'array inserito soddisfa le condizioni l'output deve essere 1 altrimenti 0
 * Tipo di problema: verifica esistenziale*/ //******** LA POST-CONDIZIONE NON DICE NULLA -0.5

#include <stdio.h>

int compresiMultipli3(int elementi[], int dimensione)
{
	int i, a, b, c, risultato;
	risultato=0;
	for(i=0;i<dimensione;i++){
		if(i<(dimensione-2)){
			a=elementi[i];
			b=elementi[i+1];
			c=elementi[i+2];  //****** I COMMENTI!!!!!! -0.5
			if((a<=10 && a>=-10) && (b<=10 && b>=-10) && (c<=10 && c>=-10)){
				if((b<=10 && b>=-10) && (c<=10 && c>=-10)){//*** OVVIO CHE SIA VERA, SEI ENTRATA QUI PERCHE' SONO TUTTI COMPRESI TRA -10 E 10 -1
					if(a%3==0 && b%3==0 && c%3==0){
						risultato=0;
					}
					if(a%3!=0 && b%3!=0 && c%3!=0){
						risultato=0;
					}
					else{
						risultato=1;  //******** RESTITUISCI IL VALORE CALCOLATO SULL'ULTIMA TRIPLA -1.5
					}
				}
				if((a<=10 && a>=-10) && (c<=10 && c>=-10)){
					if(a%3==0 && b%3==0 && c%3==0){
						risultato=0;
					}
					if(a%3!=0 && b%3!=0 && c%3!=0){
						risultato=0;
					}
					else{
						risultato=1;
					}

				}
				if((a<=10 && a>=-10) && (b<=10 && b>=-10)){
					if(a%3==0 && b%3==0 && c%3==0){
						risultato=0;
					}
					if(a%3!=0 && b%3!=0 && c%3!=0){
						risultato=0;
					}
					else{
						risultato=1;   //******** CONDIZIONE ESTREMAMENTE CONTORTA E SBAGLIATA -2

					}

				}
			}
		}
		else{ //****** MA GIA' LI HAI ESAMINATI!!!  DOVEVI SCRIVERE i<dimensione-2 NEL WHILE -2
			a=elementi[i];  //****** OPPURE NON METTERE NIENTE NELL'ELSE
			b=elementi[i-1];
			c=elementi[i-2];
			if((a<=10 && a>=-10) && (b<=10 && b>=-10) && (c<=10 && c>=-10)){
				if((b<=10 && b>=-10) && (c<=10 && c>=-10)){
					if(a%3==0 && b%3==0 && c%3==0){
						risultato=0;
					}
					if(a%3!=0 && b%3!=0 && c%3!=0){
						risultato=0;
					}
					else{
						risultato=1;
					}
				}
				if((a<=10 && a>=-10) && (c<=10 && c>=-10)){
					if(a%3==0 && b%3==0 && c%3==0){
						risultato=0;
					}
					if(a%3!=0 && b%3!=0 && c%3!=0){
						risultato=0;
					}
					else{
						risultato=1;
					}

				}
				if((a<=10 && a>=-10) && (b<=10 && b>=-10)){
					if(a%3==0 && b%3==0 && c%3==0){
						risultato=0;
					}
					if(a%3!=0 && b%3!=0 && c%3!=0){
						risultato=0;
					}
					else{
						risultato=1;
					}

				}
			}
		}
	}
	return risultato;
}

int main(int argc, char **argv)
{
	int i, lunghezza;
	printf("Quanti elementi ha l'array?\n");
	scanf("%d", &lunghezza);
	int array[lunghezza];
	for(i=0;i<lunghezza;i++){
		printf("Inserisci un intero\n");
		scanf("%d", &array[i]);
	}
	if(compresiMultipli3(array,lunghezza)){
		printf("L'array e' nei parametri\n");  //******** OUTPUT MOLTO POVERO -0.5
	}
	else{
		printf("L'array non e' nei parametri\n");
	}
}

