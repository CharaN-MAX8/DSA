class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& result, vector<int>& ans, int i){
        if(i == nums.size()){
            result.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);
        helper(nums,result, ans, i+1);
        ans.pop_back();
        helper(nums,result, ans, i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;

        helper(nums, result, ans, 0);
        return result;
    }
};