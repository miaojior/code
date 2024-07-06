#include <iostream>
using std::cout; using std::endl; using std::cin;


const int MAX_SIZE = 20;

int main() {
    int rowsA, colsA;
    cin >> rowsA >> colsA;

    int matrixA[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rowsA; ++i)
        for (int j = 0; j < colsA; ++j)
            cin >> matrixA[i][j];

    int rowsB, colsB;
    cin >> rowsB >> colsB;

    int matrixB[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < rowsB; ++i)
        for (int j = 0; j < colsB; ++j)
            cin >> matrixB[i][j];

    int replaceRow, replaceCol;
    cin >> replaceRow >> replaceCol;

    for (int i = 0; i < rowsB; ++i) {
        for (int j = 0; j < colsB; ++j) {
            int targetRow = replaceRow - rowsB  + i;
            int targetCol = replaceCol - colsB  + j;
            if (targetRow >= 0 && targetRow < rowsA && targetCol >= 0 && targetCol < colsA)
                matrixA[targetRow][targetCol] = matrixB[i][j];
        }
    }

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            if (j > 0)
                cout << " ";
            cout << matrixA[i][j];
        }
        cout << endl;
    }

    return 0;
}
