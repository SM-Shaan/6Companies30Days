#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> vv;
    Solution(vector<vector<int>>& rects) {
            vv = rects;
    }
    
    vector<int> pick() {
        vector<long long> v;
        int area=0, sum=0;
        for(int i=0;i<vv.size();i++){
            area = (vv[i][2]-vv[i][0]+1) * (vv[i][3]-vv[i][1]+1);
            sum+=area;
            v.push_back(sum);
        }
        int r = rand() % sum;
        auto it = upper_bound(v.begin(),v.end(), r)-v.begin();
        int x = rand()% (vv[it][2] - vv[it][0]+1) + vv[it][0];
        int y = rand()% (vv[it][3] - vv[it][1]+1) + vv[it][1];
        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */