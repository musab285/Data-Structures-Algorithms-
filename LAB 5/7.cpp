// Imagine a 4x4 grid where a person is on a mission to collect as many flags as possible.
// Each cell of the grid represents a potential location for placing a flag. However, there are
// constraints:
// Only one flag can be placed in each row or column.
// Additionally, no two flags can ever be placed on the same diagonal (i.e., no two flags can threaten
// each other diagonally).
// Your goal is to design a backtracking algorithm in C++ to help this person maximize the number of
// flags collected while adhering to these constraints. After implementing the algorithm, provide the
// code and report the maximum number of flags that can be placed on the 4x4 grid.

#include <iostream>
using namespace std;

#define N 4

void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << " " << board[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int board[N][N], int row, int col)
{
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[N][N], int col, int &maxFlags)
{
    if (col >= N)
    {
        int count = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (board[i][j] == 1)
                    count++;
        maxFlags = max(maxFlags, count);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            res = solveNQUtil(board, col + 1, maxFlags) || res;
            board[i][col] = 0;
        }
    }
    res = solveNQUtil(board, col + 1, maxFlags) || res;
    return res;
}

int main()
{
    int board[N][N] = {0};
    int maxFlags = 0;
    solveNQUtil(board, 0, maxFlags);
    cout << "Maximum number of flags that can be placed: " << maxFlags << endl;
    return 0;
}
