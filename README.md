Biblioteca C

Applicazione console sviluppata in linguaggio C per la gestione di un piccolo archivio bibliotecario.

Il progetto nasce come progetto di programmazione procedurale ed è stato successivamente restaurato, riorganizzato e migliorato mantenendo la logica originale dell'applicazione.

L'obiettivo è gestire in modo semplice le principali operazioni relative ai libri: inserimento, consultazione, prestito e restituzione.

---

Funzionalità

L'applicazione permette di:

- visualizzare il catalogo dei libri;
- inserire nuovi libri nell'archivio;
- generare automaticamente un codice identificativo per ogni libro;
- ricercare un libro tramite titolo;
- ricercare un libro tramite codice;
- registrare il prestito di un libro;
- registrare la restituzione di un libro;
- visualizzare lo stato di disponibilità dei libri;
- gestire gli errori durante l'inserimento dei dati;
- limitare il numero massimo di libri gestibili.

Ogni libro contiene:

- codice identificativo;
- titolo;
- autore;
- prezzo;
- stato di disponibilità.

---

Struttura del progetto

Biblioteca-C/
<pre>
├── biblioteca.h
├── biblioteca.c
├── main.c
└── README.md
</pre>

"main.c"

Contiene il punto di ingresso dell'applicazione e gestisce il menu principale.

Il "main" coordina le operazioni richieste dall'utente delegando le singole funzionalità alle funzioni definite nel modulo della biblioteca.

"biblioteca.h"

Contiene le dichiarazioni delle funzioni utilizzate dal programma e le costanti principali del progetto.

"biblioteca.c"

Contiene l'implementazione della logica applicativa:

- gestione dell'archivio;
- inserimento dei libri;
- generazione dei codici;
- ricerca;
- prestito;
- restituzione;
- visualizzazione del catalogo;
- gestione dell'input.

---

Tecnologie e concetti utilizzati

- C
- Programmazione procedurale
- "struct" e tipi definiti dall'utente
- Array
- Funzioni
- Puntatori
- Stringhe
- Cicli e strutture condizionali
- "switch"
- Gestione dell'input da console
- Generazione di numeri pseudo-casuali
- Organizzazione del codice tramite file ".c" e ".h"
- Controllo degli errori di input

---

Gestione dei dati

I libri vengono memorizzati durante l'esecuzione del programma all'interno di un array di strutture.

La capacità massima dell'archivio è di 80 libri.

Lo stato di ogni libro viene rappresentato attraverso un valore booleano:

1 → disponibile
0 → in prestito

Il codice identificativo viene generato automaticamente durante l'inserimento e viene verificato per evitare duplicati tra i libri già presenti nell'archivio.

---

Gestione dell'input

Rispetto alla versione originale del progetto, il codice è stato rivisto per rendere l'interazione con l'utente più sicura e prevedibile.

In particolare:

- è stata eliminata la funzione "gets()";
- viene utilizzata "fgets()" per la lettura delle stringhe;
- viene gestito il buffer di input dopo l'utilizzo di "scanf()";
- vengono controllate alcune condizioni di input non valide;
- vengono gestiti i valori numerici errati;
- vengono impediti titoli e autori vuoti;
- viene impedito l'inserimento di prezzi negativi.

---

Compilazione

Il progetto può essere compilato utilizzando GCC.

Da terminale, posizionarsi nella cartella del progetto ed eseguire:

gcc main.c biblioteca.c -o biblioteca

Su Windows, se si utilizza MinGW/GCC:

gcc main.c biblioteca.c -o biblioteca.exe

Per eseguire il programma:

Linux / macOS

./biblioteca

Windows

biblioteca.exe

---

Esempio di utilizzo

All'avvio viene mostrato il menu principale:

========================================
       GESTIONALE BIBLIOTECA
========================================

1 - Visualizza libri
2 - Inserisci libro
3 - Richiedi libro tramite titolo
4 - Richiedi libro tramite codice
5 - Restituisci libro
6 - Esci

Scelta:

L'utente può quindi scegliere l'operazione da eseguire.

Durante l'inserimento, ad esempio:

========== INSERIMENTO LIBRO ==========

Titolo: Il nome della rosa
Autore: Umberto Eco
Prezzo: 15.50

Libro inserito correttamente.
Codice assegnato: 4821

Il libro viene inizialmente registrato come disponibile.

---

Obiettivo del progetto

Il progetto rappresenta un progetto pratico sui principali concetti della programmazione procedurale in C e sulla gestione di dati strutturati attraverso array e "struct".

La versione presente nel repository è il risultato di un lavoro di revisione e manutenzione del progetto originale, con particolare attenzione a:

- organizzazione del codice;
- separazione tra interfaccia e implementazione;
- gestione dell'input;
- controllo degli errori;
- leggibilità;
- documentazione delle funzioni;
- mantenimento della logica originale.

---

Stato del progetto

Completato e funzionante.

Il progetto è stato mantenuto volutamente in C procedurale, senza introdurre una struttura a oggetti o convertirlo in C++.

Possibili evoluzioni future potrebbero includere la persistenza dei dati tramite file, una gestione più avanzata degli utenti e dei prestiti oppure una versione con database.

---

Autore

Mattia Castiello

Progetto realizzato come progetto pratico di programmazione in C e successivamente sottoposto a revisione e refactoring.