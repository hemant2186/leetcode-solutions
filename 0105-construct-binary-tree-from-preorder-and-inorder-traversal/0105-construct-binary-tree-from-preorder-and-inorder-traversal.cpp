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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            idxMap[inorder[i]] = i;
        }
        preIdx = 0;
        return build(preorder, 0, inorder.size() - 1);
    }
    
private:
    unordered_map<int, int> idxMap;
    int preIdx;
    
    TreeNode* build(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;
        
        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        
        int mid = idxMap[rootVal];
        
        root->left = build(preorder, left, mid - 1);
        root->right = build(preorder, mid + 1, right);
        
        return root;
    }
};