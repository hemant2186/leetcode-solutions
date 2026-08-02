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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            idxMap[inorder[i]] = i;
        }
        postIdx = postorder.size() - 1;
        return build(postorder, 0, inorder.size() - 1);
    }
    
private:
    unordered_map<int, int> idxMap;
    int postIdx;
    
    TreeNode* build(vector<int>& postorder, int left, int right) {
        if (left > right) return nullptr;
        
        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);
        
        int mid = idxMap[rootVal];

        root->right = build(postorder, mid + 1, right);
        root->left = build(postorder, left, mid - 1);
        
        return root;
    }
};