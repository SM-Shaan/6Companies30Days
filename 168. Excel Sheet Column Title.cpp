#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while (columnNumber > 0) {
            columnNumber--; 
            char s = 'A' + (columnNumber % 26); 
            res = s + res; 
            columnNumber /= 26; 
        }
        return res;
    }
};
