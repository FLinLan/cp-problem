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

// Main function to solve individual test cases
void solve() {
    string a, b;
    cin >> a >> b;

    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;

    cout << a << " " << b << '\n';
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
