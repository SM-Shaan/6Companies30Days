#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxval(vector<int>& hBars){
        int a1=0, b1=0, h=0;
        while(b1<hBars.size()){
            if(b1+1<hBars.size()&& hBars[b1+1]-hBars[b1]==1)b1++;
            else{
                h = max(h,b1-a1), b1=b1+1, a1=b1;
            }
        }
        return h;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int h,v, a1 ,a2, b1 ,b2;
        long long a=0;
        sort(hBars.begin(),hBars.end()),sort(vBars.begin(),vBars.end());
        h = maxval(hBars);
        v = maxval(vBars);
        a = min(h+2,v+2);
        return int(a*a);
    }
};