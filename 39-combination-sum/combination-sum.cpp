class Solution {
public:
    set<vector<int>> s;

    void getAllCombination(vector<int>& arr, int tar, int idx, vector<vector<int>> &ans, vector<int> combin){
        if(idx == arr.size() || tar < 0){
            return;
        }

        if(tar == 0){
            if(s.find(combin) == s.end()){
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }

        combin.push_back(arr[idx]);
        getAllCombination(arr, tar - arr[idx], idx+1, ans, combin);
        getAllCombination(arr, tar - arr[idx], idx, ans, combin);
        combin.pop_back();
        getAllCombination(arr, tar, idx+1, ans, combin);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combin;

        getAllCombination(arr, target, 0, ans, combin);
        return ans;
    }
};