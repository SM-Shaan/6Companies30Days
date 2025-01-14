#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> mp;
        vector<string> v;
        if (s.size() < 10)
            return v;
        for (int i = 0; i <= s.size() - 10; i++) {
            mp[s.substr(i, 10)]++;
        }
        for (auto it: mp) {
            if (it.second > 1) {
                v.push_back(it.first);
            }
        }
        return v;
    }
};
