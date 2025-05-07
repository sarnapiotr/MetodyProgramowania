#include <iostream>

void printBoard(bool** board, const int& count) {
    static int solutionCount{ 1 };
    std::cout << "Rozwiazanie " << solutionCount++ << std::endl;

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (board[i][j]) {
                std::cout << "X ";
            }
            else {
                std::cout << "O ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool isSafe(bool** board, const int& row, const int& col, const int& count) {
    for (int i = 0; i < row; i++) {
        if (board[i][col]) {
            return false;
        }

        for (int j = 0; j < count; j++) {
            if (board[i][j] && std::abs(row - i) == std::abs(col - j)) {
                return false;
            }
        }
    }

    return true;
}

void solveQueens(bool** board, int row, const int& count) {
    if (row == count) {
        printBoard(board, count);
        return;
    }

    for (int col = 0; col < count; col++) {
        if (isSafe(board, row, col, count)) {
            board[row][col] = true;
            solveQueens(board, row + 1, count);
            board[row][col] = false;
        }
    }
}

void nQueenProblem(const int& count) {
    bool** board = new bool*[count];
    for (int i = 0; i < count; i++) {
        board[i] = new bool[count] {false};
    }

    solveQueens(board, 0, count);

    for (int i = 0; i < count; i++) {
        delete[] board[i];
    }
    delete[] board;
}

int main()
{
    std::cout << "Algorytmy z nawrotami\n";
    std::cout << "Podaj liczbe figur: \n";

    int count{0};
    std::cin >> count;

    nQueenProblem(count);

    return 0;
}
