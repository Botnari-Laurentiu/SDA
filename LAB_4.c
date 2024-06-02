#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/**
 * @brief Structure to store node data.
 */
typedef struct NodeData {
    int data1;
    char data2;
    float data3;
} NodeData;

/**
 * @brief Structure for a binary tree node.
 */
typedef struct BinaryTreeNode {
    int key;
    NodeData data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
} BinaryTreeNode;

/**
 * @brief Structure for a binary tree.
 */
typedef struct BinaryTree {
    BinaryTreeNode* root;
} BinaryTree;

/**
 * @brief Structure for a queue node.
 */
typedef struct QueueNode {
    BinaryTreeNode* data;
    struct QueueNode* next;
} QueueNode;

/**
 * @brief Structure for a queue.
 */
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

/**
 * @brief Creates a new binary tree node.
 * 
 * @param key The key of the node.
 * @param data The data of the node.
 * @return BinaryTreeNode* A pointer to the new node.
 */
BinaryTreeNode* create_node(int key, NodeData data);

/**
 * @brief Inserts a node into the binary tree.
 * 
 * @param tree A pointer to the binary tree.
 * @param key The key of the node to be inserted.
 * @param data The data of the node to be inserted.
 */
void insert(BinaryTree* tree, int key, NodeData data);

/**
 * @brief Searches for a node in the binary tree.
 * 
 * @param tree A pointer to the binary tree.
 * @param key The key of the node to be searched.
 * @return BinaryTreeNode* A pointer to the found node, or NULL if not found.
 */
BinaryTreeNode* search(BinaryTree* tree, int key);

/**
 * @brief Displays the binary tree in inorder traversal.
 * 
 * @param tree A pointer to the binary tree.
 */
void display_inorder(BinaryTree* tree);

/**
 * @brief Helper function for inorder traversal.
 * 
 * @param root A pointer to the root of the binary tree.
 */
void display_inorder_rec(BinaryTreeNode* root);

/**
 * @brief Displays the binary tree in preorder traversal.
 * 
 * @param tree A pointer to the binary tree.
 */
void display_preorder(BinaryTree* tree);

/**
 * @brief Helper function for preorder traversal.
 * 
 * @param root A pointer to the root of the binary tree.
 */
void display_preorder_rec(BinaryTreeNode* root);

/**
 * @brief Displays the binary tree in postorder traversal.
 * 
 * @param tree A pointer to the binary tree.
 */
void display_postorder(BinaryTree* tree);

/**
 * @brief Helper function for postorder traversal.
 * 
 * @param root A pointer to the root of the binary tree.
 */
void display_postorder_rec(BinaryTreeNode* root);

/**
 * @brief Displays the binary tree using DFS (preorder traversal).
 * 
 * @param tree A pointer to the binary tree.
 */
void display_dfs(BinaryTree* tree);

/**
 * @brief Displays the binary tree using BFS.
 * 
 * @param tree A pointer to the binary tree.
 */
void display_bfs(BinaryTree* tree);

/**
 * @brief Finds the node with the minimum key in the binary tree.
 * 
 * @param tree A pointer to the binary tree.
 * @return BinaryTreeNode* A pointer to the node with the minimum key.
 */
BinaryTreeNode* find_min(BinaryTree* tree);

/**
 * @brief Deletes a node from the binary tree.
 * 
 * @param tree A pointer to the binary tree.
 * @param key The key of the node to be deleted.
 */
void delete_node(BinaryTree* tree, int key);

/**
 * @brief Helper function to delete a node from the binary tree.
 * 
 * @param root A pointer to the root of the binary tree.
 * @param key The key of the node to be deleted.
 * @return BinaryTreeNode* A pointer to the root of the modified binary tree.
 */
BinaryTreeNode* delete_node_rec(BinaryTreeNode* root, int key);

/**
 * @brief Frees all nodes in the binary tree.
 * 
 * @param tree A pointer to the binary tree.
 */
void free_tree(BinaryTree* tree);

/**
 * @brief Helper function to free all nodes in the binary tree.
 * 
 * @param root A pointer to the root of the binary tree.
 */
void free_tree_rec(BinaryTreeNode* root);

/**
 * @brief Creates a mirrored copy of the binary tree.
 * 
 * @param tree A pointer to the original binary tree.
 * @return BinaryTree* A pointer to the mirrored binary tree.
 */
