/*
5pt massimo pari:..1.5
1pt scrivi numeri:.0.8
2pt quanti numeri:.1.8
2pt leggi numeri:..1.8
TOTALE ............5.9
*/
#include <stdio.h>
#include <stdlib.h>
/*Ricorsione*/
int massimoPari(int *a,int l){
	//pre condiz l>=3
	int pari=0;  //**** il PB dipende da l questo non è un PB -1
				 //**** variabile di universalità inizializzata male -1
	//passo ricorsivo
	if (((a[0]+a[1]+a[2])%2==0) && massimoPari(a+1,l-1)) // //**** verifica della proprietà sbagliata -1.5
		pari=1;
	else
		pari=0;
	return pari;
}


/*lettura dati da file*/
int quantiNumeri(){
	int quanti=0;//variabile contatore
	int a;
	FILE *fp=fopen("interi.dat","rb");//apertura file binario in lettura
	if (fp==NULL)
		printf("File vuoto \n");
	else{
		while(fread(&a,sizeof(int),1,fp)>0)
			quanti++;
	}
	return quanti;
}//**** non chiudi il file -0.2


 void leggiNumeri(int *a,int l){
	FILE *fp=fopen("interi.dat","rb");//apertura file binario in lettura
	if (fp==NULL)
		printf("File vuoto \n");
	else{
		fread(a,sizeof(int),l,fp);
 }//**** non chiudi il file -0.2
 }




/*salvataggio dati su file*/

 void salvataggio(int *a,int l){
	FILE *fp=fopen("interi.dat","wb");//apertura file binario in scrittura
	if (fp==NULL)
		printf("File vuoto \n");
	else{
		fwrite(a,sizeof(int),l,fp);
		printf("salvataggio effettuato \n");
 }
 }//**** non chiudi il file -0.2




/*FUNZIONE PRINCIPALE*/
int main(){
	int l;//lunghezza array                  //**** non c'era bisogno di cambiare il main. Hai cambiato un po' troppo...
	int risp=-1;//scelta interazione utente  //**** anche la proprietà che bisognava verificare
	while(risp!=0){
		printf("desideri inserire un nuovo array(1) o recuperarlo da file(2)?\n");
		scanf("%d",&risp);
		if(risp==1){
				printf("inserisci la lunghezza dell'array \n");
				scanf("%d%*c",&l);
				int array[l];
				for(int i=0;i<l;i++){
					printf("inserisci il %d numero \n",i+1);
					scanf("%d",&array[i]);
				}
				if(massimoPari(array,l))
					printf("ogni tripla di interi consecutivi e' tale che la somma sia pari\n");
				else
					printf("ogni tripla di interi consecutivi non e' tale che la somma sia pari\n");
				salvataggio(array,l);
		}
		else if(risp==2){
			l=quantiNumeri();
			int array[l];
			leggiNumeri(array,l);
			if(massimoPari(array,l))
				printf("ogni tripla di interi consecutivi e' tale che la somma sia pari\n");
			else
				printf("ogni tripla di interi consecutivi non e' tale che la somma sia pari\n");
			salvataggio(array,l);
		}
		else printf("numero selezionato non valido,riprova\n");
	}
}
