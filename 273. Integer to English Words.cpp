#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<int, string> d = {
        {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"},
        {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"},
        {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"},
        {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"},
        {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"},
        {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"},
        {80, "Eighty"}, {90, "Ninety"}, {100, "Hundred"}, {1000, "Thousand"},
        {1000000, "Million"}, {1000000000, "Billion"}
    };

    string ss(int b, string s) {
        if (b >= 100) {
            s += d[b / 100] + " Hundred ";
            b %= 100;
        }
        if (b >= 20) {
            s += d[(b / 10) * 10] + " ";
            b %= 10;
        }
        if (b > 0) {
            s += d[b] + " ";
        }
        return s;
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string s = "";
        if (num >= 1000000000) {
            int b = num / 1000000000;
            s += ss(b, "") + "Billion ";
            num %= 1000000000;
        }
        if (num >= 1000000) {
            int b = num / 1000000;
            s += ss(b, "") + "Million ";
            num %= 1000000;
        }
        if (num >= 1000) {
            int b = num / 1000;
            s += ss(b, "") + "Thousand ";
            num %= 1000;
        }
        if (num > 0) {
            s += ss(num, "");
        }
        while (!s.empty() && s.back() == ' ') {
            s.pop_back();
        }
        return s;
    }
};
