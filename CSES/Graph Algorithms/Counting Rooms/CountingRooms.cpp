#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <random>
#include <chrono>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <utility>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
const char nl = '\n';


void dfs(int r, int c, int ROW, int COL, vector<vector<char>>& grid, vector<vector<int>>& vis) {
    if (r < 0 || c < 0 || r >= ROW || c >= COL || vis[r][c] || grid[r][c] == '#') return;
    
    vis[r][c] = 1;
    dfs(r+1, c, ROW, COL, grid, vis);
    dfs(r-1, c, ROW, COL, grid, vis);
    dfs(r, c+1, ROW, COL, grid, vis);
    dfs(r, c-1, ROW, COL, grid, vis);
    return;
}
void solve() {
    // g++ -std=c++17 CountingRooms.cpp -o CountingRooms && ./CountingRooms < input.txt > output.txt
    int ROW, COL;
    cin >> ROW >> COL;

    vector<vector<char>> grid(ROW, vector<char>(COL, '\0'));
    for (int r = 0; r < ROW; r++) {
        for (int c = 0; c < COL; c++) {
            char ch; cin >> ch;
            grid[r][c] = ch;
        }
    }

    vector<vector<int>> vis(ROW, vector<int>(COL, 0));
    int count = 0;
    for (int r = 0; r < ROW; r++) {
        for (int c = 0; c < COL; c++) {
            if (grid[r][c] == '.' && !vis[r][c]) {
                dfs(r, c, ROW, COL, grid, vis);
                count++;
            }
        }
    }
    cout << count << nl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
