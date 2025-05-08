/*
 * Fractional Knapsack Problem using Greedy Algorithm
 
 *
 * Problem:
 * --------
 * Given weights and values of n items, put these items in a knapsack of capacity W 
 * to get the maximum total value in the knapsack. Items can be broken into smaller parts.
 *
 * Approach:
 * ---------
 * 1. Calculate value per unit weight for each item.
 * 2. Sort all items in descending order of value/weight ratio.
 * 3. Take items starting from the highest ratio:
 *    - If the item can be fully taken, take it.
 *    - Else, take the possible fraction of it.
 *
 * Time Complexity: O(n log n) due to sorting
 * Space Complexity: O(1) (ignoring input storage)
 *
 * Sample Input:
 * weights[] = {10, 20, 30}
 * values[]  = {60, 100, 120}
 * capacity = 50
 *
 * Sample Output:
 * Maximum value in knapsack = 240.000000
 */

 #include <stdio.h>
 #include <stdlib.h>
 
 // Define a structure to represent an item with weight and value
 typedef struct {
     int weight;
     int value;
 } Item;
 
 // Comparator to sort items by value/weight ratio in descending order
 int compare(const void *a, const void *b) {
     Item *item1 = (Item *)a;
     Item *item2 = (Item *)b;
 
     double r1 = (double)item1->value / item1->weight;
     double r2 = (double)item2->value / item2->weight;
 
     if (r1 < r2) return 1;
     else if (r1 > r2) return -1;
     else return 0;
 }
 
 // Function to calculate the maximum value for the fractional knapsack
 double fractionalKnapsack(Item items[], int n, int capacity) {
     // Sort items by value/weight ratio
     qsort(items, n, sizeof(Item), compare);
 
     double totalValue = 0.0;
 
     for (int i = 0; i < n; i++) {
         // If full item can be taken
         if (capacity >= items[i].weight) {
             capacity -= items[i].weight;
             totalValue += items[i].value;
         }
         // Take fraction of item
         else {
             totalValue += (double)items[i].value * capacity / items[i].weight;
             break; // Knapsack is full
         }
     }
 
     return totalValue;
 }
 
 int main() {
     // Example list of items
     Item items[] = {{10, 60}, {20, 100}, {30, 120}};
     int n = sizeof(items) / sizeof(items[0]);
     int capacity = 50;
 
     // Compute the result
     double maxValue = fractionalKnapsack(items, n, capacity);
 
     // Output the result
     printf("Maximum value in knapsack = %f\n", maxValue);
 
     return 0;
 }
 