#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; ++i) 
            dist[i][i] = 0;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w, dist[v][u] = w;
        }

        for (int k = 0; k < n; ++k) {      
            for (int i = 0; i < n; ++i) {  
                for (int j = 0; j < n; ++j) { 
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) 
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int minR = INT_MAX, resC = -1;
        for (int i = 0; i < n; i++) {
            int reachable = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) {
                    reachable++;
                }
            }
            if (reachable < minR || (reachable == minR && i > resC)) {
                minR = reachable;
                resC = i;
            }
        }
        return resC;
    }
};