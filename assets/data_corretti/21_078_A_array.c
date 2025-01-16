/* SPECIFICA (max 1.5):....1.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......5
   MAIN PROGRAM (max 2.5):.2.5
   TOTALE..................10
*/
#include <stdio.h>

/* SPECIFICA
 * input: una sequenza di interi e la sua lunghezza
 * pre-condizione: la lunghezza è la lunghezza dell'array e lunghezza>=3
 * output: un intero "ugualiCompresi"
 * post-condizione: la funzione restituisce 1 se esiste almeno una tripla di elementi
 * consecutivi tale che almeno due elementi della tripla abbiano somma compresa tra 10
 * e 20 e d nesattamente due elementi della tripla siano uguali tra loro
 * TIPO DI PROBLEMA: problema di verifica esistenziale*/
int ugualiCompresi(int sequenza[], int lunghezza){
    int i=0;               //dichiarazione variabile contatore e sua inizializzazione a 0
    int ugualiCompresi;    //variabile che controlla se esiste una tripla che soddisfi la proprietà.
    ugualiCompresi=0;      //posta uguale a 0 perchè ancora non è stata trovata una tripla che soddisfi la proprietà
    /*controlla tutti i caratteri finchè non finiscono o finchè non trovi una tripla che soddisfi la proprietà*/
    while(i<lunghezza-2 && !ugualiCompresi){
        if(((sequenza[i]==sequenza[i+1] && sequenza[i]!=sequenza[i+2]) &&
        		((sequenza[i]+sequenza[i+1]>=10 && sequenza[i]+sequenza[i+1]<=20)
        		||(sequenza[i]+sequenza[i+2]>=10 && sequenza[i]+sequenza[i+2]<=20)
        		||(sequenza[i+1]+sequenza[i+2]>=10 && sequenza[i+1]+sequenza[i+2]<=20)))
        || ((sequenza[i]==sequenza[i+2] && sequenza[i]!=sequenza[i+1]) &&
        		((sequenza[i]+sequenza[i+1]>=10 && sequenza[i]+sequenza[i+1]<=20)
        		|| (sequenza[i]+sequenza[i+2]>=10 && sequenza[i]+sequenza[i+2]<=20)
        		|| (sequenza[i+1]+sequenza[i+2]>=10 && sequenza[i+1]+sequenza[i+2]<=20)))
        || ((sequenza[i+1]==sequenza[i+2] && sequenza[i]!=sequenza[i+1]) &&
       			 ((sequenza[i]+sequenza[i+1]>=10 && sequenza[i]+sequenza[i+1]<=20)
       			 ||(sequenza[i]+sequenza[i+2]>=10 && sequenza[i]+sequenza[i+2]<=20)
       			 ||(sequenza[i+1]+sequenza[i+2]>=10 && sequenza[i+1]+sequenza[i+2]<=20))))
        //******** CONDIZIONE ESTREMAMENTE CONTORTA: RIPETI PER 3 VOLTE GLI STESSI CONFRONTI -1
                	//	((sequenza[i]+sequenza[i+1]>=10 && sequenza[i]+sequenza[i+1]<=20)
		        	//	||(sequenza[i]+sequenza[i+2]>=10 && sequenza[i]+sequenza[i+2]<=20)
		        	//	||(sequenza[i+1]+sequenza[i+2]>=10 && sequenza[i+1]+sequenza[i+2]<=20)))

            ugualiCompresi=1;
        else
            i++;
    }
    return ugualiCompresi;
}

/*funzione principale*/
int main(){
    /*input*/
    int dimensione;
    printf("Caro utente, questo programma controlla se, nella sequenza de te inserita,\n");
    printf("esiste almeno una tripla di elementi consecutivi tale che almeno due elementi della tripla\n");
    printf("abbiano somma compresa tra 10 e 20 ed esattamente due elementi della tripla siano uguali tra loro\n");
    printf("Inserisci un carattere che indica la lunghezza dellla sequenza:\n");
    scanf("%d", &dimensione);
    int array[dimensione];
    /*Inserimento sequenza*/
    for(int i=0; i<dimensione; i++){
        printf("Inserisci un intero:\n");
        scanf("%d", &array[i]);
    }
    /*Invoca funzione e comunica l'esito all'utente*/
    if(ugualiCompresi(array, dimensione)){
        printf("Esiste almeno una tripla di elementi consecutivi tale che almeno due elementi della tripla\n");
        printf("abbiano somma compresa tra 10 e 20 ed esattamente due elementi della tripla siano uguali tra loro\n");
    }
    else{
        printf("Non esiste alcuna tripla di elementi consecutivi tale che almeno due elementi della tripla\n");
        printf("abbiano somma compresa tra 10 e 20 ed esattamente due elementi della tripla siano uguali tra loro\n");
    }
}


