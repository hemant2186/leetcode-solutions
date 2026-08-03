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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        
        while (curr != nullptr || !stk.empty()) {
            // Go as far left as possible
            while (curr != nullptr) {
                stk.push(curr);
                curr = curr->left;
            }
            
            // Visit the node
            curr = stk.top();
            stk.pop();
            
            if (--k == 0) {
                return curr->val;
            }
            
            // Move to the right subtree
            curr = curr->right;
        }
        
        return -1; // unreachable given valid constraints
    }
};