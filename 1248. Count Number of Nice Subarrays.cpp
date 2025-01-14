#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> v;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & 1)
                v.push_back(i);
        }
        int l, r, ans = 0;
        if (v.size() == 0 || v.size() < k)
            return 0;
        int n = v.size();
        for (int i = 0; i <= n - k; i++) {
            l = (i == 0) ? v[i] : v[i] - v[i - 1] - 1;
            r = (i + k - 1 == n - 1) ? nums.size() - 1 - v[i + k - 1]
                                     : v[i + k] - v[i + k - 1] - 1;
            ans += l * r + r + l + 1;
        }
        return ans;
    }
};