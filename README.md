# Hidden Markov Model Viterbi Algorithm Simulator

## Working example (From [HMM Homework](https://northeastern.instructure.com/courses/189694/files/folder/Class%20Packet?preview=29055987))

https://github.com/user-attachments/assets/95a407ff-d231-4eff-ab1f-23f42421c5a3


## Introduction

This program demonstrates the **Viterbi Algorithm** for solving a **Hidden Markov Model (HMM)** problem. The Viterbi Algorithm is used to find the most probable sequence of states (e.g., weather conditions) given a sequence of observations (e.g., activities).

For this assignment, the program:
1. Allows users to define an HMM by entering:
   - States (e.g., A, B)
   - Observations (e.g., red, balck)
   - Transition probabilities (how states change)
   - Emission probabilities (how observations arise from states)
   - Initial probabilities (starting state likelihoods)
   - An observed sequence
2. Computes the most probable sequence of states for the given observations.
3. Calculates the probability of this sequence.

This README provides step-by-step instructions to run and use the program.

## Requirements

To run the program, you need:
- A computer with **C++** installed.
- A text editor or IDE to open the code.
- A terminal or command prompt to compile and execute the program.

If you're unsure about these requirements, contact your teaching assistant or professor for help.

## How to Run the Program

### Step 1: Clone the Repository
1. Open your terminal or command prompt.
2. Navigate to the folder where you want to save the program.
3. Clone this repository by running:
   `git clone https://github.com/alisryan/viterbi`

### Step 2: Compile the Program
1. Navigate to the cloned repository:
   cd path/to/repository
2. Compile the program using:
   `g++ -std=c++11 -o viterbi main.cpp`
3. If successful, a file named `viterbi` (or `viterbi.exe` on Windows) will be created.

### Step 3: Run the Program
1. Run the program using:
   `./viterbi`
   On Windows, type `viterbi` and press Enter.

## Using the Program

When you run the program, follow the prompts to input the details of your Hidden Markov Model:

### 1. Number of States
Enter how many states your system has. For example:
   ```
   Enter the number of states: 2
   ```

### 2. Names of States
Provide the names of each state. For example:
   ```
   State 1: A
   State 2: B
   ```

### 3. Number of Observations
Enter how many possible observations there are. For example:
   ```
   Enter the number of observation symbols: 2
   ```

### 4. Names of Observations
Provide the names of each observation. For example:
   ```
   Symbol 1: red
   Symbol 2: black
   ```

### 5. Initial Probabilities
Enter the probability of starting in each state. These should sum to 1. For example:
   ```
   Initial probability for A: 0.71428571428 (5/7)
   Initial probability for B: 0.28571428571 (2/7)
   ```

### 6. Transition Probabilities
Provide the probabilities of moving from one state to another. For example:
   ```
   A -> A: 0.8
   A -> B: 0.2
   B -> A: 0.5
   B -> B: 0.5
   ```

### 7. Emission Probabilities
Provide the probabilities of observing a symbol given a state. For example:
   ```
   A emits red: 0.4
   A emits black: 0.6
   B emits red: 0.7
   B emits black: 0.3
   ```

### 8. Observed Sequence
Provide the sequence of observations. First, enter the length of the sequence, then provide the observations. For example:
   ```
   Length of observed sequence: 4
   Observation 1: red
   Observation 2: red
   Observation 3: black
   Observation 4: red
   ```

## Output

Once you provide the inputs, the program will:
1. Display a summary of your inputs (states, observations, probabilities, sequence).
2. Print the Transition Matrix and Emission Matrix for reference.
3. Compute and display:
   - The Probability of the Most Probable Sequence.
   - The Most Probable Sequence of States corresponding to the observed sequence.
4. In this case we get
   ```
   Inputs Summary:
   States: A B 
   Observations: red black 
   Observed Sequence: red red black red 
   
   Transition Matrix:
   0.800 0.200 
   0.500 0.500 
   
   Emission Matrix:
   0.400 0.600 
   0.700 0.300 
   
   Probability of the most probable sequence of states: 0.014043
   
   Most probable sequence of states:
   A A A A 
   Thank you for using the simulator!
   ```
