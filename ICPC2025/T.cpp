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

#define ll long long

// Parse duration in days, hours, minutes format
ll parseTime(const string& s) {
    ll days = 0, hours = 0, mins = 0;
    string curr = "";
    for (char c : s) {
        if (isdigit(c)) {
            curr += c;
        } else if (c == 'd') {
            days = stoll(curr);
            curr = "";
        } else if (c == 'h') {
            hours = stoll(curr);
            curr = "";
        } else if (c == 'm') {
            mins = stoll(curr);
            curr = "";
        }
    }
    if (curr != "") mins = stoll(curr);
    return days * 24 * 60 + hours * 60 + mins;
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    const ll MIN_IN_HOUR = 60;
    const ll MIN_IN_DAY = 24 * 60;
    
    ll min_rate, hour_rate, day_rate;
    
    // Read pricing tiers
    for(int i = 0; i < n; i++) {
        string duration;
        ll price;
        cin >> duration >> price;
        if(duration == "1m") min_rate = price;
        else if(duration == "1h") hour_rate = price;
        else if(duration == "1d") day_rate = price;
    }
    
    // Process each rental request
    for (int i = 0; i < q; i++) {
        string duration;
        cin >> duration;
        ll minutes = parseTime(duration);
        
        ll cost = 0;
        
        // Calculate days first
        ll days = minutes / MIN_IN_DAY;
        minutes %= MIN_IN_DAY;
        
        // Calculate hours
        ll hours = minutes / MIN_IN_HOUR;
        minutes %= MIN_IN_HOUR;
        
        // Calculate optimal cost
        cost = days * day_rate;
        
        // Handle remaining time
        if(hours > 0) {
            // Check if a day rate would be cheaper
            if((hours * hour_rate) > day_rate) {
                cost += day_rate;
            } else {
                cost += hours * hour_rate;
                // Handle remaining minutes
                if(minutes > 0) {
                    if(min_rate * minutes > hour_rate) {
                        cost += hour_rate;
                    } else {
                        cost += min_rate * minutes;
                    }
                }
            }
        } else if(minutes > 0) {
            // Just minutes left
            if(min_rate * minutes > hour_rate) {
                cost += hour_rate;
            } else {
                cost += min_rate * minutes;
            }
        }
        
        // Output in $X.XX format
        cout << fixed;
        cout.precision(2);
        cout << "$" << (double)cost / 100.0 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}