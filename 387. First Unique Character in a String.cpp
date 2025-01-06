#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> count;
        map<char, int> firstIndex; 

        for (int i = 0; i < s.size(); i++) {
            count[s[i]]++;
            if (firstIndex.find(s[i]) == firstIndex.end()) {
                firstIndex[s[i]] = i; 
            }
        }

        int mn = s.size(); 
        for (auto& entry : count) {
            if (entry.second == 1) {
                mn = min(mn, firstIndex[entry.first]);
            }
        }

        return (mn == s.size()) ? -1 : mn;
    }
};
