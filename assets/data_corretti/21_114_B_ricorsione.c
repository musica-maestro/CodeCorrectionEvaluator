/*
5pt minimo dispari:..3.5
1pt scrivi numeri:...0.2
2pt quanti numeri:...1.3
2pt leggi numeri:....0
TOTALE ..............5
*/
#include <stdio.h>
#include <stdlib.h>


quantiNumeri()
{
	int quanti=0;
	FILE *fp = fopen("Arraynumeri.txt",'r'); //**** errore di sintassi "r" -0.4
	if(fp==NULL)
	{
		printf("Apertura del file non riuscita!");
	}
	else
	{
		int numeri;
		while(fscanf(fp,"%d",numeri)!=EOF) //**** &numeri -0.3
		{
			quanti++;
		}
	}
	fclose(fp);

	return quanti;
}

void scriviNumeri(int a[], int l)
{
	FILE *fp = fopen("Arraynumeri.txt",'r');//**** errore di sintassi "w" -0.5
	if(fp==NULL)
	{
		printf("Apertura del file non riuscita!");
	}
	else
	{
		int i=0;
		while(fscanf(fp,"%d",a[i])!=EOF)//**** fprintf!  -0.3
		{
			i++;
		}
	}
	fclose(fp);
	printf("AAquisizione effettuata!");
}

int controlloMinimo(int *a)
{
	int verifica=0;
	if(a[0]<=a[1])
	{
		if(a[0]<=a[2])
		{
			if(a[0]%2!=0)
			{
				verifica=1;
			}
			else
			{
				verifica=0;
			}

		}//**** i commenti! se sei qui già sai che a[0]>a[2].
		else if(a[0]>a[2])
			{
				if(a[2]%2!=0)
			{
				verifica=1;
			}
			else
			{
				verifica=0;
			}
		}
	}
	else if(a[1]<=a[2])
	{
			if(a[1]%2!=0)
			{
				verifica=1;
			}
			else
			{
				verifica=0;
			}
	}	//**** manca il caso in cui a[2]<a[1]: -1 TROPPO COMPLICATO! -0.5
	return verifica;


}


int minimoDispari(int a[], int l)
{
	int minimod=0;// variabile usata per controllare se esistono triple con minimo dispari
	//caso base
	if(l<=2)
	{
		minimod=1;
	}
	else
	{
		minimod= controlloMinimo(a) && minimoDispari(a+1, l-1);//passo riscorsivo
	}

	return minimod;
}

void caricavettore(int a[], int l)
{
	int i;
	for(i=0;i<l;i++)
	{
		printf("Inserisci valori nell'array\n");
		scanf("%d",&a[i]);
	}
}
int main(int argc, char **argv)
{
	int lunghezza;
	int seq[lunghezza];
	printf("vuoi inserire te unal unghezza e i valori dell'array oppure prenderli dal file\n 0=nuovi 1=file\n");
	int scelta;
	scanf("%d",&scelta);
	if (scelta == 0)
	{
		printf("inserisci lunghezza\n");
		scanf("%d",&lunghezza);
		caricavettore(seq,lunghezza);
	}
	else
	{
	    int lunghezza=quantiNumeri();
	    scriviNumeri(seq,lunghezza);
	}
	//Acquisizione lunghezza array

	if(minimoDispari(seq,lunghezza))
	{
		printf("Ogni tripla di numeri ha come minimo un numero dispari\n");
	}
	else
	{
		printf("Esistono una o piÃ¹ tripla di numeri che non ha come minimo un numero dispari\n");
	}

	return 0;
}
