#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.size() < 2) return 0; 
        sort(nums.begin(), nums.end());  
        set<pair<int, int>> s; 
        int l = 0, r = 1;
        while (r < nums.size()) {
            int diff = nums[r] - nums[l];
            if (diff == k) {
                s.insert({nums[l], nums[r]});
                r++;  
            } else if (diff < k) {
                r++;  
            } else {
                l++;  
            }
            if (l == r) r++;
        }
        return s.size();  
    }
};
