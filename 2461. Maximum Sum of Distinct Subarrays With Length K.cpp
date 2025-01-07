#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int r = 0, l = 0, c = 0, n = nums.size();
        long long ans = 0, res = 0;
        if (nums.size() == 1)
            return nums[0];
        map<int, int> mp;
        while (l < n) {
            if (mp.find(nums[l]) == mp.end()) {
                mp[nums[l]] = nums[l];
                res += nums[l];
                c++, l++;
            } else {
                res -= nums[r];
                mp.erase(nums[r]);
                r++, c--;
            }
            if (c == k) {
                ans = max(ans, res);
                res -= nums[r];
                mp.erase(nums[r]);
                r++, c--;
            }
        }
        return ans;
    }
};