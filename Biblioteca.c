#include "biblioteca.h"

/*
 * Struttura dati che rappresenta un libro presente
 * nell'archivio della biblioteca.
 *
 * Il campo "presente" rappresenta lo stato del libro:
 *   1 -> disponibile
 *   0 -> attualmente in prestito
 */
typedef struct
{
    int codice;
    char titolo[80];
    char autore[100];
    float prezzo;
    int presente;

} Libro;

/*
 * Archivio principale della biblioteca.
 *
 * L'array contiene tutti i libri registrati durante
 * l'esecuzione del programma.
 */
static Libro archivio[MAX_LIBRI];

/*
 * Mostra il menu principale e acquisisce una scelta valida
 * da parte dell'utente.
 *
 * La funzione continua a richiedere l'input finché non viene
 * inserito un valore compreso tra 1 e 6.
 */
int menu_di_scelta(void)
{
    int scelta;

    printf("\n========================================\n");
    printf("       GESTIONALE BIBLIOTECA\n");
    printf("========================================\n");

    do
    {
        printf("\n");
        printf("1 - Visualizza libri\n");
        printf("2 - Inserisci libro\n");
        printf("3 - Richiedi libro tramite titolo\n");
        printf("4 - Richiedi libro tramite codice\n");
        printf("5 - Restituisci libro\n");
        printf("6 - Esci\n");

        printf("\nScelta: ");

        if (scanf("%d", &scelta) != 1)
        {
            /*
             * Se l'utente inserisce un carattere non numerico,
             * viene ripulito il buffer di input per evitare
             * un ciclo infinito alla successiva lettura.
             */
            while (getchar() != '\n')
            {
                /* Svuotamento del buffer di input. */
            }

            scelta = 0;
        }
        else
        {
            while (getchar() != '\n')
            {
                /* Rimozione dei caratteri residui dal buffer. */
            }
        }

        if (scelta < 1 || scelta > 6)
        {
            printf("\nErrore: selezionare un'opzione compresa tra 1 e 6.\n");
        }

    } while (scelta < 1 || scelta > 6);

    return scelta;
}

/*
 * Visualizza tutti i libri attualmente registrati
 * nell'archivio.
 *
 * Per ogni elemento vengono mostrati i principali dati
 * identificativi e lo stato di disponibilità.
 */
void stampa_libri(int presenti)
{
    if (presenti == 0)
    {
        printf("\nL'archivio non contiene libri.\n");
        return;
    }

    printf("\n========== CATALOGO LIBRI ==========\n");
    
	int i = 0;
	
    for (i = 0; i < presenti; i++)
    {
        printf("\nLibro #%d\n", i + 1);
        printf("Codice       : %d\n", archivio[i].codice);
        printf("Titolo       : %s\n", archivio[i].titolo);
        printf("Autore       : %s\n", archivio[i].autore);
        printf("Prezzo       : %.2f euro\n", archivio[i].prezzo);
        printf("Disponibilita: %s\n",
               archivio[i].presente ? "Disponibile" : "In prestito");
    }

    printf("\n====================================\n");
}

/*
 * Genera un codice identificativo casuale per un nuovo libro.
 *
 * Il codice viene generato nell'intervallo 1000-10999.
 *
 * Prima di restituire il codice viene verificato che non sia
 * già presente nell'archivio.
 */
static int genera_codice(void)
{
    int codice;
    int duplicato;

    do
    {
        codice = (rand() % 10000) + 1000;
        duplicato = 0;
		int i = 0;
		
        for (i = 0; i < MAX_LIBRI; i++)
        {
            if (archivio[i].codice == codice)
            {
                duplicato = 1;
                break;
            }
        }

    } while (duplicato);

    return codice;
}

/*
 * Legge una stringa da input eliminando il carattere newline
 * eventualmente presente alla fine.
 *
 * La funzione utilizza fgets() al posto della funzione gets(),
 * che è stata rimossa dallo standard C perché non consente
 * di limitare la quantità di dati letti.
 */
