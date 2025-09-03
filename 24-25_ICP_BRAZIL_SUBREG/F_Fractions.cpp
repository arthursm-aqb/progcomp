/*
Little Charles was one of the best competitive programmers in the world. However, he never really liked programming. Now that he is retired, he can dedicate his studies to what he really loves: continued fractions.

To prepare for the upcoming Imensa Competição de Phrações Contínuas (ICPC), he needs to solve the following problem:

Define p0=1 as the level 0 fraction. Then define: p1 = 1/1+1, as the level 1 fraction, p1. And also, p2 = 1/1+(1/1+1) as the level 2 fraction, p2, and so on.

Given an integer value N, help Charles determine the value of the numerator of the fraction pN.

Input
The first and only line contains an integer N (1≤N≤40).

Output
The value pN can be written as a fraction of the form a/b, where a and b are coprime. Print a line containing the value of a.
*/

#include <iostream>

using namespace std;

/*
Given the examples, we can see that the formula for the continued fraction N is p(n) = 1/1+p(n-1). If P(n-1) = a/b, then P(n) = 1/1+(a/b). When solving this expression,
we arrive at P(n) = b/b+a, that is, the numerator is the previous denominator and the denominator is the sum of the previous numerator and denominator.

We can apply this formula with a for loop that goes up to n-1, since we represent p0 with the variables a = 1 and b = 1.
Inside the for loop, we hold the value of a (numerator) with aux, assign the denominator to the numerator, then add b (denominator) to aux (numerator value).
*/

int main() {
    int n, a{1}, b{1}; cin >> n;
    for (size_t i = 0; i < n; i++) {
        int aux{a};
        a = b;
        b+= aux;
    }
  
    cout << a << endl;
    return 0;
}
