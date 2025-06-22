/*
📝 Huffman Coding – Greedy Algorithm

Problem Statement:
Given characters and their frequencies, build a binary tree (Huffman Tree) that 
minimizes the total cost of encoding characters. Then generate prefix codes 
(Huffman codes) from the tree for data compression.

Example Input:
Characters: A, B, C, D, E  
Frequencies: 5, 9, 12, 13, 16

Output:
A set of prefix codes with minimal average code length.

💡 Approach:
- Use a min-heap (priority queue) to repeatedly extract two nodes with the smallest frequencies.
- Merge them into a new node with their combined frequency.
- Repeat until one node (the root of the Huffman Tree) remains.
- Traverse the tree to assign binary codes to each character.

⏱️ Time Complexity: O(n log n) — for heap operations  
🧠 Space Complexity: O(n) — for tree and heap storage
--------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

// A Huffman tree node
struct MinHeapNode {
    char data;                  // Input character
    unsigned freq;              // Frequency of the character
    struct MinHeapNode *left, *right; // Left and right child
};

// Min-Heap structure
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **array;
};

// Function to allocate a new node
struct MinHeapNode* newNode(char data, unsigned freq) {
    struct MinHeapNode* temp = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to create a min heap of given capacity
struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**) malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// Swap two nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Heapify the min heap at index i
void minHeapify(struct MinHeap* minHeap, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != i) {
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[smallest]);
        minHeapify(minHeap, smallest);
    }
}

// Check if size is one
int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Extract minimum value node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert a new node into Min Heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* node) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && node->freq < minHeap->array[(i - 1)/2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1)/2];
        i = (i - 1)/2;
    }

    minHeap->array[i] = node;
}

// Build Min Heap
void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1)/2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// Create and build min heap from input characters and frequencies
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

// Build the Huffman Tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;

    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        // Create internal node with combined frequency and no data
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap); // Root of the tree
}

// Print Huffman codes from root of Huffman Tree
void printCodes(struct MinHeapNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

void HuffmanCodes(char data[], int freq[], int size) {
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
    int arr[100], top = 0;
    printf("Huffman Codes:\n");
    printCodes(root, arr, top);
}

int main() {
    char arr[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);
    return 0;
}