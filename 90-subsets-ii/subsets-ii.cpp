class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& result, vector<int>& ans, int i){
        if(i == nums.size()){
            result.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);
        helper(nums, result, ans, i+1);
        ans.pop_back();

        int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[idx-1]){
            idx++;
        }

        helper(nums, result, ans, idx);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> ans;

        helper(nums, result, ans, 0);
        return result;
    }
};