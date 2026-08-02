/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int levelSize = q.size();
            unsigned long long firstIndex = q.front().second;
            unsigned long long lastIndex = firstIndex;

            for (int i = 0; i < levelSize; i++) {
                auto [node, index] = q.front();
                q.pop();
                
                unsigned long long normalizedIndex = index - firstIndex;
                lastIndex = normalizedIndex;

                if (node->left)
                    q.push({node->left, 2 * normalizedIndex});
                if (node->right)
                    q.push({node->right, 2 * normalizedIndex + 1});
            }

            maxWidth = max(maxWidth, (int)(lastIndex + 1));
        }

        return maxWidth;
    }
};