#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0,r=0,c=0;
        map<int,int> mp;
        while(r<nums.size()){
            (mp.find(nums[r])==mp.end())?mp[nums[r]]=1:mp[nums[r]]+=1;
            c = max(c, r-l);
            if(mp[nums[r]]>k){
                while (mp[nums[r]] > k) { 
                    mp[nums[l]]--;
                    l++;
                }
            }
            r++;
        }
        c = max(c, r-l);
        return c;
    }
};