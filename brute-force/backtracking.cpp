// C++ program for Knight Tour problem
#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

int const N = 8;
int const origin[2] = {0, 0};

int iteraction = 0;

int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[], int yMove[]);

/* A utility function to check if i,j are
valid indexes for N*N chessboard */
int isSafe(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

/* A utility function to print
solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            cout << " " << setw(2) << sol[x][y] << " ";
        cout << endl;
    }
}

/* This function solves the Knight Tour problem using
Backtracking. This function mainly uses solveKTUtil()
to solve the problem. It returns false if no complete
tour is possible, otherwise return true and prints the
tour.
Please note that there may be more than one solutions,
this function prints one of the feasible solutions. */
int solveKT()
{
    int sol[N][N];

    /* Initialization of solution matrix */
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;

    /* xMove[] and yMove[] define next move of Knight.
    xMove[] is for next value of x coordinate
    yMove[] is for next value of y coordinate */
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    // Since the Knight is initially at the first block
    sol[origin[0]][origin[1]] = 0;

    /* Start from 0,0 and explore all tours using
    solveKTUtil() */
    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0)
    {
        // cout << "Solution does not exist" << endl;
        return 0;
    }
    else
    {
        printSolution(sol);
        return 1;
    }
}

/* A recursive utility function to solve Knight Tour
problem */
int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[8], int yMove[8])
{
    iteraction++;

    int k, next_x, next_y;
    if (movei == N * N)
        return 1;

    /* Try all next moves from
    the current coordinate x, y */
    for (k = 0; k < 8; k++)
    {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol))
        {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, sol,
                            xMove, yMove) == 1)
                return 1;
            else

                // backtracking
                sol[next_x][next_y] = -1;
        }
    }
    return 0;
}

// Driver Code
int main()
{
    // Function Call
    auto start = std::chrono::system_clock::now();

    int result = 0;

    cout << "_________________________________" << endl;
    cout << "Alogrithm: "
         << "Backtracking" << endl;

    cout << "N: " << N << endl;
    cout << "Origin: " << endl;
    cout << "  X: " << origin[0] << endl;
    cout << "  y: " << origin[1] << endl;
    cout << endl;
    cout << endl;

    solveKT();

    cout << "Iteraction: " << iteraction << endl;

    // if (result == 1)
    //     cout << "Status: success" << endl;
    // else
    //     cout << "Status: failure" << endl;

    auto end = std::chrono::system_clock::now();

    int elapsed_micros = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    int elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::time_t start_time = std::chrono::system_clock::to_time_t(start);

    std::cout << "started computation at " << std::ctime(&start_time)
              << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_ms << "ms "
              << "elapsed time: " << elapsed_micros << "µs " << std::endl;

    cout << endl;
    cout << endl;

    return 0;
}
