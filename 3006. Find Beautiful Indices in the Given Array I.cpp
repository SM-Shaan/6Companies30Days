#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSubstringIndices(const string& text, const string& pattern) {
    vector<int> indices;
    size_t pos = text.find(pattern); 
    while (pos != string::npos) {
        indices.push_back(pos);
        pos = text.find(pattern, pos + 1); 
    }
    return indices;
}
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> v1 = findSubstringIndices(s,a),v2 = findSubstringIndices(s,b), result;
        sort(v1.begin(),v1.end()), sort(v2.begin(),v2.end());
        int j = 0;
        for (int i : v1) {
            while (j < v2.size() && v2[j] < i - k) {
                j++;
            }
            if (j < v2.size() && abs(v2[j] - i) <= k) {
                result.push_back(i);
            }
        }
        return result;
    }
};