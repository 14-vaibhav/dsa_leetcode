class Solution {
public:
    char processStr(string s, long long k) {
        const long long LIM = 1e15 + 1;

        int n = s.size();
        vector<long long> len(n);

        long long cur = 0;

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (c >= 'a' && c <= 'z') {
                cur++;
            }
            else if (c == '*') {
                if (cur > 0) cur--;
            }
            else if (c == '#') {
                cur = min(LIM, cur * 2);
            }

            len[i] = cur;
        }

        if (k >= cur) return '.';

        for (int i = n - 1; i >= 0; i--) {
            long long before = (i == 0 ? 0 : len[i - 1]);
            char c = s[i];

            if (c >= 'a' && c <= 'z') {
                if (k == before)
                    return c;
            }
            else if (c == '#') {
                if (k >= before)
                    k -= before;
            }
            else if (c == '%') {
                k = before - 1 - k;
            }
        }

        return '.';
    }
};