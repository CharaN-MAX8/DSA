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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int levelSize = q.size();
            vector<int> currLevel(levelSize);
            
            for(int i=0; i<levelSize; i++){
                TreeNode* curr = q.front();
                q.pop();

                int idx = (leftToRight) ? i : (levelSize-i-1);
                currLevel[idx] = curr->val;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            leftToRight = !leftToRight;
            result.push_back(currLevel);
        }
        return result;
    }
};