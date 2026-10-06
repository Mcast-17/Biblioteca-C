#include "biblioteca.h"

/*
 * Punto di ingresso dell'applicazione.
 *
 * Il main gestisce il ciclo principale del programma e
 * delega alle funzioni del modulo biblioteca le singole
 * operazioni richieste dall'utente.
 */
int main(void)
{
    int presenti = 0;
    int scelta;
    int codice;
    char titolo[80];

    /*
     * Inizializza il generatore di numeri pseudo-casuali
     * utilizzando l'orario corrente come seme.
     *
     * L'inizializzazione viene eseguita una sola volta
     * all'avvio del programma.
     */
    srand((unsigned int)time(NULL));

    printf("========================================\n");
    printf("       BENVENUTO NELLA BIBLIOTECA\n");
    printf("========================================\n");

    /*
     * Il ciclo principale rimane attivo fino alla scelta
     * dell'opzione "Esci".
     */
    do
    {
        scelta = menu_di_scelta();

        switch (scelta)
        {
            case 1:
                /*
                 * Visualizza tutti i libri attualmente
                 * registrati nell'archivio.
                 */
                stampa_libri(presenti);
                break;

            case 2:
                /*
                 * Inserisce un nuovo libro e aggiorna
                 * il numero complessivo dei libri presenti.
                 */
                presenti = inserimento_libri(presenti);
                break;

            case 3:
                /*
                 * Ricerca un libro attraverso il titolo
                 * e ne registra il prestito se disponibile.
                 */
                printf("\nInserisci il titolo del libro: ");

                if (fgets(titolo, sizeof(titolo), stdin) != NULL)
                {
                    titolo[strcspn(titolo, "\n")] = '\0';
                    richiesta_titolo(presenti, titolo);
                }
                else
                {
                    printf("\nErrore nella lettura del titolo.\n");
                }

                break;

            case 4:
                /*
                 * Ricerca un libro attraverso il codice
                 * identificativo e ne registra il prestito
                 * se disponibile.
                 */
                printf("\nInserisci il codice del libro: ");

                if (scanf("%d", &codice) == 1)
                {
                    while (getchar() != '\n')
                    {
                        /* Pulizia del buffer di input. */
                    }

                    richiesta_codice(presenti, codice);
                }
                else
                {
                    printf("\nErrore: codice non valido.\n");

                    while (getchar() != '\n')
                    {
                        /* Pulizia del buffer di input. */
                    }
                }

                break;

            case 5:
                /*
                 * Ricerca un libro attraverso il codice
                 * e registra la relativa restituzione.
                 */
                printf("\nInserisci il codice del libro da restituire: ");

                if (scanf("%d", &codice) == 1)
                {
                    while (getchar() != '\n')
                    {
                        /* Pulizia del buffer di input. */
                    }

                    restituzione(presenti, codice);
                }
                else
                {
                    printf("\nErrore: codice non valido.\n");

                    while (getchar() != '\n')
                    {
                        /* Pulizia del buffer di input. */
                    }
                }

                break;

            case 6:
                /*
                 * Termina normalmente l'esecuzione del programma.
                 */
                printf("\nUscita dal programma. Grazie!\n");
                break;
                
                default:
                /*
                 * Questa situazione viene già gestita dalla
                 * validazione presente in menu_di_scelta().
                 */
                printf("\nScelta non valida.\n");
                break;
        }

    } while (scelta != 6);

    return 0;
}
