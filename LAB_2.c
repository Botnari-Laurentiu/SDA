/**
 * @file LAB_2.c
 * @brief A program to manage student records using linked list.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_ADDRESS_LENGTH 50
#define MAX_MAJOR_LENGTH 30

/**
 * @struct Student
 * @brief Structure representing a student.
 */
typedef struct Student {
    char *name; /**< Name of the student */
    int age; /**< Age of the student */
    float gpa; /**< GPA of the student */
    int id; /**< ID of the student */
    char *major; /**< Major of the student */
    char *address; /**< Address of the student */
} Student;

/**
 * @struct ListNode
 * @brief Structure representing a node in a linked list.
 */
typedef struct ListNode {
    Student data; /**< Data of the node */
    struct ListNode *next; /**< Pointer to the next node */
} ListNode;

/**
 * @struct LinkedList
 * @brief Structure representing a linked list of students.
 */
typedef struct LinkedList {
    ListNode *head; /**< Pointer to the head of the list */
    int size; /**< Size of the list */
} LinkedList;

/**
 * @brief Prints the menu options.
 */
void print_menu();

/**
 * @brief Generates a random string.
 * @param max_length The maximum length of the string.
 * @return Pointer to the generated string.
 */
char *generate_random_string(int max_length);

/**
 * @brief Inputs data for a student.
 * @param student Pointer to the student structure.
 */
void input_student_data(Student *student);

/**
 * @brief Reads student records from the user.
 * @param n Number of students to read.
 * @return Pointer to the linked list of students.
 */
LinkedList *read_students(int n);

/**
 * @brief Displays the student records.
 * @param list Pointer to the linked list of students.
 */
void display_students(LinkedList *list);

/**
 * @brief Searches for a student by ID.
 * @param list Pointer to the linked list of students.
 * @param id ID of the student to search for.
 * @return Position of the student in the list, or -1 if not found.
 */
int search_student(LinkedList *list, int id);

/**
 * @brief Releases memory allocated for the linked list.
 * @param list Pointer to the linked list of students.
 */
void release_memory(LinkedList *list);

/**
 * @brief Sorts the student records by ID.
 * @param list Pointer to the linked list of students.
 */
void sort_students(LinkedList *list);

/**
 * @brief Swaps two nodes in the linked list.
 * @param a Pointer to the first node.
 * @param b Pointer to the second node.
 */
void swap_nodes(ListNode *a, ListNode *b);

/**
 * @brief Inserts a new student record at the end of the list.
 * @param list Pointer to the linked list of students.
 */
void insert_end(LinkedList *list);

/**
 * @brief Inserts a new student record at the beginning of the list.
 * @param list Pointer to the linked list of students.
 */
void insert_beginning(LinkedList *list);

/**
 * @brief Inserts a new student record at a specified position in the list.
 * @param list Pointer to the linked list of students.
 */
void insert_position(LinkedList *list);

/**
 * @brief Deletes a student record from a specified position in the list.
 * @param list Pointer to the linked list of students.
 * @param position Position of the student to delete.
 */
void delete_position(LinkedList *list, int position);

/**
 * @brief Reverses the linked list.
 * @param list Pointer to the linked list of students.
 */
void reverse_list(LinkedList *list);

/**
 * @brief Enumerates the menu options.
 */
enum MenuOption {
    READ_STUDENTS = 1, /**< Read students option */
    DISPLAY_STUDENTS, /**< Display students option */
    SEARCH_STUDENT, /**< Search student option */
    RELEASE_MEMORY, /**< Release memory option */
    SORT_STUDENTS, /**< Sort students option */
    INSERT_END, /**< Insert at end option */
    INSERT_BEGINNING, /**< Insert at beginning option */
    INSERT_POSITION, /**< Insert at position option */
    DELETE_POSITION, /**< Delete from position option */
    REVERSE_LIST, /**< Reverse list option */
    CLEAN_LIST, /**< Clean list option */
    EXIT_PROGRAM = 0, /**< Exit program option */
};

/**
 * @brief The main function.
 * @return Exit status.
 */
