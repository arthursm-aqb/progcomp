/*
The SBC (Brazilian Computer Society) is developing various models of architectures for quantum computers, with the goal of making them accessible to everyone in the future.
One of the main challenges faced by the development teams is quantum decoherence, which occurs when a qubit in superposition (simultaneously representing states 0and 1) collapses to 0 or 1due to environmental interference.

For each model developed, the rate of quantum decoherence will be analyzed. To do this, the qubits will be observed in an isolated state and under normal temperature and pressure conditions. 
The rate of quantum decoherence is the ratio between the number of qubits that collapsed under normal temperature and pressure conditions and the number of qubits that were in superposition in the isolated state.

Since there are several models, you have been asked to develop a program that calculates this rate. After all, you need extracurricular hours to graduate, right?!

Input:
The first line contains an integer N(10≤N≤105) indicating the number of qubits in the computer.
The next two lines contain the strings S(isolated state) and T(normal conditions), respectively, each of size N, composed of the characters {0,1,∗}, where ∗indicates a qubit in superposition.

It is guaranteed that: 

At least one qubit is in superposition in S
Every qubit not in superposition in S remains identical in T

Output:
The output should contain the rate of quantum decoherence in decimal form, with exactly two decimal places.
*/

#include <iostream>
#include <format>
 
using namespace std;
int main() {
   
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int N; cin >> N;
    double cN{0.0}, cNN{0.0};
    char S[N], T[N];
    for (size_t i = 0; i < N; i++) cin >> S[i];
    for (size_t i = 0; i < N; i++) cin >> T[i];
    for (size_t i = 0; i < N; i++) {
        if (S[i]=='*') cNN++;
        if (T[i]=='*') cN++;
    }
    double Taxa{(cNN-cN)/cNN};
    cout << format("{:.2f}\n", Taxa);
 
    return 0;
}
