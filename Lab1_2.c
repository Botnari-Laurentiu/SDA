#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int year;
    char* model;
    int price;
} Element;

Element* array = NULL;
int size = 0;

void citesteElemente() {
    printf("Introduceti numarul de elemente: ");
    scanf("%d", &size);
    array = (Element*)malloc(size * sizeof(Element));
    printf("Introduceti elementele:\n");
    for (int i = 0; i < size; ++i) {
        printf("Element %d:\n", i + 1);
        printf("Anul: ");
        scanf("%d", &array[i].year);
        printf("Modelul: ");
        char temp[100];
        scanf("%s", temp);
        array[i].model = (char*)malloc((strlen(temp) + 1) * sizeof(char));
        strcpy(array[i].model, temp);
        printf("Pretul: ");
        scanf("%d", &array[i].price);
    }
}

void afiseazaElemente() {
    printf("Elementele tabloului sunt:\n");
    for (int i = 0; i < size; ++i) {
        printf("Element %d:\n", i + 1);
        printf("Anul: %d\n", array[i].year);
        printf("Modelul: %s\n", array[i].model);
        printf("Pretul: %d\n", array[i].price);
    }
}

int cautaElement(int year) {
    for (int i = 0; i < size; ++i) {
        if (array[i].year == year) {
            return i;
        }
    }
    return -1;
}

void elibereazaMemorie() {
    for (int i = 0; i < size; ++i) {
        free(array[i].model); // Free memory allocated for model strings
    }
    free(array);
    size = 0;
}

void swap(Element* a, Element* b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Element arr[], int low, int high) {
    int pivot = arr[high].year;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].year < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(Element arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void sorteazaElemente() {
    quickSort(array, 0, size - 1);
    printf("Elementele sortate.\n");
}

void insereazaLaCapat(Element element) {
    array = (Element*)realloc(array, (size + 1) * sizeof(Element));
    array[size] = element;
    size++;
}

void insereazaLaInceput(Element element) {
    array = (Element*)realloc(array, (size + 1) * sizeof(Element));
    for (int i = size; i > 0; --i) {
        array[i] = array[i - 1];
    }
    array[0] = element;
    size++;
}

void insereazaLaPozitie(Element element, int pozitie) {
    array = (Element*)realloc(array, (size + 1) * sizeof(Element));
    for (int i = size; i > pozitie; --i) {
        array[i] = array[i - 1];
    }
    array[pozitie] = element;
    size++;
}

void stergeDeLaPozitie(int pozitie) {
    for (int i = pozitie; i < size - 1; ++i) {
        array[i] = array[i + 1];
    }
    array = (Element*)realloc(array, (size - 1) * sizeof(Element));
    size--;
}

int main() {
    int optiune;
    Element element;
    int pozitie;

    do {
        printf("\nAlegeti o optiune:\n");
        printf("1. Citeste elemente\n");
        printf("2. Afiseaza elemente\n");
        printf("3. Cauta un element\n");
        printf("4. Elibereaza memorie\n");
        printf("5. Sorteaza elemente\n");
        printf("6. Insereaza la capat\n");
        printf("7. Insereaza la inceput\n");
        printf("8. Insereaza la o pozitie\n");
        printf("9. Sterge de la o pozitie\n");
        printf("0. Iesire\n");

        printf("Optiune: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1:
                citesteElemente();
                break;
            case 2:
                afiseazaElemente();
                break;
            case 3:
                printf("Introduceti anul cautat: ");
                scanf("%d", &element.year);
                pozitie = cautaElement(element.year);
                if (pozitie != -1) {
                    printf("Elementul cu anul %d se afla pe pozitia %d.\n", element.year, pozitie);
                } else {
                    printf("Elementul cu anul %d nu a fost gasit.\n", element.year);
                }
                break;
            case 4:
                elibereazaMemorie();
                printf("Memoria eliberata.\n");
                break;
            case 5:
                sorteazaElemente();
                printf("Elementele sortate.\n");
                break;
            case 6:
                printf("Introduceti elementul de adaugat:\n");
                printf("Anul: ");
                scanf("%d", &element.year);
                printf("Modelul: ");
                char temp[100];
                scanf("%s", temp);
                element.model = (char*)malloc((strlen(temp) + 1) * sizeof(char));
                strcpy(element.model, temp);
                printf("Pretul: ");
                scanf("%d", &element.price);
                insereazaLaCapat(element);
                printf("Element adaugat la capat.\n");
                break;
            case 7:
                printf("Introduceti elementul de adaugat:\n");
                printf("Anul: ");
                scanf("%d", &element.year);
                printf("Modelul: ");
                char temp2[100];
                scanf("%s", temp2);
                element.model = (char*)malloc((strlen(temp2) + 1) * sizeof(char));
                strcpy(element.model, temp2);
                printf("Pretul: ");
                scanf("%d", &element.price);
                insereazaLaInceput(element);
                printf("Element adaugat la inceput.\n");
                break;
            case 8:
                printf("Introduceti elementul de adaugat:\n");
                printf("Anul: ");
                scanf("%d", &element.year);
                printf("Modelul: ");
                char temp3[100];
                scanf("%s", temp3);
                element.model = (char*)malloc((strlen(temp3) + 1) * sizeof(char));
                strcpy(element.model, temp3);
                printf("Pretul: ");
                scanf("%d", &element.price);
                printf("Introduceti pozitia: ");
                scanf("%d", &pozitie);
                insereazaLaPozitie(element, pozitie);
                printf("Elementadaugat la pozitia specificata.\n");
                break;
            case 9:
                printf("Introduceti pozitia de sters: ");
                scanf("%d", &pozitie);
                stergeDeLaPozitie(pozitie);
                printf("Element sters de la pozitia specificata.\n");
                break;
            case 0:
                printf("Programul se inchide.\n");
                break;
                default:
                printf("Optiune invalida!\n");
            }
    } 
        while (optiune != 0);

    return 0;
}