BinaryTree* mirror(BinaryTree* tree);

/**
 * @brief Helper function to create a mirrored copy of the binary tree.
 * 
 * @param root A pointer to the root of the binary tree.
 * @return BinaryTreeNode* A pointer to the root of the mirrored binary tree.
 */
BinaryTreeNode* mirror_rec(BinaryTreeNode* root);

/**
 * @brief Gets the height of the binary tree.
 * 
 * @param tree A pointer to the binary tree.
 * @return int The height of the binary tree.
 */
int get_height(BinaryTree* tree);

/**
 * @brief Helper function to get the height of the binary tree.
 * 
 * @param root A pointer to the root of the binary tree.
 * @return int The height of the binary tree.
 */
int get_height_rec(BinaryTreeNode* root);

/**
 * @brief Stores the inorder traversal of the binary tree in an array.
 * 
 * @param root A pointer to the root of the binary tree.
 * @param arr An array to store the inorder traversal.
 * @param index A pointer to the current index in the array.
 */
void store_inorder(BinaryTreeNode* root, int* arr, int* index);

/**
 * @brief Builds a balanced BST from a sorted array.
 * 
 * @param arr An array containing the sorted elements.
 * @param start The starting index of the array.
 * @param end The ending index of the array.
 * @return BinaryTreeNode* A pointer to the root of the balanced BST.
 */
BinaryTreeNode* build_balanced_bst(int* arr, int start, int end);

/**
 * @brief Balances the binary tree.
 * 
 * @param tree A pointer to the original binary tree.
 * @return BinaryTree* A pointer to the balanced binary tree.
 */
BinaryTree* balance_bst(BinaryTree* tree);

/**
 * @brief Creates a new queue node.
 * 
 * @param data A pointer to the binary tree node to be stored in the queue node.
 * @return QueueNode* A pointer to the new queue node.
 */
QueueNode* create_queue_node(BinaryTreeNode* data);

/**
 * @brief Creates a new queue.
 * 
 * @return Queue* A pointer to the new queue.
 */
Queue* create_queue();

/**
 * @brief Checks if the queue is empty.
 * 
 * @param queue A pointer to the queue.
 * @return int 1 if the queue is empty, 0 otherwise.
 */
int is_empty(Queue* queue);

/**
 * @brief Enqueues a binary tree node into the queue.
 * 
 * @param queue A pointer to the queue.
 * @param data A pointer to the binary tree node to be enqueued.
 */
void enqueue(Queue* queue, BinaryTreeNode* data);

/**
 * @brief Dequeues a binary tree node from the queue.
 * 
 * @param queue A pointer to the queue.
 * @return BinaryTreeNode* A pointer to the dequeued binary tree node.
 */
BinaryTreeNode* dequeue(Queue* queue);

/**
 * @brief Destroys the queue and frees all allocated memory.
 * 
 * @param queue A pointer to the queue.
 */
void destroy_queue(Queue* queue);

/**
 * @brief Displays the menu for binary tree operations.
 */
void display_menu() {
    printf("%d Binary Search Tree Operations\n", INSERT_NODE);
    printf("%d. Insert a node\n", SEARCH_NODE);
    printf("%d. Search for a node\n", DISPLAY_INORDER);
    printf("%d. Display tree in inorder\n", DISPLAY_PREORDER);
    printf("%d. Display tree in preorder\n", DISPLAY_POSTORDER);
    printf("%d. Display tree in postorder\n", DISPLAY_DFS);
    printf("%d. Display tree using DFS\n", DISPLAY_DFS);
    printf("%d. Display tree using BFS\n", DISPLAY_BFS);
    printf("%d. Delete a node\n", DELETE_NODE);
    printf("%d. Mirror the tree\n", MIRROR_TREE);
    printf("%d. Balance the tree\n", BALANCE_TREE);
    printf("%d. Clean the tree\n", CLEAN_TREE);
    printf("%d. Exit\n", EXIT_PROGRAM);
    printf("Enter your choice: ");
}

/**
 * @brief Enumeration for menu options.
 */
typedef enum {
    INSERT_NODE = 1,
    SEARCH_NODE,
    DISPLAY_INORDER,
    DISPLAY_PREORDER,
    DISPLAY_POSTORDER,
    DISPLAY_DFS,
    DISPLAY_BFS,
    DELETE_NODE,
    MIRROR_TREE,
    BALANCE_TREE,
    CLEAN_TREE,
    EXIT_PROGRAM
} MenuOption;

