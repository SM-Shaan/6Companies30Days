#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), ans1 = 0, ans2 = 0;
        int m = n / 2,l =0;
        sort(nums.begin(), nums.end());
        if(n>1) {l = n / 2 - 1;}
        for (auto i : nums) {
            ans1 += abs(i - nums[m]);
            if(n>1) {ans2 += abs(i - nums[l]);}
        }
        return (n & 1 ? ans1 : min(ans1, ans2));
    }
};