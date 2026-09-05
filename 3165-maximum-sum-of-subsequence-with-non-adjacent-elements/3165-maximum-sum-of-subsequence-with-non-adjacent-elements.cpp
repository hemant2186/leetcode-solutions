class Solution {
public:
    using ll = long long;

    struct Node {
        ll dp[2][2];

        Node() {
            memset(dp, 0, sizeof(dp));
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {
        Node res;

        for (int leftTake = 0; leftTake < 2; leftTake++) {
            for (int rightTake = 0; rightTake < 2; rightTake++) {
                for (int leftTake2 = 0; leftTake2 < 2; leftTake2++) {
                    for (int rightTake2 = 0; rightTake2 < 2; rightTake2++) {

                        if (rightTake && leftTake2)
                            continue;

                        res.dp[leftTake][rightTake2] = max(
                            res.dp[leftTake][rightTake2],
                            a.dp[leftTake][rightTake] +
                            b.dp[leftTake2][rightTake2]
                        );
                    }
                }
            }
        }

        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            tree[node].dp[0][0] = 0;

            tree[node].dp[1][1] = max(0, nums[l]);

            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = Node();

            tree[node].dp[0][0] = 0;
            tree[node].dp[1][1] = max(0, val);

            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    int maximumSumSubsequence(vector<int>& nums,
                              vector<vector<int>>& queries) {

        int n = nums.size();

        tree.resize(4 * n + 5);

        build(1, 0, n - 1, nums);

        const ll MOD = 1e9 + 7;
        ll ans = 0;

        for (auto &q : queries) {

            int pos = q[0];
            int val = q[1];

            update(1, 0, n - 1, pos, val);

            ll best = 0;

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    best = max(best, tree[1].dp[i][j]);
                }
            }

            ans = (ans + best) % MOD;
        }

        return ans;
    }
};