int main() {
    BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
    if (tree == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }
    tree->root = NULL;

    int choice, key;
    NodeData data;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case INSERT_NODE:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter data1 (int): ");
                scanf("%d", &data.data1);
                printf("Enter data2 (char): ");
                scanf(" %c", &data.data2);
                printf("Enter data3 (float): ");
                scanf("%f", &data.data3);
                insert(tree, key, data);
                break;
            case SEARCH_NODE:
                printf("Enter key to search: ");
                scanf("%d", &key);
                BinaryTreeNode* result = search(tree, key);
                if (result != NULL)
                    printf("Node found: key = %d, data1 = %d, data2 = %c, data3 = %f\n",
                           result->key, result->data.data1, result->data.data2, result->data.data3);
                else
                    printf("Node not found.\n");
                break;
            case DISPLAY_INORDER:
                display_inorder(tree);
                break;
            case DISPLAY_PREORDER:
                display_preorder(tree);
                break;
            case DISPLAY_POSTORDER:
                display_postorder(tree);
                break;
            case DISPLAY_DFS:
                display_dfs(tree);
                break;
            case DISPLAY_BFS:
                display_bfs(tree);
                break;
            case DELETE_NODE:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete_node(tree, key);
                break;
            case MIRROR_TREE:
                {
                    BinaryTree* mirrored_tree = mirror(tree);
                    printf("Mirrored tree (inorder):\n");
                    display_inorder(mirrored_tree);
                    free_tree(mirrored_tree);
                }
                break;
            case BALANCE_TREE:
                {
                    BinaryTree* balanced_tree = balance_bst(tree);
                    printf("Balanced tree (inorder):\n");
                    display_inorder(balanced_tree);
                    free_tree(balanced_tree);
                }
                break;
            case CLEAN_TREE:
                free_tree(tree);
                tree->root = NULL;
                printf("Tree cleaned.\n");
                break;
            case EXIT_PROGRAM:
                free_tree(tree);
                free(tree);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != EXIT_PROGRAM);

    return EXIT_SUCCESS;
}

/**
 * @brief Creates a new binary tree node.
 * 
 * @param key The key of the node.
 * @param data The data of the node.
 * @return BinaryTreeNode* A pointer to the new node.
 */
BinaryTreeNode* create_node(int key, NodeData data) {
    BinaryTreeNode* new_node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    new_node->key = key;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

/**
 * @brief Inserts a new node into the binary tree.
 * 
 * @param tree A pointer to the binary tree.
 * @param key The key of the node to be inserted.
 * @param data The data of the node to be inserted.
 */
void insert(BinaryTree* tree, int key, NodeData data) {
    BinaryTreeNode* new_node = create_node(key, data);

    if (tree->root == NULL) {
        tree->root = new_node;
        return;
    }

    BinaryTreeNode* current = tree->root;
    BinaryTreeNode* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }

    if (key < parent->key)
        parent->left = new_node;
    else
        parent->right = new_node;
}

/**
 * @brief Searches for a node with the given key in the binary tree.
 * 
 * @param tree A pointer to the binary tree.
 * @param key The key to search for.
 * @return BinaryTreeNode* A pointer to the node if found, otherwise NULL.
 */
BinaryTreeNode* search(BinaryTree* tree, int key) {
    BinaryTreeNode* root = tree->root;
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return search(&(BinaryTree){ root->left }, key);
    else
        return search(&(BinaryTree){ root->right }, key);
}

/**
 * @brief Displays the binary tree in inorder traversal.
 * 
 * @param tree A pointer to the binary tree.
 */
void display_inorder(BinaryTree* tree) {
    display_inorder_rec(tree->root);
    printf("\n");
}

/**
 * @brief Helper function for inorder traversal.
 * 
 * @param root A pointer to the root of the binary tree.
 */
void display_inorder_rec(BinaryTreeNode* root) {
    if (root != NULL) {
        display_inorder_rec(root->left);
        printf("%d ", root->key);
        display_inorder_rec(root->right);
    }
}

/**
 * @brief Displays the binary tree in preorder traversal.
 * 
 * @param tree A pointer to the binary tree.
 */
void display_preorder(BinaryTree* tree) {
    display_preorder_rec(tree->root);
    printf("\n");
}

