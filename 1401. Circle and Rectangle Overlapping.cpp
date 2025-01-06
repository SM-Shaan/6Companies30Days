#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int cx = max(x1, min(xCenter, x2)), cy = max(y1, min(yCenter, y2));
        int d = sqrt((cx-xCenter)*(cx-xCenter) + (cy-yCenter)*(cy-yCenter));
        return (d<=radius);
    }
};