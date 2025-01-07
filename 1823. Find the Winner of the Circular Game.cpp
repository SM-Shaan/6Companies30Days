#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheWinner(int n, int k) {
        std::map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            mp[i] = i;
        }
        auto it = mp.begin(); 
        while (mp.size() > 1) {
            for (int i = 1; i < k; i++) {
                it++;
                if (it == mp.end()) { 
                    it = mp.begin();
                }
            }
            auto toErase = it;
            it++;
            if (it == mp.end()) { 
                it = mp.begin();
            }
            mp.erase(toErase);
        }
        return mp.begin()->first; 
    }
};
