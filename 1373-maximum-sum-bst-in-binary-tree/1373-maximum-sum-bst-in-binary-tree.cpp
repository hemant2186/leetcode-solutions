class NodeValue {
public:
    long minNode, maxNode, sum;

    NodeValue(long minNode, long maxNode, long sum) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};

class Solution {
private:
    int maxSum = 0;

    NodeValue maxSumBSTHelper(TreeNode* root) {
        // An empty tree is a valid BST of sum 0.
        if (!root) {
            return NodeValue(LONG_MAX, LONG_MIN, 0);
        }

        // Get values from left and right subtree of current tree.
        auto left = maxSumBSTHelper(root->left);
        auto right = maxSumBSTHelper(root->right);

        // Current node is greater than max in left AND smaller than min in right, it is a BST.
        if (left.maxNode < root->val && root->val < right.minNode) {
            long sum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, (int)sum);
            return NodeValue(min((long)root->val, left.minNode),
                              max((long)root->val, right.maxNode),
                              sum);
        }

        // Otherwise, return [-inf, inf] so that parent can't be valid BST
        return NodeValue(LONG_MIN, LONG_MAX, 0);
    }

public:
    int maxSumBST(TreeNode* root) {
        maxSumBSTHelper(root);
        return maxSum;
    }
};