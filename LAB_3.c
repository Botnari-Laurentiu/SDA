#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

typedef struct binary_tree {
    Node *root;
} Tree;

/**
 * @brief Creates a new node with the given data.
 * 
 * @param data The data to store in the node.
 * @return Node* Pointer to the newly created node.
 */
Node* create_node(int data) { 
    Node *tree_node = (Node *) calloc(1, sizeof(Node));
    tree_node->data = data;
    return tree_node;
}

/**
 * @brief Deletes a given node.
 * 
 * @param tree_node Pointer to the node to be deleted.
 */
void delete_node(Node *tree_node) {
    if (tree_node) {
        free(tree_node);
    }
}

/**
 * @brief Creates a new tree.
 * 
 * @return Tree* Pointer to the newly created tree.
 */
Tree* create_tree() {
    Tree *tree = (Tree *) calloc(1, sizeof(Tree));
    return tree;
}

/**
 * @brief Recursively deletes all nodes starting from the given node.
 * 
 * @param current Pointer to the current node to start deletion from.
 */
void delete_all_nodes_from_node(Node *current) {
    if (current) {
        delete_all_nodes_from_node(current->left);
        delete_all_nodes_from_node(current->right);
        free(current);
    }
}

/**
 * @brief Clears all nodes from the tree.
 * 
 * @param tree Pointer to the tree to clear.
 */
void clear_tree(Tree *tree) {
    if (tree && tree->root) {
        delete_all_nodes_from_node(tree->root);
        tree->root = NULL;
    }
}

/**
 * @brief Deletes the tree and frees its memory.
 * 
 * @param tree Pointer to the tree to delete.
 */
void delete_tree(Tree *tree) {
    if (tree) {
        clear_tree(tree);
        free(tree);
    }
}

/**
 * @brief Inserts a new node into the tree starting from the given current node.
 * 
 * @param current Pointer to the current node to start insertion from.
 * @param new_node Pointer to the new node to be inserted.
 */
void insert_node(Node *current, Node *new_node) {
    if (current) {
        if (current->data > new_node->data) {
            if (current->left) {
                insert_node(current->left, new_node);
            } else {
                current->left = new_node;
            }
        } else {
            if (current->right) {
                insert_node(current->right, new_node);
            } else {
                current->right = new_node;
            }
        }
    }
}

/**
 * @brief Inserts a new data element into the tree.
 * 
 * @param tree Pointer to the tree where the data will be inserted.
 * @param data The data to be inserted.
 */
void insert_data(Tree *tree, int data) {
    if (tree) {
        Node *new_node = create_node(data);
        if (tree->root) {
            insert_node(tree->root, new_node);
        } else {
            tree->root = new_node;
        }
    }
}

/**
 * @brief Prints the data stored in the given node.
 * 
 * @param node Pointer to the node whose data will be printed.
 */
void print_node(Node *node) {
    if (node) {
        printf("%d ", node->data);
    }
}

/**
 * @brief Prints the tree using a specified traversal method.
 * 
 * @param tree Pointer to the tree to be printed.
 * @param tree_traversal Pointer to the function for tree traversal.
 */
void print_tree(Tree *tree, void (*tree_traversal)(Node *, void (*node_action)(Node *))) {
    if (tree) {
        if (tree->root) {
            printf("\nElements in the tree:\n");
            tree_traversal(tree->root, print_node);
            printf("\n");
        } else {
            printf("The tree is empty.\n");
        }
    } else {
        printf("The tree is not allocated.\n");
    }
}

/**
 * @brief Performs a post-order traversal of the tree and applies a specified action to each node.
 * 
 * @param current Pointer to the current node.
 * @param node_action Pointer to the function to be applied to each node.
 */
void post_order_traversal(Node *current, void (*node_action)(Node *)) {
    if (current) {
        post_order_traversal(current->left, node_action);
        post_order_traversal(current->right, node_action);
        node_action(current);
    }
}

