#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<pair<int,int>> v;
        for(int i=0;i<aliceValues.size();i++)
            v.push_back({aliceValues[i]+bobValues[i],i});
        sort(v.begin(),v.end());
        int b=1,p=0,q=0;
        for(int i=aliceValues.size()-1;i>=0;i--){
            if(b){
                p+=aliceValues[v[i].second],b=0;
            }else{
                q+=bobValues[v[i].second], b=1;
            }
        }
        return (p==q?0:(p>q?1:-1));
    }
};