int main() {
    LinkedList *head = (LinkedList *)malloc(sizeof(LinkedList));
    if (head == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    head->head = NULL;
    head->size = 0;

    int choice;
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf(" %d", &choice);
        switch (choice) {
            case READ_STUDENTS: {
                int n;
                printf("Enter the number of students to read: ");
                scanf("%d", &n);
                head = read_students(n);
                break;
            }
            case DISPLAY_STUDENTS:
                display_students(head);
                break;
            case SEARCH_STUDENT: {
                int id;
                printf("Enter ID to search: ");
                scanf("%d", &id);
                int pos = search_student(head, id);
                if (pos != -1)
                    printf("Student found at position %d.\n", pos);
                else
                    printf("Student not found.\n");
                break;
            }
            case RELEASE_MEMORY:
                release_memory(head);
                printf("Memory released.\n");
                break;
            case SORT_STUDENTS:
                sort_students(head);
                printf("Students sorted.\n");
                break;
            case INSERT_END:
                insert_end(head);
                printf("New student inserted at the end.\n");
                break;
            case INSERT_BEGINNING:
                insert_beginning(head);
                printf("New student inserted at the beginning.\n");
                break;
            case INSERT_POSITION:
                insert_position(head);
                printf("New student inserted at the specified position.\n");
                break;
            case DELETE_POSITION: {
                int pos;
                printf("Enter the position of student to delete: ");
                scanf("%d", &pos);
                delete_position(head, pos - 1);
                printf("Student deleted from the specified position.\n");
                break;
            }
            case REVERSE_LIST:
                reverse_list(head);
                printf("List reversed.\n");
                break;
            case CLEAN_LIST:
                release_memory(head);
                printf("List cleaned.\n");
                break;
            case EXIT_PROGRAM:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != EXIT_PROGRAM);

    release_memory(head);

    return 0;
}

/**
 * @brief Prints the menu options to the console.
 * 
 * This function prints a menu displaying various options for interacting with the student records.
 * Each option is represented by a letter or number, along with a corresponding action.
 * 
 * Options:
 * - '1': Read students - Read student records from the user.
 * - '2': Display students - Display the student records currently stored in the linked list.
 * - '3': Search student - Search for a student by their ID.
 * - '4': Release memory - Release the memory allocated for the linked list and its nodes.
 * - '5': Sort students - Sort the student records by their ID in ascending order.
 * - '6': Insert student at end - Insert a new student record at the end of the linked list.
 * - '7': Insert student at beginning - Insert a new student record at the beginning of the linked list.
 * - '8': Insert student at position - Insert a new student record at a specified position in the linked list.
 * - '9': Delete student from position - Delete a student record from a specified position in the linked list.
 * - '10': Reverse list - Reverse the order of student records in the linked list.
 * - '11': Clean list - Clean the linked list by releasing memory without deleting the nodes.
 * - '0': Exit - Exit the program.
 */
void print_menu() {
    printf("\n--- Menu ---\n"
           "a. Read students\n"
           "b. Display students\n"
           "c. Search student\n"
           "d. Release memory\n"
           "e. Sort students\n"
           "f. Insert student at end\n"
           "g. Insert student at beginning\n"
           "h. Insert student at position\n"
           "i. Delete student from position\n"
           "j. Reverse list\n"
           "k. Clean list\n"
           "0. Exit\n");
}

char *generate_random_string(int max_length) {
    char *random_string = (char *)malloc((max_length + 1) * sizeof(char));
    if (random_string == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < max_length; ++i) {
        random_string[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    random_string[max_length] = '\0';
    return random_string;
}
/**
 * @brief Inputs data for a student.
 * 
 * This function initializes the fields of a Student structure with random data.
 * The name, age, GPA, ID, major, and address fields are filled with random values.
 * 
 * @param student Pointer to the Student structure to be initialized.
 */
void input_student_data(Student *student) {

    student->name = generate_random_string(MAX_NAME_LENGTH);

    student->age = 18 + rand() % 8;

    student->gpa = 2.0 + (float)(rand() % 20) / 10.0;

    student->id = 1000 + rand() % 9000;

    student->major = generate_random_string(MAX_MAJOR_LENGTH);

    student->address = generate_random_string(MAX_ADDRESS_LENGTH);
}
/**
 * @brief Reads student records from the user and creates a linked list.
 * 
 * This function prompts the user to input data for a specified number of students.
 * It creates a linked list of student records based on the input data and returns a pointer to the list.
 * 
 * @param n The number of students to read.
 * @return A pointer to the LinkedList structure containing the student records, or NULL if memory allocation fails.
 * @note The caller is responsible for releasing the memory allocated for the linked list.
 */
LinkedList *read_students(int n) {
    int i;
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if (list == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    list->head = NULL;
    list->size = 0;
    for (i = 0; i < n; i++) {
        ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
        if (temp == NULL) {
            printf("Memory allocation failed\n");
            release_memory(list);
            return NULL;
        }
        input_student_data(&(temp->data));
        temp->next = NULL;

        if (list->head == NULL) {
            list->head = temp;
        } else {
            ListNode *current = list->head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = temp;
        }
        list->size++;
    }
    return list;
}
/**
 * @brief Displays the student records stored in a linked list.
 * 
 * This function prints the details of each student record stored in the given linked list.
 * It prints the name, age, GPA, ID, major, and address of each student.
 * 
 * @param list Pointer to the LinkedList structure containing the student records.
 */
void display_students(LinkedList *list) {
    ListNode *temp = list->head;
    while (temp != NULL) {
        printf("Name: %s\n", temp->data.name);
        printf("Age: %d\n", temp->data.age);
        printf("GPA: %.2f\n", temp->data.gpa);
        printf("ID: %d\n", temp->data.id);
        printf("Major: %s\n", temp->data.major);
        printf("Address: %s\n", temp->data.address);
        printf("\n");
        temp = temp->next;
    }
}
/**
 * @brief Searches for a student by their ID in a linked list.
 * 
 * This function searches for a student with the specified ID in the given linked list.
 * If the student is found, it returns the position of the student in the list.
 * If the student is not found, it returns -1.
 * 
 * @param list Pointer to the LinkedList structure containing the student records.
 * @param id The ID of the student to search for.
 * @return The position of the student in the list if found, otherwise -1.
 */

int search_student(LinkedList *list, int id) {
    ListNode *temp = list->head;
    int pos = 0;
    while (temp != NULL) {
        if (temp->data.id == id)
            return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

/**
 * @brief Releases memory allocated for the linked list.
 * 
 * This function traverses the linked list and releases the memory allocated for
 * each node and its associated student data. The memory for the list structure
 * itself is also released.
 * 
 * @param list A pointer to the linked list of students.
 */
void release_memory(LinkedList *list) {
    if (list == NULL)
        return;
    ListNode *curr = list->head;
    ListNode *next;
    while (curr != NULL) {
        next = curr->next;
        free(curr->data.name);
        free(curr->data.major);
        free(curr->data.address);
        free(curr);
        curr = next;
    }
    list->head = NULL;
    list->size = 0;
    free(list);
}

/**
 * @brief Sorts the student records by ID.
 * 
 * This function sorts the student records in the linked list by their ID in
 * ascending order using the bubble sort algorithm. It repeatedly swaps adjacent
 * nodes if they are in the wrong order until the list is sorted.
 * 
 * @param list A pointer to the linked list of students.
 */
void sort_students(LinkedList *list) {
    if (list->head == NULL || list->head->next == NULL) {
        return;
    }

    int swapped;
    ListNode *ptr1;
    ListNode *lptr = NULL;
    do {
        swapped = 0;
        ptr1 = list->head;
        while (ptr1->next != lptr) {
            if (ptr1->data.id > ptr1->next->data.id) {
                swap_nodes(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

/**
 * @brief Swaps two nodes in the linked list.
 * 
 * This function swaps the data between two nodes in the linked list. It is used
 * as a helper function for the sort_students() function.
 * 
 * @param a A pointer to the first node.
 * @param b A pointer to the second node.
 */
void swap_nodes(ListNode *a, ListNode *b) {
    Student temp = a->data;
    a->data = b->data;
    b->data = temp;
}

/**
 * @brief Inserts a new student record at the end of the list.
 * 
 * This function creates a new node with student data and inserts it at the end
 * of the linked list.
 * 
 * @param list A pointer to the linked list of students.
 */
void insert_end(LinkedList *list) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("\nEnter data for the new student:\n");
    input_student_data(&(newNode->data));

    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->size = 1;
        return;
    }

    ListNode *temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    list->size++;
}

/**
 * @brief Inserts a new student record at the beginning of the list.
 * 
 * This function creates a new node with student data and inserts it at the
 * beginning of the linked list.
 * 
 * @param list A pointer to the linked list of students.
 */
void insert_beginning(LinkedList *list) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("\nEnter data for the new student:\n");
    input_student_data(&(newNode->data));

    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

/**
 * @brief Inserts a new student record at a specified position in the list.
 * 
 * This function creates a new node with student data and inserts it at a
 * specified position in the linked list. If the position is greater than the
 * size of the list, the new node is inserted at the end.
 * 
 * @param list A pointer to the linked list of students.
 */
void insert_position(LinkedList *list) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    input_student_data(&(newNode->data));
    int position;
    printf("Enter the position to insert: ");
    scanf("%d", &position);

    if (position < 0 || position > list->size) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    if (position == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        ListNode *current = list->head;
        int currentPosition = 0;
        while (currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    list->size++;
}

/**
 * @brief Deletes a student record from a specified position in the list.
 * 
 * This function removes the student record at a specified position in the
 * linked list and releases the memory allocated for the node and its associated
 * data. If the position is out of bounds, no deletion occurs.
 * 
 * @param list A pointer to the linked list of students.
 * @param position The position of the student to delete.
 */
void delete_position(LinkedList *list, int position) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 0) {
        ListNode *temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
        return;
    }
    ListNode *prev = NULL;
    ListNode *current = list->head;
    int count = 0;
    while (current != NULL && count != position) {
        prev = current;
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Position is out of range\n");
        return;
    }
    prev->next = current->next;
    free(current);
    list->size--;
}

/**
 * @brief Reverses the order of student records in the list.
 * 
 * This function reverses the order of student records in the linked list by
 * reversing the direction of the next pointers of the nodes.
 * 
 * @param list A pointer to the linked list of students.
 */
void reverse_list(LinkedList *list) {
    ListNode *prev = NULL;
    ListNode *current = list->head;
    ListNode *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
}