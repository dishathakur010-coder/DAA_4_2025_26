#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        const int INF = INT_MAX / 2;
        vector<vector<int>> dp(1 << n, vector<int>(n, INF));
        dp[1][0] = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            for (int u = 0; u < n; u++) {
                if (!(mask & (1 << u))) continue;
                if (dp[mask][u] == INF)  continue;
                for (int v = 0; v < n; v++) {
                    if (mask & (1 << v)) continue; 
                    int newMask = mask | (1 << v);
                    dp[newMask][v] = min(
                        dp[newMask][v],
                        dp[mask][u] + cost[u][v]
                    );
                }
            }
        }
        int fullMask = (1 << n) - 1;
        int ans = INF;
        for (int u = 1; u < n; u++) {
            ans = min(ans, dp[fullMask][u] + cost[u][0]);
        }

        return ans;
    }
};
