#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * Numero massimo di libri gestibili dall'archivio.
 */
#define MAX_LIBRI 80

/*
 * Visualizza tutti i libri presenti nell'archivio.
 *
 * Parametri:
 *   presenti - numero di libri attualmente registrati.
 */
void stampa_libri(int presenti);

/*
 * Inserisce un nuovo libro nell'archivio.
 *
 * La funzione acquisisce i dati del libro, genera il relativo
 * codice identificativo e aggiorna il numero di libri presenti.
 *
 * Parametri:
 *   presenti - numero di libri attualmente registrati.
 *
 * Valore restituito:
 *   Il nuovo numero di libri presenti nell'archivio.
 */
int inserimento_libri(int presenti);

/*
 * Cerca un libro attraverso il titolo e, se disponibile,
 * ne registra il prestito.
 *
 * Parametri:
 *   presenti - numero di libri attualmente registrati.
 *   titolo   - titolo del libro da ricercare.
 */
void richiesta_titolo(int presenti, char titolo[]);

/*
 * Cerca un libro attraverso il codice identificativo e,
 * se disponibile, ne registra il prestito.
 *
 * Parametri:
 *   presenti - numero di libri attualmente registrati.
 *   cod      - codice identificativo del libro.
 */
void richiesta_codice(int presenti, int cod);

/*
 * Registra la restituzione di un libro identificato
 * attraverso il relativo codice.
 *
 * Parametri:
 *   presenti - numero di libri attualmente registrati.
 *   cod      - codice identificativo del libro restituito.
 */
void restituzione(int presenti, int cod);

/*
 * Visualizza il menu principale e acquisisce la scelta
 * dell'utente.
 *
 * Valore restituito:
 *   Un valore compreso tra 1 e 6 corrispondente
 *   all'operazione selezionata.
 */
int menu_di_scelta(void);

#endif /* BIBLIOTECA_H_INCLUDED */
