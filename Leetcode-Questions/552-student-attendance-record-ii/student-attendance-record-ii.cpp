class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return countRecords(0, 0, 0, n, dp, MOD);
    }

private:
    int countRecords(int i, int a, int l, int n, vector<vector<vector<int>>>& dp, const int MOD) {
        if (i == n) return 1;
        if (dp[i][a][l] != -1) return dp[i][a][l];

        int ans = 0;

        // Student is present
        ans = (ans + countRecords(i + 1, a, 0, n, dp, MOD)) % MOD;

        // Student is late
        if (l < 2) ans = (ans + countRecords(i + 1, a, l + 1, n, dp, MOD)) % MOD;

        // Student is absent
        if (a < 1) ans = (ans + countRecords(i + 1, a + 1, 0, n, dp, MOD)) % MOD;

        dp[i][a][l] = ans;
        return ans;
    }
};
