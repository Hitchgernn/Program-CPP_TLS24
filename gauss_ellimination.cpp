//CASE : MATRIX NON-SINGULAR
#include <bits/stdc++.h>
#define ll long long
using namespace std;

double matrix[5][5];

//fungsi pembuat upper triangle matrix
void gauss_ellimination(int row, int column) {
    if (column == 1) {
        double l = matrix[row][column]/matrix[1][1];
        for (int i = 1; i <= 4; i++) {
            matrix[row][i] = matrix[row][i] - l*matrix[1][i];
        }
    } else {
        double l = matrix[row][column]/matrix[2][2];
        for (int i = 2; i <= 4; i++) {
            matrix[row][i] = matrix[row][i] - l*matrix[2][i];
        }
    }
}    

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 1; i <= 3; i++) {
        cout << "Masukkan baris matrix ke " << i << ":" << endl;
        for (int j = 1; j <= 4; j++) {
            cin >> matrix[i][j];
        }
    }

    //membuat upper triangle matrix
    if (matrix[2][1] != 0) {
        gauss_ellimination(2, 1);
    }
    if (matrix[3][1] != 0) {
        gauss_ellimination(3, 1);
    }
    if (matrix[3][2] != 0) {
        gauss_ellimination(3, 2);
    }
    
    //mensubtitusi upper triangle matrix
    int z = matrix[3][4]/matrix[3][3];
    int y = (matrix[2][4] - z*matrix[2][3])/matrix[2][2];
    int x = (matrix[1][4] - z*matrix[1][3] - y*matrix[1][2])/matrix[1][1];

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    
    return 0;
}