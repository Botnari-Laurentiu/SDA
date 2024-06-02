 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct car {
    char *name;
    int price;
    int age;
} car;


void add_elements(car list[], int size);
void print_elements(car list[], int size);
int check_car_name(car list[], int size);
int check_car_price(car list[], int size);
int check_car_age(car list[], int size);

int main() {
    int n;
    int size = 2;
    int index;

    while (true) {
        printf("faceti lista de automobile\n");
        scanf("%d", &n);
        if (n == 1) {
            car list[2];
            add_elements(list, size);
            print_elements(list, size);
            
            // Search by name
            index = check_car_name(list, size);
            if (index != -1) {
                printf("masina gasita la index %d\n", index);
            } else {
                printf("Car not found\n");
            }
            
             index = check_car_price(list, size);
            if (index != -1) {
                 printf("masina gasita la index %d\n", index);
             } else {
                 printf("Car not found\n");
             }
            
             index = check_car_age(list, size);
             if (index != -1) {
                printf("Car found at index %d\n", index);
             } else {
                 printf("Car not found\n");
            }
            
            break;
        }
    }
    return 0;
}

void add_elements(car list[], int size) {
    for (int i = 0; i < size; i++) {
        list[i].name = (char *)malloc(100 * sizeof(char));
        printf("Adauga denumirea automobilului:\n");
        scanf("%s", list[i].name);
        printf("Adauga anul automobilului:\n");
        scanf("%d", &list[i].age);
        printf("Adauga pretul automobilului:\n");
        scanf("%d", &list[i].price);
    }
}

void print_elements(car list[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\t\t%d\t\t%d$\n", list[i].name, list[i].age, list[i].price);
    }
}

int check_car_name(car list[], int size) {
    char car_name[50];
    printf("Introduceti denumirea automobilului din lista:\n");
    scanf("%s", car_name);
    for (int i = 0; i < size; i++) {
        if (strcmp(list[i].name, car_name) == 0) {
            return i;
        }
    }
    return -1;
}

int check_car_price(car list[], int size) {
    int price;
    printf("Introduceti pretul automobilului:\n");
    scanf("%d", &price);
    for (int i = 0; i < size; i++) {
        if (list[i].price == price) {
            return i;
        }
    }
    return -1;
}

int check_car_age(car list[], int size) {
    int age;
    printf("Introduceti anul automobilului:\n");
    scanf("%d", &age);
    for (int i = 0; i < size; i++) {
        if (list[i].age == age) {
            return i;
        }
    }
    return -1;
}
