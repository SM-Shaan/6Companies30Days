#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size(), k=0,l=0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1) k++;
                else if(grid[i][j] == 0) l++;
            }
        }
        if(q.empty()&&k) return -1;
        else if(q.empty()&&l) return 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int a = 0;
        while (!q.empty()) {
            queue<pair<int, int>> p;
            if (!q.empty()) {
                a++;
            }
            while (!q.empty()) {
                auto it = q.front();
                p.push({it.first, it.second});
                q.pop();
            }
            
            while (!p.empty()) {
                auto [f,s] = p.front();
                p.pop();
                for (auto [dx, dy] : directions) {
                    int nx = f + dx, ny = s + dy;

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return a-1;
    }
};