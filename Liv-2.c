#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Document
typedef struct Document {
    int id;
    char name[50];
    int totalLines;
    int linesLeft;
    struct Document* next;
} Document;

// Structure for Printer
typedef struct Printer {
    int id;
    int printTime;
    Document* currentDocument;
    struct Printer* next;
} Printer;

// Function to initialize a new Document
Document* createDocument(int id, const char* name, int totalLines) {
    Document* doc = (Document*)malloc(sizeof(Document));
    if (doc == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    doc->id = id;
    strncpy(doc->name, name, sizeof(doc->name));
    doc->totalLines = totalLines;
    doc->linesLeft = totalLines;
    doc->next = NULL;
    return doc;
}

// Function to initialize a new Printer
Printer* createPrinter(int id, int printTime) {
    Printer* printer = (Printer*)malloc(sizeof(Printer));
    if (printer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    printer->id = id;
    printer->printTime = printTime;
    printer->currentDocument = NULL;
    printer->next = NULL;
    return printer;
}

// Function to add a Document to the print queue
void addDocument(Document** queue, Document* doc) {
    if (*queue == NULL) {
        *queue = doc;
    } else {
        Document* current = *queue;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = doc;
    }
}

// Function to distribute queued Documents to available Printers
void distributeDocuments(Document** queue, Printer* printers) {
    Document* currentDoc = *queue;
    while (currentDoc != NULL) {
        Printer* minPrinter = NULL;
        int minTime = -1;
        Printer* currentPrinter = printers;
        while (currentPrinter != NULL) {
            if (currentPrinter->currentDocument == NULL) {
                int time = currentDoc->linesLeft * currentPrinter->printTime;
                if (minTime == -1 || time < minTime) {
                    minTime = time;
                    minPrinter = currentPrinter;
                }
            }
            currentPrinter = currentPrinter->next;
        }
        if (minPrinter != NULL) {
            minPrinter->currentDocument = currentDoc;
            currentDoc = currentDoc->next;
        } else {
            break; // No available printer
        }
    }
}

// Function to simulate the printing process
// Function to simulate the printing process
void printDocuments(Document** queue, Printer* printers) {
    Document* currentDoc = *queue;
    while (currentDoc != NULL) {
        Printer* currentPrinter = printers;
        while (currentPrinter != NULL) {
            if (currentPrinter->currentDocument == currentDoc) {
                int linesToPrint = currentDoc->linesLeft;
                if (linesToPrint > 0) {
                    int printedLines = currentPrinter->printTime;
                    if (printedLines >= linesToPrint) {
                        printf("Printer %d printed document %d completely\n", currentPrinter->id, currentDoc->id);
                        currentPrinter->currentDocument->linesLeft = 0;
                        currentPrinter->currentDocument = NULL;
                    } else {
                        currentPrinter->currentDocument->linesLeft -= printedLines;
                        printf("Printer %d is printing document %d, %d seconds remaining\n", currentPrinter->id, currentDoc->id, (currentDoc->linesLeft / currentPrinter->printTime) * currentPrinter->printTime);
                    }
                }
            }
            currentPrinter = currentPrinter->next;
        }
        currentDoc = currentDoc->next;
    }
}
 
void displayStatus(Document* queue, Printer* printers) {
    printf("Print Queue:\n");
    Document* currentDoc = queue;
    while (currentDoc != NULL) {
        printf("Document %d (%s) - %d lines left\n", currentDoc->id, currentDoc->name, currentDoc->linesLeft);
        currentDoc = currentDoc->next;
    }
    printf("\nPrinters:\n");
    Printer* currentPrinter = printers;
    while (currentPrinter != NULL) {
        printf("Printer %d - %d seconds per line\n", currentPrinter->id, currentPrinter->printTime);
        if (currentPrinter->currentDocument != NULL) {
            printf("  Printing Document %d\n", currentPrinter->currentDocument->id);
        } else {
            printf("  Idle\n");
        }
        currentPrinter = currentPrinter->next;
    }
}

void freeMemory(Document* queue, Printer* printers) {
    Document* currentDoc = queue;
    while (currentDoc != NULL) {
        Document* temp = currentDoc;
        currentDoc = currentDoc->next;
        free(temp);
    }
    Printer* currentPrinter = printers;
    while (currentPrinter != NULL) {
        Printer* temp = currentPrinter;
        currentPrinter = currentPrinter->next;
        free(temp);
    }
}

int main() {
    int numPrinters;
    printf("Enter the number of printers: ");
    scanf("%d", &numPrinters);

    Printer* printers = NULL;
    for (int i = 1; i <= numPrinters; i++) {
        int printTime;
        printf("Enter print time for printer %d (in seconds per line): ", i);
        scanf("%d", &printTime);
        if (printers == NULL) {
            printers = createPrinter(i, printTime);
        } else {
            Printer* temp = createPrinter(i, printTime);
            temp->next = printers;
            printers = temp;
        }
    }

    int numDocuments;
    printf("Enter the number of documents: ");
    scanf("%d", &numDocuments);

    Document* queue = NULL;
    for (int i = 1; i <= numDocuments; i++) {
        char name[50];
        int totalLines;
        printf("Enter name and total lines for document %d: ", i);
        scanf("%s %d", name, &totalLines);
        addDocument(&queue, createDocument(i, name, totalLines));
    }

    distributeDocuments(&queue, printers);

    printDocuments(&queue, printers);

    displayStatus(queue, printers);

    freeMemory(queue, printers);

    return 0;
}