/**
 * @brief Helper function for preorder traversal.
 * 
 * @param root A pointer to the root of the binary tree.
 */
void display_preorder_rec(BinaryTreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        display_preorder_rec(root->left);
        display_preorder_rec(root->right);
    }
}

/**
 * @brief Displays the binary tree in postorder traversal.
 * 
 * @param tree A pointer to the binary tree.
 */
void display_postorder(BinaryTree* tree) {
    display_postorder_rec(tree->root);
    printf("\n");
}

/**
 * @brief Helper function for postorder traversal.
 * 
 * @param root A pointer to the root of the binary tree.
 */
void display_postorder_rec(BinaryTreeNode* root) {
    if (root != NULL) {
        display_postorder_rec(root->left);
        display_postorder_rec(root->right);
        printf("%d ", root->key); 
    }
}

/**
 * @brief Displays the binary tree using DFS (preorder traversal).
 * 
 * @param tree A pointer to the binary tree.
 */
void display_dfs(BinaryTree* tree) {
    display_preorder(tree);
}

/**
 * @brief Displays the binary tree using BFS.
 * 
 * @param tree A pointer to the binary tree.
 */
void display_bfs(BinaryTree* tree) {
    if (tree->root == NULL)
        return;

    Queue* queue = create_queue();
    enqueue(queue, tree->root);

    while (!is_empty(queue)) {
        BinaryTreeNode* current = dequeue(queue);
        printf("%d ", current->key);

        if (current->left != NULL)
            enqueue(queue, current->left);
        if (current->right != NULL)
            enqueue(queue, current->right);
    }
    printf("\n");
    destroy_queue(queue);
}

/**
 * @brief Finds the node with the minimum key in the binary tree.
 * 
 * @param tree A pointer to the binary tree.
 * @return BinaryTreeNode* A pointer to the node with the minimum key.
 */
BinaryTreeNode* find_min(BinaryTree* tree) {
    BinaryTreeNode* current = tree->root;
    while (current != NULL && current->left != NULL)
        current = current->left;
    return current;
}

/**
 * @brief Deletes a node with the given key from the binary tree.
 * 
 * @param tree A pointer to the binary tree.
 * @param key The key of the node to be deleted.
 */
void delete_node(BinaryTree* tree, int key) {
    tree->root = delete_node_rec(tree->root, key);
}

/**
 * @brief Helper function to delete a node with the given key from the binary tree.
 * 
 * @param root A pointer to the root of the binary tree.
 * @param key The key of the node to be deleted.
 * @return BinaryTreeNode* A pointer to the root of the modified binary tree.
 */
BinaryTreeNode* delete_node_rec(BinaryTreeNode* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = delete_node_rec(root->left, key);
    else if (key > root->key)
        root->right = delete_node_rec(root->right, key);
    else {
        if (root->left == NULL) {
            BinaryTreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BinaryTreeNode* temp = root->left;
            free(root);
            return temp;
        }

        BinaryTreeNode* temp = find_min(&(BinaryTree){ root->right });
        root->key = temp->key;
        root->data = temp->data;
        root->right = delete_node_rec(root->right, temp->key);
    }
    return root;
}

/**
 * @brief Frees all nodes in the binary tree.
 * 
 * @param tree A pointer to the binary tree.
 */
void free_tree(BinaryTree* tree) {
    free_tree_rec(tree->root);
}

/**
 * @brief Helper function to free all nodes in the binary tree.
 * 
 * @param root A pointer to the root of the binary tree.
 */
void free_tree_rec(BinaryTreeNode* root) {
    if (root != NULL) {
        free_tree_rec(root->left);
        free_tree_rec(root->right);
        free(root);
    }
}

/**
 * @brief Creates a mirrored copy of the binary tree.
 * 
 * @param tree A pointer to the original binary tree.
 * @return BinaryTree* A pointer to the mirrored binary tree.
 */
