#include <iostream>
using std::cin; using std::cout; using std::endl;

class FiveInARow {
private:
    int board[19][19];
    int winner;
    int win_x, win_y;
    bool checkLine(int x, int y, int dx, int dy);
public:
    FiveInARow();
    void readBoard();
    void findWinner();
    void outputResult();
};

int main() {
    FiveInARow game;
    game.readBoard();
    game.findWinner();
    game.outputResult();
    return 0;
}

bool FiveInARow::checkLine(int x, int y, int dx, int dy){
    int color = board[x][y];
    if (color == 0) 
        return false;
    for (int k = 1; k < 5; ++k) {
        int nx = x + k * dx;
        int ny = y + k * dy;
        if (nx < 0 || nx >= 19 || ny < 0 || ny >= 19 || board[nx][ny] != color)
            return false;
    }
    winner = color;
    win_x = x;
    win_y = y;
    return true;
}

FiveInARow::FiveInARow(){
    winner = 0;
    win_x = win_y = -1;
}

void FiveInARow::readBoard() {
    for (int i = 0; i < 19; ++i)
        for (int j = 0; j < 19; ++j)
            cin >> board[i][j];
}

void FiveInARow::findWinner() {
    for (int i = 0; i < 19; ++i) 
        for (int j = 0; j < 19; ++j) 
            if (checkLine(i, j, 0, 1) || checkLine(i, j, 1, 0) || 
                checkLine(i, j, 1, 1) || checkLine(i, j, 1, -1))
                return;
}

void FiveInARow::outputResult() {
    if (winner == 0)
        cout << "No" << endl;
    else 
        cout << winner << ":" << win_x + 1 << "," << win_y + 1 << endl;
}