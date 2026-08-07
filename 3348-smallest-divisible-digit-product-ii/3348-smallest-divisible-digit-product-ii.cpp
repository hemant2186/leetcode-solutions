class Solution {
public:
    struct Cnt {
        int a, b, c, d;
    };

    string smallestNumber(string num, long long t) {
        int need2 = 0, need3 = 0, need5 = 0, need7 = 0;

        while (t % 2 == 0) t /= 2, need2++;
        while (t % 3 == 0) t /= 3, need3++;
        while (t % 5 == 0) t /= 5, need5++;
        while (t % 7 == 0) t /= 7, need7++;

        if (t != 1) return "-1";

        vector<Cnt> val(10);
        val[2] = {1,0,0,0};
        val[3] = {0,1,0,0};
        val[4] = {2,0,0,0};
        val[5] = {0,0,1,0};
        val[6] = {1,1,0,0};
        val[7] = {0,0,0,1};
        val[8] = {3,0,0,0};
        val[9] = {0,2,0,0};

        const int A = 46;
        const int B = 29;
        const int INF = 1e9;

        vector<vector<int>> dp(A + 1, vector<int>(B + 1, INF));
        dp[0][0] = 0;

        for (int a = 0; a <= A; a++) {
            for (int b = 0; b <= B; b++) {
                if (a == 0 && b == 0) continue;
                auto relax = [&](int da, int db) {
                    dp[a][b] = min(dp[a][b],
                        1 + dp[max(0, a - da)][max(0, b - db)]);
                };
                relax(1,0);
                relax(0,1);
                relax(2,0);
                relax(1,1);
                relax(3,0);
                relax(0,2);
            }
        }

        auto feasible = [&](int len, int a, int b, int c, int d) {
            return dp[a][b] + c + d <= len;
        };

        auto build = [&](int len, int a, int b, int c, int d) {
            string res;
            for (int i = 0; i < len; i++) {
                int left = len - i - 1;
                for (int dig = 1; dig <= 9; dig++) {
                    int na = max(0, a - val[dig].a);
                    int nb = max(0, b - val[dig].b);
                    int nc = max(0, c - val[dig].c);
                    int nd = max(0, d - val[dig].d);

                    if (feasible(left, na, nb, nc, nd)) {
                        res.push_back(char('0' + dig));
                        a = na;
                        b = nb;
                        c = nc;
                        d = nd;
                        break;
                    }
                }
            }
            return res;
        };

        int n = num.size();

        vector<Cnt> pref(n + 1);
        vector<int> bad(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i];
            if (num[i] == '0') bad[i + 1] = 1;
            bad[i + 1] |= bad[i];

            Cnt x = val[num[i] - '0'];
            pref[i + 1].a += x.a;
            pref[i + 1].b += x.b;
            pref[i + 1].c += x.c;
            pref[i + 1].d += x.d;
        }

        if (!bad[n] &&
            pref[n].a >= need2 &&
            pref[n].b >= need3 &&
            pref[n].c >= need5 &&
            pref[n].d >= need7)
            return num;

        for (int i = n - 1; i >= 0; i--) {
            if (bad[i]) continue;

            int cur = num[i] - '0';

            for (int d = max(1, cur + 1); d <= 9; d++) {
                int a = max(0, need2 - pref[i].a - val[d].a);
                int b = max(0, need3 - pref[i].b - val[d].b);
                int c = max(0, need5 - pref[i].c - val[d].c);
                int e = max(0, need7 - pref[i].d - val[d].d);

                int rem = n - i - 1;

                if (!feasible(rem, a, b, c, e)) continue;

                return num.substr(0, i) + char('0' + d)
                     + build(rem, a, b, c, e);
            }
        }

        int L = n + 1;
        while (!feasible(L, need2, need3, need5, need7))
            L++;

        return build(L, need2, need3, need5, need7);
    }
};