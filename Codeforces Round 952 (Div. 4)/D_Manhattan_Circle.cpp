#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <limits>
#include <numeric>
#include <cstring>  // For memset
#include <climits> // For INT_MAX, INT_MIN

using namespace std;

// For fast input and output
#define fast_io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// Shortcuts for commonly used types
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

// Constants
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

// Macros for convenience
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)

// Utility functions
template <typename T>
void print_vector(const vector<T>& v) {
    for (const auto& elem : v) {
        cout << elem << ' ';
    }
    cout << '\n';
}

template <typename T>
void read_vector(vector<T>& v) {
    for (auto& elem : v) {
        cin >> elem;
    }
}

// Utility function to read a grid 
template <typename T>
void read_grid(vector<vector<T>>& grid, int h, int w) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }
}

// Utility function to print a grid
template <typename T>
void print_grid(const vector<vector<T>>& grid, int h, int w) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
}

int dfs(int r, int c , int ROWS, int COLS, vector<vector<char>>& grid) {
    if (r == ROWS || c == COLS || r < 0 || c < 0) return 0;
    if (grid[r][c] == '.') return 0;

    int down = dfs(r-1, c, ROWS, COLS, grid);
    int left = dfs(r, c-1, ROWS, COLS, grid);
    int up = dfs(r+1, c, ROWS, COLS, grid);
    int right = dfs(r, c+1, ROWS, COLS, grid);

    return 1 + up + down + left + right;
}

// Main function to solve individual test cases
void solve() {
    // Example: Read number of elements in a vector and the vector itself
    int n, m;
    cin >> n >> m;

    // dfs brute force algorithm O (N * M * 4^n)
    // getting the maximum value
    vector<vector<char>> grid(n, vector<char>(m));
    read_grid(grid, n, m);

    int ROWS = grid.size(), COLS = grid[0].size();
    int max_val = INT_MIN;
    int x = 0, y = 0;

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            int val = dfs(r, c, ROWS, COLS, grid);
            if (val > max_val) {
                max_val = max(val, max_val);
                x = r;
                y = c;
            }
        }
    }

    cout << x+1 << " " << y+1 << '\n';
}

int main() {
    fast_io;

    int t;  
    cin >> t; // Read number of test cases

    while (t--) {
        solve();
    }

    return 0;
}
