/* SPECIFICA (max 1):......0.3
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......2.5
   MAIN PROGRAM (max 2):...0.3
   TOTALE (10).............4.1
*/
/*SPECIFICA
*INPUT:Una sequenza s di interi  //******** MANCA LA LUNGHEZZA -0.2
*PRE-CONDIZIONI:s è una sequenza di interi
*OUTPUT: degli interi consecutivi //********* L'OUTPUT DEVE ESSERE UN BOOLEANO -0.2
*POST-CONDIZIONI: gli interi consecutivi sono positivi //******** LA POST CONDIZIONE NON E' QUESTA -0.3
*TIPO DI PROBLEMA: verifica universale
*/
#include<stdio.h>
/*funzione che verifica se ogni tripla di elementi consecutivi presenta esattamente due interi positivi*/
int duePositivi(int interi[],int lunghezza){
	int num=0; //contatore
	int i;
	for(i=0;i<lunghezza-2;i++)      //****** COSI' VERIFICHI SE CI SONO ALMENO DUE POSITIVI, NON ESATTAMENTE DUE -1.5
		if((interi[i]>0&&interi[i+1]>0&&interi[i+2]>0))||(interi[i]>0&&interi[i+1]>0)||(inter[i]>0&&interi[i+2]>0)||(interi[i+1]>0&&interi[i+2])
			num=1;
			//******* QUESTA E' UNA VERIFICA ESISTENZIALE, NON UNIVERSALE -2
		else
			i++;
	return 0;
}



/*funzione principale*/
int main(){
	int l; //l è il numero degli elementi
	printf("Sono un programma che verifica se in ogni tripla di elementi adiacenti");
	printf("ci sono esattamente due positivi");
	printf("Inserire il numero degli elementi");
	scanf("%d",&l);
	for(int i=0;i<l;i++);//****** ISTRUZIONE VUOTA, NON LEGGI NIENTE -1
		int seq[l];      //****** L'ARRAY LO DEVI DICHIARARE PRIMA DI LEGGERE GLI INTERI -0.5
	printf("%d",seq[i]);
     duePositivi(sequenza,lunghezza);
     if(duePositivi(sequenza,lunghezza))
	 printf("Tutte le triple contengono due interi positivi");  //******* ESATTAMENTE -0.2
     else
	 printf("Non tutte le triple contengono due positivi.");
}


