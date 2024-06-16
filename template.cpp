#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
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

// Main function to solve individual test cases
void solve() {
    // Example: Read number of elements in a vector and the vector itself
    int n;
    cin >> n;
    vi v(n);
    read_vector(v);
    
    // Example processing: Sort the vector and print it
    sort(all(v));
    print_vector(v);
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
