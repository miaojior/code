#include <iostream>
#include <queue>
#include <cstring>
using std::cin; using std::cout; using std::endl;
using std::queue;

struct Point {
    int x, y;
};

class Island {
private:
    int n;
    int matrix[9][9];
    bool visited[9][9];
    bool isSurrounded(int x, int y);
public:
    Island(int size);
    void outputResult();
};

int main() {
    int size;
    cin >> size;
    Island island(size);
    island.outputResult();
    return 0;
}

Island::Island(int size) : n(size){
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];
    memset(visited, false, sizeof(visited));
}

bool Island::isSurrounded(int x, int y) {
    queue<Point> q;
    q.push({x, y});
    visited[x][y] = true;
    bool surrounded = true;
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (!q.empty()){
        Point current = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = current.x + dirs[i][0];
            int ny = current.y + dirs[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (!visited[nx][ny] && matrix[nx][ny] == 0) {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
            }else{
                surrounded = false;
            }
        }
    }
    return surrounded;
}

void Island::outputResult(){
    int area = 0;
    for (int i = 1; i < n - 1; ++i) 
        for (int j = 1; j < n - 1; ++j) 
            if (matrix[i][j] == 0 && !visited[i][j]) 
                if (isSurrounded(i, j)) 
                    area++;
    cout << area << endl;
}
