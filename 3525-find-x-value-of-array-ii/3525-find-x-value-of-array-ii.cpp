class Solution {
public:
    struct Node {
        int prod = 1;
        array<int, 5> cnt{}; 
    };

    int n, k;
    vector<Node> seg;

    Node mergeNode(const Node& L, const Node& R) {
        Node res;
        res.prod = (L.prod * R.prod) % k;

        for (int r = 0; r < k; ++r) {
            res.cnt[r] += L.cnt[r];
        }
        for (int r = 0; r < k; ++r) {
            int nr = (L.prod * r) % k;
            res.cnt[nr] += R.cnt[r];
        }
        return res;
    }

    void build(int p, int l, int r, const vector<int>& nums) {
        if (l == r) {
            int x = nums[l] % k;
            seg[p].prod = x;
            seg[p].cnt[x] = 1;  
            return;
        }

        int mid = (l + r) / 2;
        build(p * 2, l, mid, nums);
        build(p * 2 + 1, mid + 1, r, nums);

        seg[p] = mergeNode(seg[p * 2], seg[p * 2 + 1]);
    }

    void update(int p, int l, int r, int idx, int val) {
        if (l == r) {
            int x = val % k;
            seg[p] = Node();
            seg[p].prod = x;
            seg[p].cnt[x] = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(p * 2, l, mid, idx, val);
        else
            update(p * 2 + 1, mid + 1, r, idx, val);

        seg[p] = mergeNode(seg[p * 2], seg[p * 2 + 1]);
    }

    Node query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return seg[p];
        }

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(p * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(p * 2 + 1, mid + 1, r, ql, qr);

        Node left = query(p * 2, l, mid, ql, qr);
        Node right = query(p * 2 + 1, mid + 1, r, ql, qr);

        return mergeNode(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int K,
                            vector<vector<int>>& queries) {
        n = nums.size();
        k = K;

        seg.resize(4 * n);
        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            nums[index] = value;
            update(1, 0, n - 1, index, value);
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }
        return ans;
    }
};