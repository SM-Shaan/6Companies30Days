#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), m = t.size(), a = 0, i = 0, b = 0, c = 0;
        while (a < n) {
            if (abs(s[a] - t[a]) + c <= maxCost) {
                c += abs(s[a] - t[a]);
                a++;
            } else {
                c -= abs(s[i] - t[i]);
                b = max(b, a - i);
                i++;
            }
        }
        b = max(b, a - i);
        return b;
    }
};