/**
 * @brief Performs an in-order traversal of the tree and applies a specified action to each node.
 * 
 * @param current Pointer to the current node.
 * @param node_action Pointer to the function to be applied to each node.
 */
void in_order_traversal(Node *current, void (*node_action)(Node *)) {
    if (current) {
        in_order_traversal(current->left, node_action);
        node_action(current);
        in_order_traversal(current->right, node_action);
    }
}

/**
 * @brief Performs a pre-order traversal of the tree and applies a specified action to each node.
 * 
 * @param current Pointer to the current node.
 * @param node_action Pointer to the function to be applied to each node.
 */
void pre_order_traversal(Node *current, void (*node_action)(Node *)) {
    if (current) {
        node_action(current);
        pre_order_traversal(current->left, node_action);
        pre_order_traversal(current->right, node_action);
    }
}

/**
 * @brief Helper function for depth-first search.
 * 
 * @param current Pointer to the current node.
 * @param data Data to search for.
 * @return Node* Pointer to the node with the desired data, or NULL if not found.
 */
Node *dfs_helper(Node *current, int data) {
    if (current) {
        if (current->data == data) {
            return current;
        }
        Node *left_search = dfs_helper(current->left, data);
        return left_search ? left_search : dfs_helper(current->right, data);
    }
    return NULL;
}

/**
 * @brief Searches for a node in the tree using depth-first search.
 * 
 * @param tree Pointer to the tree to search in.
 * @param data Data to search for.
 * @return Node* Pointer to the node with the desired data, or NULL if not found.
 */
Node *dfs(Tree *tree, int data) {
    if (tree && tree->root) {
        return dfs_helper(tree->root, data);
    }
    return NULL;
}

/**
 * @brief Calculates the depth of the tree.
 * 
 * @param current Pointer to the current node.
 * @return The depth of the tree from the given node.
 */
int calculate_depth(Node *current) {
    if (!current) {
        return -1; // If the node is NULL, return -1
    }
    int left_depth = calculate_depth(current->left);
    int right_depth = calculate_depth(current->right);
    return (left_depth > right_depth ? left_depth : right_depth) + 1;
}

/**
 * @brief Calculates the depth of a given node.
 * 
 * @param root Pointer to the root node.
 * @param target Pointer to the target node.
 * @param depth Current depth of the search.
 * @return The depth of the target node.
 */
int calculate_node_depth(Node *root, Node *target, int depth) {
    if (!root) {
        return -1;
    }
    if (root == target) {
        return depth;
    }
    int left_depth = calculate_node_depth(root->left, target, depth + 1);
    if (left_depth != -1) {
        return left_depth;
    }
    return calculate_node_depth(root->right, target, depth + 1);
}

/**
 * @brief Calculates the height of a given node.
 * 
 * @param node Pointer to the node.
 * @return The height of the node.
 */
int calculate_node_height(Node *node) {
    if (!node) {
        return -1;
    }
    int left_height = calculate_node_height(node->left);
    int right_height = calculate_node_height(node->right);
    return (left_height > right_height ? left_height : right_height) + 1;
}

/**
 * @brief Prints all leaves in the tree.
 * 
 * @param current Pointer to the current node.
 */
void print_leaves(Node *current) {
    if (current) {
        if (!current->left && !current->right) {
            printf("%d ", current->data);
        } else {
            print_leaves(current->left);
            print_leaves(current->right);
        }
    }
}

/**
 * @brief Reads a number of random elements from the user and inserts them into the tree.
 * 
 * @param tree Pointer to the tree to insert the elements into.
 */
void read_tree_from_input(Tree *tree) {
    int num_elements;
    printf("\nEnter the number of random elements to be inserted into the tree: ");
    scanf("%d", &num_elements);

    for (int i = 0; i < num_elements; i++) {
        int data = rand() % 10000;  // Generate a random value between 0 and 99
        printf("Inserting random element %d: %d\n", i + 1, data);
        insert_data(tree, data);
    }
}

