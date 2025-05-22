/*
    Problem Statement:
    -------------------
    Given an array of integers, create a binary tree where elements are inserted as nodes
    in a specific order (root, left child, right child, etc.), perform an inorder traversal,
    and print the tree level by level. The program should output the inorder traversal and
    a visual representation of the tree.

    The binary tree is constructed such that for each node at index i in the array, its left
    child is at index 2i+1 and right child is at index 2i+2. The operations demonstrate
    basic tree construction and traversal techniques.

    Example:
    Input:
        arr[] = {10, 5, 15, 3, 7, 12, 18}

    Output:
        Inorder traversal of the binary tree: 5 7 10 12 15 3 18
        Binary tree in level order:
           10
         5   15
        7  12 3  18

    Explanation:
        - The array is used to create a binary tree with 10 as the root, 5 (left) and 15 (right),
          and so on.
        - Inorder traversal visits nodes in the order: left subtree, root, right subtree.
        - The tree is printed level by level with indentation to show its structure.

    Approach:
    ---------
    Three methods are implemented for key operations:
    1. Standard Operations (Original): Recursive inorder traversal and level-order printing.
    2. Iterative Inorder Traversal: Uses a stack for non-recursive inorder traversal.
    3. Preorder Traversal: Recursive preorder traversal as an alternative to inorder.
*/

#include <stdio.h>
#include <stdlib.h>

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
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
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
    struct Node* stack[100]; // Assuming a reasonable maximum size
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
// 3. Preorder Traversal
// ----------------------
void preorder(struct Node* root) {
    // Recursive preorder traversal: root, left, right
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// ----------------------
// Main Function
// ----------------------
int main() {
    // Input array
    int arr[] = {10, 5, 15, 3, 7, 12, 18};
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

    // -------- Preorder Traversal --------
    // printf("Preorder traversal of the binary tree: ");
    // preorder(root);
    // printf("\n");

    // Print the tree structure
    printf("Binary tree in level order:\n");
    printTree(root);

    return 0;
}