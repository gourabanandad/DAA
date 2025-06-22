# ⚡ Greedy Algorithms in DAA

Welcome to the **Greedy Algorithms** section of this repository! Here, you'll find implementations of popular greedy algorithms commonly encountered in algorithmic challenges, interviews, and problem-solving tasks.

---

## 🧠 What is a Greedy Algorithm?

A **Greedy Algorithm** solves problems by making the **locally optimal choice** at each step with the hope of finding the **global optimum**. It works well when the problem satisfies:

- **Greedy Choice Property**: A globally optimal solution can be arrived at by making a series of locally optimal choices.
- **Optimal Substructure**: The problem can be broken down into subproblems which can be solved independently and combined.

---

## ✅ Problems Implemented

| S.No | Algorithm Name                  | Description                                                                 | Time Complexity     |
|:----:|----------------------------------|-----------------------------------------------------------------------------|---------------------|
| 1    | Activity Selection              | Select the maximum number of non-overlapping activities.                    | O(n log n)          |
| 2    | Fractional Knapsack             | Maximize total value by taking fractions based on value/weight ratio.       | O(n log n)          |
| 3    | Job Sequencing with Deadlines   | Schedule jobs within deadlines to maximize total profit.                    | O(n²) or O(n log n) |
| 4    | Prim’s Algorithm (MST)          | Find Minimum Spanning Tree using greedy edge selection.                     | O(V²)               |
| 5    | Huffman Coding                  | Generate optimal prefix codes based on character frequency.                 | O(n log n)          |

---

## 🛠️ How to Use

You can easily compile and run any of the programs in this folder. Follow these simple steps:

1. Open your terminal or command prompt.
2. Navigate to the directory containing the `.c` files.
3. Use the following commands to compile and run each program:

   For the **Activity Selection Problem**:
   ```bash
   gcc activity_selection.c -o activity_selection
   ./activity_selection

   Repeat similarly for other files.
Each program is designed to run in the terminal, where it will display the results of the greedy algorithm applied to the problem.
---

## ✅ Contributing

Want to contribute?

* Add new Greedy problems.
* Optimize existing solutions.
* Write better documentation or add more comments to help others understand the algorithms better.

Feel free to fork the repository, make your changes, and submit a pull request!


---

## 📜 License

This project is open-source under the [MIT License](../LICENSE).

---

⭐ Star this repository if you find it helpful or inspiring!
