/*
 ============================================================================
  📚 Problem: Reverse a Singly Linked List
  ----------------------------------------------------------------------------
  Given the head of a singly linked list, reverse the list and return the 
  new head pointer after reversal.

  👉 Time‑Complexity: O(n)  
     Space‑Complexity: 
        • Iterative: O(1) 
        • Recursive: O(n) due to recursion stack
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

/* Structure for a node in the linked list */
struct Node {
    int data;
    struct Node* next;
};

/* Creates a new node with the given value */
struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

/* Inserts a node at the beginning of the linked list */
void insertAtHead(struct Node** headRef, int value) {
    struct Node* node = createNode(value);
    node->next = *headRef;
    *headRef = node;
}

/* Prints all elements of the linked list */
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

/* ------------------------------------------------------------------
   🔁 Iterative Approach: Reverses the linked list by changing links
-------------------------------------------------------------------- */
struct Node* reverseIterative(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;

    while (curr != NULL) {
        struct Node* next = curr->next; // Store the next node
        curr->next = prev;              // Reverse the link
        prev = curr;                    // Move prev forward
        curr = next;                    // Move curr forward
    }

    return prev; // New head after reversal
}

/* ------------------------------------------------------------------
   🔁 Recursive Approach: Reverses the list using call stack
-------------------------------------------------------------------- */
struct Node* reverseRecursive(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head; // Base case

    struct Node* rest = reverseRecursive(head->next); // Reverse rest
    head->next->next = head; // Make next node point to current
    head->next = NULL;       // Set current node's next to NULL

    return rest; // Return new head
}


int main(void) {
    struct Node* head = NULL;

    // Creating the list: 1 -> 2 -> 3 -> 4 -> 5
    for (int i = 5; i >= 1; --i)
        insertAtHead(&head, i);

    printf("Original list:\n");
    printList(head);

    // Uncomment only ONE of the below lines to use a reversal method:

    head = reverseIterative(head);     // 🔁 Using Iterative approach
    // head = reverseRecursive(head);  // 🔁 Using Recursive approach

    printf("\nReversed list:\n");
    printList(head);

    return 0;
}
