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


/*

[2,3,6,7]
target - nums[i]
0 + nums[i]
[2,2,2,2] target 7 

*/
void backtrack(vector<int>& nums, set<vector<int>>& ans, vector<int>& path, int target) {
    if (target < 0) return; 
    if (target == 0) {
        vector<int> vec(path.begin(), path.end());
        sort(vec.begin(), vec.end());
        ans.insert(vec);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        path.push_back(nums[i]);
        backtrack(nums, ans, path, target - nums[i]);
        path.pop_back();
    }
    return;
}


void solve() {
    // g++ -std=c++17 CombinationSum.cpp -o CombinationSum && ./CombinationSum < input.txt > output.txt
    
    // input:
    vector<int> nums = {2, 3, 6, 7}; 
    int target = 7;
    
    // ouptut:
    set<vector<int>> ans;
    vector<int> path;
    backtrack(nums, ans, path, target); // backtracking funciton.
    
    for (auto& vec : ans) {
        cout << "[";
        for (auto n : vec) {
            cout << n << ",";
        }
        cout << "],";
    }
    cout << '\n';
    return;
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

