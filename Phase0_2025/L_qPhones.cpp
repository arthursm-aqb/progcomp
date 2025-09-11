/*
The Brazilian Society of Smartphones (SBC) is developing a new model of smartphones that utilizes quantum computing, the qPhones. Unlike traditional devices that store bits, this new architecture will use qubits.

A qubit (quantum bit) is the basic unit of quantum information, just as a bit is in classical computing. However, while a classical bit can only assume one state at a time (0 or 1), a qubit can exist in superposition,
assuming multiple states simultaneously as a "quantum mixture" of 0 and 1, each with a probability of being measured when observed.

Thus, if a device can store qubits, all of its combinations can be represented simultaneously due to superposition. For example, if a device stores 3 qubits, we can have the representation of 23=8
superposed classical states, which are 000, 001, 010, 011, 100, 101, 110, and 111.

In practice, we can assume that to simulate 1 qubit we need 2 bits, to simulate 2 qubits we need 4 bits, to simulate 3 qubits we need 8 bits, and so on. Therefore, to fully simulate the memory of a classical cell phone with Mmegabytes (MB), 
the engineers at SBC need to ensure that the qubits of the new device can represent at least M megabytes. Consider that 1 MB is equivalent to 10^6 bytes.

You have recently been hired by SBC to assist in the production line of the new quantum smartphones. Your task is, given the memory value of M megabytes,
to determine the minimum number of qubits necessary to simulate all possible states of a classical device with that amount of memory.

Input:
An integer M(1≤M≤10^10) representing the amount of memory in MB of a traditional device.

Output:
Output a single line with an integer representing the minimum number of qubits necessary to simulate all possible states of a classical device with M megabytes of memory.
*/

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //The input will be up to 10 billion, so long long int MB gives us plenty of leeway to avoid the danger of overflow.
    long long int MB; cin >> MB;
    //The smallest possible input will be 1, so, as a standard, 23 will be ideal, even to reduce the time in the for loop (a minimal difference, but better than nothing).
    //We multiply MB by 8 million to convert Megabytes to bits.
    int contador{23};
    MB *= 8000000;

    //Here, we will shift the “counter” bit 1 positions and compare if it is still less than the number of states in quobit overlap (MB). Until it is found, 
    //we will increment the “counter” variable, which marks the number of quobits needed to simulate the number of states in MB in quobits.
    for (contador; (1LL << contador)<MB; contador++);
    cout << contador << endl;
    return 0;
}
