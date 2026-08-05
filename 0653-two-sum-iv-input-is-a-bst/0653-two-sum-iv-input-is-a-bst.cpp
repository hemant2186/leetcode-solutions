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
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        stack<TreeNode*> leftStack, rightStack;
        pushLeft(root, leftStack);
        pushRight(root, rightStack);

        int lo = nextLeft(leftStack);
        int hi = nextRight(rightStack);

        while (lo < hi) {
            int sum = lo + hi;
            if (sum == k) return true;
            else if (sum < k) lo = nextLeft(leftStack);
            else hi = nextRight(rightStack);
        }
        return false;
    }

private:
    void pushLeft(TreeNode* node, stack<TreeNode*>& s) {
        for (; node != NULL; s.push(node), node = node->left);
    }

    void pushRight(TreeNode* node, stack<TreeNode*>& s) {
        for (; node != NULL; s.push(node), node = node->right);
    }

    int nextLeft(stack<TreeNode*>& s) {
        TreeNode* node = s.top();
        s.pop();
        pushLeft(node->right, s);
        return node->val;
    }

    int nextRight(stack<TreeNode*>& s) {
        TreeNode* node = s.top();
        s.pop();
        pushRight(node->left, s);
        return node->val;
    }
};