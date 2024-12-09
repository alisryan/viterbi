#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <limits>

using namespace std;

// Utility function to print a 2D vector
void print2DVector(const vector<vector<double>>& matrix, const string& label) {
    cout << "\n" << label << ":\n";
    for (const auto& row : matrix) {
        for (double val : row) {
            cout << fixed << setprecision(3) << val << " ";
        }
        cout << endl;
    }
}

// Utility function to validate input
double getValidatedInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (!cin.fail() && value >= 0.0 && value <= 1.0) break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid probability between 0 and 1.\n";
    }
    return value;
}

// Viterbi Algorithm
vector<int> viterbi(
    const vector<string>& observations,
    const vector<string>& states,
    const vector<vector<double>>& transitionMatrix,
    const vector<vector<double>>& emissionMatrix,
    const vector<double>& initialProbabilities,
    const vector<string>& observedSequence
) {
    int numStates = states.size();
    int numObservations = observedSequence.size();

    vector<vector<double>> dp(numStates, vector<double>(numObservations, 0));
    vector<vector<int>> backpointer(numStates, vector<int>(numObservations, -1));

    // Mapping observations to indices for easier lookup
    unordered_map<string, int> obsIndex;
    for (int i = 0; i < observations.size(); ++i) {
        obsIndex[observations[i]] = i;
    }

    // Initialization
    for (int s = 0; s < numStates; ++s) {
        dp[s][0] = initialProbabilities[s] * emissionMatrix[s][obsIndex[observedSequence[0]]];
        backpointer[s][0] = 0;
    }

    // Recursion
    for (int t = 1; t < numObservations; ++t) {
        for (int s = 0; s < numStates; ++s) {
            double maxProb = 0;
            int maxState = 0;

            for (int prevS = 0; prevS < numStates; ++prevS) {
                double prob = dp[prevS][t - 1] * transitionMatrix[prevS][s] * emissionMatrix[s][obsIndex[observedSequence[t]]];
                if (prob > maxProb) {
                    maxProb = prob;
                    maxState = prevS;
                }
            }
            dp[s][t] = maxProb;
            backpointer[s][t] = maxState;
        }
    }

    // Termination
    double maxFinalProb = 0;
    int lastState = 0;
    for (int s = 0; s < numStates; ++s) {
        if (dp[s][numObservations - 1] > maxFinalProb) {
            maxFinalProb = dp[s][numObservations - 1];
            lastState = s;
        }
    }

    // Print the probability of the most probable sequence
    cout << "\nProbability of the most probable sequence of states: " 
     << fixed << setprecision(6) << maxFinalProb << endl;


    // Backtracking
    vector<int> bestPath(numObservations);
    int currentState = lastState;
    for (int t = numObservations - 1; t >= 0; --t) {
        bestPath[t] = currentState;
        currentState = backpointer[currentState][t];
    }

    return bestPath;
}

int main() {
    cout << "Welcome to the Hidden Markov Model (HMM) Viterbi Algorithm Simulator!\n";

    // Input number of states and their names
    int numStates;
    cout << "\nEnter the number of states: ";
    cin >> numStates;

    vector<string> states(numStates);
    cout << "Enter the names of the states:\n";
    for (int i = 0; i < numStates; ++i) {
        cout << "State " << i + 1 << ": ";
        cin >> states[i];
    }

    // Input number of observations and their symbols
    int numObservations;
    cout << "\nEnter the number of observation symbols: ";
    cin >> numObservations;

    vector<string> observations(numObservations);
    cout << "Enter the observation symbols:\n";
    for (int i = 0; i < numObservations; ++i) {
        cout << "Symbol " << i + 1 << ": ";
        cin >> observations[i];
    }

    // Input initial probabilities
    vector<double> initialProbabilities(numStates);
    cout << "\nEnter the initial probabilities for each state:\n";
    for (int i = 0; i < numStates; ++i) {
        initialProbabilities[i] = getValidatedInput("Initial probability for " + states[i] + ": ");
    }

    // Input transition probabilities
    vector<vector<double>> transitionMatrix(numStates, vector<double>(numStates));
    cout << "\nEnter the transition probabilities (from each state to each state):\n";
    for (int i = 0; i < numStates; ++i) {
        for (int j = 0; j < numStates; ++j) {
            transitionMatrix[i][j] = getValidatedInput(states[i] + " -> " + states[j] + ": ");
        }
    }

    // Input emission probabilities
    vector<vector<double>> emissionMatrix(numStates, vector<double>(numObservations));
    cout << "\nEnter the emission probabilities (from each state to each observation):\n";
    for (int i = 0; i < numStates; ++i) {
        for (int j = 0; j < numObservations; ++j) {
            emissionMatrix[i][j] = getValidatedInput(states[i] + " emits " + observations[j] + ": ");
        }
    }

    // Input observed sequence
    int sequenceLength;
    cout << "\nEnter the length of the observed sequence: ";
    cin >> sequenceLength;

    vector<string> observedSequence(sequenceLength);
    cout << "Enter the observed sequence (choose from symbols you defined earlier):\n";
    for (int i = 0; i < sequenceLength; ++i) {
        cout << "Observation " << i + 1 << ": ";
        cin >> observedSequence[i];
    }

    // Display inputs
    cout << "\nInputs Summary:\n";
    cout << "States: ";
    for (const auto& state : states) cout << state << " ";
    cout << "\nObservations: ";
    for (const auto& obs : observations) cout << obs << " ";
    cout << "\nObserved Sequence: ";
    for (const auto& obs : observedSequence) cout << obs << " ";
    cout << endl;

    print2DVector(transitionMatrix, "Transition Matrix");
    print2DVector(emissionMatrix, "Emission Matrix");

    // Run Viterbi
    vector<int> bestPath = viterbi(observations, states, transitionMatrix, emissionMatrix, initialProbabilities, observedSequence);

    // Output the result
    cout << "\nMost probable sequence of states:\n";
    for (int stateIdx : bestPath) {
        cout << states[stateIdx] << " ";
    }
    cout << endl;

    cout << "Thank you for using the simulator!\n";
    return 0;
}
