// Imagine you are given a grid representing a maze, where &#39;0&#39;s represent obstacles(red
// highlighted) or walls, and &#39;1&#39;s represent open paths or empty cells. You have two arrays at your
// disposal: an empty Solution array and a maze represented by the following grid:

// Your task is to guide a lion through this maze from the starting point at (0, 0) to reach a piece of
// meat located at the destination point (4, 4). The lion is also not allowed to move diagonally. The lion
// can only move through open paths (&#39;1&#39;s) while avoiding obstacles (&#39;0&#39;s).
// Please provide a C++ code that uses a backtracking algorithm to navigate the maze and move the
// lion to the meat. Additionally, display the contents of the Solution array after the lion has reached
// the meat.

#include <iostream>
using namespace std;

#define N 5
bool isSafe(int maze[N][N], int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1)
    {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y) == true)
    {
        if (sol[x][y] == 1)
            return false;

        sol[x][y] = 1;

        if (solveMazeUtil(maze, x + 1, y, sol) == true)
            return true;

        if (solveMazeUtil(maze, x, y + 1, sol) == true)
            return true;

        if (solveMazeUtil(maze, x - 1, y, sol) == true)
            return true;

        if (solveMazeUtil(maze, x, y - 1, sol) == true)
            return true;

        sol[x][y] = 0;
        return false;
    }

    return false;
}   

bool solveMaze(int maze[N][N])
{
    int sol[N][N] = {0};

    if (solveMazeUtil(maze, 0, 0, sol) == false)
    {
        cout << "Solution doesn't exist";
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
    return true;
}

int main()
{
    int maze[N][N] = {{1, 0, 0, 0, 0},
                      {1, 1, 0, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 1, 0, 1},
                      {0, 0, 1, 1, 1}};

    solveMaze(maze);
    return 0;
}