BinaryTree* mirror(BinaryTree* tree) {
    BinaryTree* mirrored_tree = (BinaryTree*)malloc(sizeof(BinaryTree));
    if (mirrored_tree == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    mirrored_tree->root = mirror_rec(tree->root);
    return mirrored_tree;
}

/**
 * @brief Helper function to create a mirrored copy of the binary tree.
 * 
 * @param root A pointer to the root of the binary tree.
 * @return BinaryTreeNode* A pointer to the root of the mirrored binary tree.
 */
BinaryTreeNode* mirror_rec(BinaryTreeNode* root) {
    if (root == NULL)
        return NULL;

    BinaryTreeNode* mirrored_root = create_node(root->key, root->data);
    mirrored_root->left = mirror_rec(root->right);
    mirrored_root->right = mirror_rec(root->left);
    return mirrored_root;
}

/**
 * @brief Gets the height of the binary tree.
 * 
 * @param tree A pointer to the binary tree.
 * @return int The height of the binary tree.
 */
int get_height(BinaryTree* tree) {
    return get_height_rec(tree->root);
}

/**
 * @brief Helper function to get the height of the binary tree.
 * 
 * @param root A pointer to the root of the binary tree.
 * @return int The height of the binary tree.
 */
int get_height_rec(BinaryTreeNode* root) {
    if (root == NULL)
        return 0;
    int left_height = get_height_rec(root->left);
    int right_height = get_height_rec(root->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}

/**
 * @brief Stores the inorder traversal of the binary tree in an array.
 * 
 * @param root A pointer to the root of the binary tree.
 * @param arr An array to store the inorder traversal.
 * @param index A pointer to the current index in the array.
 */
void store_inorder(BinaryTreeNode* root, int* arr, int* index) {
    if (root == NULL)
        return;
    store_inorder(root->left, arr, index);
    arr[*index] = root->key;
    (*index)++;
    store_inorder(root->right, arr, index);
}

/**
 * @brief Builds a balanced BST from a sorted array.
 * 
 * @param arr An array containing the sorted elements.
 * @param start The starting index of the array.
 * @param end The ending index of the array.
 * @return BinaryTreeNode* A pointer to the root of the balanced BST.
 */
BinaryTreeNode* build_balanced_bst(int* arr, int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    BinaryTreeNode* root = create_node(arr[mid], (NodeData){0, 0, 0});
    root->left = build_balanced_bst(arr, start, mid - 1);
    root->right = build_balanced_bst(arr, mid + 1, end);
    return root;
}

/**
 * @brief Balances the binary tree.
 * 
 * @param tree A pointer to the original binary tree.
 * @return BinaryTree* A pointer to the balanced binary tree.
 */
BinaryTree* balance_bst(BinaryTree* tree) {
    if (tree->root == NULL)
        return NULL;

    int n = get_height(tree); // Initial allocation
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    int index = 0;
    store_inorder(tree->root, arr, &index);

    BinaryTree* balanced_tree = (BinaryTree*)malloc(sizeof(BinaryTree));
    if (balanced_tree == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(arr);
        exit(EXIT_FAILURE);
    }
    balanced_tree->root = build_balanced_bst(arr, 0, index - 1);
    free(arr);
    return balanced_tree;
}

/**
 * @brief Creates a new queue node.
 * 
 * @param data A pointer to the binary tree node to be stored in the queue node.
 * @return QueueNode* A pointer to the new queue node.
 */
QueueNode* create_queue_node(BinaryTreeNode* data) {
    QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/**
 * @brief Creates a new queue.
 * 
 * @return Queue* A pointer to the new queue.
 */
Queue* create_queue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

/**
 * @brief Checks if the queue is empty.
 * 
 * @param queue A pointer to the queue.
 * @return int 1 if the queue is empty, 0 otherwise.
 */
int is_empty(Queue* queue) {
    return queue->front == NULL;
}

/**
 * @brief Enqueues a binary tree node into the queue.
 * 
 * @param queue A pointer to the queue.
 * @param data A pointer to the binary tree node to be enqueued.
 */
void enqueue(Queue* queue, BinaryTreeNode* data) {
    QueueNode* new_node = create_queue_node(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = new_node;
        return;
    }
    queue->rear->next = new_node;
    queue->rear = new_node;
}

/**
 * @brief Dequeues a binary tree node from the queue.
 * 
 * @param queue A pointer to the queue.
 * @return BinaryTreeNode* A pointer to the dequeued binary tree node.
 */
BinaryTreeNode* dequeue(Queue* queue) {
    if (is_empty(queue))
        return NULL;

    QueueNode* temp = queue->front;
    BinaryTreeNode* data = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
    return data;
}

/**
 * @brief Destroys the queue and frees all allocated memory.
 * 
 * @param queue A pointer to the queue.
 */
void destroy_queue(Queue* queue) {
    while (!is_empty(queue))
        dequeue(queue);
    free(queue);
}
