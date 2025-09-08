/*
In the year 1935, physicist Erwin Schrödinger received a mysterious package labeled only as "Box 42." Inside, a bizarre quantum experiment was set up by a group of eccentric scientists. 
The box contains a cat, a vial of poison activated by an unstable radioactive atom, and a note beside it with a single instruction: "Do not open unless you are ready to accept a single truth."

According to quantum physics, while the box is closed, it is impossible to determine the state of the cat. The entire system is in a quantum superposition: the cat is both alive and dead simultaneously.
However, if someone has the courage to open the box, the superposition collapses, revealing whether the cat is indeed alive or dead.

You, as an apprentice of the old Schrödinger, have found records with the state of the box and the internal reading of the state of the cat; these are privileged information that is not observable to anyone who has not opened the box.
Your mission is to determine the observable state of the cat at the described moment.

Input:
The only line of input contains two integers C and G(0≤C,G≤1). C=1 indicates that the box is closed, and C=0 indicates that it is open. G=1 indicates that the cat is alive, and G=0 indicates that the cat is dead.

Output:
Print a single string, "vivo e morto" if it is not possible to know the state of the cat, "vivo" if it is possible to determine that the cat is alive, or "morto" if it is possible to determine that the cat is dead.
*/

#include <iostream>

using namespace std;
int main() {

    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int C, G; cin >> C >> G;
    switch (C) {
        case 0:
            if (G) cout << "vivo\n";
            else cout << "morto";
            break;
        case 1:
            cout << "vivo e morto\n";
    }

    return 0;
}

