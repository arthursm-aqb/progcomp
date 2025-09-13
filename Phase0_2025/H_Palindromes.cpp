/*
Several quantum alternatives to traditional algorithms have been researched to solve a variety of problems. Using quantum logic gates, it is possible to gain performance in some specific types of tasks,
leading to improvements, for example, in number factorization algorithms and data set searches.

Shor is working on a quantum algorithm for recognizing palindromes in binary sequences. To do this, he needs to generate a large number of examples,
and he decided that he would need to know for a given positive integer X, what the largest integer Y less than or equal to X would be, whose binary representation is palindromic.

Shor has a lot of experience with quantum algorithms, but he is having difficulty creating a classical algorithm that solves this problem. Can you help?

Input:
The only line of input contains the integer X(1≤X≤10^18).

Output:
Output a single line with the corresponding integer Y.
*/

#include <iostream>

// The problem states the input X can be up to 10^18. A standard integer cannot hold this value.
// A long long int is used because its range (up to 10^18) is sufficient.
#define lli long long int

using namespace std;

//This function finds the largest binary palindrome 'Y' such that Y <= X.

//Since the input can be as large as 10^18 (quintillions), a brute-force approach (checking X, X-1, X-2...) is not feasible.
//This is because for large numbers, binary palindromes are very sparse (far apart), requiring too many checks.

//Therefore, the strategy is to abandon a search-based method and instead directly construct the answer.

//First, we handle a special edge case: numbers that ARE powers of two (e.g., 4, 8, 16...).
//For an X that is a power of two (8, binary '1000'), it's impossible to form a palindrome
//with the same number of bits that is <= X (the smallest would be '1001', or 9).
//Thus, the answer must have one less bit. The largest palindrome with one less bit is always
//The preceding number (X-1), which is composed entirely of '1's (7, binary '111').

//For numbers that are NOT powers of two, the largest palindrome Y <= X will most likely have the same number of bits as X.
//The strategy is as follows:
//1. Start with the most basic possible palindrome that has the same number of bits as X.
//2. Iterate through the symmetric pairs of bits.
//3. For each pair, test: "If I turn these two bits on (set them to '1'), does the resulting number exceed X?"
//4. If it does not exceed X, we commit to this decision and add the bits to our answer. If it does, we leave them as '0'.

//The final number resulting from this construction process will be the desired palindrome.

lli Palindromo(lli x) {
    //Base case
    if (x == 1) return 1;

    size_t posicao;
    //This loop finds the position of the Most Significant Bit of x and stores it in posicao.
    //This will be used to construct the base palindrome if needed.
    for (posicao = 0; (1LL << (posicao + 1)) <= x; posicao++);

    //Another edge case: if x is a power of 2, we return x-1.
    if (x == (1LL << posicao)) return x - 1;

    //If execution reaches this point, X is neither 1 nor a power of two.
    //We form a simple palindrome with the same number of bits as x and then
    //test increments at symmetric bit positions.
    //Example: If x is 11 (binary '1011'), it has 4 bits. The simple palindrome is formed by shifting a '1' bit
    //y 3 positions (1 -> '1000') and adding 1, resulting in '1001' (9).
    //Now we will try to form a larger palindrome by setting symmetric bits.
    //In this example, the symmetric positions are bits 2 and 1. If setting them results in a number
    //greater than 11 (like '1111' = 15), then the only possible answer is the base palindrome we formed: 9.
    lli resposta = (1LL << posicao) + 1;
    for (size_t i = posicao - 1; i >= posicao - i; i--) {
        //Create a value representing the bit on the left-hand side of the center.
        //It is important to form symmetrical numbers since they remain the same when written backwards.
        lli aux{(1LL << i)};

        //If 'i' is not the center bit (i.e., it has a pair), add its symmetric counterpart to the value.
        if (i > posicao - i) aux += (1LL << (posicao - i));
        
        //If adding the symmetric pair to our current answer does not exceed x, we commit to it.
        //Otherwise, we continue the process, checking all symmetric positions once.
        if (resposta + aux <= x) resposta += aux;
    }

    return resposta;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli x;
    cin >> x;
    cout << Palindromo(x) << endl;
    return 0;
}
