/*
    Problem Statement:
    -------------------
    Given an array of integers, create a binary tree where elements are inserted as nodes
    in a specific order (root, left child, right child, etc.), perform an inorder traversal,
    print the tree level by level, and convert the tree back to an array. The program should
    output the inorder traversal, a visual representation of the tree, and the array
    representation.

    The binary tree is constructed such that for each node at index i in the array, its left
    child is at index 2i+1 and right child is at index 2i+2. The operations demonstrate
    basic tree manipulation and traversal techniques.

    Example:
    Input:
        arr[] = {10, 5, 3, 15, 7, 12, 18}

    Output:
        Inorder traversal of the binary tree: 5 7 10 12 3 15 18
           10
         5   3
        7  15
       12 18
        Array representation of the binary tree: 10 5 3 7 15 12 18

    Explanation:
        - The array is used to create a binary tree with 10 as the root, 5 (left) and 3 (right),
          and so on.
        - Inorder traversal visits nodes in the order: left subtree, root, right subtree.
        - The tree is printed level by level with indentation to show structure.
        - The tree is converted back to an array in the same order as the input.

    Approach:
    ---------
    Three methods are implemented for key operations:
    1. Standard Operations (Original): Recursive inorder traversal and level-order printing.
    2. Iterative Inorder Traversal: Uses a stack for non-recursive inorder traversal.
    3. Level-Order Array Conversion: Converts the tree to an array using a queue-based approach.
*/

#include <stdio.h>
#include <stdlib.h>
#define COUNT 5

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// ----------------------
// Utility function to create a new node
// ----------------------
struct Node* CreateNode(int data) {
    // Allocate memory for a new node
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// ----------------------
// 1. Standard Operations (Original)
// ----------------------
void CreateTree(struct Node** root, int arr[], int size) {
    // Array to store nodes for easy access to parents
    struct Node* node[size];
    for (int i = 0; i < size; i++) {
        if (*root == NULL) {
            // Create root node for the first element
            *root = CreateNode(arr[i]);
            node[i] = *root;
        } else {
            // Create a new node and assign it as left or right child
            struct Node* temp;
            struct Node* parent;
            if (i % 2 == 0) {
                // Even index: right child of parent at (i-1)/2
                temp = CreateNode(arr[i]);
                parent = node[(i - 1) / 2];
                parent->right = temp;
                node[i] = temp;
            } else {
                // Odd index: left child of parent at (i-1)/2
                temp = CreateNode(arr[i]);
                parent = node[(i - 1) / 2];
                parent->left = temp;
                node[i] = temp;
            }
        }
    }
}

void inorder_standard(struct Node* root) {
    // Recursive inorder traversal: left, root, right
    if (root != NULL) {
        inorder_standard(root->left);
        printf("%d ", root->data);
        inorder_standard(root->right);
    }
}

void convertToArray_standard(struct Node* root, int array[], int size) {
    // Convert tree to array using parent-child indexing
    struct Node* node[size];
    node[0] = root;
    array[0] = root->data;
    for (int i = 1; i < size; i++) {
        struct Node* parent = node[(i - 1) / 2];
        if (i % 2 == 0) {
            // Even index: right child
            node[i] = parent->right;
            array[i] = parent->right->data;
        } else {
            // Odd index: left child
            node[i] = parent->left;
            array[i] = parent->left->data;
        }
    }
}

void printLevel(struct Node* root, int level) {
    // Print nodes at a specific level
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

int height(struct Node* node) {
    // Calculate the height of the tree
    if (node == NULL)
        return 0;
    int l = height(node->left);
    int r = height(node->right);
    return (l > r ? l : r) + 1;
}

void printTree(struct Node* root) {
    // Print the tree level by level with indentation
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        for (int j = 0; j < (h - i); j++)
            printf(" ");
        printLevel(root, i);
        printf("\n");
    }
}

// ----------------------
// 2. Iterative Inorder Traversal
// ----------------------
void inorder_iterative(struct Node* root) {
    // Stack for iterative traversal
    struct Node* stack[COUNT];
    int top = -1;
    struct Node* current = root;

    // Traverse until current is NULL and stack is empty
    while (current != NULL || top >= 0) {
        // Push all left nodes to stack
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        // Pop and process the top node
        current = stack[top--];
        printf("%d ", current->data);
        // Move to the right subtree
        current = current->right;
    }
}

// ----------------------
// 3. Level-Order Array Conversion
// ----------------------
void convertToArray_levelOrder(struct Node* root, int array[], int size) {
    // Queue for level-order traversal
    struct Node* queue[COUNT];
    int front = 0, rear = -1, index = 0;

    // Enqueue the root
    if (root == NULL) return;
    queue[++rear] = root;

    // Process nodes level by level
    while (front <= rear && index < size) {
        struct Node* current = queue[front++];
        array[index++] = current->data;

        // Enqueue left child
        if (current->left != NULL)
            queue[++rear] = current->left;
        // Enqueue right child
        if (current->right != NULL)
            queue[++rear] = current->right;
    }
}

// ----------------------
// Main Function
// ----------------------
int main() {
    // Input array
    int arr[] = {10, 5, 3, 15, 7, 12, 18};
    int size = sizeof(arr) / sizeof(arr[0]);
    struct Node* root = NULL;

    // Create the binary tree
    CreateTree(&root, arr, size);

    // -------- Standard Inorder Traversal --------
    printf("Inorder traversal of the binary tree: ");
    inorder_standard(root);
    printf("\n");

    // -------- Iterative Inorder Traversal --------
    // printf("Iterative inorder traversal: ");
    // inorder_iterative(root);
    // printf("\n");

    // Print the tree structure
    printTree(root);

    // Convert tree to array
    int array[size];
    convertToArray_standard(root, array, size);

    // -------- Level-Order Array Conversion --------
    // convertToArray_levelOrder(root, array, size);

    // Print array representation
    printf("Array representation of the binary tree: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}