static void leggi_stringa(char buffer[], int dimensione)
{
    if (fgets(buffer, dimensione, stdin) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}

/*
 * Inserisce un nuovo libro nell'archivio.
 *
 * Vengono richiesti titolo, autore e prezzo.
 * Il codice identificativo viene generato automaticamente.
 *
 * Il libro viene registrato inizialmente come disponibile.
 *
 * Valore restituito:
 *   Numero aggiornato di libri presenti nell'archivio.
 */
int inserimento_libri(int presenti)
{
    if (presenti >= MAX_LIBRI)
    {
        printf("\nErrore: l'archivio ha raggiunto la capacita massima.\n");
        return presenti;
    }

    Libro *libro = &archivio[presenti];

    libro->codice = genera_codice();

    printf("\n========== INSERIMENTO LIBRO ==========\n");

    printf("Titolo: ");
    leggi_stringa(libro->titolo, sizeof(libro->titolo));

    if (strlen(libro->titolo) == 0)
    {
        printf("Errore: il titolo non puo essere vuoto.\n");
        return presenti;
    }

    printf("Autore: ");
    leggi_stringa(libro->autore, sizeof(libro->autore));

    if (strlen(libro->autore) == 0)
    {
        printf("Errore: l'autore non puo essere vuoto.\n");
        return presenti;
    }

    printf("Prezzo: ");

    if (scanf("%f", &libro->prezzo) != 1)
    {
        while (getchar() != '\n')
        {
            /* Svuotamento del buffer di input. */
        }

        printf("Errore: prezzo non valido.\n");
        return presenti;
    }

    while (getchar() != '\n')
    {
        /* Rimozione dei caratteri residui dal buffer. */
    }

    if (libro->prezzo < 0)
    {
        printf("Errore: il prezzo non puo essere negativo.\n");
        return presenti;
    }

    libro->presente = 1;

    printf("\nLibro inserito correttamente.\n");
    printf("Codice assegnato: %d\n", libro->codice);

    return presenti + 1;
}

/*
 * Cerca un libro attraverso il titolo.
 *
 * Se il libro viene trovato e risulta disponibile,
 * viene registrato il prestito modificandone lo stato.
 *
 * Se il libro è già in prestito viene mostrato un messaggio
 * informativo.
 */
void richiesta_titolo(int presenti, char titolo[])
{
	int i = 0;
    for (i = 0; i < presenti; i++)
    {
        if (strcmp(titolo, archivio[i].titolo) == 0)
        {
            if (archivio[i].presente)
            {
                archivio[i].presente = 0;

                printf("\nPrestito effettuato con successo.\n");
                printf("Libro: %s\n", archivio[i].titolo);
                printf("Codice: %d\n", archivio[i].codice);
            }
            else
            {
                printf("\nIl libro richiesto e' gia in prestito.\n");
            }

            return;
        }
    }

    printf("\nNessun libro trovato con il titolo indicato.\n");
}

/*
 * Cerca un libro attraverso il codice identificativo.
 *
 * Se il libro viene trovato e risulta disponibile,
 * viene registrato il prestito.
 *
 * Se il codice non corrisponde ad alcun libro, viene
 * restituito un messaggio di errore.
 */
void richiesta_codice(int presenti, int cod)
{
	int i = 0;
    for (i = 0; i < presenti; i++)
    {
        if (cod == archivio[i].codice)
        {
            if (archivio[i].presente)
            {
                archivio[i].presente = 0;

                printf("\nPrestito effettuato con successo.\n");
                printf("Libro: %s\n", archivio[i].titolo);
            }
            else
            {
                printf("\nIl libro richiesto e' gia in prestito.\n");
            }

            return;
        }
    }

    printf("\nErrore: nessun libro corrisponde al codice indicato.\n");
}

/*
 * Registra la restituzione di un libro identificato dal codice.
 *
 * Il libro viene ricercato nell'archivio e, se presente,
 * viene riportato allo stato disponibile.
 */
void restituzione(int presenti, int cod)
{
	int i = 0;
    for (i = 0; i < presenti; i++)
    {
        if (cod == archivio[i].codice)
        {
            if (!archivio[i].presente)
            {
                archivio[i].presente = 1;
                printf("\nRestituzione completata con successo.\n");
                printf("Libro: %s\n", archivio[i].titolo);
            }
            else
            {
                printf("\nIl libro risulta gia disponibile.\n");
            }

            return;
        }
    }

    printf("\nErrore: nessun libro corrisponde al codice indicato.\n");
}
