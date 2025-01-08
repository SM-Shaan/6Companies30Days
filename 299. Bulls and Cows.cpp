#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size(), b = 0, c = 0;
        map<char, int> ms, mg, ma; 
        for (int i = 0; i < n; i++) {
            ms[secret[i]]++, mg[guess[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (guess[i] == secret[i]) {
                (ma.find(secret[i]) != ma.end()) ? ma[secret[i]]++: ma[secret[i]] = 1;
                ms[secret[i]]--, mg[guess[i]]--;
            }
        }
        for (auto i : ms) {
            if (mg.find(i.first) != mg.end()) {
                c += min(i.second, mg[i.first]);
            }
        }
        for (auto i : ma) {
            b += i.second;
        }
        return to_string(b) + "A" + to_string(c) + "B";
    }
};
