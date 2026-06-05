class Solution {
public:
    struct Node {
        long long ways;
        long long waviness;
    };

    string s;
    Node dp[20][2][11][11];
    bool vis[20][2][11][11];

    Node dfs(int pos, bool started, int prev2, int prev1, bool tight) {
        if (pos == s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][started][prev2][prev1]) {
            return dp[pos][started][prev2][prev1];
        }

        int limit = tight ? s[pos] - '0' : 9;

        Node ans = {0, 0};

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, false, 10, 10, ntight);

                ans.ways += nxt.ways;
                ans.waviness += nxt.waviness;
            } else {
                int add = 0;

                if (started && prev2 != 10) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d)) {
                        add = 1;
                    }
                }

                int nprev2, nprev1;

                if (!started) {
                    nprev2 = 10;
                    nprev1 = d;
                } else {
                    nprev2 = prev1;
                    nprev1 = d;
                }

                Node nxt =
                    dfs(pos + 1, true, nprev2, nprev1, ntight);

                ans.ways += nxt.ways;
                ans.waviness += nxt.waviness + 1LL * add * nxt.ways;
            }
        }

        if (!tight) {
            vis[pos][started][prev2][prev1] = true;
            dp[pos][started][prev2][prev1] = ans;
        }

        return ans;
    }

    long long solve(long long x) {
        if (x < 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        return dfs(0, false, 10, 10, true).waviness;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};