#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <random>
#include <chrono>
#include <cmath>
#include <string>
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

void backtrack(int i, ll sum1, ll sum2, vector<ll>& nums, ll& mini) {
    if (i >= nums.size()) {
        mini = min(mini, abs(sum1 - sum2));
        return;
    }
    backtrack(i+1, sum1 + nums[i], sum2, nums, mini);
    backtrack(i+1, sum1, sum2 + nums[i], nums, mini);
    return;
}

void solve() {
    // g++ -std=c++17 AppleDivision.cpp -o AppleDivision && ./AppleDivision < input.txt > output.txt
    int n; cin >> n;
    vector<ll> nums;
    for (int i = 0; i < n; i++) {
        ll val; cin >> val;
        nums.push_back(val);
    }
    ll mini = INF;
    backtrack(0, 0, 0, nums, mini);
    cout << mini << nl;
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
