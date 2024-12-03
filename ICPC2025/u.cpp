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
#include <unordered_set>
#include <unordered_map>

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


void solve() {
    // g++ -std=c++17 u.cpp -o u && ./u < input.txt > output.txt
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    vector<int> orig;
    for (int i = 0; i < n; i++) {
        orig.push_back(i+1);
    }

    int moves = 0;

    vector<int> rule(n, 0);
    for (int i = 0; i < n; i++) {
        int index = orig[i];
        
        rule.push_back()
    }

    while (1) {
        // if nums == orig break;
        
        moves++;
    }
    cout << moves << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}