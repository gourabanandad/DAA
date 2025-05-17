# ⚡ Greedy Algorithms in DAA

Welcome to the **Greedy Algorithms** section of this repository! Here, you'll find implementations of popular greedy algorithms commonly encountered in algorithmic challenges, interviews, and problem-solving tasks.


## 🧠 What is a Greedy Algorithm?

A **Greedy Algorithm** is an approach for solving optimization problems by making a series of choices. At each step, it chooses the option that provides the most immediate benefit, without worrying about the global optimal solution. Greedy algorithms are used for problems where a local optimum choice leads to a global optimum solution.


### Key Properties:
- **Greedy Choice Property**: A global optimum can be arrived at by choosing the best local solution.
- **Optimal Substructure**: A problem has an optimal solution that can be constructed efficiently from optimal solutions to its subproblems.

---


## 💡 Problems Implemented

In this directory, we've implemented the following problems using greedy algorithms:

1. **Activity Selection Problem**  
   This problem involves selecting the maximum number of activities that don’t overlap, given their start and finish times. We implement this by choosing the activity that finishes first, which allows us to make room for other activities.

2. **Fractional Knapsack Problem**  
   In this problem, we need to maximize the profit by selecting items to be placed into a knapsack. Unlike the 0/1 knapsack, where we can only pick items in whole quantities, here we can take fractional parts of an item, choosing based on the highest value-to-weight ratio.

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
