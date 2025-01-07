#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int c1=1, c2=1, i=0, res= 0, n = arr.size();
        if(arr.size()<3) return 0;
        while(i<n-1){
            bool f1= false, f2=false;
            if(i+1<n &&arr[i]<arr[i+1]){
                f1=true;
                while(i+1<n && arr[i]<arr[i+1]){
                    c1++, i++;
                }
            }
            if(i+1<n && arr[i]>arr[i+1]){
                f2=true;
                while(i+1<n && arr[i]>arr[i+1]){
                    c2++, i++;
                }
            }
            if(i+1<n && arr[i]==arr[i+1]){
                i++;
            }
            f1 && f2? res = max(res, c1+c2-1) : res = res;
            c1=1, c2=1;
        }
        return res;
    }
};