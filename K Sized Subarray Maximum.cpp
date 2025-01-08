//GFG
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> ans; 
        multiset<int> s; 
        int l = 0, r = 0;
        while (r < arr.size()) {
            s.insert(arr[r]);
            if (r - l + 1 == k) {
                ans.push_back(*s.rbegin());
                s.erase(s.find(arr[l])),l++; 
            }
            r++; 
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); 
    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); 
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); 

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

