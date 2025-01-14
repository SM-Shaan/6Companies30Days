#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.size() == 0)
            return 0;
        sort(g.begin(), g.end()), sort(s.begin(), s.end());
        int l = 0, r = 0;
        while (l < g.size() && r < s.size()) {
            if (s[r] >= g[l]) {
                l++;
            }
            r++;
        }
        return l;
    }
};