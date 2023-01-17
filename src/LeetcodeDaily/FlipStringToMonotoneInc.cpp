#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int n;

	int rec(string &s, vector<vector<int>>& dp, int currInd, int prev) {
		if (currInd == n) return 0;

		if (dp[currInd][prev] != -1) return dp[currInd][prev];

		int flip = INT_MAX;
		int notFlip = INT_MAX;

		if (s[currInd] == '0') {
			if (prev == 0) {
				flip = 1 + rec(s, dp, currInd + 1, 1);
				notFlip = 0 + rec(s, dp, currInd + 1, 0);
			} else { // if the prev is 1.
				flip = 1 + rec(s, dp, currInd + 1, 1);
			}
		} else { // if the currInd is 1.
			if (prev == 0) {
				flip = 1 + rec(s, dp, currInd + 1, 0);
				notFlip = 0 + rec(s, dp, currInd + 1, 1);
			} else {
				notFlip = rec(s, dp, currInd + 1, 1);
			}
		}
		return dp[currInd][prev] = min(flip, notFlip);
	}

    int minFlipsMonoIncr(string s) {
        n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        // since it needs to be monotonic increasig so for first index wee are assuming prev as 0.
        return rec(s, dp, 0, 0);
    }
};