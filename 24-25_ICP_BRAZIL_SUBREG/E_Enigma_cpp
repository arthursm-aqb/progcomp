/*

The princess of Nlogonia keeps her pearl collection in a square jewelry case made up of N
 columns, each column containing N
 small boxes. She places a different number of pearls in each box, and arranges the box so that in each column, from top to bottom, the boxes contain an increasing number of pearls and in each row, from left to right, the boxes also contain an increasing number of pearls.

The princess suspects that her little sister, who is very mischievous, is messing with her things in her games. In particular, the princess suspects that her jewelry case has been rotated 90 degrees clockwise, possibly multiple times.

Figure (a) below shows an example of the original arrangement of a 4×4
 case. Figure (b) shows the case rotated clockwise, 90 degrees, once.

Given the number of pearls in each box, write a program to determine the smallest number of 90-degree counterclockwise rotations that are necessary to return the jewelry case to its original state.

Input
The first line of the input contains an integer N, the number of rows and columns in the case (2≤N≤50). Each of the following Nlines contains Nintegers Ki,j, the number of pearls in the box in row i and column j (0≤Ki,j≤105, for 1≤i≤N and 1≤j≤N). 
In the input, the rows are given from top to bottom, and the columns are given from left to right.

Output
Your program should output a single line containing only one integer R
(which can be 0, 1, 2, or 3), the smallest number of times the jewelry case must be rotated counterclockwise to return to its original state.

*/

#include <iostream>
#include <vector>

using namespace std;
int n;

/*Function to check if the matrix is sorted in ascending order in rows and columns. If so, it returns true; if it finds the first occurrence of unsorted data, it returns false.*/
bool check(const vector<vector<int>>& m) {
    for (size_t i = 0; i+1 < n; i++) {
        for (size_t j = 0; j+1 < n; j++) {
            if (m[i][j]>=m[i+1][j] || m[i][j] >= m[i][j+1]) {
                return false;
            }
        }
    }
    return true;
}

/*Function that rotates the matrix 90 degrees counterclockwise. It uses a temporary matrix to store the rotation values of the matrix and, at the end, copies them to the main matrix.*/
void spin(vector<vector<int>>& m) {
    vector<vector<int>> temp(n, vector<int>(n,0));
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++){
            temp[(n-1)-j][i] = m[i][j];
        }
    }

    m = temp;
}


int main() {

    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for (auto& linha : m) {
        for (auto& coluna: linha) {
            cin >> coluna;
        }
    }

    int res{0};

/*If it is not sorted, this instruction is repeated and the res variable is iterated.*/
    while (!check(m)) {

        spin(m);
        res++;
    }

    cout << res << endl;
    return 0;
}
