// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

// Example 1:

// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1}, 
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output:
// DDRDRR DRDDRR
// Explanation:
// The rat can reach the destination at 
// (3, 3) from (0, 0) by two paths - DRDDRR 
// and DDRDRR, when printed in sorted order 
// we get DDRDRR DRDDRR.
// Example 2:
// Input:
// N = 2
// m[][] = {{1, 0},
//          {1, 0}}
// Output:
// -1
// Explanation:
// No path exists and destination cell is 
// blocked.
// Your Task:  
// You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order. 
// Note: In case of no path, return an empty list. The driver will output "-1" automatically.

// Expected Time Complexity: O((3N^2)).
// Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

// Constraints:
// 2 ≤ N ≤ 5
// 0 ≤ m[i][j] ≤ 1



#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void printSol(vector<string> ans)
{
    int n = ans.size();
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}
bool validCall(vector<vector<int>> &m, int &n, int a, int b, vector<vector<int>> &visited)
{
    if ((a >= 0 && a < n) && (b >= 0 && b < n) && (visited[a][b] == 0) && (m[a][b] == 1))
        return true;
    return false;
}
void solve(vector<vector<int>> &m, int a, int b, int &n, vector<string> &ans, string &path, vector<vector<int>> &visited)
{
    if (a == n - 1 && b == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[a][b] = 1;

    int newx = a + 1;
    int newy = b;
    if (validCall(m, n, newx, newy, visited))
    {
        path.push_back('D');
        solve(m, newx, newy, n, ans, path, visited);
        path.pop_back();
    }

    newx = a;
    newy = b - 1;
    if (validCall(m, n, newx, newy, visited))
    {
        path.push_back('L');
        solve(m, newx, newy, n, ans, path, visited);
        path.pop_back();
    }

    newx = a;
    newy = b + 1;
    if (validCall(m, n, newx, newy, visited))
    {
        path.push_back('R');
        solve(m, newx, newy, n, ans, path, visited);
        path.pop_back();
    }

    newx = a - 1;
    newy = b;
    if (validCall(m, n, newx, newy, visited))
    {
        path.push_back('U');
        solve(m, newx, newy, n, ans, path, visited);
        path.pop_back();
    }

    visited[a][b] = 0;
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    string path;
    vector<string> ans;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    if (m[0][0] == 0)
        return ans;
    solve(m, 0, 0, n, ans, path, visited);
    return ans;
}
int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {1, 1, 1, 1}};
    vector<string> ans = findPath(maze, 4);
    printSol(ans);
    return 0;
}