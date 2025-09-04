#include <iostream>

using namespace std;

int main(){
    // We create a vector to serve as a ‘warehouse’, storing the total count of ‘1’ bits for each position.
    // The problem states that the maximum input value is 1 billion (10^9).
    // Since 2^29 is ~537 million and 2^30 is ~1.07 billion, 30 counters are needed (for bits 0 to 29).
    int aBits[30]{0}, n; cin >> n;
    for(size_t i = 0; i < n; i++) {
        int valor; cin >> valor;
    //Upon receiving the user's value, we enter a nested loop with the condition that the current value is not less than the tested bit position. For example:
    //31 goes up to bit position 5, so we can store bits of it in aBits up to position 5, so it would not make sense for the for loop to continue, and it would be a waste of performance.
        for (size_t j = 0; (1<<j)<=valor; j++) {
            aBits[j]+= ((1<<j)&valor)? 1 : 0;
        }
    }

    //Here is the main point of this solution: assembling the values. The problem asks for a lexicographically maximum sequence, that is, a sequence with the largest possible numbers assembled with the available bits of the values given by the user.
    //For this reason, we collect the bits in the previous loop. In this sense, by having a stock of bits from the collected numbers, we can assemble the largest possible number a1, then the largest possible number a2 with the remaining bits, and so on.
    //Then we declare a variable num that will be responsible for assembling the aN and then printed to move on to the next assembled number.
    //Within the second for, we go through the 29 positions and if there are any bits left over, then we do an OR operation with bit 1 shifted j positions and decrement the number of bits from the current position in aBits.
    //This process repeats until there are no more bits left to assemble another number.
    int num;
    for(size_t i = 0; i < n; i++) {
        num = 0;
        for (size_t j = 0; j<30; j++) {
            if(aBits[j]>0) {
                num|= 1 << j;
                aBits[j]--;
            }
        }

        cout << num << (i==n-1 ? "\n" : " ");
    }

    return 0;
}
