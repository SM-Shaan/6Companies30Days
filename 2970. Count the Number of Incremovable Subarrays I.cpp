#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        vector<vector<int>> v = subArray(nums);
        int c = 0;
        for (int i = 0; i < v.size(); i++) {
            bool f = true;
            if (v[i].size() > 1) {
                for (int j = 0; j < v[i].size() - 1; j++) {
                    if (v[i][j] >= v[i][j + 1]) {
                        f = false;
                        break;
                    }
                }
            }
            c += f ? 1 : 0;
        }
        return c;
    }
    vector<vector<int>> subArray(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> vv;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vector<int> v1;
                for (int k = 0; k <= n-1; k++) {
                    if(k>=i&&k<=j) continue;
                    else v1.push_back(arr[k]);
                }
                vv.push_back(v1);
            }
        }
        return vv;
    }
};