/*
    Problem Statement:
    -------------------
    Given a set of jobs, each with an ID, deadline, and profit, schedule the jobs to maximize
    total profit such that each job is completed before its deadline. The program should output
    the sequence of job IDs that achieves this.

    The Job Sequencing with Deadlines problem is a greedy algorithm problem where each job takes
    one unit of time to complete, and only one job can be scheduled at a time. Jobs are scheduled
    in slots from 1 to the maximum deadline, prioritizing higher-profit jobs.

    Example:
    Input:
        jobs[] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}}
        (ID, deadline, profit)

    Output:
        Job sequence: 1 3 5

    Explanation:
        - Jobs are sorted by profit in descending order: {1, 100}, {3, 27}, {4, 25}, {2, 19}, {5, 15}.
        - Job 1 (deadline 2) is scheduled in slot 2, Job 3 (deadline 2) in slot 1, Job 5 (deadline 3) in slot 3.
        - Jobs 2 and 4 cannot be scheduled due to slot conflicts (deadlines 1 and 1).
        - The sequence maximizes profit within the constraints.

    Approach:
    ---------
    Three methods are implemented below:
    1. Standard Job Sequencing (Original): Greedy approach with sorting by profit and slot assignment.
    2. Job Sequencing with Total Profit: Tracks and outputs the total profit of scheduled jobs.
    3. Dynamic Slot Allocation: Dynamically allocates slots based on maximum deadline.
*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a job
typedef struct {
    int id;     // Job ID
    int deadline; // Deadline of the job
    int profit;   // Profit of the job
} Job;

// ----------------------
// Comparator function for qsort
// ----------------------
int compare(const void *a, const void *b) {
    // Sort jobs by profit in descending order
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;
    return job2->profit - job1->profit;
}

// ----------------------
// 1. Standard Job Sequencing (Original)
// ----------------------
void jobSequencing_standard(Job jobs[], int n, int maxDeadline) {
    // Array to track assigned jobs in time slots
    int slot[maxDeadline];
    // Initialize all slots as free (-1)
    for (int i = 0; i < maxDeadline; i++) {
        slot[i] = -1;
    }

    // Assign jobs to the latest possible free slot
    for (int i = 0; i < n; i++) {
        // Start from the job's deadline or maxDeadline, whichever is smaller
        for (int j = (jobs[i].deadline < maxDeadline ? jobs[i].deadline : maxDeadline) - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i; // Assign job to this slot
                break;
            }
        }
    }

    // Print the scheduled job sequence
    printf("Job sequence: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i] != -1) {
            printf("%d ", jobs[slot[i]].id);
        }
    }
    printf("\n");
}

// ----------------------
// 2. Job Sequencing with Total Profit
// ----------------------
void jobSequencing_profit(Job jobs[], int n, int maxDeadline) {
    // Array to track assigned jobs
    int slot[maxDeadline];
    int totalProfit = 0;
    // Initialize slots as free
    for (int i = 0; i < maxDeadline; i++) {
        slot[i] = -1;
    }

    // Assign jobs to slots
    for (int i = 0; i < n; i++) {
        for (int j = (jobs[i].deadline < maxDeadline ? jobs[i].deadline : maxDeadline) - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                totalProfit += jobs[i].profit; // Add profit
                break;
            }
        }
    }

    // Print results
    printf("Job sequence (with profit): ");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i] != -1) {
            printf("%d ", jobs[slot[i]].id);
        }
    }
    printf("\nTotal profit: %d\n", totalProfit);
}

// ----------------------
// 3. Dynamic Slot Allocation
// ----------------------
void jobSequencing_dynamic(Job jobs[], int n, int maxDeadline) {
    // Dynamically allocate slot array
    int *slot = (int *)malloc(maxDeadline * sizeof(int));
    // Initialize slots as free
    for (int i = 0; i < maxDeadline; i++) {
        slot[i] = -1;
    }

    // Assign jobs to slots
    for (int i = 0; i < n; i++) {
        for (int j = (jobs[i].deadline < maxDeadline ? jobs[i].deadline : maxDeadline) - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                break;
            }
        }
    }

    // Print results
    printf("Job sequence (dynamic allocation): ");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i] != -1) {
            printf("%d ", jobs[slot[i]].id);
        }
    }
    printf("\n");

    // Free allocated memory
    free(slot);
}

// ----------------------
// Main Function
// ----------------------
int main() {
    // Input jobs
    Job jobs[] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    int n = sizeof(jobs) / sizeof(jobs[0]);
    int maxDeadline = 0;

    // Find the maximum deadline
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    // Sort jobs by profit in descending order
    qsort(jobs, n, sizeof(Job), compare);

    // -------- Standard Job Sequencing --------
    jobSequencing_standard(jobs, n, maxDeadline);

    // -------- Job Sequencing with Total Profit --------
    // jobSequencing_profit(jobs, n, maxDeadline);

    // -------- Dynamic Slot Allocation --------
    // jobSequencing_dynamic(jobs, n, maxDeadline);

    return 0;
}