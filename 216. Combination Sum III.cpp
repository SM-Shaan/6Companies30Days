#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> v;
    void backtrack(int s, int val, vector<int>& v1, int k, int n) {
        
        if (v1.size() == k) {
            if (s == n)
                v.push_back(v1);
            return;
        }
        if (val > 9 || s>n)
            return;

        v1.push_back(val);
        backtrack( s + val, val + 1, v1, k, n);
        v1.pop_back();

        backtrack(s, val + 1, v1, k, n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v1;
        backtrack( 0, 1, v1, k, n);
        return v;
    }
};