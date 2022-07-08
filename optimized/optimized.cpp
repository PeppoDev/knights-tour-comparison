// C++ program for Knight Tour problem
#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

int const N = 32; 
int const origin[2] = {0, 0}; 
      // Move pattern on basis of the change of
// x coordinates and y coordinates respectively
static int cx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
static int cy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

int iteraction = 0;

// function restricts the knight to remain within
// the 8x8 chessboard
bool limits(int x, int y)
{
    return ((x >= 0 && y >= 0) && (x < N && y < N));
}

/* Checks whether a square is valid and empty or not */
bool isempty(int a[], int x, int y)
{
    return (limits(x, y)) && (a[y * N + x] < 0);
}

/* Returns the number of empty squares adjacent
   to (x, y) */
int getDegree(int a[], int x, int y)
{
    int count = 0;
    for (int i = 0; i < N; ++i)
        if (isempty(a, (x + cx[i]), (y + cy[i])))
            count++;

    return count;
}

// Picks next point using Warnsdorff's heuristic.
// Returns false if it is not possible to pick
// next point.
bool nextMove(int a[], int *x, int *y)
{
    int min_deg_idx = -1, c, min_deg = (N + 1), nx, ny;

    // Try all N adjacent of (*x, *y) starting
    // from a random adjacent. Find the adjacent
    // with minimum degree.
    int start = rand() % N;
    for (int count = 0; count < N; ++count)
    {
        int i = (start + count) % N;
        nx = *x + cx[i];
        ny = *y + cy[i];
        if ((isempty(a, nx, ny)) &&
            (c = getDegree(a, nx, ny)) < min_deg)
        {
            min_deg_idx = i;
            min_deg = c;
        }
    }

    // IF we could not find a next cell
    if (min_deg_idx == -1)
        return false;

    // Store coordinates of next point
    nx = *x + cx[min_deg_idx];
    ny = *y + cy[min_deg_idx];

    // Mark next move
    a[ny * N + nx] = a[(*y) * N + (*x)] + 1;

    // Update next point
    *x = nx;
    *y = ny;

    return true;
}

/* displays the chessboard with all the
  legal knight's moves */
void print(int a[])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            printf("%d\t", a[j * N + i]);
        printf("\n");
    }
}

/* checks its neighbouring squares */
/* If the knight ends on a square that is one
   knight's move from the beginning square,
   then tour is closed */
bool neighbour(int x, int y, int xx, int yy)
{
    for (int i = 0; i < N; ++i)
        if (((x + cx[i]) == xx) && ((y + cy[i]) == yy))
            return true;

    return false;
}

/* Generates the legal moves using warnsdorff's
  heuristics. Returns false if not possible */
bool findClosedTour()
{
    // Filling up the chessboard matrix with -1's
    int a[N * N];
    for (int i = 0; i < N * N; ++i)
        a[i] = -1;

    // Random initial position
    int sx = origin[0];
    int sy = origin[1];

    // Current points are same as initial points
    int x = sx, y = sy;
    a[y * N + x] = 1; // Mark first move.

    // Keep picking next points using
    // Warnsdorff's heuristic
    for (int i = 0; i < N * N - 1; ++i)
        if (nextMove(a, &x, &y) == 0)
            return false;

    // Check if tour is closed (Can end
    // at starting point)
    if (!neighbour(x, y, sx, sy))
        return false;

    print(a);
    return true;
}

// Driver code
int main()
{

    auto start = std::chrono::system_clock::now();

    // int result = 0;

    cout << "_________________________________" << endl;
    cout << "Alogrithm: "
         << "Optimized" << endl;

    cout << "N: " << N << endl;
    cout << "Origin: " << endl;
    cout << "  X: " << origin[0] << endl;
    cout << "  y: " << origin[1] << endl;
    cout << endl;
    cout << endl;

    while (!findClosedTour())
    {
        iteraction++;
    }

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