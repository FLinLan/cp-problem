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
    // g++ -std=c++17 template.cpp -o template && ./template < input.txt > output.txt
    vector<pair<char, string>> mp = {{'1',"1101011"}, {'2', "1001011"}, 
                                      {'3' , "1100101"} , {'4' , "1011011"}, {'5' , "1101101"}, 
                                      {'6' , "1001101"}, {'7' , "1010011"}, {'8' , "1101001"}, 
                                      {'9' , "110101"}, {'0', "101011"}, {'-' , "101101"}, {'S' , "1011001"}};


    int n; 
    cin >> n;
   

    for (int i = 0; i < n; i++) {
        int size ;
        cin >> size;
        string codes;
        for (int j = 0; j < size; j++) {
            int pix ;
            cin >> pix;
            if (pix <= 127) {
                codes += '1';
            } else {
                codes += '0';
            }
        }

        // for (auto& ele : codes) {
        //     cout << ele;
        // }
        // cout << endl;

        string ans;
        
        int j = 0;
        int count = 0;
        while (j < size) {
            int match = 0;
            for (auto& ele : mp) {
                bool found = 1;
                int inc = j;
                for (int k = 0; k < ele.second.size(); k++) {
                    if (inc >= size) {
                        found = 0;
                        break;
                    }
                    if (ele.second[k] != codes[inc]) {
                        found = 0;
                        break;
                    } else {
                        inc++;
                    }
                }
                if (found) {
                    // std::cout << "found: " << ele.first << ", index: " << inc << endl;
                    if (count == 0) {
                        if (ele.first != 'S') {
                            continue;
                        }
                    }
                    if (count > 1 && ele.first == 'S' && inc != size) {
                        break;
                    } 
                    if (inc == size) {
                        if (ele.first != 'S') {
                            break;
                        }
                    }
                    if (ele.first != 'S')
                        ans.push_back(ele.first);
                    j = inc;
                    match = 1;
                    count++;
                    break;
                }
            }
            if (!match) {
                ans = "INVALID";
                break;
            } else {
                if (j < size && codes[j] != '0') {
                    ans = "INVALID";
                    break;
                }
                j++;
            }
        }

        if (ans.empty()) {
            ans = "INVALID";
        }
        std::cout << ans << std::endl;
        
    }
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
