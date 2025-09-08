/*
There is a particle at point X=1 on an infinite number line with a charge value of Y. When interacting with the line, it gains unusual properties: by absorbing energy, this particle releases enough kinetic energy to move gcd(X,Y)
steps along the number line, where gcd(X,Y) is the greatest common divisor of X and Y. That is, with each procedure, the particle moves from position X to position X+gcd(X,Y).

Scientists need to energize the particle K times in order to discover new properties about it; however, they need to predict at which point the particle will stop after these procedures so that they can reuse it in future studies.

Therefore, help determine what the final position X will be after the K processes.

Input:
The input consists of a single line with two integers Y(1≤Y≤109) and K(1≤K≤109).

Output:
Print an integer containing the position X where the particle will stop following the above procedures.
*/
