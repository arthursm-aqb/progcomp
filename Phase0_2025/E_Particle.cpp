/*
There is a particle at point X=1 on an infinite number line with a charge value of Y. When interacting with the line, it gains unusual properties: by absorbing energy, this particle releases enough kinetic energy to move gcd(X,Y)
steps along the number line, where gcd(X,Y) is the greatest common divisor of X and Y. That is, with each procedure, the particle moves from position X to position X+gcd(X,Y).

Scientists need to energize the particle K times in order to discover new properties about it; however, they need to predict at which point the particle will stop after these procedures so that they can reuse it in future studies.

Therefore, help determine what the final position X will be after the K processes.

Input:
The input consists of a single line with two integers Y(1≤Y≤10^9) and K(1≤K≤10^9).

Output:
Print an integer containing the position X where the particle will stop following the above procedures.
*/

#include <iostream>
#include <vector>


using namespace std;


int main() {

    //Since K can be 10^9, we cannot adopt the normal strategy of calculating the gcd K times, as this will betoo slow. To solve this problem, we have to find a way to solve X = old_X + gcd(old_X,Y) in advance.
    //When calculating the GCD manually, we realize that at some point the GCD will be equal to Y, and if there are K steps remaining, the growth will be linear X = X+gcd*K. 
    //Therefore, we can adopt a strategy: incorporate the prime factors of Y into the GCD so that the GCD grows as fast as possible to Y or close to it with the given K.
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int Y, K; cin >> Y >> K;

    vector<int> p;

    //So, after receiving the data from Y and K, we create a vector p that will store the prime factors of Y.
    //In the following for loop, we will store the prime factors in p in ascending order, and if there is still a value left in Y (Y>1), it will be the largest prime, subsequently also stored in p.


    for (int i = 2; i*i <= Y; i++) {
        while (Y%i==0) {
            p.push_back(i);
            Y/=i;
        }
    }

    if (Y>1) {
        p.push_back(Y);
    }

    //The next step is to calculate X = X + gcd(X,Y). We create a long long int (to avoid overflow) response and initialize it with 1, then scan the vector p using an interval-based for loop.
    //This will be necessary for the growth of X. The strategy here is as follows: at the beginning, gcd(1, Y) will be 1 until X reaches a prime factor of Y. Thus, gcd(X,Y) would be P1 (a prime factor of Y) and X would grow by X+P1. 
    //If there are K steps remaining, there may come a time when the gcd will be P2, P3,.. ...Pn, or even Y. Based on this, the cost to reach Pn is Pn-1. 
    //For example, (1, 20), the first prime factor of 20 is 2, so the gcd will incorporate 2 after the first gcd calculation, so 2-1 = 1 step. 
    //This way, we can use a strategy where each time a prime factor is incorporated, we reduce K by Pn-1 until we reach the gcd Y. Then, in the first if, we check if we have enough steps to reduce Pn-1. 
    //If so, we incorporate the prime into the GCD, deduct Pn-1 from K, and skip to the next prime. Otherwise, the GCD is already the maximum possible. Finally, we calculate X + gcd(X,Y)*k, which is equivalent to resp * (k+1).
  


    long long int resp = 1;
    for (auto primos: p) {
        if (K>primos-1) {
            resp*=primos;
            K-= primos-1;
        }
        else {
            resp *= K+1;
            K = 0;
            break;
        }
    }
  
    //When exiting this for loop, it may happen that we never enter the else clause, since the steps were sufficient to incorporate all the primes, leaving K remaining.
    //Thus, we calculate resp * (k+1) again, and it is guaranteed to always work, because if we entered the else, the last resp * (k-1) will be resp * 1.
  
    resp*=K+1;
    cout << resp << endl;

    return 0;
}
