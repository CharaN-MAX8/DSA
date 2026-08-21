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
    TreeNode* helper(TreeNode* root, int val){
        if(!root) return new TreeNode(val);
        
        if(root->val > val){
            root->left = helper(root->left, val);
        } else {
            root->right = helper(root->right, val);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);

        for(int i=1; i<preorder.size(); i++){
            helper(root, preorder[i]);
        }
        return root;
    }
};