
class Solution {
public:
    long long solveOneDirection(
        const vector<int>& firstFinish,
        const vector<int>& secondStart,
        const vector<int>& secondDuration) {

        int m = secondStart.size();

        vector<pair<int, int>> rides;
        for (int i = 0; i < m; i++) {
            rides.push_back({secondStart[i], secondDuration[i]});
        }

        sort(rides.begin(), rides.end());

        vector<int> starts(m);
        vector<long long> prefMinDur(m);
        vector<long long> suffMinFinish(m);

        for (int i = 0; i < m; i++) {
            starts[i] = rides[i].first;
        }

        prefMinDur[0] = rides[0].second;
        for (int i = 1; i < m; i++) {
            prefMinDur[i] = min(prefMinDur[i - 1],
                                (long long)rides[i].second);
        }

        suffMinFinish[m - 1] =
            (long long)rides[m - 1].first + rides[m - 1].second;

        for (int i = m - 2; i >= 0; i--) {
            suffMinFinish[i] =
                min(suffMinFinish[i + 1],
                    (long long)rides[i].first + rides[i].second);
        }

        long long ans = LLONG_MAX;

        for (long long x : firstFinish) {

            int pos = upper_bound(starts.begin(), starts.end(), x)
                      - starts.begin();

            if (pos > 0) {
                ans = min(ans, x + prefMinDur[pos - 1]);
            }

            if (pos < m) {
                ans = min(ans, suffMinFinish[pos]);
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<int> landFinish(n);
        vector<int> waterFinish(m);

        for (int i = 0; i < n; i++) {
            landFinish[i] = landStartTime[i] + landDuration[i];
        }

        for (int j = 0; j < m; j++) {
            waterFinish[j] = waterStartTime[j] + waterDuration[j];
        }

        long long ans1 =
            solveOneDirection(landFinish,
                              waterStartTime,
                              waterDuration);

        long long ans2 =
            solveOneDirection(waterFinish,
                              landStartTime,
                              landDuration);

        return (int)min(ans1, ans2);
    }
};