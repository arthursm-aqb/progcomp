#include <iostream>

using namespace std;
int main() {

    std::ios_base::sync_with_stdio(0);
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