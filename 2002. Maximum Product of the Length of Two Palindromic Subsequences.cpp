#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int result =0;
    bool isPalin(string& s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++, j--;
        }
        return true;
    }
    void backtrack(string &s, int ind, string& s1, string& s2){
        if(ind>=s.length()){
            if(isPalin(s1)&&isPalin(s2))
                result = max(result, (int)s1.length()*(int)s2.length());
            return;
        }
        s1.push_back(s[ind]);
        backtrack(s,ind+1,s1,s2);
        s1.pop_back();

        s2.push_back(s[ind]);
        backtrack(s,ind+1,s1,s2);
        s2.pop_back();

        backtrack(s,ind+1, s1,s2);
    }
    int maxProduct(string s) {
        string s1="",s2="";
        backtrack(s,0,s1,s2);
        return result;
    }
};