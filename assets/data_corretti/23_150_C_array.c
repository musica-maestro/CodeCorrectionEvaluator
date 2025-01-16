/* SPECIFICA (max 1):......0.8
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......2
   MAIN PROGRAM (max 2):...2
   TOTALE (10).............5.8
*/
#include <stdio.h>
#include <string.h>
/*
il tipo di problema è: di verifica universale
-IMPUT:una sequenza di interi //******** MANCA LA LUNGHEZZA -0.2
-PRE CODNIZIONI: interi positivi
-OUTPUT: un valore 'esiste'
-POST CONDIZIONI: esiste è uguale a true se in ogni tripla ci sono almeno due numeri composti da una sola cifra

*/
int dueUnaCifra (int* array, int l){
	int esiste=1;
	int i=0;
	//while(i<l&&esiste){
		/*if (!(((array[i]>='0' && array[i]<='9') && (array[i+1]>='0' && array[i+1]<='9'))||((array[i]>='0'&&array[i]<='9')&&(array[i+2]>='0'&&array[i+2]<='9'))||((array[i+1]>='0'&&array[i+1]<='9')&&(array[i+2]>='0'&&array[i+2]<='9'))))
			esiste=0;*/
		for (int i = 0; i < l-3; ++i){ //***** i<=l-3 -0.5
		//if (!(array[i]<='9'||array[i+1]<='9'||array[i+2]<='9'))
		if(!((array[i]<='9'&&array[i+2]<='9'&&array[i+1]>'9')||   //******* CONFRONTI UN INTERO CON UN CARATTERE! -1.5
		     (array[i]<='9'&&array[i+1]<='9'&&array[i+2]>'9')||   //****** COSI' VERIFICHI SE CI SONO ESATTAMENTE DUE DI UNA CIFRA, NON ALMENO DUE -1.5
		     (array[i+1]<='9'&&array[i+2]<='9'&&array[i+3]>'9'))) //***** CONSIDERI UN QUADRUPLA??? -1
			esiste=0;
		}
	//i++;}
	return esiste;
}







int main(int argc, char const *argv[])
{
int l;
printf("utente, inserisci la lunghezza del tuo array: \n");
scanf("%d", &l);
int array[l];
printf("ora inserisci gli elementi dell'array \n");
for (int i = 0; i < l; i++)
{
	scanf("%d", &array[l]);
}
if (dueUnaCifra(array, l))
	printf("la tua propietà VALE\n"); //************ OUTPUT NON ESPLICATIVO -0.5
else
	printf("la tua propietà NON VALE\n");
}