/**
 * @brief Enum representing menu options.
 */
typedef enum {
    OPTION_READ_ELEMENTS = 1,
    OPTION_DISPLAY_TREE = 2,
    OPTION_CALCULATE_TREE_DEPTH = 3,
    OPTION_SEARCH_NODE = 4,
    OPTION_CALCULATE_NODE_DEPTH = 5,
    OPTION_CALCULATE_NODE_HEIGHT = 6,
    OPTION_DISPLAY_LEAVES = 7,
    OPTION_CLEAR_TREE = 8,
    OPTION_EXIT = 9
} MenuOption;

/**
 * @brief Interactive menu function to interact with the binary tree.
 */
void menu() {
    Tree *tree = create_tree();
    int choice = 0;

    do {
        printf("\n--- Menu ---\n"
           "1. Read elements into the tree\n"
           "2. Display elements in the tree (In-order)\n"
           "3. Calculate the depth of the tree\n"
           "4. Search for a node in the tree\n"
           "5. Calculate the depth of a node\n"
           "6. Calculate the height of a node\n"
           "7. Display all leaves of the tree\n"
           "8. Clear the tree elements\n"
           "9. Free the memory of the tree and exit\n"
           "Enter your choice: ");
        scanf("%d", &choice);

        MenuOption option = (MenuOption) choice;

        switch (option) {
            case OPTION_READ_ELEMENTS:
                read_tree_from_input(tree);
                break;

            case OPTION_DISPLAY_TREE:
                print_tree(tree, in_order_traversal);
                break;

            case OPTION_CALCULATE_TREE_DEPTH:
                printf("\nThe depth of the tree is: %d\n", calculate_depth(tree->root));
                break;

            case OPTION_SEARCH_NODE: {
                int search_data;
                printf("\nEnter the search key: ");
                scanf("%d", &search_data);
                Node *found_node = dfs(tree, search_data);
                if (found_node) {
                    printf("\nThe node with key %d was found.\n", search_data);
                } else {
                    printf("\nThe node with key %d was not found.\n", search_data);
                }
                break;
            }

            case OPTION_CALCULATE_NODE_DEPTH: {
                int search_data;
                printf("\nEnter the key to calculate depth: ");
                scanf("%d", &search_data);
                Node *target_node = dfs(tree, search_data);
                if (target_node) {
                    int node_depth = calculate_node_depth(tree->root, target_node, 0);
                    printf("\nThe depth of the node with key %d is: %d\n", search_data, node_depth);
                } else {
                    printf("\nThe node with key %d was not found.\n", search_data);
                }
                break;
            }

            case OPTION_CALCULATE_NODE_HEIGHT: {
                int search_data;
                printf("\nEnter the key to calculate height: ");
                scanf("%d", &search_data);
                Node *target_node = dfs(tree, search_data);
                if (target_node) {
                    int node_height = calculate_node_height(target_node);
                    printf("\nThe height of the node with key %d is: %d\n", search_data, node_height);
                } else {
                    printf("\nThe node with key %d was not found.\n", search_data);
                }
                break;
            }

            case OPTION_DISPLAY_LEAVES:
                printf("\nLeaves of the tree are: ");
                print_leaves(tree->root);
                printf("\n");
                break;

            case OPTION_CLEAR_TREE:
                clear_tree(tree);
                printf("\nThe tree has been cleared.\n");
                break;

            case OPTION_EXIT:
                delete_tree(tree);
                printf("\nThe memory of the tree has been freed. Exiting...\n");
                break;

            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    } while (choice != OPTION_EXIT);
}

/**
 * @brief The main function of the program.
 * 
 * @return int 0 if the program executes successfully.
 */
int main() {
    srand(time(NULL));
    menu();
    return 0;
}
