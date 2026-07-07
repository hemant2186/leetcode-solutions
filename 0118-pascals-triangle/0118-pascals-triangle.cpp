class Solution {
public:
    vector<int> generateRow(int row) {
        vector<int> res;

        int ans = 1;
        res.push_back(ans);

        for (int i = 1; i <= row; i++) {
            ans *= (row - i + 1);
            ans /= i;
            res.push_back(ans);
        }

        return res;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; i++) {
            triangle.push_back(generateRow(i));
        }

        return triangle;
    }
};
