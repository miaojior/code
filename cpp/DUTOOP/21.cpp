#include <iostream>
#include <cstring>
using std::cin; using std::cout; using std::endl;

class Island {
private:
    int grid[9][9];
    int n;
    bool isSurroundedByOnes(int x, int y);
public:
    Island(int size);
    void readGrid();
    int calculateIslandArea();
    void outputIslandArea();
};

int main() {
    int n;
    cin >> n;

    Island island(n);
    island.readGrid();
    island.outputIslandArea();

    return 0;
}

bool Island::isSurroundedByOnes(int x, int y) {
    for (int i = x + 1; i < n; i++) {
        if (grid[i][y] == 1) break;
        if (grid[i][y] == 0 && i == n - 1) return false;
    }
    for (int i = x - 1; i >= 0; i--) {
        if (grid[i][y] == 1) break;
        if (grid[i][y] == 0 && i == 0) return false;
    }
    for (int j = y + 1; j < n; j++) {
        if (grid[x][j] == 1) break;
        if (grid[x][j] == 0 && j == n - 1) return false;
    }
    for (int j = y - 1; j >= 0; j--) {
        if (grid[x][j] == 1) break;
        if (grid[x][j] == 0 && j == 0) return false;
    }
    return true;
}

Island::Island(int size) : n(size) {}

void Island::readGrid() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];
}

int Island::calculateIslandArea() {
    int islandArea = 0;
    for (int i = 1; i < n - 1; ++i)
        for (int j = 1; j < n - 1; ++j)
            if (grid[i][j] == 0 && isSurroundedByOnes(i, j))
                ++islandArea;
    return islandArea;
}

void Island::outputIslandArea() {
    cout << calculateIslandArea() << endl;
}