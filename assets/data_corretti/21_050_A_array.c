/* SPECIFICA (max 1.5):....0.5
   TIPO PROBLEMA (max 1):..1
   FUNZIONE (max 6):.......4.5
   MAIN PROGRAM (max 2.5):.2.3
   TOTALE..................8.3
*/
/* SPECIFICA: Data una sequenza di interi, verificare se esiste una tripla di elementi consecutivi tale che almeno
            due elementi della tripla hanno una somma compresa fra 10 e 20 (estremi inclusi) ed esattamente due elementi della tripla
            sono uguali fra loro.
 * Input: sequenza di n interi x0, ..., xn-1
 * Pre-condizioni: gli n della sequenza sono interi
 * Output: tripla di elementi consecutivi, dove due elementi hanno somma compresa tra 10 e 20 (estremi compresi) e due elementi
           uguali fra loro
 * Post-condizioni: valore booleano trovato //******** SCAMBI OUTPUT E POST-CONDIZIONI, MA LA POST-CONDIZIONE E' SBAGLIATA -1
 * TIPO DI PROBLEMA: verifica esistenziale
*/
#include <stdio.h>
#define MAX 100

int ugualiCompresi(int interi[], int lunghezza) {
    int i;            //variabile contatore
    int trovato;      //elemento della tripla trovato
    i = 0;            //inizializzazione variabile contatore
    trovato = 0;      //inizialmente no

    while(i<lunghezza-2 && !trovato)
        /* se la condizione risulta essere vera */
        if((((interi[i]+interi[i+1]>=10) && (interi[i]+interi[i+1]<=20))
        || ((interi[i]+interi[i+2]>=10) && (interi[i]+interi[i+2]<=20))
        || ((interi[i+1]+interi[i+2]>=10) && (interi[i+1]+interi[i+2]<=20)))
        && ((interi[i]==interi[i+1]) || (interi[i]==interi[i+2])
        || (interi[i+2]==interi[i+1])))
        //******** CONDIZIONE ERRATA: E' RICHIESTO CHE SIANO UGUALI ESATTAMENTE DUE ELEMENTI (QUINDI IL TERZO DEVE ESSERE DIVERSO)
		//******** ES. se la tripla e' 5 5 5 LA TUA CONDIZIONE E' SODDISFATTA  -1.5

            trovato = 1;
        else
            i++;            //altrimenti vado avanti

        return trovato;
}

int main() {
    int i;           //variabile contatore
    int n;           //variabile elementi che compongono la sequenza
    int x[MAX];      //array  //******** COSI' SPRECHI SPAZIO IN MEMORIA! -0.2
    int tripla;
    /* vediamo di quanti elementi è composta la sequenza */
    printf("Ciao! Di quanti elementi %c composta la sequenza? ", 138);
    scanf("%d", &n);
    /* inseriamo gli elementi della sequenza */
    printf("Adesso inserisci la sequenza di interi: \n");
    for(i=0; i<n; i++)
        scanf("%d", &x[i]);
    tripla = ugualiCompresi(x,n);        //invocazione funzione ugualiCompresi

    /* se la tripla esiste */
    if(tripla==1)
        printf("Esiste una tripla dove la somma di due interi %c compresa fra 10 e 20 e due esattamente uguali\n", 138);
    /* se la tripla non esiste */
    else
        printf("Non esiste una tripla dove la somma di due interi %c compresa fra 10 e 20 e due esattamente uguali\n", 138);
}