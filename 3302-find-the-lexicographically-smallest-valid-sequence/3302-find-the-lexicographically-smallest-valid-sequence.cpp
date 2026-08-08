class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> pos[26];
        for (int i = 0; i < n; ++i) {
            pos[word1[i] - 'a'].push_back(i);
        }

        vector<int> exact(m + 1, -1);
        vector<int> one(m + 1, -1);
        exact[m] = n;
        one[m] = n;

        auto lastBefore = [&](int c, int bound) -> int {
            auto &v = pos[c];

            auto it = lower_bound(v.begin(), v.end(), bound);

            if (it == v.begin())
                return -1;

            --it;
            return *it;
        };

        for (int j = m - 1; j >= 0; --j) {
            int c = word2[j] - 'a';

            exact[j] = lastBefore(c, exact[j + 1]);
            int takeExact = lastBefore(c, one[j + 1]);
            int takeMismatch = (exact[j + 1] == -1)
                              ? -1
                              : exact[j + 1] - 1;

            one[j] = max(takeExact, takeMismatch);
        }

        if (one[0] == -1)
            return {};

        vector<int> ans;
        ans.reserve(m);

        int prev = -1;
        bool usedMismatch = false;

        for (int j = 0; j < m; ++j) {
            bool found = false;

            for (int i = prev + 1; i < n; ++i) {
                bool same = (word1[i] == word2[j]);

                if (usedMismatch) {
                    if (!same)
                        continue;

                    if (i < exact[j + 1]) {
                        ans.push_back(i);
                        prev = i;
                        found = true;
                        break;
                    }
                } else {
                    if (same) {
                        if (i < one[j + 1]) {
                            ans.push_back(i);
                            prev = i;
                            found = true;
                            break;
                        }
                    } else {
                        if (i < exact[j + 1]) {
                            ans.push_back(i);
                            prev = i;
                            usedMismatch = true;
                            found = true;
                            break;
                        }
                    }
                }
            }

            if (!found)
                return {};
        }

        return ans;
    }
};