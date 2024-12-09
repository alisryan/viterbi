# Hidden Markov Model Viterbi Algorithm Simulator

## Introduction

This program demonstrates the **Viterbi Algorithm** for solving a **Hidden Markov Model (HMM)** problem. The Viterbi Algorithm is used to find the most probable sequence of states (e.g., weather conditions) given a sequence of observations (e.g., activities).

For this assignment, the program:
1. Allows users to define an HMM by entering:
   - States (e.g., Sunny, Rainy)
   - Observations (e.g., Walk, Shop)
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
   git clone https://github.com/alisryan/viterbi

### Step 2: Compile the Program
1. Navigate to the cloned repository:
   cd path/to/repository
2. Compile the program using:
   g++ -o viterbi viterbi.cpp
3. If successful, a file named `viterbi` (or `viterbi.exe` on Windows) will be created.

### Step 3: Run the Program
1. Run the program using:
   ./viterbi
   On Windows, type `viterbi` and press Enter.

## Using the Program

When you run the program, follow the prompts to input the details of your Hidden Markov Model:

### 1. Number of States
Enter how many states your system has. For example:
Enter the number of states: 2

### 2. Names of States
Provide the names of each state. For example:
State 1: Sunny
State 2: Rainy

### 3. Number of Observations
Enter how many possible observations there are. For example:
Enter the number of observation symbols: 2

### 4. Names of Observations
Provide the names of each observation. For example:
Symbol 1: Walk
Symbol 2: Shop

### 5. Initial Probabilities
Enter the probability of starting in each state. These should sum to 1. For example:
Initial probability for Sunny: 0.5
Initial probability for Rainy: 0.5

### 6. Transition Probabilities
Provide the probabilities of moving from one state to another. For example:
Sunny -> Sunny: 0.8
Sunny -> Rainy: 0.2
Rainy -> Sunny: 0.4
Rainy -> Rainy: 0.6

### 7. Emission Probabilities
Provide the probabilities of observing a symbol given a state. For example:
Sunny emits Walk: 0.9
Sunny emits Shop: 0.1
Rainy emits Walk: 0.5
Rainy emits Shop: 0.5

### 8. Observed Sequence
Provide the sequence of observations. First, enter the length of the sequence, then provide the observations. For example:
Length of observed sequence: 3
Observation 1: Walk
Observation 2: Shop
Observation 3: Walk

## Output

Once you provide the inputs, the program will:
1. Display a summary of your inputs (states, observations, probabilities, sequence).
2. Print the Transition Matrix and Emission Matrix for reference.
3. Compute and display:
   - The Probability of the Most Probable Sequence.
   - The Most Probable Sequence of States corresponding to the observed sequence.

## Predefined Example (Optional)

If you're unsure what to input, use the following predefined example:

- States: Sunny, Rainy
- Observations: Walk, Shop
- Initial Probabilities: Sunny = 0.5, Rainy = 0.5
- Transition Probabilities:
  Sunny -> Sunny: 0.8
  Sunny -> Rainy: 0.2
  Rainy -> Sunny: 0.4
  Rainy -> Rainy: 0.6
- Emission Probabilities:
  Sunny emits Walk: 0.9
  Sunny emits Shop: 0.1
  Rainy emits Walk: 0.5
  Rainy emits Shop: 0.5
- Observed Sequence: Walk, Shop, Walk

## Troubleshooting

1. The program doesn’t compile:
   - Ensure you have copied the entire code correctly.
   - Check that g++ or your C++ compiler is installed.

2. The program outputs incorrect results:
   - Verify that all probabilities sum to 1 (e.g., initial, transition, and emission probabilities).

3. I don’t understand the output:
   - The program outputs the most likely sequence of states for your observations and the probability of this sequence.

## Conclusion

This program demonstrates the Viterbi algorithm's ability to solve Hidden Markov Models efficiently. By following this guide, you can:
- Define your own HMM.
- Explore how different probabilities affect the outcome.
- Gain insights into how dynamic programming algorithms work.

If you have questions or need help, don’t hesitate to ask!
