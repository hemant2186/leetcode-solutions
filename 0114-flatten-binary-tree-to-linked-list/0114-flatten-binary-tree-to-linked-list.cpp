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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                // Find the rightmost node in curr's left subtree
                // (this is the predecessor in preorder traversal)
                TreeNode* pred = curr->left;
                while (pred->right) {
                    pred = pred->right;
                }
                // Rewire: attach curr's original right subtree
                // to the rightmost node of curr's left subtree
                pred->right = curr->right;

                // Move left subtree to the right, clear left
                curr->right = curr->left;
                curr->left = nullptr;
            }
            // Move to next node in the flattened list
            curr = curr->right;
        }
    }
};