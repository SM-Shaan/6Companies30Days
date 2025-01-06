#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int c = 0, r = 0;
                if (i - 1 >= 0 && j - 1 >= 0) {
                    c++;
                    r += img[i - 1][j - 1];
                }
                if (i - 1 >= 0) {
                    c++;
                    r += img[i - 1][j];
                }
                if (i - 1 >= 0 && j + 1 < m) {
                    c++;
                    r += img[i - 1][j + 1];
                }
                if (j - 1 >= 0) {
                    c++;
                    r += img[i][j - 1];
                }
                if (j + 1 < m) {
                    c++;
                    r += img[i][j + 1];
                }
                if (i + 1 < n && j - 1 >= 0) {
                    c++;
                    r += img[i + 1][j - 1];
                }
                if (i + 1 < n) {
                    c++;
                    r += img[i + 1][j];
                }
                if (i + 1 < n && j + 1 < m) {
                    c++;
                    r += img[i + 1][j + 1];
                }
                c++;
                r += img[i][j];
                v[i][j] = r / c;
            }
        }
        return v;
    }
};
