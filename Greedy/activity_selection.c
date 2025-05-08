/*
 * Activity Selection Problem using Greedy Algorithm
 
 
 * Problem:
 * --------
 * Given a set of activities with start and end times, select the maximum number 
 * of activities that can be performed by a single person, assuming that a person 
 * can only work on a single activity at a time.
 *
 * Approach:
 * ---------
 * We use a greedy algorithm that selects the activity which ends earliest.
 * 1. Sort all activities by their end time.
 * 2. Always pick the first activity.
 * 3. For the rest, pick the next activity only if its start time is 
 *    greater than or equal to the end time of the last selected activity.
 *
 * Time Complexity: O(n log n) for sorting + O(n) for selection = O(n log n)
 * Space Complexity: O(1) (ignoring input storage)
 *
 * Sample Input:
 * activities[] = {{1, 3}, {2, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}, {5, 9}}
 *
 * Sample Output:
 * Selected activities:
 * (1, 3)
 * (3, 5)
 * (5, 7)
 * (8, 9)
 */

 #include <stdio.h>
 #include <stdlib.h>
 
 // Define a structure to represent an activity with start and end time
 typedef struct {
     int start;
     int end;
 } Activity;
 
 // Comparator function for qsort to sort activities based on end time
 int compare(const void *a, const void *b) {
     Activity *act1 = (Activity *)a;
     Activity *act2 = (Activity *)b;
     return act1->end - act2->end;
 }
 
 // Function to perform activity selection and print the selected activities
 void activitySelection(Activity activities[], int n) {
     // Sort the activities based on end time
     qsort(activities, n, sizeof(Activity), compare);
 
     printf("Selected activities:\n");
 
     // Always select the first activity
     int lastEnd = activities[0].end;
     printf("(%d, %d)\n", activities[0].start, activities[0].end);
 
     // Iterate through remaining activities
     for (int i = 1; i < n; i++) {
         // Select activity if it doesn't overlap with the last selected one
         if (activities[i].start >= lastEnd) {
             printf("(%d, %d)\n", activities[i].start, activities[i].end);
             lastEnd = activities[i].end;
         }
     }
 }
 
 int main() {
     // Example list of activities with start and end times
     Activity activities[] = {{1, 3}, {2, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
     int n = sizeof(activities) / sizeof(activities[0]);
 
     // Call the function to perform activity selection
     activitySelection(activities, n);
 
     return 0;
 }
 